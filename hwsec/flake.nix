{
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  inputs.luispkgs.url = "github:Luis-Hebendanz/nixpkgs/luispkgs";

  outputs = { self, nixpkgs, luispkgs }:
    let
      supportedSystems = [ "x86_64-linux" "x86_64-darwin" "aarch64-linux" "aarch64-darwin" ];
      forAllSystems = nixpkgs.lib.genAttrs supportedSystems;
      pkgs = forAllSystems (system: nixpkgs.legacyPackages.${system});
      luis = import luispkgs
      {
        system = "x86_64-linux";
        config = {
          allowUnfree = true;
        };
      };
    in
    rec {
     devShells = forAllSystems (system: {
        default =
          let
            spkgs = pkgs.${system};
            pypkgs = pkgs.${system}.python310Packages;
          in
          pkgs.${system}.mkShellNoCC {
            packages = with spkgs; [
              pypkgs.myhdl
              picocom
            ] ++ (with luis; [
              xc3sprog
            ]);

        };
      });
    };
}

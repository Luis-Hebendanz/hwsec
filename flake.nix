{
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  inputs.luispkgs.url = "github:Luis-Hebendanz/nixpkgs/luispkgs";
  inputs.reha = {
    url = "github:Luis-Hebendanz/rhea";
    flake = false;
  };

  outputs = { self, nixpkgs, luispkgs, reha }:
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
     devShells = forAllSystems (system: rec {
        pythonShell =           let
            pypkgs = spkgs.python310Packages;
            spkgs = pkgs.${system};
            my-python-packages = ps: with ps; [
              # Add python dependencies here
              autopep8
              setuptools
              ipython
              pyserial
              numpy
              matplotlib
              scikit-learn
              #myhdl
              #rhea
              pytest
            ];
            python-with-my-packages = spkgs.python3.withPackages my-python-packages;

          in (spkgs.mkShell {
          buildInputs = with spkgs; [
              python-with-my-packages
              picocom
              bash
              coreutils
              zlib
              lsb-release
              stdenv.cc.cc
              pkg-config
              ncurses5
              libuuid
              xorg.libXext
              xorg.libICE
              xorg.libXrandr
              xorg.libX11
              xorg.libXrender
              xorg.libXtst
              xorg.libXi
              xorg.libSM
              xorg.libXft
              xorg.libxcb
              xorg.libxcb
              # common requirements
              freetype
              fontconfig
              glib
              gtk2
              gtk3

              # to compile some xilinx examples
              opencl-clhpp
              ocl-icd
              opencl-headers

              # from installLibs.sh
              graphviz
              (lib.hiPrio gcc)
              unzip
              nettools
            ] ++ (with luis; [
              xc3sprog
            ]);
        });

        default =
          let
            pypkgs = spkgs.python310Packages;
            spkgs = pkgs.${system};
            my-python-packages = ps: with ps; [
              # Add python dependencies here
              autopep8
              setuptools
              ipython
              pyserial
              numpy
              matplotlib
              #myhdl
              #rhea
              pytest
            ];
            python-with-my-packages = spkgs.python3.withPackages my-python-packages;

          in
          (spkgs.buildFHSUserEnv {
            name = "xilinx-vitis";
            runScript = "bash";
            multiPkgs = null;
            profile = ''
            # export LC_NUMERIC="en_US.UTF-8"
            source ./xilinx_install/14.7/ISE_DS/settings64.sh
            export PATH=$PATH:"./xilinx_install/14.7/ISE_DS/ISE/bin/lin64/"
            echo "Execute '_pn' for the xilinx fpga editor"
            '';
            targetPkgs = pkgs: with spkgs; [
              python-with-my-packages
              picocom
              bash
              coreutils
              zlib
              lsb-release
              stdenv.cc.cc
              pkg-config
              ncurses5
              libuuid
              xorg.libXext
              xorg.libICE
              xorg.libXrandr
              xorg.libX11
              xorg.libXrender
              xorg.libXtst
              xorg.libXi
              xorg.libSM
              xorg.libXft
              xorg.libxcb
              xorg.libxcb
              # common requirements
              freetype
              fontconfig
              glib
              gtk2
              gtk3

              # to compile some xilinx examples
              opencl-clhpp
              ocl-icd
              opencl-headers

              # from installLibs.sh
              graphviz
              (lib.hiPrio gcc)
              unzip
              nettools
            ] ++ (with luis; [
              xc3sprog
            ]);

        }).env;
      });
    };
}

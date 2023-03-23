#
#
# ISE implementation script
# create: Thu, 23 Mar 2023 10:58:38 +0000
# by: blinky.py
#
#
# set compile directory:
set compile_directory .
set top_name pprov
set top pprov
# set Project:
set proj pprov
# change to the directory:
cd xilinx/
# set ucf file:
set constraints_file pprov.ucf
# set variables:
project new pprov.xise
project set family spartan6
project set device XC6SLX9
project set package TQG144
project set speed -2

# add hdl files:
xfile add pprov.ucf
xfile add pprov.v
# test if set_source_directory is set:
if { ! [catch {set source_directory $source_directory}]} {
  project set "Macro Search Path"
 $source_directory -process Translate
}
project set "Create Binary Configuration File" "true" -process "Generate Programming File"
 # run the implementation:
process run "Synthesize" 
process run "Translate" 
process run "Map" 
process run "Place & Route" 
process run "Generate Programming File" 
# close the project:
project close


# PlanAhead Launch Script for Post-Synthesis floorplanning, created by Project Navigator

create_project -name ex1 -dir "/home/lhebendanz/Projects/hwsec/ex1/planAhead_run_2" -part xc6slx9tqg144-2
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "/home/lhebendanz/Projects/hwsec/ex1/top.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {/home/lhebendanz/Projects/hwsec/ex1} }
set_property target_constrs_file "papilio_pro.ucf" [current_fileset -constrset]
add_files [list {papilio_pro.ucf}] -fileset [get_property constrset [current_run]]
link_design

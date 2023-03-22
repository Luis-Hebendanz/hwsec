/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_02919053116098515681_2910696936_init();
    work_m_00494931976917237279_1197626901_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_00494931976917237279_1197626901");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}

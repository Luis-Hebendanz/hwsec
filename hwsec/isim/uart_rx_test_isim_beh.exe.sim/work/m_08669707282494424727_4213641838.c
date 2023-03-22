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

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/morty/ex1/uart_rx.v";
static int ng1[] = {1, 0};
static unsigned int ng2[] = {0U, 0U};
static int ng3[] = {0, 0};
static unsigned int ng4[] = {2U, 0U};
static int ng5[] = {2, 0};
static unsigned int ng6[] = {1U, 0U};
static int ng7[] = {8, 0};



static void Always_40_0(char *t0)
{
    char t8[8];
    char t33[8];
    char t38[8];
    char t42[8];
    char t45[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    int t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t39;
    char *t40;
    char *t41;
    char *t43;
    char *t44;
    char *t46;
    char *t47;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    int t65;
    int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    char *t79;
    char *t80;

LAB0:    t1 = (t0 + 3456U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 3776);
    *((int *)t2) = 1;
    t3 = (t0 + 3488);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(41, ng0);

LAB5:    xsi_set_current_line(43, ng0);
    t4 = (t0 + 2384);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 32, t6, 16, t7, 32);
    t9 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t9, t8, 0, 0, 16, 0LL);
    xsi_set_current_line(44, ng0);
    t2 = (t0 + 2224);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB6:    t5 = ((char*)((ng2)));
    t10 = xsi_vlog_unsigned_case_compare(t4, 3, t5, 3);
    if (t10 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng4)));
    t10 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t10 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng6)));
    t10 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t10 == 1)
        goto LAB11;

LAB12:
LAB13:    goto LAB2;

LAB7:    xsi_set_current_line(45, ng0);

LAB14:    xsi_set_current_line(46, ng0);
    t6 = (t0 + 1504U);
    t7 = *((char **)t6);
    t6 = ((char*)((ng3)));
    memset(t8, 0, 8);
    t9 = (t7 + 4);
    t11 = (t6 + 4);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t6);
    t14 = (t12 ^ t13);
    t15 = *((unsigned int *)t9);
    t16 = *((unsigned int *)t11);
    t17 = (t15 ^ t16);
    t18 = (t14 | t17);
    t19 = *((unsigned int *)t9);
    t20 = *((unsigned int *)t11);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB18;

LAB15:    if (t21 != 0)
        goto LAB17;

LAB16:    *((unsigned int *)t8) = 1;

LAB18:    t25 = (t8 + 4);
    t26 = *((unsigned int *)t25);
    t27 = (~(t26));
    t28 = *((unsigned int *)t8);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB19;

LAB20:
LAB21:    goto LAB13;

LAB9:    xsi_set_current_line(53, ng0);

LAB23:    xsi_set_current_line(54, ng0);
    t3 = (t0 + 2384);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 472);
    t9 = *((char **)t7);
    t7 = ((char*)((ng5)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_divide(t8, 32, t9, 32, t7, 32);
    memset(t33, 0, 8);
    t11 = (t6 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB25;

LAB24:    t24 = (t8 + 4);
    if (*((unsigned int *)t24) != 0)
        goto LAB25;

LAB28:    if (*((unsigned int *)t6) < *((unsigned int *)t8))
        goto LAB27;

LAB26:    *((unsigned int *)t33) = 1;

LAB27:    t31 = (t33 + 4);
    t12 = *((unsigned int *)t31);
    t13 = (~(t12));
    t14 = *((unsigned int *)t33);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB29;

LAB30:
LAB31:    goto LAB13;

LAB11:    xsi_set_current_line(61, ng0);

LAB33:    xsi_set_current_line(62, ng0);
    t3 = (t0 + 2384);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 472);
    t9 = *((char **)t7);
    memset(t8, 0, 8);
    t7 = (t6 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB35;

LAB34:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB35;

LAB38:    if (*((unsigned int *)t6) < *((unsigned int *)t9))
        goto LAB37;

LAB36:    *((unsigned int *)t8) = 1;

LAB37:    memset(t33, 0, 8);
    t25 = (t8 + 4);
    t12 = *((unsigned int *)t25);
    t13 = (~(t12));
    t14 = *((unsigned int *)t8);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t25) != 0)
        goto LAB41;

LAB42:    t32 = (t33 + 4);
    t17 = *((unsigned int *)t33);
    t18 = *((unsigned int *)t32);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB43;

LAB44:    memcpy(t45, t33, 8);

LAB45:    t73 = (t45 + 4);
    t74 = *((unsigned int *)t73);
    t75 = (~(t74));
    t76 = *((unsigned int *)t45);
    t77 = (t76 & t75);
    t78 = (t77 != 0);
    if (t78 > 0)
        goto LAB58;

LAB59:
LAB60:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 2384);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 472);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    t6 = (t5 + 4);
    if (*((unsigned int *)t6) != 0)
        goto LAB65;

LAB64:    t9 = (t7 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB65;

LAB68:    if (*((unsigned int *)t5) < *((unsigned int *)t7))
        goto LAB67;

LAB66:    *((unsigned int *)t8) = 1;

LAB67:    memset(t33, 0, 8);
    t24 = (t8 + 4);
    t12 = *((unsigned int *)t24);
    t13 = (~(t12));
    t14 = *((unsigned int *)t8);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB69;

LAB70:    if (*((unsigned int *)t24) != 0)
        goto LAB71;

LAB72:    t31 = (t33 + 4);
    t17 = *((unsigned int *)t33);
    t18 = *((unsigned int *)t31);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB73;

LAB74:    memcpy(t45, t33, 8);

LAB75:    t56 = (t45 + 4);
    t74 = *((unsigned int *)t56);
    t75 = (~(t74));
    t76 = *((unsigned int *)t45);
    t77 = (t76 & t75);
    t78 = (t77 != 0);
    if (t78 > 0)
        goto LAB88;

LAB89:
LAB90:    goto LAB13;

LAB17:    t24 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t24) = 1;
    goto LAB18;

LAB19:    xsi_set_current_line(47, ng0);

LAB22:    xsi_set_current_line(48, ng0);
    t31 = ((char*)((ng3)));
    t32 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t32, t31, 0, 0, 16, 0LL);
    xsi_set_current_line(49, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 0LL);
    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);
    goto LAB21;

LAB25:    t25 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB27;

LAB29:    xsi_set_current_line(55, ng0);

LAB32:    xsi_set_current_line(57, ng0);
    t32 = ((char*)((ng3)));
    t34 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t34, t32, 0, 0, 16, 0LL);
    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);
    goto LAB31;

LAB35:    t24 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t24) = 1;
    goto LAB37;

LAB39:    *((unsigned int *)t33) = 1;
    goto LAB42;

LAB41:    t31 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB42;

LAB43:    t34 = (t0 + 2544);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    t37 = ((char*)((ng7)));
    memset(t38, 0, 8);
    t39 = (t36 + 4);
    if (*((unsigned int *)t39) != 0)
        goto LAB47;

LAB46:    t40 = (t37 + 4);
    if (*((unsigned int *)t40) != 0)
        goto LAB47;

LAB50:    if (*((unsigned int *)t36) < *((unsigned int *)t37))
        goto LAB48;

LAB49:    memset(t42, 0, 8);
    t43 = (t38 + 4);
    t20 = *((unsigned int *)t43);
    t21 = (~(t20));
    t22 = *((unsigned int *)t38);
    t23 = (t22 & t21);
    t26 = (t23 & 1U);
    if (t26 != 0)
        goto LAB51;

LAB52:    if (*((unsigned int *)t43) != 0)
        goto LAB53;

LAB54:    t27 = *((unsigned int *)t33);
    t28 = *((unsigned int *)t42);
    t29 = (t27 & t28);
    *((unsigned int *)t45) = t29;
    t46 = (t33 + 4);
    t47 = (t42 + 4);
    t48 = (t45 + 4);
    t30 = *((unsigned int *)t46);
    t49 = *((unsigned int *)t47);
    t50 = (t30 | t49);
    *((unsigned int *)t48) = t50;
    t51 = *((unsigned int *)t48);
    t52 = (t51 != 0);
    if (t52 == 1)
        goto LAB55;

LAB56:
LAB57:    goto LAB45;

LAB47:    t41 = (t38 + 4);
    *((unsigned int *)t38) = 1;
    *((unsigned int *)t41) = 1;
    goto LAB49;

LAB48:    *((unsigned int *)t38) = 1;
    goto LAB49;

LAB51:    *((unsigned int *)t42) = 1;
    goto LAB54;

LAB53:    t44 = (t42 + 4);
    *((unsigned int *)t42) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB54;

LAB55:    t53 = *((unsigned int *)t45);
    t54 = *((unsigned int *)t48);
    *((unsigned int *)t45) = (t53 | t54);
    t55 = (t33 + 4);
    t56 = (t42 + 4);
    t57 = *((unsigned int *)t33);
    t58 = (~(t57));
    t59 = *((unsigned int *)t55);
    t60 = (~(t59));
    t61 = *((unsigned int *)t42);
    t62 = (~(t61));
    t63 = *((unsigned int *)t56);
    t64 = (~(t63));
    t65 = (t58 & t60);
    t66 = (t62 & t64);
    t67 = (~(t65));
    t68 = (~(t66));
    t69 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t69 & t67);
    t70 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t70 & t68);
    t71 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t71 & t67);
    t72 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t72 & t68);
    goto LAB57;

LAB58:    xsi_set_current_line(63, ng0);

LAB61:    xsi_set_current_line(64, ng0);
    t79 = ((char*)((ng3)));
    t80 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t80, t79, 0, 0, 16, 0LL);
    xsi_set_current_line(65, ng0);
    t2 = (t0 + 1504U);
    t3 = *((char **)t2);
    t2 = (t0 + 2064);
    t5 = (t0 + 2064);
    t6 = (t5 + 72U);
    t7 = *((char **)t6);
    t9 = (t0 + 2544);
    t11 = (t9 + 56U);
    t24 = *((char **)t11);
    xsi_vlog_generic_convert_bit_index(t8, t7, 2, t24, 8, 2);
    t25 = (t8 + 4);
    t12 = *((unsigned int *)t25);
    t10 = (!(t12));
    if (t10 == 1)
        goto LAB62;

LAB63:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng1)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 32, t5, 8, t6, 32);
    t7 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t7, t8, 0, 0, 8, 0LL);
    goto LAB60;

LAB62:    xsi_vlogvar_assign_value(t2, t3, 0, *((unsigned int *)t8), 1);
    goto LAB63;

LAB65:    t11 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB67;

LAB69:    *((unsigned int *)t33) = 1;
    goto LAB72;

LAB71:    t25 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB72;

LAB73:    t32 = (t0 + 2544);
    t34 = (t32 + 56U);
    t35 = *((char **)t34);
    t36 = ((char*)((ng7)));
    memset(t38, 0, 8);
    t37 = (t35 + 4);
    if (*((unsigned int *)t37) != 0)
        goto LAB77;

LAB76:    t39 = (t36 + 4);
    if (*((unsigned int *)t39) != 0)
        goto LAB77;

LAB80:    if (*((unsigned int *)t35) < *((unsigned int *)t36))
        goto LAB79;

LAB78:    *((unsigned int *)t38) = 1;

LAB79:    memset(t42, 0, 8);
    t41 = (t38 + 4);
    t20 = *((unsigned int *)t41);
    t21 = (~(t20));
    t22 = *((unsigned int *)t38);
    t23 = (t22 & t21);
    t26 = (t23 & 1U);
    if (t26 != 0)
        goto LAB81;

LAB82:    if (*((unsigned int *)t41) != 0)
        goto LAB83;

LAB84:    t27 = *((unsigned int *)t33);
    t28 = *((unsigned int *)t42);
    t29 = (t27 & t28);
    *((unsigned int *)t45) = t29;
    t44 = (t33 + 4);
    t46 = (t42 + 4);
    t47 = (t45 + 4);
    t30 = *((unsigned int *)t44);
    t49 = *((unsigned int *)t46);
    t50 = (t30 | t49);
    *((unsigned int *)t47) = t50;
    t51 = *((unsigned int *)t47);
    t52 = (t51 != 0);
    if (t52 == 1)
        goto LAB85;

LAB86:
LAB87:    goto LAB75;

LAB77:    t40 = (t38 + 4);
    *((unsigned int *)t38) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB79;

LAB81:    *((unsigned int *)t42) = 1;
    goto LAB84;

LAB83:    t43 = (t42 + 4);
    *((unsigned int *)t42) = 1;
    *((unsigned int *)t43) = 1;
    goto LAB84;

LAB85:    t53 = *((unsigned int *)t45);
    t54 = *((unsigned int *)t47);
    *((unsigned int *)t45) = (t53 | t54);
    t48 = (t33 + 4);
    t55 = (t42 + 4);
    t57 = *((unsigned int *)t33);
    t58 = (~(t57));
    t59 = *((unsigned int *)t48);
    t60 = (~(t59));
    t61 = *((unsigned int *)t42);
    t62 = (~(t61));
    t63 = *((unsigned int *)t55);
    t64 = (~(t63));
    t10 = (t58 & t60);
    t65 = (t62 & t64);
    t67 = (~(t10));
    t68 = (~(t65));
    t69 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t69 & t67);
    t70 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t70 & t68);
    t71 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t71 & t67);
    t72 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t72 & t68);
    goto LAB87;

LAB88:    xsi_set_current_line(70, ng0);

LAB91:    xsi_set_current_line(71, ng0);
    t73 = (t0 + 1504U);
    t79 = *((char **)t73);
    t73 = (t0 + 1904);
    xsi_vlogvar_wait_assign_value(t73, t79, 0, 0, 1, 0LL);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2224);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    goto LAB90;

}


extern void work_m_08669707282494424727_4213641838_init()
{
	static char *pe[] = {(void *)Always_40_0};
	xsi_register_didat("work_m_08669707282494424727_4213641838", "isim/uart_rx_test_isim_beh.exe.sim/work/m_08669707282494424727_4213641838.didat");
	xsi_register_executes(pe);
}

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
static const char *ng0 = "/home/lhebendanz/Projects/hwsec2/hwsec/top.v";
static int ng1[] = {0, 0};
static int ng2[] = {16, 0};
static int ng3[] = {65, 0};
static int ng4[] = {1, 0};
static unsigned int ng5[] = {0U, 0U};
static unsigned int ng6[] = {7U, 0U};
static unsigned int ng7[] = {4U, 0U};
static int ng8[] = {15, 0};
static unsigned int ng9[] = {1U, 0U};
static unsigned int ng10[] = {2U, 0U};
static int ng11[] = {32000000, 0};
static int ng12[] = {115200, 0};
static int ng13[] = {115, 0};
static int ng14[] = {112, 0};
static int ng15[] = {103, 0};
static int ng16[] = {27, 0};



static void Initial_98_0(char *t0)
{
    char t5[8];
    char t16[8];
    char t18[8];
    char t19[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t17;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    unsigned int t30;
    int t31;
    char *t32;
    unsigned int t33;
    int t34;
    int t35;
    unsigned int t36;
    unsigned int t37;
    int t38;
    int t39;

LAB0:    xsi_set_current_line(98, ng0);

LAB2:    xsi_set_current_line(99, ng0);
    xsi_set_current_line(99, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 5808);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);

LAB3:    t1 = (t0 + 5808);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = ((char*)((ng2)));
    memset(t5, 0, 8);
    xsi_vlog_signed_less(t5, 32, t3, 32, t4, 32);
    t6 = (t5 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    xsi_set_current_line(99, ng0);

LAB6:    xsi_set_current_line(100, ng0);
    t12 = ((char*)((ng3)));
    t13 = (t0 + 5808);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memset(t16, 0, 8);
    xsi_vlog_unsigned_add(t16, 32, t12, 32, t15, 32);
    t17 = (t0 + 5168);
    t20 = (t0 + 5168);
    t21 = (t20 + 72U);
    t22 = *((char **)t21);
    t23 = (t0 + 5168);
    t24 = (t23 + 64U);
    t25 = *((char **)t24);
    t26 = (t0 + 5808);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    xsi_vlog_generic_convert_array_indices(t18, t19, t22, t25, 2, 1, t28, 32, 1);
    t29 = (t18 + 4);
    t30 = *((unsigned int *)t29);
    t31 = (!(t30));
    t32 = (t19 + 4);
    t33 = *((unsigned int *)t32);
    t34 = (!(t33));
    t35 = (t31 && t34);
    if (t35 == 1)
        goto LAB7;

LAB8:    xsi_set_current_line(99, ng0);
    t1 = (t0 + 5808);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = ((char*)((ng4)));
    memset(t5, 0, 8);
    xsi_vlog_signed_add(t5, 32, t3, 32, t4, 32);
    t6 = (t0 + 5808);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 32);
    goto LAB3;

LAB7:    t36 = *((unsigned int *)t18);
    t37 = *((unsigned int *)t19);
    t38 = (t36 - t37);
    t39 = (t38 + 1);
    xsi_vlogvar_wait_assign_value(t17, t16, 0, *((unsigned int *)t19), t39, 0LL);
    goto LAB8;

}

static void Always_105_1(char *t0)
{
    char t6[8];
    char t17[8];
    char t49[8];
    char t55[8];
    char t89[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    int t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t28;
    int t29;
    char *t30;
    unsigned int t31;
    int t32;
    int t33;
    unsigned int t34;
    unsigned int t35;
    int t36;
    int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;
    char *t87;
    char *t88;
    char *t90;
    char *t91;
    char *t92;
    char *t93;
    char *t94;
    char *t95;
    char *t96;
    char *t97;
    char *t98;
    char *t99;

LAB0:    t1 = (t0 + 6968U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(105, ng0);
    t2 = (t0 + 7288);
    *((int *)t2) = 1;
    t3 = (t0 + 7000);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(106, ng0);

LAB5:    xsi_set_current_line(108, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 4528);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(109, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3888);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(110, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4208);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(111, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3728);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(112, ng0);
    t2 = (t0 + 5328);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5328);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(113, ng0);
    t2 = (t0 + 5488);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5488);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(114, ng0);
    t2 = (t0 + 4848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);
    xsi_set_current_line(115, ng0);
    t2 = (t0 + 4688);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4688);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(116, ng0);
    t2 = (t0 + 4368);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4368);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(118, ng0);
    t2 = (t0 + 4048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4048);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(119, ng0);
    t2 = (t0 + 5648);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 5648);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 32, 0LL);
    xsi_set_current_line(121, ng0);
    t2 = (t0 + 4848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB6:    t5 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t5, 3);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng9)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng10)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t8 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t8 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(123, ng0);

LAB18:    xsi_set_current_line(124, ng0);
    t7 = (t0 + 3328U);
    t9 = *((char **)t7);
    t7 = (t9 + 4);
    t10 = *((unsigned int *)t7);
    t11 = (~(t10));
    t12 = *((unsigned int *)t9);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB19;

LAB20:
LAB21:    xsi_set_current_line(130, ng0);
    t2 = (t0 + 5488);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t7 = ((char*)((ng2)));
    memset(t6, 0, 8);
    t9 = (t5 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB26;

LAB25:    t15 = (t7 + 4);
    if (*((unsigned int *)t15) != 0)
        goto LAB26;

LAB29:    if (*((unsigned int *)t5) < *((unsigned int *)t7))
        goto LAB28;

LAB27:    *((unsigned int *)t6) = 1;

LAB28:    t18 = (t6 + 4);
    t10 = *((unsigned int *)t18);
    t11 = (~(t10));
    t12 = *((unsigned int *)t6);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB30;

LAB31:
LAB32:    goto LAB17;

LAB9:    xsi_set_current_line(136, ng0);

LAB34:    xsi_set_current_line(137, ng0);
    t3 = (t0 + 2848U);
    t5 = *((char **)t3);
    t3 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t9 = (t3 + 4);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t3);
    t12 = (t10 ^ t11);
    t13 = *((unsigned int *)t7);
    t14 = *((unsigned int *)t9);
    t28 = (t13 ^ t14);
    t31 = (t12 | t28);
    t34 = *((unsigned int *)t7);
    t35 = *((unsigned int *)t9);
    t38 = (t34 | t35);
    t39 = (~(t38));
    t40 = (t31 & t39);
    if (t40 != 0)
        goto LAB38;

LAB35:    if (t38 != 0)
        goto LAB37;

LAB36:    *((unsigned int *)t6) = 1;

LAB38:    t16 = (t6 + 4);
    t41 = *((unsigned int *)t16);
    t42 = (~(t41));
    t43 = *((unsigned int *)t6);
    t44 = (t43 & t42);
    t45 = (t44 != 0);
    if (t45 > 0)
        goto LAB39;

LAB40:
LAB41:    xsi_set_current_line(142, ng0);
    t2 = (t0 + 2848U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t3 + 4);
    t10 = *((unsigned int *)t2);
    t11 = (~(t10));
    t12 = *((unsigned int *)t3);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t2) != 0)
        goto LAB45;

LAB46:    t7 = (t6 + 4);
    t28 = *((unsigned int *)t6);
    t31 = *((unsigned int *)t7);
    t34 = (t28 || t31);
    if (t34 > 0)
        goto LAB47;

LAB48:    memcpy(t55, t6, 8);

LAB49:    t80 = (t55 + 4);
    t81 = *((unsigned int *)t80);
    t82 = (~(t81));
    t83 = *((unsigned int *)t55);
    t84 = (t83 & t82);
    t85 = (t84 != 0);
    if (t85 > 0)
        goto LAB61;

LAB62:
LAB63:    xsi_set_current_line(151, ng0);
    t2 = (t0 + 5328);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t7 = ((char*)((ng8)));
    memset(t6, 0, 8);
    t9 = (t5 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB66;

LAB65:    t15 = (t7 + 4);
    if (*((unsigned int *)t15) != 0)
        goto LAB66;

LAB69:    if (*((unsigned int *)t5) < *((unsigned int *)t7))
        goto LAB68;

LAB67:    *((unsigned int *)t6) = 1;

LAB68:    t18 = (t6 + 4);
    t10 = *((unsigned int *)t18);
    t11 = (~(t10));
    t12 = *((unsigned int *)t6);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB70;

LAB71:
LAB72:    goto LAB17;

LAB11:    xsi_set_current_line(157, ng0);

LAB74:    xsi_set_current_line(158, ng0);
    t3 = (t0 + 3008U);
    t5 = *((char **)t3);
    t3 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t9 = (t3 + 4);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t3);
    t12 = (t10 ^ t11);
    t13 = *((unsigned int *)t7);
    t14 = *((unsigned int *)t9);
    t28 = (t13 ^ t14);
    t31 = (t12 | t28);
    t34 = *((unsigned int *)t7);
    t35 = *((unsigned int *)t9);
    t38 = (t34 | t35);
    t39 = (~(t38));
    t40 = (t31 & t39);
    if (t40 != 0)
        goto LAB78;

LAB75:    if (t38 != 0)
        goto LAB77;

LAB76:    *((unsigned int *)t6) = 1;

LAB78:    t16 = (t6 + 4);
    t41 = *((unsigned int *)t16);
    t42 = (~(t41));
    t43 = *((unsigned int *)t6);
    t44 = (t43 & t42);
    t45 = (t44 != 0);
    if (t45 > 0)
        goto LAB79;

LAB80:
LAB81:    xsi_set_current_line(163, ng0);
    t2 = (t0 + 3008U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t3 + 4);
    t10 = *((unsigned int *)t2);
    t11 = (~(t10));
    t12 = *((unsigned int *)t3);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB83;

LAB84:    if (*((unsigned int *)t2) != 0)
        goto LAB85;

LAB86:    t7 = (t6 + 4);
    t28 = *((unsigned int *)t6);
    t31 = *((unsigned int *)t7);
    t34 = (t28 || t31);
    if (t34 > 0)
        goto LAB87;

LAB88:    memcpy(t55, t6, 8);

LAB89:    t80 = (t55 + 4);
    t81 = *((unsigned int *)t80);
    t82 = (~(t81));
    t83 = *((unsigned int *)t55);
    t84 = (t83 & t82);
    t85 = (t84 != 0);
    if (t85 > 0)
        goto LAB101;

LAB102:
LAB103:    xsi_set_current_line(171, ng0);
    t2 = (t0 + 5328);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t7 = ((char*)((ng8)));
    memset(t6, 0, 8);
    t9 = (t5 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB106;

LAB105:    t15 = (t7 + 4);
    if (*((unsigned int *)t15) != 0)
        goto LAB106;

LAB109:    if (*((unsigned int *)t5) < *((unsigned int *)t7))
        goto LAB108;

LAB107:    *((unsigned int *)t6) = 1;

LAB108:    t18 = (t6 + 4);
    t10 = *((unsigned int *)t18);
    t11 = (~(t10));
    t12 = *((unsigned int *)t6);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB110;

LAB111:
LAB112:    goto LAB17;

LAB13:    xsi_set_current_line(177, ng0);

LAB114:    xsi_set_current_line(178, ng0);
    t3 = (t0 + 5648);
    t5 = (t3 + 56U);
    t7 = *((char **)t5);
    t9 = ((char*)((ng11)));
    t15 = ((char*)((ng12)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_divide(t6, 32, t9, 32, t15, 32);
    memset(t17, 0, 8);
    t16 = (t7 + 4);
    if (*((unsigned int *)t16) != 0)
        goto LAB116;

LAB115:    t18 = (t6 + 4);
    if (*((unsigned int *)t18) != 0)
        goto LAB116;

LAB119:    if (*((unsigned int *)t7) < *((unsigned int *)t6))
        goto LAB118;

LAB117:    *((unsigned int *)t17) = 1;

LAB118:    t20 = (t17 + 4);
    t10 = *((unsigned int *)t20);
    t11 = (~(t10));
    t12 = *((unsigned int *)t17);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB120;

LAB121:
LAB122:    goto LAB17;

LAB15:    xsi_set_current_line(185, ng0);

LAB130:    xsi_set_current_line(186, ng0);
    t3 = ((char*)((ng4)));
    t5 = (t0 + 3728);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(188, ng0);
    t2 = (t0 + 2528U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t10 = *((unsigned int *)t2);
    t11 = (~(t10));
    t12 = *((unsigned int *)t3);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB131;

LAB132:
LAB133:    xsi_set_current_line(201, ng0);
    t2 = (t0 + 3328U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t10 = *((unsigned int *)t2);
    t11 = (~(t10));
    t12 = *((unsigned int *)t3);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB140;

LAB141:
LAB142:    goto LAB17;

LAB19:    xsi_set_current_line(125, ng0);

LAB22:    xsi_set_current_line(126, ng0);
    t15 = (t0 + 3168U);
    t16 = *((char **)t15);
    t15 = (t0 + 5168);
    t18 = (t0 + 5168);
    t19 = (t18 + 72U);
    t20 = *((char **)t19);
    t21 = (t0 + 5168);
    t22 = (t21 + 64U);
    t23 = *((char **)t22);
    t24 = (t0 + 5488);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    xsi_vlog_generic_convert_array_indices(t6, t17, t20, t23, 2, 1, t26, 8, 2);
    t27 = (t6 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (!(t28));
    t30 = (t17 + 4);
    t31 = *((unsigned int *)t30);
    t32 = (!(t31));
    t33 = (t29 && t32);
    if (t33 == 1)
        goto LAB23;

LAB24:    xsi_set_current_line(127, ng0);
    t2 = (t0 + 5488);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t7 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t5, 8, t7, 32);
    t9 = (t0 + 5488);
    xsi_vlogvar_wait_assign_value(t9, t6, 0, 0, 8, 0LL);
    goto LAB21;

LAB23:    t34 = *((unsigned int *)t6);
    t35 = *((unsigned int *)t17);
    t36 = (t34 - t35);
    t37 = (t36 + 1);
    xsi_vlogvar_wait_assign_value(t15, t16, 0, *((unsigned int *)t17), t37, 0LL);
    goto LAB24;

LAB26:    t16 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB28;

LAB30:    xsi_set_current_line(131, ng0);

LAB33:    xsi_set_current_line(132, ng0);
    t19 = ((char*)((ng6)));
    t20 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t20, t19, 0, 0, 3, 0LL);
    goto LAB32;

LAB37:    t15 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB38;

LAB39:    xsi_set_current_line(138, ng0);

LAB42:    xsi_set_current_line(139, ng0);
    t18 = ((char*)((ng1)));
    t19 = (t0 + 5008);
    xsi_vlogvar_wait_assign_value(t19, t18, 0, 0, 1, 0LL);
    goto LAB41;

LAB43:    *((unsigned int *)t6) = 1;
    goto LAB46;

LAB45:    t5 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t5) = 1;
    goto LAB46;

LAB47:    t9 = (t0 + 5008);
    t15 = (t9 + 56U);
    t16 = *((char **)t15);
    t18 = ((char*)((ng1)));
    memset(t17, 0, 8);
    t19 = (t16 + 4);
    t20 = (t18 + 4);
    t35 = *((unsigned int *)t16);
    t38 = *((unsigned int *)t18);
    t39 = (t35 ^ t38);
    t40 = *((unsigned int *)t19);
    t41 = *((unsigned int *)t20);
    t42 = (t40 ^ t41);
    t43 = (t39 | t42);
    t44 = *((unsigned int *)t19);
    t45 = *((unsigned int *)t20);
    t46 = (t44 | t45);
    t47 = (~(t46));
    t48 = (t43 & t47);
    if (t48 != 0)
        goto LAB53;

LAB50:    if (t46 != 0)
        goto LAB52;

LAB51:    *((unsigned int *)t17) = 1;

LAB53:    memset(t49, 0, 8);
    t22 = (t17 + 4);
    t50 = *((unsigned int *)t22);
    t51 = (~(t50));
    t52 = *((unsigned int *)t17);
    t53 = (t52 & t51);
    t54 = (t53 & 1U);
    if (t54 != 0)
        goto LAB54;

LAB55:    if (*((unsigned int *)t22) != 0)
        goto LAB56;

LAB57:    t56 = *((unsigned int *)t6);
    t57 = *((unsigned int *)t49);
    t58 = (t56 & t57);
    *((unsigned int *)t55) = t58;
    t24 = (t6 + 4);
    t25 = (t49 + 4);
    t26 = (t55 + 4);
    t59 = *((unsigned int *)t24);
    t60 = *((unsigned int *)t25);
    t61 = (t59 | t60);
    *((unsigned int *)t26) = t61;
    t62 = *((unsigned int *)t26);
    t63 = (t62 != 0);
    if (t63 == 1)
        goto LAB58;

LAB59:
LAB60:    goto LAB49;

LAB52:    t21 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB53;

LAB54:    *((unsigned int *)t49) = 1;
    goto LAB57;

LAB56:    t23 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB57;

LAB58:    t64 = *((unsigned int *)t55);
    t65 = *((unsigned int *)t26);
    *((unsigned int *)t55) = (t64 | t65);
    t27 = (t6 + 4);
    t30 = (t49 + 4);
    t66 = *((unsigned int *)t6);
    t67 = (~(t66));
    t68 = *((unsigned int *)t27);
    t69 = (~(t68));
    t70 = *((unsigned int *)t49);
    t71 = (~(t70));
    t72 = *((unsigned int *)t30);
    t73 = (~(t72));
    t8 = (t67 & t69);
    t29 = (t71 & t73);
    t74 = (~(t8));
    t75 = (~(t29));
    t76 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t76 & t74);
    t77 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t77 & t75);
    t78 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t78 & t74);
    t79 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t79 & t75);
    goto LAB60;

LAB61:    xsi_set_current_line(143, ng0);

LAB64:    xsi_set_current_line(144, ng0);
    t86 = (t0 + 5168);
    t87 = (t86 + 56U);
    t88 = *((char **)t87);
    t90 = (t0 + 5168);
    t91 = (t90 + 72U);
    t92 = *((char **)t91);
    t93 = (t0 + 5168);
    t94 = (t93 + 64U);
    t95 = *((char **)t94);
    t96 = (t0 + 5328);
    t97 = (t96 + 56U);
    t98 = *((char **)t97);
    xsi_vlog_generic_get_array_select_value(t89, 8, t88, t92, t95, 2, 1, t98, 8, 2);
    t99 = (t0 + 4368);
    xsi_vlogvar_wait_assign_value(t99, t89, 0, 0, 8, 0LL);
    xsi_set_current_line(145, ng0);
    t2 = (t0 + 5328);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t7 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t5, 8, t7, 32);
    t9 = (t0 + 5328);
    xsi_vlogvar_wait_assign_value(t9, t6, 0, 0, 8, 0LL);
    xsi_set_current_line(146, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 5008);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(147, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 4208);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB63;

LAB66:    t16 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB68;

LAB70:    xsi_set_current_line(152, ng0);

LAB73:    xsi_set_current_line(153, ng0);
    t19 = ((char*)((ng6)));
    t20 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t20, t19, 0, 0, 3, 0LL);
    goto LAB72;

LAB77:    t15 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB78;

LAB79:    xsi_set_current_line(159, ng0);

LAB82:    xsi_set_current_line(160, ng0);
    t18 = ((char*)((ng1)));
    t19 = (t0 + 5008);
    xsi_vlogvar_wait_assign_value(t19, t18, 0, 0, 1, 0LL);
    goto LAB81;

LAB83:    *((unsigned int *)t6) = 1;
    goto LAB86;

LAB85:    t5 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t5) = 1;
    goto LAB86;

LAB87:    t9 = (t0 + 5008);
    t15 = (t9 + 56U);
    t16 = *((char **)t15);
    t18 = ((char*)((ng1)));
    memset(t17, 0, 8);
    t19 = (t16 + 4);
    t20 = (t18 + 4);
    t35 = *((unsigned int *)t16);
    t38 = *((unsigned int *)t18);
    t39 = (t35 ^ t38);
    t40 = *((unsigned int *)t19);
    t41 = *((unsigned int *)t20);
    t42 = (t40 ^ t41);
    t43 = (t39 | t42);
    t44 = *((unsigned int *)t19);
    t45 = *((unsigned int *)t20);
    t46 = (t44 | t45);
    t47 = (~(t46));
    t48 = (t43 & t47);
    if (t48 != 0)
        goto LAB93;

LAB90:    if (t46 != 0)
        goto LAB92;

LAB91:    *((unsigned int *)t17) = 1;

LAB93:    memset(t49, 0, 8);
    t22 = (t17 + 4);
    t50 = *((unsigned int *)t22);
    t51 = (~(t50));
    t52 = *((unsigned int *)t17);
    t53 = (t52 & t51);
    t54 = (t53 & 1U);
    if (t54 != 0)
        goto LAB94;

LAB95:    if (*((unsigned int *)t22) != 0)
        goto LAB96;

LAB97:    t56 = *((unsigned int *)t6);
    t57 = *((unsigned int *)t49);
    t58 = (t56 & t57);
    *((unsigned int *)t55) = t58;
    t24 = (t6 + 4);
    t25 = (t49 + 4);
    t26 = (t55 + 4);
    t59 = *((unsigned int *)t24);
    t60 = *((unsigned int *)t25);
    t61 = (t59 | t60);
    *((unsigned int *)t26) = t61;
    t62 = *((unsigned int *)t26);
    t63 = (t62 != 0);
    if (t63 == 1)
        goto LAB98;

LAB99:
LAB100:    goto LAB89;

LAB92:    t21 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB93;

LAB94:    *((unsigned int *)t49) = 1;
    goto LAB97;

LAB96:    t23 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB97;

LAB98:    t64 = *((unsigned int *)t55);
    t65 = *((unsigned int *)t26);
    *((unsigned int *)t55) = (t64 | t65);
    t27 = (t6 + 4);
    t30 = (t49 + 4);
    t66 = *((unsigned int *)t6);
    t67 = (~(t66));
    t68 = *((unsigned int *)t27);
    t69 = (~(t68));
    t70 = *((unsigned int *)t49);
    t71 = (~(t70));
    t72 = *((unsigned int *)t30);
    t73 = (~(t72));
    t8 = (t67 & t69);
    t29 = (t71 & t73);
    t74 = (~(t8));
    t75 = (~(t29));
    t76 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t76 & t74);
    t77 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t77 & t75);
    t78 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t78 & t74);
    t79 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t79 & t75);
    goto LAB100;

LAB101:    xsi_set_current_line(164, ng0);

LAB104:    xsi_set_current_line(165, ng0);
    t86 = (t0 + 5168);
    t87 = (t86 + 56U);
    t88 = *((char **)t87);
    t90 = (t0 + 5168);
    t91 = (t90 + 72U);
    t92 = *((char **)t91);
    t93 = (t0 + 5168);
    t94 = (t93 + 64U);
    t95 = *((char **)t94);
    t96 = (t0 + 5328);
    t97 = (t96 + 56U);
    t98 = *((char **)t97);
    xsi_vlog_generic_get_array_select_value(t89, 8, t88, t92, t95, 2, 1, t98, 8, 2);
    t99 = (t0 + 4688);
    xsi_vlogvar_wait_assign_value(t99, t89, 0, 0, 8, 0LL);
    xsi_set_current_line(166, ng0);
    t2 = (t0 + 5328);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t7 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t5, 8, t7, 32);
    t9 = (t0 + 5328);
    xsi_vlogvar_wait_assign_value(t9, t6, 0, 0, 8, 0LL);
    xsi_set_current_line(167, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 5008);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(168, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 4528);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB103;

LAB106:    t16 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB108;

LAB110:    xsi_set_current_line(172, ng0);

LAB113:    xsi_set_current_line(173, ng0);
    t19 = ((char*)((ng6)));
    t20 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t20, t19, 0, 0, 3, 0LL);
    goto LAB112;

LAB116:    t19 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB118;

LAB120:    xsi_set_current_line(179, ng0);

LAB123:    xsi_set_current_line(180, ng0);
    t21 = ((char*)((ng1)));
    t22 = (t0 + 5648);
    xsi_vlogvar_wait_assign_value(t22, t21, 0, 0, 32, 0LL);
    xsi_set_current_line(181, ng0);
    t2 = (t0 + 3728);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t10 = *((unsigned int *)t7);
    t11 = (~(t10));
    t12 = *((unsigned int *)t5);
    t13 = (t12 & t11);
    t14 = (t13 & 1U);
    if (t14 != 0)
        goto LAB127;

LAB125:    if (*((unsigned int *)t7) == 0)
        goto LAB124;

LAB126:    t9 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t9) = 1;

LAB127:    t15 = (t6 + 4);
    t16 = (t5 + 4);
    t28 = *((unsigned int *)t5);
    t31 = (~(t28));
    *((unsigned int *)t6) = t31;
    *((unsigned int *)t15) = 0;
    if (*((unsigned int *)t16) != 0)
        goto LAB129;

LAB128:    t40 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t40 & 1U);
    t41 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t41 & 1U);
    t18 = (t0 + 3728);
    xsi_vlogvar_wait_assign_value(t18, t6, 0, 0, 1, 0LL);
    goto LAB122;

LAB124:    *((unsigned int *)t6) = 1;
    goto LAB127;

LAB129:    t34 = *((unsigned int *)t6);
    t35 = *((unsigned int *)t16);
    *((unsigned int *)t6) = (t34 | t35);
    t38 = *((unsigned int *)t15);
    t39 = *((unsigned int *)t16);
    *((unsigned int *)t15) = (t38 | t39);
    goto LAB128;

LAB131:    xsi_set_current_line(189, ng0);

LAB134:    xsi_set_current_line(190, ng0);
    t5 = (t0 + 3008U);
    t7 = *((char **)t5);
    t5 = (t7 + 4);
    t28 = *((unsigned int *)t5);
    t31 = (~(t28));
    t34 = *((unsigned int *)t7);
    t35 = (t34 & t31);
    t38 = (t35 != 0);
    if (t38 > 0)
        goto LAB135;

LAB136:    xsi_set_current_line(195, ng0);

LAB139:    xsi_set_current_line(196, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);

LAB137:    goto LAB133;

LAB135:    xsi_set_current_line(191, ng0);

LAB138:    xsi_set_current_line(192, ng0);
    t9 = (t0 + 2688U);
    t15 = *((char **)t9);
    t9 = (t0 + 4688);
    xsi_vlogvar_wait_assign_value(t9, t15, 0, 0, 8, 0LL);
    xsi_set_current_line(193, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 4528);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB137;

LAB140:    xsi_set_current_line(202, ng0);

LAB143:    xsi_set_current_line(203, ng0);
    t5 = (t0 + 3168U);
    t7 = *((char **)t5);

LAB144:    t5 = ((char*)((ng13)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 8, t5, 32);
    if (t8 == 1)
        goto LAB145;

LAB146:    t2 = ((char*)((ng14)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 8, t2, 32);
    if (t8 == 1)
        goto LAB147;

LAB148:    t2 = ((char*)((ng15)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 8, t2, 32);
    if (t8 == 1)
        goto LAB149;

LAB150:    t2 = ((char*)((ng16)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 8, t2, 32);
    if (t8 == 1)
        goto LAB151;

LAB152:
LAB154:
LAB153:    xsi_set_current_line(221, ng0);

LAB160:    xsi_set_current_line(222, ng0);
    t2 = (t0 + 3008U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t10 = *((unsigned int *)t2);
    t11 = (~(t10));
    t12 = *((unsigned int *)t3);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB161;

LAB162:    xsi_set_current_line(227, ng0);

LAB165:    xsi_set_current_line(228, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);

LAB163:
LAB155:    goto LAB142;

LAB145:    xsi_set_current_line(204, ng0);

LAB156:    xsi_set_current_line(205, ng0);
    t9 = ((char*)((ng1)));
    t15 = (t0 + 5488);
    xsi_vlogvar_wait_assign_value(t15, t9, 0, 0, 8, 0LL);
    xsi_set_current_line(206, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);
    goto LAB155;

LAB147:    xsi_set_current_line(208, ng0);

LAB157:    xsi_set_current_line(209, ng0);
    t3 = ((char*)((ng1)));
    t5 = (t0 + 5328);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    xsi_set_current_line(210, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5008);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(211, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);
    goto LAB155;

LAB149:    xsi_set_current_line(213, ng0);

LAB158:    xsi_set_current_line(214, ng0);
    t3 = ((char*)((ng1)));
    t5 = (t0 + 5328);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 8, 0LL);
    xsi_set_current_line(215, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5008);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(216, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);
    goto LAB155;

LAB151:    xsi_set_current_line(218, ng0);

LAB159:    xsi_set_current_line(219, ng0);
    t3 = ((char*)((ng1)));
    t5 = (t0 + 3888);
    xsi_vlogvar_wait_assign_value(t5, t3, 0, 0, 1, 0LL);
    goto LAB155;

LAB161:    xsi_set_current_line(223, ng0);

LAB164:    xsi_set_current_line(224, ng0);
    t5 = (t0 + 3168U);
    t9 = *((char **)t5);
    t5 = (t0 + 4688);
    xsi_vlogvar_wait_assign_value(t5, t9, 0, 0, 8, 0LL);
    xsi_set_current_line(225, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 4528);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB163;

}


extern void work_m_05086722898534847092_3823007873_init()
{
	static char *pe[] = {(void *)Initial_98_0,(void *)Always_105_1};
	xsi_register_didat("work_m_05086722898534847092_3823007873", "isim/top_test_isim_beh.exe.sim/work/m_05086722898534847092_3823007873.didat");
	xsi_register_executes(pe);
}

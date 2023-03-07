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
static const char *ng0 = "/home/morty/ex1/uart_tx.v";
static int ng1[] = {1, 0};
static unsigned int ng2[] = {0U, 0U};
static int ng3[] = {0, 0};
static unsigned int ng4[] = {1U, 0U};
static int ng5[] = {8, 0};
static unsigned int ng6[] = {2U, 0U};



static void Always_44_0(char *t0)
{
    char t15[8];
    char t18[8];
    char t29[8];
    char t33[8];
    char t41[8];
    char t82[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t16;
    int t17;
    char *t19;
    char *t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t30;
    char *t31;
    char *t32;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    char *t46;
    char *t47;
    unsigned int t48;
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
    char *t81;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    char *t88;
    char *t89;

LAB0:    t1 = (t0 + 3776U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(44, ng0);
    t2 = (t0 + 4096);
    *((int *)t2) = 1;
    t3 = (t0 + 3808);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(45, ng0);

LAB5:    xsi_set_current_line(47, ng0);
    t4 = (t0 + 1504U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(48, ng0);

LAB9:    xsi_set_current_line(49, ng0);
    t11 = (t0 + 2384);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = ((char*)((ng1)));
    memset(t15, 0, 8);
    xsi_vlog_unsigned_add(t15, 32, t13, 16, t14, 32);
    t16 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t16, t15, 0, 0, 16, 0LL);
    xsi_set_current_line(50, ng0);
    t2 = (t0 + 2864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB10:    t5 = ((char*)((ng2)));
    t17 = xsi_vlog_unsigned_case_compare(t4, 3, t5, 3);
    if (t17 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t17 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t17 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng6)));
    t17 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t17 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB8;

LAB11:    xsi_set_current_line(51, ng0);

LAB18:    xsi_set_current_line(52, ng0);
    t11 = (t0 + 1664U);
    t12 = *((char **)t11);
    t11 = (t0 + 2704);
    xsi_vlogvar_wait_assign_value(t11, t12, 0, 0, 8, 0LL);
    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2064);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 0LL);
    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 16, 0LL);
    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);
    goto LAB17;

LAB13:    xsi_set_current_line(60, ng0);

LAB19:    xsi_set_current_line(61, ng0);
    t3 = (t0 + 2384);
    t5 = (t3 + 56U);
    t11 = *((char **)t5);
    t12 = (t0 + 472);
    t13 = *((char **)t12);
    memset(t15, 0, 8);
    t12 = (t11 + 4);
    if (*((unsigned int *)t12) != 0)
        goto LAB21;

LAB20:    t14 = (t13 + 4);
    if (*((unsigned int *)t14) != 0)
        goto LAB21;

LAB24:    if (*((unsigned int *)t11) < *((unsigned int *)t13))
        goto LAB23;

LAB22:    *((unsigned int *)t15) = 1;

LAB23:    memset(t18, 0, 8);
    t19 = (t15 + 4);
    t6 = *((unsigned int *)t19);
    t7 = (~(t6));
    t8 = *((unsigned int *)t15);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t19) != 0)
        goto LAB27;

LAB28:    t21 = (t18 + 4);
    t22 = *((unsigned int *)t18);
    t23 = *((unsigned int *)t21);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB29;

LAB30:    memcpy(t41, t18, 8);

LAB31:    t73 = (t41 + 4);
    t74 = *((unsigned int *)t73);
    t75 = (~(t74));
    t76 = *((unsigned int *)t41);
    t77 = (t76 & t75);
    t78 = (t77 != 0);
    if (t78 > 0)
        goto LAB44;

LAB45:
LAB46:    xsi_set_current_line(68, ng0);
    t2 = (t0 + 2384);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t11 = (t0 + 472);
    t12 = *((char **)t11);
    memset(t15, 0, 8);
    t11 = (t5 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB49;

LAB48:    t13 = (t12 + 4);
    if (*((unsigned int *)t13) != 0)
        goto LAB49;

LAB52:    if (*((unsigned int *)t5) < *((unsigned int *)t12))
        goto LAB51;

LAB50:    *((unsigned int *)t15) = 1;

LAB51:    memset(t18, 0, 8);
    t16 = (t15 + 4);
    t6 = *((unsigned int *)t16);
    t7 = (~(t6));
    t8 = *((unsigned int *)t15);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t16) != 0)
        goto LAB55;

LAB56:    t20 = (t18 + 4);
    t22 = *((unsigned int *)t18);
    t23 = *((unsigned int *)t20);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB57;

LAB58:    memcpy(t41, t18, 8);

LAB59:    t56 = (t41 + 4);
    t74 = *((unsigned int *)t56);
    t75 = (~(t74));
    t76 = *((unsigned int *)t41);
    t77 = (t76 & t75);
    t78 = (t77 != 0);
    if (t78 > 0)
        goto LAB72;

LAB73:
LAB74:    goto LAB17;

LAB15:    xsi_set_current_line(76, ng0);

LAB76:    xsi_set_current_line(77, ng0);
    t3 = (t0 + 2384);
    t5 = (t3 + 56U);
    t11 = *((char **)t5);
    t12 = (t0 + 472);
    t13 = *((char **)t12);
    memset(t15, 0, 8);
    t12 = (t11 + 4);
    if (*((unsigned int *)t12) != 0)
        goto LAB78;

LAB77:    t14 = (t13 + 4);
    if (*((unsigned int *)t14) != 0)
        goto LAB78;

LAB81:    if (*((unsigned int *)t11) < *((unsigned int *)t13))
        goto LAB80;

LAB79:    *((unsigned int *)t15) = 1;

LAB80:    t19 = (t15 + 4);
    t6 = *((unsigned int *)t19);
    t7 = (~(t6));
    t8 = *((unsigned int *)t15);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB82;

LAB83:
LAB84:    goto LAB17;

LAB21:    t16 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB23;

LAB25:    *((unsigned int *)t18) = 1;
    goto LAB28;

LAB27:    t20 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB28;

LAB29:    t25 = (t0 + 2544);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    t28 = ((char*)((ng5)));
    memset(t29, 0, 8);
    t30 = (t27 + 4);
    if (*((unsigned int *)t30) != 0)
        goto LAB33;

LAB32:    t31 = (t28 + 4);
    if (*((unsigned int *)t31) != 0)
        goto LAB33;

LAB36:    if (*((unsigned int *)t27) < *((unsigned int *)t28))
        goto LAB34;

LAB35:    memset(t33, 0, 8);
    t34 = (t29 + 4);
    t35 = *((unsigned int *)t34);
    t36 = (~(t35));
    t37 = *((unsigned int *)t29);
    t38 = (t37 & t36);
    t39 = (t38 & 1U);
    if (t39 != 0)
        goto LAB37;

LAB38:    if (*((unsigned int *)t34) != 0)
        goto LAB39;

LAB40:    t42 = *((unsigned int *)t18);
    t43 = *((unsigned int *)t33);
    t44 = (t42 & t43);
    *((unsigned int *)t41) = t44;
    t45 = (t18 + 4);
    t46 = (t33 + 4);
    t47 = (t41 + 4);
    t48 = *((unsigned int *)t45);
    t49 = *((unsigned int *)t46);
    t50 = (t48 | t49);
    *((unsigned int *)t47) = t50;
    t51 = *((unsigned int *)t47);
    t52 = (t51 != 0);
    if (t52 == 1)
        goto LAB41;

LAB42:
LAB43:    goto LAB31;

LAB33:    t32 = (t29 + 4);
    *((unsigned int *)t29) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB35;

LAB34:    *((unsigned int *)t29) = 1;
    goto LAB35;

LAB37:    *((unsigned int *)t33) = 1;
    goto LAB40;

LAB39:    t40 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB40;

LAB41:    t53 = *((unsigned int *)t41);
    t54 = *((unsigned int *)t47);
    *((unsigned int *)t41) = (t53 | t54);
    t55 = (t18 + 4);
    t56 = (t33 + 4);
    t57 = *((unsigned int *)t18);
    t58 = (~(t57));
    t59 = *((unsigned int *)t55);
    t60 = (~(t59));
    t61 = *((unsigned int *)t33);
    t62 = (~(t61));
    t63 = *((unsigned int *)t56);
    t64 = (~(t63));
    t65 = (t58 & t60);
    t66 = (t62 & t64);
    t67 = (~(t65));
    t68 = (~(t66));
    t69 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t69 & t67);
    t70 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t70 & t68);
    t71 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t71 & t67);
    t72 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t72 & t68);
    goto LAB43;

LAB44:    xsi_set_current_line(62, ng0);

LAB47:    xsi_set_current_line(63, ng0);
    t79 = (t0 + 2704);
    t80 = (t79 + 56U);
    t81 = *((char **)t80);
    t83 = (t0 + 2704);
    t84 = (t83 + 72U);
    t85 = *((char **)t84);
    t86 = (t0 + 2544);
    t87 = (t86 + 56U);
    t88 = *((char **)t87);
    xsi_vlog_generic_get_index_select_value(t82, 1, t81, t85, 2, t88, 8, 2);
    t89 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t89, t82, 0, 0, 1, 0LL);
    xsi_set_current_line(64, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t11 = ((char*)((ng1)));
    memset(t15, 0, 8);
    xsi_vlog_unsigned_add(t15, 32, t5, 8, t11, 32);
    t12 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t12, t15, 0, 0, 8, 0LL);
    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 16, 0LL);
    goto LAB46;

LAB49:    t14 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB51;

LAB53:    *((unsigned int *)t18) = 1;
    goto LAB56;

LAB55:    t19 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB56;

LAB57:    t21 = (t0 + 2544);
    t25 = (t21 + 56U);
    t26 = *((char **)t25);
    t27 = ((char*)((ng5)));
    memset(t29, 0, 8);
    t28 = (t26 + 4);
    if (*((unsigned int *)t28) != 0)
        goto LAB61;

LAB60:    t30 = (t27 + 4);
    if (*((unsigned int *)t30) != 0)
        goto LAB61;

LAB64:    if (*((unsigned int *)t26) < *((unsigned int *)t27))
        goto LAB63;

LAB62:    *((unsigned int *)t29) = 1;

LAB63:    memset(t33, 0, 8);
    t32 = (t29 + 4);
    t35 = *((unsigned int *)t32);
    t36 = (~(t35));
    t37 = *((unsigned int *)t29);
    t38 = (t37 & t36);
    t39 = (t38 & 1U);
    if (t39 != 0)
        goto LAB65;

LAB66:    if (*((unsigned int *)t32) != 0)
        goto LAB67;

LAB68:    t42 = *((unsigned int *)t18);
    t43 = *((unsigned int *)t33);
    t44 = (t42 & t43);
    *((unsigned int *)t41) = t44;
    t40 = (t18 + 4);
    t45 = (t33 + 4);
    t46 = (t41 + 4);
    t48 = *((unsigned int *)t40);
    t49 = *((unsigned int *)t45);
    t50 = (t48 | t49);
    *((unsigned int *)t46) = t50;
    t51 = *((unsigned int *)t46);
    t52 = (t51 != 0);
    if (t52 == 1)
        goto LAB69;

LAB70:
LAB71:    goto LAB59;

LAB61:    t31 = (t29 + 4);
    *((unsigned int *)t29) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB63;

LAB65:    *((unsigned int *)t33) = 1;
    goto LAB68;

LAB67:    t34 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t34) = 1;
    goto LAB68;

LAB69:    t53 = *((unsigned int *)t41);
    t54 = *((unsigned int *)t46);
    *((unsigned int *)t41) = (t53 | t54);
    t47 = (t18 + 4);
    t55 = (t33 + 4);
    t57 = *((unsigned int *)t18);
    t58 = (~(t57));
    t59 = *((unsigned int *)t47);
    t60 = (~(t59));
    t61 = *((unsigned int *)t33);
    t62 = (~(t61));
    t63 = *((unsigned int *)t55);
    t64 = (~(t63));
    t17 = (t58 & t60);
    t65 = (t62 & t64);
    t67 = (~(t17));
    t68 = (~(t65));
    t69 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t69 & t67);
    t70 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t70 & t68);
    t71 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t71 & t67);
    t72 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t72 & t68);
    goto LAB71;

LAB72:    xsi_set_current_line(69, ng0);

LAB75:    xsi_set_current_line(70, ng0);
    t73 = ((char*)((ng1)));
    t79 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t79, t73, 0, 0, 1, 0LL);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 16, 0LL);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 2864);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    goto LAB74;

LAB78:    t16 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB80;

LAB82:    xsi_set_current_line(78, ng0);

LAB85:    xsi_set_current_line(79, ng0);
    t20 = ((char*)((ng1)));
    t21 = (t0 + 2064);
    xsi_vlogvar_wait_assign_value(t21, t20, 0, 0, 1, 0LL);
    xsi_set_current_line(80, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2864);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    goto LAB84;

}


extern void work_m_02919053116098515681_2910696936_init()
{
	static char *pe[] = {(void *)Always_44_0};
	xsi_register_didat("work_m_02919053116098515681_2910696936", "isim/uart_rx_test_isim_beh.exe.sim/work/m_02919053116098515681_2910696936.didat");
	xsi_register_executes(pe);
}

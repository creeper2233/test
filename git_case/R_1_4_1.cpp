/**
 * 规则id: GJB_8114_R_1_4_1
 * 规则名称：在if-else if语句中必须使用else分支。
 */

//文档用例
void exam_vio() {
    int i = 0, j = 0;
    double x = 0.0;
    //..
    if (0 == i) {
        x = 1.0;
    } else if (1 == i) {
        x = 2.0;
    }/*violation#R_1_4_1*/
    if (0 == j) {
        x = x + 5.0;
    }
}

void exam_ok() {
    int i = 0, j = 0;
    double x = 0.0;
    //..
    if (0 == i) {
        x = 1.0;
    } else if (1 == i) {
        x = 2.0;
    } else {/*ok*/
        x = 0.0;
    }
    if (0 == j) {
        x = x + 5.0;
    }
}

//判断条件中存在函数
int test_vio_0() {
    return 1;
}

void exam_vio_0() {
    int i;
    if (test_vio_0() == 1) {
        i = 1;
    } else if (test_vio_0() == 2) {
        i = 2;
    }/*violation#R_1_4_1*/

}

int test_ok_0() {
    return 1;
}

void exam_ok_0() {
    int i;
    if (test_ok_0() == 1) {
        i = 1;
    } else if (test_ok_0() == 2) {
        i = 2;
    } else {/*ok*/
        i = 0;
    }
}

//嵌套
void exam_vio_1() {
    int i = 2, j = 2, n = 2, m = 2;
    double x, y;
    if (i == 0) {
        x = 0.0;
    } else if (i == 1) {
        x = 1.0;
    } else {
        if (j == 2) {
            x = 2.0;
        } else if (j == 3) {
            x = 3.0;
        }/*violation#R_1_4_1*/
    }

    if (n == 2) {
        if (m == 1) {
            y = 1.0;
        } else if (m == 2) {
            y = 2.0;
        }/*violation#R_1_4_1*/
    }
}

void exam_ok_1() {
    int i = 2, j = 2, n = 2, m = 2;
    double x, y;
    if (i == 0) {
        x = 0.0;
    } else if (i == 1) {
        x = 1.0;
    } else {
        if (j == 2) {
            x = 2.0;
        } else if (j == 3) {
            x = 3.0;
        } else {/*ok*/
            x = 4.0;
        }
    }

    if (n == 2) {
        if (m == 1) {
            y = 1.0;
        } else if (m == 2) {
            y = 2.0;
        } else {/*ok*/
            y = 3.0;
        }
    }
}

//宏定义
#define dis_vio(x, y) \
if(x==1){ \
    y=1; \
}else if(x==2){ \
    y=2; \
}/*violation#R_1_4_1*/

void exam_vio_2() {
    int x = 1;
    int y;
    dis_vio(x, y);
}

#define dis_ok(x, y) \
if(x==1){ \
    y=1; \
}else if(x==2){ \
    y=2; \
}else{ /*ok*/\
    y=3; \
}

void exam_ok_2() {
    int x = 1;
    int y;
    dis_ok(x, y);
}


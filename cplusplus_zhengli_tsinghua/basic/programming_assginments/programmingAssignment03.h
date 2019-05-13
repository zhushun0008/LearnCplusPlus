//
// Created by Zhu Kevin on 2018/7/18.
//

#ifndef CPLUSPLUS_BASIC_PROGRAMMINGASSIGNMENT02_02_H
#define CPLUSPLUS_BASIC_PROGRAMMINGASSIGNMENT02_02_H

#include <iostream>
using namespace std;


bool is_right_triangle(int a, int b, int c) {
    if ((a * a + b * b == c * c) || (b * b + c * c == a * a) || (c * c + a * a == b * b)) {
        return true;
    }
    return false;

}

void c_31() {
    /*
    C3-1 直角三角形  (100 满分)
    题目描述

    输入一个三角形的3边长度，判断该三角形是否为直角三角形，若是则输出True，若不是则输出False。推荐做法：定义一个函数，接受三个int参数，返回bool，再用主函数调用之。


    输入描述
    每行输入三个由空格隔开的整数 a, b, c ，表示三角形的 3 条边长

    1 <= a,b ,c <= 10000

    输出描述
    对于每一行输入，输出True或者False表明是否为直角三角形

            样例输入
    3 4 5
    6 7 8
    1 1 1

    样例输出
            True
    False
            False
            */

    int num_element = 3;
    int edge_list[3];
    for (int i = 0; i < num_element; i++) {
        cin >> edge_list[i];
    }
    if (is_right_triangle(edge_list[0], edge_list[1], edge_list[2])) {
        cout << "True";
    } else { cout << "False"; }
}


void c_32() {
    /*
    C3-2 斐波那契数列  (100 满分)
    题目描述
    斐波那契数列f(n)满足以下定义：

    f(0) = 1, f(1) = 1, f(n) = f(n-1) + f(n-2) (n >= 2)。

    请用递归的方法编写函数，对于给定的n，求出斐波那契数列的第n项f(n)


    输入描述
    每行输入一个整数 n

    0 <= n<= 30


    输出描述
    对于每一行输入，输出斐波那契数列第n项的值f(n)


    样例输入
    1
    10
    25
    样例输出
    1
    89
    121393
    */
    int nth_fib;
    cin >> nth_fib;
    int fib_pre_pre = 1;
    int fib_pre = 1;
    int fib_i = 0;
    if (nth_fib > 1) {
        for (int i = 2; i <= nth_fib; i++) {
            fib_i = fib_pre_pre + fib_pre;
            fib_pre_pre = fib_pre;
            fib_pre = fib_i;
        }
        cout << fib_i;
    } else {
        cout << 1;
    }
}

int is_ugly_factor_and_devive(int check_number) {
    if (check_number % 2 == 0) {
        return (check_number / 2);
    } else if (check_number % 3 == 0) {
        return (check_number / 3);
    } else if (check_number % 5 == 0) {
        return check_number / 5;
    } else if (check_number == 1) {
        return check_number;
    } else {
        return -1;
    }
}

void c_33() {
    /*
    C3-3 丑数  (100 满分)
    题目描述
    只包含因子2,3,5的正整数被称作丑数，比如4,10,12都是丑数，而7,23,111则不是丑数，另外1也不是丑数。请编写一个函数，输入一个整数n，能够判断该整数是否为丑数，如果是，则输出True，否则输出False。

    输入描述
    每行输入一个正整数 n

    1 <= n<= 1000000

    输出描述
    对于每一行输入，输出其是否为丑数，是则输出True，否则输出False

    样例输入
    4
    7
    12
    样例输出
            True
            False
            True
    */
    int check_number;
    cin >> check_number;
    bool flag = false;
    if (check_number == 1) {
        cout << "False";
        return;
    }
    while (check_number > 1) {
        int temp_data = is_ugly_factor_and_devive(check_number);

        if (temp_data == -1) {
            cout << "False";
            return;
        } else {
            check_number = temp_data;
        }
    }
    cout << "True";
    return;
}

#endif //CPLUSPLUS_BASIC_PROGRAMMINGASSIGNMENT02_02_H




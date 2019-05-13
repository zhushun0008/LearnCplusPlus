//
// Created by Zhu Kevin on 2018/10/6.
//

#ifndef CPLUSPLUS_ZHENGLI_TSINGHUA_PROGRAMMINGASSIGNMENT04_H
#define CPLUSPLUS_ZHENGLI_TSINGHUA_PROGRAMMINGASSIGNMENT04_H

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


class Integer {
private:
    int _num;
public:
//构造函数
    Integer(int num) {
        _num = num;
    }

//计算当前Integer 和 b之间的最大公约数
    int gcd(Integer b) {
        int bigger_num = 0;
        int lower_num = 0;
        if (b._num > _num) {
            bigger_num = b._num;
            lower_num = _num;
        } else {
            bigger_num = _num;
            lower_num = b._num;
        }
        for (int i = lower_num; i >= 1; i--) {
            if (bigger_num % i == 0 && lower_num % i == 0)
                return i;
        }
        return 1;
    }

    int inversed() {
        int inversed_num = 0;
        int temp_num = _num;
        while (temp_num) {

            inversed_num = inversed_num * 10 + (temp_num % 10);
            temp_num /= 10;
        }
        return inversed_num;
    }

};

int c_41() {
//    C4 - 1
//    最大公约数(100 满分)
//    题目描述
//    求两个正整数a和b的最大公约数。
//
//    要求使用c++ class编写程序。
//    输入描述
//    两个正整数a,b，并且1=<a,b <=10000
//
//    输出描述
//    a和b的最大公约数
//
//    样例输入
//    1000 1000
//    样例输出
//    1000
    int a, b;
    cin >> a >> b;
//    cout << "a:" << a << endl;
//    cout << "b:" << b << endl;
    assert(a >= 1 && a <= 10000 && b >= 1 && b <= 10000);
    Integer A(a);
    Integer B(b);
    cout << A.gcd(B) << endl;
    return 0;
}


int c_42() {
//    C4-2 反转整数  (100 满分)
//    题目描述
//    对于输入的一个正整数，输出其反转形式
//    输入描述
//    一个正整数a ，且1=<a<=1,000,000,000
//
//    输出描述
//    a的反转形式
//
//    样例输入
//    1011
//    样例输出
//    1101
    int n;
    cin >> n;
    Integer integer(n);
    cout << integer.inversed() << endl;
    return 0;
}


class Equation {
private:
    int _a, _b, _c;

    double get_normal() {
        return static_cast<double >(_b * _b - 4 * _a * _c);
    }

public:
    Equation(int a, int b, int c) {
        _a = a;
        _b = b;
        _c = c;
    }

    void solve() {
        if (_a != 0) {
            if (get_normal() > 0) {
                float small_root = (-_b - sqrt(get_normal())) / (2.0 * _a);
                float big_root = (-_b + sqrt(get_normal())) / (2.0 * _a);
                if (small_root > big_root) {
                    float temp_root = small_root;
                    small_root = big_root;
                    big_root = temp_root;
                }
                cout << 1 << endl;
                cout << fixed << setprecision(2) << small_root << " " << big_root << endl;
            } else if (get_normal() == 0) {
                cout << 2 << endl;
                cout << fixed << setprecision(2) << (-_b / (2.0 * _a)) << endl;
            } else if (get_normal() < 0) {
                cout << 3 << endl;
            }
        } else {
            if (_b != 0) {
                cout << 6 << endl;
                cout << fixed << setprecision(2) << (-1.0 * _c / _b) << endl;
            } else if (_c != 0) {
                cout << 4 << endl;
            } else if (_c == 0) {
                cout << 5 << endl;
            }
        }
    }
};

int c_43() {

//    C4-3 一元二次方程求解  (100 满分)
//    题目描述
//    对于一元二次方程ax^2 + bx + c = 0,解可以分为很多情况。
//    若该方程有两个不相等实根，首先输出1，换行，然后从小到大输出两个实根，换行；
//    若该方程有两个相等实根，首先输出2，换行，然后输出这个这个实根，换行；
//    若该方程有一对共轭复根，输出3，换行；
//    若该方程有无解，输出4，换行；
//    若该方程有无穷个解，输出5，换行；
//    若该方程只有一个根，首先输出6，换行，然后输出这个跟，换行；
//    要求使用c++ class编写程序。
//    输入描述
//    该一元二次方程的系数a, b, c
//    ，且-100=<a, b, c<=100
//
//    输出描述
//    解的情况
//    。
//    输出解的时候保留两位小数
//
//    样例输入
//    1 4 3
//    样例输出
//    1
//    -3.00 -1.00
    int a, b, c;
    cin >> a >> b >> c;
    Equation tmp(a, b, c);
    tmp.solve();
    return 0;
}


#endif //CPLUSPLUS_ZHENGLI_TSINGHUA_PROGRAMMINGASSIGNMENT04_H

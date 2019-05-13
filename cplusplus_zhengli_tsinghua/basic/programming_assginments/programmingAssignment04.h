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
//���캯��
    Integer(int num) {
        _num = num;
    }

//���㵱ǰInteger �� b֮������Լ��
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
//    ���Լ��(100 ����)
//    ��Ŀ����
//    ������������a��b�����Լ����
//
//    Ҫ��ʹ��c++ class��д����
//    ��������
//    ����������a,b������1=<a,b <=10000
//
//    �������
//    a��b�����Լ��
//
//    ��������
//    1000 1000
//    �������
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
//    C4-2 ��ת����  (100 ����)
//    ��Ŀ����
//    ���������һ��������������䷴ת��ʽ
//    ��������
//    һ��������a ����1=<a<=1,000,000,000
//
//    �������
//    a�ķ�ת��ʽ
//
//    ��������
//    1011
//    �������
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

//    C4-3 һԪ���η������  (100 ����)
//    ��Ŀ����
//    ����һԪ���η���ax^2 + bx + c = 0,����Է�Ϊ�ܶ������
//    ���÷��������������ʵ�����������1�����У�Ȼ���С�����������ʵ�������У�
//    ���÷������������ʵ�����������2�����У�Ȼ�����������ʵ�������У�
//    ���÷�����һ�Թ���������3�����У�
//    ���÷������޽⣬���4�����У�
//    ���÷�����������⣬���5�����У�
//    ���÷���ֻ��һ�������������6�����У�Ȼ���������������У�
//    Ҫ��ʹ��c++ class��д����
//    ��������
//    ��һԪ���η��̵�ϵ��a, b, c
//    ����-100=<a, b, c<=100
//
//    �������
//    ������
//    ��
//    ������ʱ������λС��
//
//    ��������
//    1 4 3
//    �������
//    1
//    -3.00 -1.00
    int a, b, c;
    cin >> a >> b >> c;
    Equation tmp(a, b, c);
    tmp.solve();
    return 0;
}


#endif //CPLUSPLUS_ZHENGLI_TSINGHUA_PROGRAMMINGASSIGNMENT04_H

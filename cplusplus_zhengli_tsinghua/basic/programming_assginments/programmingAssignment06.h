//
// Created by Zhu Kevin on 2018/10/6.
//

#ifndef CPLUSPLUS_ZHENGLI_TSINGHUA_PROGRAMMINGASSIGNMENT06_H
#define CPLUSPLUS_ZHENGLI_TSINGHUA_PROGRAMMINGASSIGNMENT06_H

#include <iostream>
#include <string>

using namespace std;

int c_61() {
//    C6-1 最大子数组和  (100 满分)
//    题目描述
//    给定一个数组a[0,...,n-1],求其最大子数组(长度>=1)和
//    输入描述
//    第一行一个整数n(1<=n<=5000)，然后依次输入n个整数（每个整数范围[-5000, 5000]）
//    输出描述
//    输出一个整数表示最大子数组和
//    样例输入
//    5
//    1 -1 1 1 -1
//    样例输出
//    2

    int array_size;
    cin >> array_size;
//    assert(array_size >= 1 && array_size <= 5000);
    int *a = new int[array_size];
    for (int i = 0; i < array_size; i++)
        cin >> a[i];
//    for(int i=0;i<array_size;i++) {
//        cout << a[i];
//    }
    int max_sum = a[0];
    int cur_sum = a[0];
    for (int i = 1; i < array_size; i++) {
        if (cur_sum + a[i] >= 0) {
            cur_sum += a[i];
            if (max_sum < cur_sum) {
                max_sum = cur_sum;
            }
        } else {
            cur_sum = 0;
        }

    }
    cout << max_sum << endl;
}

bool is_reverse(const string a) {
    return true;
}

string gen_sub_seq(const string &a, int *num) {
    if (a.length() > 0) {
        string new_str1 = a[0] + gen_sub_seq(a.substr(1, a.length()), num);
        cout << new_str1 << endl;
        if (is_reverse(new_str1)) {
            (*num)++;
        }
        string new_str2 = gen_sub_seq(a.substr(1, a.length()), num);
        cout << new_str2 << endl;

        if (is_reverse(new_str2)) {
            (*num)++;
        }
    }
}

int c_62() {
//    C6-2 字符串的回文子序列个数  (100 满分)
//    题目描述
//    求一个长度不超过15的字符串的回文子序列个数（子序列长度>=1）。
//    输入描述
//    输入一个长度不超过15的字符串,字符串均由小写字母表示
//    输出描述
//    输出其回文子序列个数
//    样例输入
//    abaa
//    样例输出
//    10
//    注释
//    本例中其所有回文子序列为：
//    a,b,a,a,aba,aba,aa,aa,aa,aaa
//    一个字符串的子序列是指在原字符串上去除某些字符但不破坏余下元素的相对位置（在前或在后）而形成的新字符串。
    string str;
    getline(cin, str);
    int num = 0;
    gen_sub_seq(str, &num);
}

void select_sort(int *a, int num_element) {
    if (num_element <= 1) return;
    int temp = 0;
    for (int i = 0; i < num_element - 1; i++) {
        for (int j = i+1; j < num_element; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int c_63() {
//    C6-3 数组第K小数  (100 满分)
//    题目描述
//    给定一个整数数组a[0,...,n-1]，求数组中第k小数
//    输入描述
//    首先输入数组长度n和k，其中1<=n<=5000, 1<=k<=n
//    然后输出n个整形元素，每个数的范围[1, 5000]
//    输出描述
//    该数组中第k小数
//    样例输入
//    4 2
//    1 2 3 4
//    样例输出
//    2
    int array_size;
    cin >> array_size;
    int kth_biggest;
    cin >> kth_biggest;
//    assert(array_size >= 1 && array_size <= 5000);
    int *a = new int[array_size];
    for (int i = 0; i < array_size; i++)
        cin >> a[i];
    select_sort(a, array_size);
//    for (int i = 0; i < array_size; i++)
//        cout<< a[i];
    cout << a[kth_biggest - 1] << endl;
}

#endif //CPLUSPLUS_ZHENGLI_TSINGHUA_PROGRAMMINGASSIGNMENT06_H

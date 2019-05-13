//
// Created by Zhu Kevin on 2018/10/6.
//

#ifndef CPLUSPLUS_ZHENGLI_TSINGHUA_PROGRAMMINGASSIGNMENT06_H
#define CPLUSPLUS_ZHENGLI_TSINGHUA_PROGRAMMINGASSIGNMENT06_H

#include <iostream>
#include <string>

using namespace std;

int c_61() {
//    C6-1 ����������  (100 ����)
//    ��Ŀ����
//    ����һ������a[0,...,n-1],�������������(����>=1)��
//    ��������
//    ��һ��һ������n(1<=n<=5000)��Ȼ����������n��������ÿ��������Χ[-5000, 5000]��
//    �������
//    ���һ��������ʾ����������
//    ��������
//    5
//    1 -1 1 1 -1
//    �������
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
//    C6-2 �ַ����Ļ��������и���  (100 ����)
//    ��Ŀ����
//    ��һ�����Ȳ�����15���ַ����Ļ��������и����������г���>=1����
//    ��������
//    ����һ�����Ȳ�����15���ַ���,�ַ�������Сд��ĸ��ʾ
//    �������
//    �������������и���
//    ��������
//    abaa
//    �������
//    10
//    ע��
//    �����������л���������Ϊ��
//    a,b,a,a,aba,aba,aa,aa,aa,aaa
//    һ���ַ�������������ָ��ԭ�ַ�����ȥ��ĳЩ�ַ������ƻ�����Ԫ�ص����λ�ã���ǰ���ں󣩶��γɵ����ַ�����
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
//    C6-3 �����KС��  (100 ����)
//    ��Ŀ����
//    ����һ����������a[0,...,n-1]���������е�kС��
//    ��������
//    �����������鳤��n��k������1<=n<=5000, 1<=k<=n
//    Ȼ�����n������Ԫ�أ�ÿ�����ķ�Χ[1, 5000]
//    �������
//    �������е�kС��
//    ��������
//    4 2
//    1 2 3 4
//    �������
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

//
// Created by Zhu Kevin on 2018/6/26.
//

#ifndef C2_1_PROGRAMMINGASSIGNMENT01_H
#define C2_1_PROGRAMMINGASSIGNMENT01_H
#include <iostream>

using namespace std;

void c_21() {
    /*题目描述
    任意给定 n 个整数，求这 n 个整数序列的和、最小值、最大值

    输入描述
    输入一个整数n，代表接下来输入整数个数，0 < n <= 100，接着输入n个整数，整数用int表示即可。

    输出描述
    输出整数序列的和、最小值、最大值。用空格隔开，占一行

    样例输入
    2
    1 2
    样例输出
    3 1 2
     */

    int numElement;
    int myArray[100];
    int minValue;
    int maxValue = 0;
    int sum;
    cin >> numElement;
    for (int i = 0; i < numElement; i++) {
        cin >> myArray[i];
        if (i == 0) {
            minValue = myArray[0];
            maxValue = myArray[0];
        } else {
            if (minValue > myArray[i]) {
                minValue = myArray[i];
            }
            if (maxValue < myArray[i]) {
                maxValue = myArray[i];
            }
        };
        sum += myArray[i];

    }
    cout << sum << " " << minValue << " " << maxValue;
}


void c_22() {
    /*
    题目描述
    已知一个只包含 0 和 1 的二进制数，长度不大于 10 ，将其转换为十进制并输出。

    输入描述
    输入一个二进制整数n，其长度大于0且不大于10

    输出描述
    输出转换后的十进制数， 占一行

    样例输入
    110

    样例输出
    6
     */

    int number = 0;
    string a;

    cin >> a;
    for (int i = 0; i < a.length(); i++) {
        number = number * 2 + int(a[i]) - int('0');
    }
    cout << number << endl;
}

void printOneLineForDiamond(int nstage, int lineIndex) {
    int maxCharInLine = nstage * 2 - 1;
    int numDiamondInLine = (lineIndex - 1) * 2 + 1;
    int halfEmptyCharInLIne = (maxCharInLine - numDiamondInLine) / 2;
    for (int i = 0; i < halfEmptyCharInLIne; i++) {
        cout << " ";
    }
    for (int i = 0; i < numDiamondInLine; i++) {
        cout << "*";
    }
    for (int i = 0; i < halfEmptyCharInLIne; i++) {
        cout << " ";
    }
    cout << endl;

}

void c_23() {
    /*
        C2-3实心菱形  (100 满分)
        题目描述
        打印 n 阶实心菱形

        输入描述
        输入一个整数n，0 < n <= 10

        输出描述
        输出 n 阶实心菱形 ， 占 2*n-1 行

        样例输入
        3
        样例输出
          *
         ***
        *****
         ***
          *
     */
    int nStage;
    cin >> nStage;
    int maxNumChar = nStage * 2 - 1;
    for (int i = 1; i <= nStage; i++) {
        printOneLineForDiamond(nStage, i);
    }
    for (int i = nStage - 1; i > 0; i--)
        printOneLineForDiamond(nStage, i);
}


#endif //C2_1_PROGRAMMINGASSIGNMENT01_H


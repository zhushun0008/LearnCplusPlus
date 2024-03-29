//
// Created by Zhu Kevin on 2018/10/6.
//

#ifndef CPLUSPLUS_ZHENGLI_TSINGHUA_PROGRAMMINGASSIGNMENT05_H
#define CPLUSPLUS_ZHENGLI_TSINGHUA_PROGRAMMINGASSIGNMENT05_H

#include <iostream>

using namespace std;

class Yuebao {
    static double profitRate;
private:
    double _balance;
public:
    Yuebao(double init_money);

    Yuebao();

    static void setProfitRate(double rate);

    void deposit(double amount);

    void withdraw(double amount);

    double getBalance();

    void addProfit();
};

Yuebao::Yuebao(double init_money) : _balance(init_money) {
}

Yuebao::Yuebao() : Yuebao(0) {}

void Yuebao::setProfitRate(double rate) {
    profitRate = rate;
}

double Yuebao::getBalance() {
    return _balance;
}

void Yuebao::addProfit() {
    _balance += _balance * profitRate;
}

void Yuebao::withdraw(double amount) {
    _balance -= amount;
}

void Yuebao::deposit(double amount) {
    _balance += amount;
}

// 静态成员变量必须初始化
double Yuebao::profitRate = 0;

int c_51() {
//    C5-1 “鱼额宝”  (100 满分)
//    题目描述
//    请实现一个“鱼额宝”类，下面已给出代码模板，请根据main函数中对该类的操作，补充类实现部分完成代码。
//    “鱼额宝”类可以记录账户余额、存钱、取钱、计算利息。该类中有一个私有静态成员变量profitRate存储“鱼额宝”的利率，
//    可以用共有静态成员函数setProfitRate修改利率的值。程序输入为第1天至第n天连续n天的账户操作，每天只能进行一次账户操作，或存或取，
//    每一天产生的利息是前一天的账户余额与“鱼额宝”利率的乘积，产生的利息当天也将存入账户余额，由于第1天之前账户不存在，
//    所以第1天一定是新建账户并存钱，且当天不会有利息存入余额。程序在接受n天操作的输入后，要求计算出第n天操作完成后的账户余额并输出。
//    代码如下：
//    输入描述
//       每个测例共 n+2 行
//       第 1 行输入一个整数 n ，表示接下来有 n 天的操作
//       第 2 行输入一个实数，为 “ 鱼额宝 ” 的利率， n 天中利率不变
//       接下来有 n 行，代表 n 天的操作，每行有 2 个数，第 1 个数或 0 或 1 ， 0 表示存钱， 1 表示取钱，第二个实数为存取的金额
//       1 <= n <= 20
//    输出描述
//       对于每一个测例，输出第n天操作完成后的账户余额
//    样例输入
//    3
//    0.1
//    0 10
//    0 10
//    1 10
//    样例输出
//    13.1
    int n;
    while (cin >> n) {
        double profitRate;
        cin >> profitRate;
        Yuebao::setProfitRate(profitRate);//设定鱼额宝的利率
        Yuebao y(0); //新建鱼额宝账户，余额初始化为0
        int operation;//接受输入判断是存还是取
        double amount;//接受输入存取金额
        for (int i = 0; i < n; ++i) {
            y.addProfit();//加入前一天余额产生的利息
            cin >> operation >> amount;
            if (operation == 0)
                y.deposit(amount);//存入金额
            else
                y.withdraw(amount);//取出金额
        }
        cout << y.getBalance() << endl;//输出最终账户余额
    }
    return 0;
}

class Mouse {
public:
    static int num;

    Mouse() {
        ++num;
    }
    Mouse(Mouse & a) {
        ++num;
    }
    ~Mouse() {
        --num;
    }
};

int Mouse::num = 0;

void fn(Mouse m);


void fn(Mouse m) {
    cout << Mouse::num << endl;
    Mouse n(m);
    cout << Mouse::num << endl;
}

int c_52() {
//    C5-2 数老鼠  (100 满分)
//    题目描述
//    请实现一个老鼠类，下面已给出代码模板，请根据main函数中对该类的操作，补充类实现部分完成代码。
//
//    该类有个公有静态变量num记录该类的所有对象数，主函数将会在不同语句之后输出对象数，只有正确地实现该类，
//    保证num正确记录该类的对象数，才能输出正确的结果。
//    输入描述
//    输出描述
//    主函数的输出已经写好

    Mouse::num = 0;
    Mouse a;
    cout << Mouse::num << endl;
    Mouse b(a);
    cout << Mouse::num << endl;
    for (int i = 0; i < 10; ++i) {
        Mouse x;
        cout << Mouse::num << endl;
    }
    fn(a);
    cout << Mouse::num << endl;
    return 0;
}


#endif //CPLUSPLUS_ZHENGLI_TSINGHUA_PROGRAMMINGASSIGNMENT05_H

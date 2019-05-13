//
// Created by Zhu Kevin on 2018/10/10.
//

#ifndef CPLUSPLUS_ZHENGLI_TSINGHUA_ADVANCED_PA01_H
#define CPLUSPLUS_ZHENGLI_TSINGHUA_ADVANCED_PA01_H

#include <iostream>
#include <string>

using namespace std;

class Account {
    string userName;
public:
    Account() {};

    Account(string name);

    void PrintUserName();
};

Account::Account(string name) {
    userName = name;
}

void Account::PrintUserName() {
    cout << userName << endl;
}

class CreditAccount : public Account {
public:
    CreditAccount(string name, int credit) : Account(name), credit(credit) {}

    void PrintInfo();

private:
    int credit;
};


void CreditAccount::PrintInfo() {
    PrintUserName();
    cout << credit << endl;
}

int c_71() {
//    C7-1 账户类  (100 满分)
//    题目描述
//    定义一个基类Account，数据成员包含string类变量userName用于保存账户主人姓名，函数成员包括默认构造函数、
//      带参构造函数用于初始化数据成员和输出姓名的成员函PrintName()。从Account类派生出CreditAccount类，
//      增加整型数据成员credit用于记录该用户信用额度，函数成员包括带参构造函数用于初始化数据成员和输出账户信息的成员函数PrintInfo()。
//      要求：在函数PrintInfo()中需要调用基类的成员函数PrintName()。
//    //请实现Account构造函数Account(char *name)
//    //请实现Account的PrintUserName()函数
//    //请实现CreditAccount类的构造函数CreditAccount(char* name, long number)
//    //请实现CreditAccount类的PrintInfo()函数
//    输入描述
//      无
//
//    输出描述
//      输出共两行，第一行为账户姓名，第二行为账户信用额度
//
//    样例输入
//      无
//
//    样例输出
//      I Love CPP
//      10000

    CreditAccount a("I Love CPP", 10000);
    a.PrintInfo();
    return 0;
}



class Base1 {
public:
    Base1(int x);

    ~Base1();
};

class Base2 {
public:
    Base2(int x);

    ~Base2();
};

class Base3 {
public:
    Base3(int x);

    ~Base3();
};

class Derived : public Base2, Base1, Base3 {
public:
    Derived(int x1, int x2, int x3, int x4);

    ~Derived();
};

Base1::Base1(int x) {
    cout << "Base1 constructor called " << x << endl;
}

Base1::~Base1() {
    cout << "Base1 destructor called" << endl;
}

Base2::Base2(int x) {
    cout << "Base2 constructor called " << x << endl;
}

Base2::~Base2() {
    cout << "Base2 destructor called" << endl;
}

Base3::Base3(int x) {
    cout << "Base3 constructor called " << x << endl;
}

Base3::~Base3() {
    cout << "Base3 destructor called" << endl;
}

Derived::Derived(int x1, int x2, int x3, int x4) : Base1(x2), Base2(x3), Base3(x4) {
    cout << "Derived constructor called " << x1 << endl;
}

Derived::~Derived() {
    cout << "Derived destructor called" << endl;
}

int c_72() {
//    C7-2 多继承  (100 满分)
//    题目描述
//      下面的代码声明了三个基类Base1、Base2和Base3，然后从这三个基类按照公有方式派生出类Derived。在每个类中分别定义带一个整型参数的
//      构造函数和析构函数输出提示信息，构造函数的提示信息中需要包含整型参数的数值。请将下面的代码补充完整，使得输出结果与样例输出相同，
//      注意：测试数据有多组。
//
//    输入描述
//      每组输入为 4 个整数用空格隔开
//    输出描述
//      根据构造和析构函数的调用顺序输出
//    样例输入
//      1 2 3 4
//
//    样例输出
//      Base2 constructor called 3
//      Base1 constructor called 2
//      Base3 constructor called 4
//      Derived constructor called 1
//      Derived destructor called
//      Base3 destructor called
//      Base1 destructor called
//      Base2 destructor called
    int x[4];
    for (int i = 0; i < 4; ++i)
        cin >> x[i];
    Derived d(x[0], x[1], x[2], x[3]);
    return 0;
}

struct Base11
{
    int x;
    Base11(int x);
};

struct Base22
{
    int x;
    Base22(int x);
};

struct Derived11:public Base11, public Base22
{
    int x;
    Derived11(Base11& a, Base22& b);
};

Base11::Base11(int x): x(x) {}

Base22::Base22(int x): x(x) {}

Derived11::Derived11(Base11& a, Base22& b): Base11(a.x), Base22(b.x), x(a.x+b.x) {}

int c_73() {
//    C7-3 用类实现A+B  (100 满分)
//    题目描述
//    下面的代码声明了两个基类Base1和Base2，然后从这两个基类按照公有方式派生出类Derived。基类和派生类都各自包含一个公有成员x，
//    并且Base1和Base2各有接受一个整型参数的构造函数，Derived的构造函数接受Base1和Base2的对象引用a，b来初始化Derived类对象，
//    并令x为Base1::x和Base2::x之和。请将下面的代码补充完成，使得输出符合要求。
//    请实现Base1，Base2, Derived的构造函数
//    输入描述
//      每组输入为 2 个整数用空格隔开
//
//    输出描述
//      主函数自动完成输出
//
//    样例输入
//      1 2
//
//    样例输出
//      1+2=3
        int x, y;
        cin >> x >> y;
        Base11 a(x);
        Base22 b(y);
        Derived11 d(a, b);
        cout << d.Base11::x << "+" << d.Base22::x << "=" << d.x << endl;
        return 0;
}

#endif //CPLUSPLUS_ZHENGLI_TSINGHUA_ADVANCED_PA01_H

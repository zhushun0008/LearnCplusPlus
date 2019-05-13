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
//    C7-1 �˻���  (100 ����)
//    ��Ŀ����
//    ����һ������Account�����ݳ�Ա����string�����userName���ڱ����˻�����������������Ա����Ĭ�Ϲ��캯����
//      ���ι��캯�����ڳ�ʼ�����ݳ�Ա����������ĳ�Ա��PrintName()����Account��������CreditAccount�࣬
//      �����������ݳ�Աcredit���ڼ�¼���û����ö�ȣ�������Ա�������ι��캯�����ڳ�ʼ�����ݳ�Ա������˻���Ϣ�ĳ�Ա����PrintInfo()��
//      Ҫ���ں���PrintInfo()����Ҫ���û���ĳ�Ա����PrintName()��
//    //��ʵ��Account���캯��Account(char *name)
//    //��ʵ��Account��PrintUserName()����
//    //��ʵ��CreditAccount��Ĺ��캯��CreditAccount(char* name, long number)
//    //��ʵ��CreditAccount���PrintInfo()����
//    ��������
//      ��
//
//    �������
//      ��������У���һ��Ϊ�˻��������ڶ���Ϊ�˻����ö��
//
//    ��������
//      ��
//
//    �������
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
//    C7-2 ��̳�  (100 ����)
//    ��Ŀ����
//      ����Ĵ�����������������Base1��Base2��Base3��Ȼ������������ఴ�չ��з�ʽ��������Derived����ÿ�����зֱ����һ�����Ͳ�����
//      ���캯�����������������ʾ��Ϣ�����캯������ʾ��Ϣ����Ҫ�������Ͳ�������ֵ���뽫����Ĵ��벹��������ʹ�������������������ͬ��
//      ע�⣺���������ж��顣
//
//    ��������
//      ÿ������Ϊ 4 �������ÿո����
//    �������
//      ���ݹ�������������ĵ���˳�����
//    ��������
//      1 2 3 4
//
//    �������
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
//    C7-3 ����ʵ��A+B  (100 ����)
//    ��Ŀ����
//    ����Ĵ�����������������Base1��Base2��Ȼ������������ఴ�չ��з�ʽ��������Derived������������඼���԰���һ�����г�Աx��
//    ����Base1��Base2���н���һ�����Ͳ����Ĺ��캯����Derived�Ĺ��캯������Base1��Base2�Ķ�������a��b����ʼ��Derived�����
//    ����xΪBase1::x��Base2::x֮�͡��뽫����Ĵ��벹����ɣ�ʹ���������Ҫ��
//    ��ʵ��Base1��Base2, Derived�Ĺ��캯��
//    ��������
//      ÿ������Ϊ 2 �������ÿո����
//
//    �������
//      �������Զ�������
//
//    ��������
//      1 2
//
//    �������
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

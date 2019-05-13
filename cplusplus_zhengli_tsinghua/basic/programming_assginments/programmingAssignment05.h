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

// ��̬��Ա���������ʼ��
double Yuebao::profitRate = 0;

int c_51() {
//    C5-1 ������  (100 ����)
//    ��Ŀ����
//    ��ʵ��һ���������࣬�����Ѹ�������ģ�壬�����main�����жԸ���Ĳ�����������ʵ�ֲ�����ɴ��롣
//    ����������Լ�¼�˻�����Ǯ��ȡǮ��������Ϣ����������һ��˽�о�̬��Ա����profitRate�洢�����������ʣ�
//    �����ù��о�̬��Ա����setProfitRate�޸����ʵ�ֵ����������Ϊ��1������n������n����˻�������ÿ��ֻ�ܽ���һ���˻�����������ȡ��
//    ÿһ���������Ϣ��ǰһ����˻�����롰�������ʵĳ˻�����������Ϣ����Ҳ�������˻������ڵ�1��֮ǰ�˻������ڣ�
//    ���Ե�1��һ�����½��˻�����Ǯ���ҵ��첻������Ϣ�����������ڽ���n������������Ҫ��������n�������ɺ���˻��������
//    �������£�
//    ��������
//       ÿ�������� n+2 ��
//       �� 1 ������һ������ n ����ʾ�������� n ��Ĳ���
//       �� 2 ������һ��ʵ����Ϊ �� �� �� �����ʣ� n �������ʲ���
//       �������� n �У����� n ��Ĳ�����ÿ���� 2 �������� 1 ������ 0 �� 1 �� 0 ��ʾ��Ǯ�� 1 ��ʾȡǮ���ڶ���ʵ��Ϊ��ȡ�Ľ��
//       1 <= n <= 20
//    �������
//       ����ÿһ�������������n�������ɺ���˻����
//    ��������
//    3
//    0.1
//    0 10
//    0 10
//    1 10
//    �������
//    13.1
    int n;
    while (cin >> n) {
        double profitRate;
        cin >> profitRate;
        Yuebao::setProfitRate(profitRate);//�趨��������
        Yuebao y(0); //�½����˻�������ʼ��Ϊ0
        int operation;//���������ж��Ǵ滹��ȡ
        double amount;//���������ȡ���
        for (int i = 0; i < n; ++i) {
            y.addProfit();//����ǰһ������������Ϣ
            cin >> operation >> amount;
            if (operation == 0)
                y.deposit(amount);//������
            else
                y.withdraw(amount);//ȡ�����
        }
        cout << y.getBalance() << endl;//��������˻����
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
//    C5-2 ������  (100 ����)
//    ��Ŀ����
//    ��ʵ��һ�������࣬�����Ѹ�������ģ�壬�����main�����жԸ���Ĳ�����������ʵ�ֲ�����ɴ��롣
//
//    �����и����о�̬����num��¼��������ж������������������ڲ�ͬ���֮�������������ֻ����ȷ��ʵ�ָ��࣬
//    ��֤num��ȷ��¼����Ķ����������������ȷ�Ľ����
//    ��������
//    �������
//    ������������Ѿ�д��

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

//
// Created by Zhu Kevin on 2018/10/10.
//

#ifndef CPLUSPLUS_ZHENGLI_TSINGHUA_ADVANCED_PA08_H
#define CPLUSPLUS_ZHENGLI_TSINGHUA_ADVANCED_PA08_H

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Complex {
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {};

    Complex operator+(const Complex &c2) const;

    Complex operator-(const Complex &c2) const;

    /*ʵ��������������*/
    Complex operator*(const Complex &c2) const;

    Complex operator/(const Complex &c2) const;

    friend ostream &operator<<(ostream &out, const Complex &c);

private:
    double real;
    double imag;
};

Complex Complex::operator+(const Complex &c2) const {
    return Complex(real + c2.real, imag + c2.imag);
}

Complex Complex::operator-(const Complex &c2) const {
    return Complex(real - c2.real, imag - c2.imag);
}

Complex Complex::operator*(const Complex &c2) const {
    return Complex(real * c2.real - imag * c2.imag, imag * c2.real + real * c2.imag);
}

Complex Complex::operator/(const Complex &c2) const {
    return Complex((real * c2.real + imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag),
                   (imag * c2.real - real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag));
}

ostream &operator<<(ostream &out, const Complex &c) {
    out << c.real << " " << c.imag << endl;
    return out;
}

int c_81() {
//    C8-1 �����Ӽ��˳�  (100 ����)
//    ��Ŀ����
//    �����������ļӼ��˳���
//
//    Ҫ��ʹ��c++ class��д���򡣿��Դ�������class
//    ��������
//    ��һ������double����������ʾ��һ��������ʵ���鲿
//
//    �ڶ�������double����������ʾ�ڶ���������ʵ���鲿
//
//
//    �������
//    ������μ������������ļӼ��˳���һ��һ�����
//
//    ������������ʵ�����ո�Ȼ�����鲿��
//
//
//    ��������
//    1 1
//    3 -1
//
//    �������
//    4 0
//      -2 2
//    4 2
//    0.2 0.4

    double real, imag;
    cin >> real >> imag;
    Complex c1(real, imag);
    cin >> real >> imag;
    Complex c2(real, imag);
    cout << c1 + c2;
    cout << c1 - c2;
    cout << c1 * c2;
    cout << c1 / c2;
}


const double pi = 3.14;

class Shape {
public:
    Shape() {}

    ~Shape() {}

    virtual double getArea() = 0;

    virtual double getPerim() = 0;
};

class Circle : public Shape {
public:
    Circle(double rad) : radius(rad) {}

    ~Circle() {}

    /*��������������*/
    double getArea();

    double getPerim();

private:
    double radius;
};

double Circle::getArea() { return pi * radius * radius; }

double Circle::getPerim() { return 2 * pi * radius; }

int c_82() {
//    C8-2 Բ���ܳ������  (100 ����)
//      ��Ŀ����
//        ��Բ���ܳ����������֪Բ���shape������̳С�
//
//      Ҫ��ʹ��c++ class��д���򡣿��Դ�������class
//      ��������
//        ����Բ�İ뾶
//
//      �������
//        ���Բ���ܳ������
//
//      ��������
//          10
//
//      �������
//          314 62.8
    double radius;
    cin >> radius;
    Circle c(radius);
    cout << c.getArea() << " " << c.getPerim() << endl;
}


class Shape1 {
public:
    Shape1() {}

    virtual ~Shape1() {}
};

class Triangle : public Shape1 {
public:
    Triangle() {}

    ~Triangle() {}
};

class Rectangle : public Shape1 {
public:
    Rectangle() {}

    ~Rectangle() {}
};

/*��dynamic_cast����ת����������ɸú���*/
int getVertexCount(Shape1 *b) {
    Triangle *tri = dynamic_cast<Triangle *>(b);
    if ( tri != nullptr) return 3;
    Rectangle * rec = dynamic_cast<Rectangle *>(b);
    if (rec != nullptr) return 4;
    Shape1 * shape = dynamic_cast<Shape1 *>(b);
    if (shape != nullptr) return 0;
    return 0;
}

int c_83() {
    //C8-3 �����λ��ǳ����Σ�  (100 ����)
    //��Ŀ����
    //   �ڶ�̬�����У������ָ��ȿ���ָ�����Ķ����ֿ���ָ��������Ķ������ǿ���ʹ��dynamic_cast����ת�����������жϵ�ǰָ��
    //  �������Ƕ�̬���ͣ��Ƿ��ܹ�ת����Ϊĳ��Ŀ�����͵�ָ�롣
    //   ͬѧ���Ȳ���dynamic_cast��ʹ��˵������http://en.wikipedia.org/wiki/Run-time_type_information#dynamic_cast����
    //   Ȼ��ʹ�ø�����ת�����������������򣨸��������룩��
    //   ����int getVertexCount(Shape * b)����b�Ķ�����Ŀ����bָ��Shape���ͣ�����ֵΪ0��
    //   ��bָ��Triangle���ͣ�����ֵΪ3����bָ��Rectangle���ͣ�����ֵΪ4��

    Shape1 s;
    cout << getVertexCount(&s) << endl;
    Triangle t;
    cout << getVertexCount(&t) << endl;
    Rectangle r;
    cout << getVertexCount(&r) << endl;
}

#endif //CPLUSPLUS_ZHENGLI_TSINGHUA_ADVANCED_PA08_H

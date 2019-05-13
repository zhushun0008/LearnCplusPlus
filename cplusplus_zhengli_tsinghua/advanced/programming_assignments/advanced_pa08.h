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

    /*实现下面三个函数*/
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
//    C8-1 复数加减乘除  (100 满分)
//    题目描述
//    求两个复数的加减乘除。
//
//    要求使用c++ class编写程序。可以创建如下class
//    输入描述
//    第一行两个double类型数，表示第一个复数的实部虚部
//
//    第二行两个double类型数，表示第二个复数的实部虚部
//
//
//    输出描述
//    输出依次计算两个复数的加减乘除，一行一个结果
//
//    输出复数先输出实部，空格，然后是虚部，
//
//
//    样例输入
//    1 1
//    3 -1
//
//    样例输出
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

    /*补充这两个函数*/
    double getArea();

    double getPerim();

private:
    double radius;
};

double Circle::getArea() { return pi * radius * radius; }

double Circle::getPerim() { return 2 * pi * radius; }

int c_82() {
//    C8-2 圆的周长和面积  (100 满分)
//      题目描述
//        求圆的周长和面积，已知圆类从shape抽象类继承。
//
//      要求使用c++ class编写程序。可以创建如下class
//      输入描述
//        输入圆的半径
//
//      输出描述
//        输出圆的周长和面积
//
//      样例输入
//          10
//
//      样例输出
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

/*用dynamic_cast类型转换操作符完成该函数*/
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
    //C8-3 三角形还是长方形？  (100 满分)
    //题目描述
    //   在多态概念中，基类的指针既可以指向基类的对象，又可以指向派生类的对象。我们可以使用dynamic_cast类型转换操作符来判断当前指针
    //  （必须是多态类型）是否能够转换成为某个目的类型的指针。
    //   同学们先查找dynamic_cast的使用说明（如http://en.wikipedia.org/wiki/Run-time_type_information#dynamic_cast），
    //   然后使用该类型转换操作符完成下面程序（该题无输入）。
    //   函数int getVertexCount(Shape * b)计算b的顶点数目，若b指向Shape类型，返回值为0；
    //   若b指向Triangle类型，返回值为3；若b指向Rectangle类型，返回值为4。

    Shape1 s;
    cout << getVertexCount(&s) << endl;
    Triangle t;
    cout << getVertexCount(&t) << endl;
    Rectangle r;
    cout << getVertexCount(&r) << endl;
}

#endif //CPLUSPLUS_ZHENGLI_TSINGHUA_ADVANCED_PA08_H

//2_1.cpp
#include <iostream>
using namespace std;

int example2_1() {
	cout << "Hello! " << endl;
	cout << "Welcome to C++! " << endl;
	return 0;
}


int example2_2() {
    int year;
    bool isLeapYear;

    cout << "Enter the year: ";
    cin >> year;
    isLeapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));

    if (isLeapYear)
        cout << year << " is a leap year" << endl;
    else
        cout << year << " is not a leap year" << endl;

    return 0;
}

int example2_3() {
    int x, y;
    cout << "Enter x and y:";
    cin >> x >> y;

    if (x != y)
        if (x > y)
            cout << "x > y" << endl;
        else
            cout << "x < y" << endl;
    else
        cout << "x = y" << endl;

    return 0;
}

int example2_4() {
    int day;

    cin >> day;
    switch (day) {
        case 0:
            cout << "Sunday" << endl;
            break;
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "Saturday" << endl;
            break;
        default:
            cout << "Day out of range Sunday .. Saturday" << endl;
            break;
    }

    return 0;
}

int example2_5() {
    int i = 1, sum = 0;
    while (i <= 10) {
        sum += i;
        i++;
    }
    cout << "sum = " << sum << endl;
    return 0;
}

int example2_6() {
    int n, right_digit, newnum = 0;
    cout << "Enter the number: ";
    cin >> n;

    cout << "The number in reverse order is ";
    do {
        right_digit = n % 10;
        cout << right_digit;
        n /= 10;
    } while (n != 0);
    cout << endl;

    return 0;
}

int example2_7() {
    int i = 1, sum = 0;
    do {
        sum += i;
        i++;
    } while (i <= 10);
    cout << "sum = " << sum << endl;

    return 0;
}

int example2_8() {
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Number  " << n << "   Factors  ";

    for (int k = 1; k <= n; k++)
        if (n % k == 0)
            cout << k << "  ";
    cout << endl;

    return 0;
}


int example2_9() {
    const int N = 4;
    for (int i = 1; i <= N; i++) {	//���ǰ4��ͼ��
        for (int j = 1; j <= 30; j++)
            cout << ' ';	//��ͼ������30��
        for (int j = 1; j <= 8 - 2 * i; j++)
            cout << ' ';
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << '*';
        cout << endl;
    }
    for (int i = 1; i <= N - 1; i++) {	//�����3��ͼ��
        for (int j = 1; j <= 30; j++)
            cout << ' ';	//��ͼ������30��
        for (int j = 1; j <= 7 - 2 * i ;j++)
            cout << '*';
        cout << endl;
    }
    return 0;
}

int example2_10() {
    int i = 0, j = 0, n;
    cout << "Enter some integers please (enter 0 to quit):" << endl;
    cin >> n;
    while (n != 0) {
        if (n > 0) i += 1;
        if (n < 0) j += 1;
        cin >> n;
    }
    cout << "Count of positive integers: " << i << endl;
    cout << "Count of negative integers: " << j << endl;
    return 0;
}

enum GameResult { WIN, LOSE, TIE, CANCEL };

int example2_11() {
    GameResult result;                  //声明变量时,可以不写关键字enum
    enum GameResult omit = CANCEL;      //也可以在类型名前写enum

    for (int count = WIN ; count <= CANCEL ; count++) {	//隐含类型转换
        result = GameResult(count);		//显式类型转换
        if (result == omit)
            cout << "The game was cancelled" << endl;
        else {
            cout << "The game was played ";
            if (result == WIN)
                cout << "and we won!";
            if (result == LOSE)
                cout << "and we lost.";
            cout << endl;
        }
    }
    return 0;
}

struct Student1 {	//学生信息结构体
    int num;		//学号
    string name;	//姓名
    char sex;		//性别
    int age;		//年龄
} stu = { 97001, "Lin Lin", 'F', 19};

//int example2_12() {
//    cout << setw(7) << stu.num;
//    cout << setw(20) << stu.name;
//    cout << setw(3) << stu.sex;
//    cout << setw(3) << stu.age;
//    cout << endl;
//    return 0;
//}

struct Animal {
    int weight;
    int feet;
};

int example2_13() {
    Animal dog1, dog2, chicken;

    dog1.weight = 15;
    dog2.weight = 37;
    chicken.weight = 3;

    dog1.feet = 4;
    dog2.feet = 4;
    chicken.feet = 2;

    cout << "The weight of dog1 is " << dog1.weight << endl;
    cout << "The weight of dog2 is " << dog2.weight << endl;
    cout << "The weight of chicken is "<< chicken.weight << endl;

    return 0;
}


struct Aircraft {
    int wingspan;	//翼幅
    int passengers; //乘客
    union {					//无名联合作为结构体的内嵌成员
        float fuelLoad; 	//战斗机装载的燃料
        float bombLoad; 	//轰炸机装载的炸弹
        int pallets; 		//运输机的货盘
    };
} fighter, bomber, transport;

int example2_14() {
    fighter.wingspan = 40;
    fighter.passengers = 1;
    fighter.fuelLoad = 12000.0;

    bomber.wingspan = 90;
    bomber.passengers = 12;
    bomber.bombLoad = 14000.0;

    transport.wingspan = 106;
    transport.passengers = 4;
    transport.pallets = 42;

    transport.fuelLoad = 18000.0;
    fighter.pallets = 4;

    cout << "The fighter carries " << fighter.pallets << " pallets." << endl;
    cout << "The bomber bomb load is " << bomber.bombLoad << endl;

    return 0;
}


enum Level { FRESHMAN, SOPHOMORE, JUNIOR, SENIOR };
enum Grade { A, B, C, D };

struct Student {
    unsigned number : 27;
    Level level : 2;
    Grade grade : 2;
};

int example2_15() {
    Student s = { 12345678, SOPHOMORE, B };
    cout << "Size of Student: " << sizeof(Student) << endl;
    cout << "Number:    " << s.number << endl;
    cout << "Level:     ";
    switch (s.level) {
        case FRESHMAN:  cout << "freshman"; break;
        case SOPHOMORE: cout << "sophomore"; break;
        case JUNIOR:    cout << "junior"; break;
        case SENIOR:    cout << "senior"; break;
    }
    cout << endl;
    cout << "Grade:     ";
    switch (s.grade) {
        case A: cout << "A"; break;
        case B: cout << "B"; break;
        case C: cout << "C"; break;
        case D: cout << "D"; break;
    }
    cout << endl;
    return 0;
}
//
//  main.cpp
//  66-析构函数调用顺序
//
//  Created by Fearless on 2021/6/24.
//

#include <iostream>
using namespace std;

// =====================================================
class Str {
    char *Sp;
    int Length;

public:
    Str(char *string) {
        if (string) {
            Length = strlen(string);
            // 在构造函数中将成员数据指针 指向动态开辟的内存
            Sp = new char[Length + 1];
            // 用初值为开辟的内存赋值
            stpcpy(Sp, string);
        } else {
            Sp = 0;
        }
    }

    void Show(void) {
        cout << Sp << endl;
    }

    // 析构函数，当释放对象时收回用new开辟的空间
    ~Str() {
        if (Sp) {
            delete []Sp;
        }
    }
};
// =====================================================




class Test {
    float x, y;
public:
    Test(float a, float b) {
        x = a;
        y = b;
        cout << "调用了构造函数" << endl;
    }
    
    void Print(void) {
        cout << x << "\t" << y << endl;
    }
    
    ~Test() {
        cout << "调用了析构函数" << endl;
    }
};

// =====================================================


class Rectangle {
    float x, y;
public:
    Rectangle() {
        x = 0;
        y = 0;
        cout << "初始化静态局部对象" << endl;
    }
    
    Rectangle(float a) {
        x = a;
        y = 0;
        cout << "初始化全局对象" << endl;
    }
    
    Rectangle(float a, float b) {
        x = a;
        y = b;
        cout << "初始化自动局部对象" << endl;
    }
    
    ~Rectangle() {
        cout << "调用析构函数" << endl;
    }
};

Rectangle rect(100.0); // 定义全局对象

void func(void) {
    cout << "进入func()函数" << endl;
    Rectangle rect1(10.0, 20.0);    // 定义局部自动对象
    static Rectangle rect2;         // 初始化静态局部对象
}

// =====================================================


class Check {
    float x, y;
public:
    Check(float a = 0, float b = 0) {
        x = a;
        y = b;
        cout << "调用了构造函数" << endl;
    }
    
    ~Check() {
        cout << "调用了析构函数" << endl;
    }
    
};


// =====================================================
/**
 实现类型转换的构造函数
 同类型的对象可以相互赋值，相当于类中的数据成员相互赋值;
 如果直接将数据赋给对象，所赋入的数据需要强制类型转换，这种转 换需要调用构造函数。
 */

class Rect {
    float x, y;
public:
    Rect(float a, float b) {
        x = a;
        y = b;
        cout << "调用构造函数" << endl;
    }
    
    ~Rect() {
        cout << "调用析构函数" << endl;
    }
    
    void Print(void) {
        cout << x << "\t" << y << endl;
    }
};


// =====================================================


class X {
    float x;
public:
    X(float a) {
        x = a;
        cout << "调用构造函数" << endl;
    }
    
    ~X() {
        cout << "调用析构函数" << endl;
    }
    
    void Print(void) {
        cout << x << endl;
    }
};




// =====================================================


class A {
    float x;
public:
    A(int a) {
        x = a;
        cout << "调用了A的构造函数" << endl;
    }
    
    ~A() {
        cout << "调用了A的析构函数" << endl;
    }
};

class B {
    float y;
public:
    B(int a) {
        y = a;
        cout << "调用了B的构造函数" << endl;
    }
    ~B() {
        cout << "调用了B的析构函数" << endl;
    }
};

class C {
    float z;
    B b1;           // 调用了B的构造函数
    A a1;           // 调用了A的构造函数
public:
    C(int a, int b, int c) : a1(a), b1(b) {
        z = c;
        cout << "调用了C的构造函数" << endl;
    }
    ~C() {
        cout << "调用了C的析构函数" << endl;
    }
};


// =====================================================


class Data {
    float x, y;
public:
    Data(float a = 0, float b = 0) {
        x = a;
        y = b;
        cout << "调用了构造函数" << endl;
    }
    
    
    /**
     如果没有定义完成拷贝功能的构造函数，编译器自动生成一个隐含的完成拷贝功能的构造函数
     依次完成类中对应数据成员的拷贝。
     
     如果类中的数据成员中使用的 new 运算符，动态地申请存储空间进行赋初值时。必须在类中 显示的
     定义一个完成拷贝功能的构造函数，以便正确实现数据成员的复制。
     
     */
    // 形参 必须 是同类型对象的引用
    Data(Data &data) {
        x = data.x;
        y = data.y;
        cout << "调用了完成拷贝功能的构造函数" << endl;
    }
    
    void Print(void) {
        cout << x << "\t" << y << endl;
    }
    
    ~Data() {
        cout << "调用了析构函数" << endl;
    }
};






// =====================================================

int main() {

//    C c1(1, 2, 3);  // 调用了C的构造函数
    
    
    
//    Str s("Study C++");
//    s.Show();
    
    
    
//    cout << "进入main()函数" << endl;
//    func();
//    func(); // 第二次func()不会调用静态局部对象，static只会初始化一次
    
    
    
//    cout << "进入main()函数" << endl;
//
//    Test *test1;
//    test1 = new Test(2.0, 3.0); // 调用构造函数
//    test1->Print();
//    delete test1;               // 调用了析构函数
//
//    cout << "退出main()函数" << endl;
    
    
    
    
//    cout << "进入main()函数" << endl;
//    Check *check;
//    check = new Check[5];       // 开辟数组空间
//    cout << "\n完成开辟数组空间" << endl;
//    delete []check;             // 必须用[]删除开辟的空间
//    cout << "退出main()函数" << endl;
    
    
    
//    Rect rect1(1.0, 1.0);
//    rect1.Print();
//
//    rect1 = Rect(3.0, 30.0);        // 产生临时对象，初始化并赋值后立即释放
//    rect1.Print();
//
//    cout << "退出主函数" << endl;
    
    
//    X x1(1.0);
//    x1.Print();
//
//    X x2 = 100;
//    x2.Print();
//
//    x1 = 10;
//    x1.Print();
//
//    cout << "退出主函数main()" << endl;
    
  
    Data data1(10.0, 20.0);
    Data data2(data1);
    
    
    data1.Print();
    data2.Print();
    
    return 0;
}

/**
 调用了B的构造函数
 调用了A的构造函数
 调用了C的构造函数
 调用了C的析构函数
 调用了A的析构函数
 调用了B的析构函数
 */



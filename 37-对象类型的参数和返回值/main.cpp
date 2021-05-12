//
//  main.cpp
//  37-对象类型的参数和返回值
//
//  Created by XFB on 2021/5/12.
//

#include <iostream>
using namespace std;

class Car {
public:
    // 构造函数
    Car() {
        cout << "Car() - " << this << endl;
    }
    // 拷贝构造函数
    Car(const Car &car) {
        cout << "Car(const Car &car) - " << this << endl;
    }
    // 析构函数
    ~Car() {
        cout << "~Car() - " << this << endl;
    }
    void run() {
        cout << "run()" << endl;
    }
};

// 这样会生成新的临时对象，因为Car car
void test1(Car car) {
    
}

Car test2() {
    return Car();
}

Car test3() {
    Car car;
    return car;
}

int main() {
    
    Car car; // Car() - 0x7ffeefbff4d8
    Car car6(car); // Car(const Car &car) - 0x7ffeefbff4d0
    
//    Car car2; // Car() - 0x7ffeefbff4d8
//    car2 = test2(); // Car() - 0x7ffeefbff4d0
//    test1(Car()); // Car() - 0x7ffeefbff4c0
//
//    cout << 1 << endl;
//    Car().run();
//    cout << 2 << endl;
//
//    Car car3; // Car()
//    car3 = test3();
  
    getchar();
    return 0;
}

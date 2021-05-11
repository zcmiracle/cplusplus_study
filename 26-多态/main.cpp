//
//  main.cpp
//  26-多态
//
//  Created by XFB on 2021/5/10.
//

#include <iostream>
using namespace std;

/**
 父类指针、子类指针
 1、父类指针可以指向子类对象，是安全的，开发中经常用到（继承方式必须是 public）
 2、子类指针指向父类对象是 【不安全的】
 
 
 多态：C++中的默认调用不存在调用，【根据指针类型调用对应的函数】只看【指针类型】
 默认情况下，编译器只会 根据指针类型调用对应的函数，不存在多态
 多态是面向对象非常重要的一个特性
    1、同一操作作用于不同的对象，可以有不同的解释，产生不同的执行结果
 
 重点：
 C++中的多态通过虚函数实现 （virtual function）来实现
 虚函数：被virtual修饰的成员函数
 只要在父类中声明为虚函数，子类中【重写】的函数也自动变成虚函数（也就是说子类中）

 */


struct Person {
    int m_age;
};

struct Student: Person {
    int m_score;
};


void test() {
    
    // 父类指针 指向 子类对象
    Person *p = new Student();
  
    // 子类指针 指向 父类对象 报错 error
//    Student *stu = new Person();
    Student *p1 = (Student *) new Person();
    p1->m_age = 10;
    // 误将别人的数据给抹掉，因为堆空间实际是Person对象，只有m_age，是没有m_score
    // 如果给m_score赋值可能赋给其他对象
    p1->m_score = 100;
    
    cout << p1->m_age << endl;
    cout << p1->m_score << endl;
}


//struct Dog {
//    void speak() {
//        std::cout << "Dog::speak()" << std::endl;
//    }
//
//    void run() {
//        std::cout << "Dog::run()" << std::endl;
//    }
//};
//
//struct Cat {
//    void speak() {
//        std::cout << "Cat::speak()" << std::endl;
//    }
//
//    void run() {
//        std::cout << "Cat::run()" << std::endl;
//    }
//};
//
//struct Pig {
//    void speak() {
//        std::cout << "Pig::speak()" << std::endl;
//    }
//
//    void run() {
//        std::cout << "Pig::run()" << std::endl;
//    }
//};

struct Animal {
    // virtual 虚函数
    virtual void speak() {
        std::cout << "Animal::speak()" << std::endl;
    }
    
    // virtual 虚函数
    virtual void run() {
        std::cout << "Animal::run()" << std::endl;
    }
};

struct Dog : Animal {
    void speak() {
        std::cout << "Dog::speak()" << std::endl;
    }

    void run() {
        std::cout << "Dog::run()" << std::endl;
    }
};

struct Cat : Animal {
    void speak() {
        std::cout << "Cat::speak()" << std::endl;
    }

    void run() {
        std::cout << "Cat::run()" << std::endl;
    }
};

struct Pig : Animal  {
    void speak() {
        std::cout << "Pig::speak()" << std::endl;
    }

    void run() {
        std::cout << "Pig::run()" << std::endl;
    }
};

void liu(Animal *animal) {
    animal->speak();
    animal->run();
}

//void liu(Dog *dog) {
//    dog->speak();
//    dog->run();
//}
//
//void liu(Cat *cat) {
//    cat->speak();
//    cat->run();
//}
//
//void liu(Pig *pig) {
//    pig->speak();
//    pig->run();
//}


int main() {
    
//    // 指针类型是Cat，所以不管后面是Dog还是Pig，只看指针类型
//    Cat *cat = (Cat *) new Dog();
//    cat->speak(); // call Cat::speak
//    cat->run(); //call Cat::run();
    
    Animal *p = new Pig();
    p->speak();
    p->run();
    
    liu(new Dog());
    liu(new Cat());
    liu(new Pig());
    
    getchar();
    return 0;
}

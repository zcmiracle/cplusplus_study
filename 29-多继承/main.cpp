//
//  main.cpp
//  29-多继承
//
//  Created by XFB on 2021/5/11.
//

#include <iostream>

using namespace std;
/**
 多继承-虚函数
 1、如果子类继承的多个父类都有虚函数，那么子类对象就会产生对应的【多张虚表】
 
 同名函数：

 */


//// 学生
//struct Student {
//    int m_score;
//    void study() {
//        std::cout << "Student::study() - score = " << m_score << std::endl;
//    }
//};
//
//// 工人
//struct Worker {
//    int m_salary;
//    void work() {
//        std::cout << "Worker::work() - salary = " << m_salary << std::endl;
//    }
//};
//
//// 大学生 多继承
//struct Undergraduate: public Student, public Worker {
//    int m_grade; // 年级
//    void play() {
//        std::cout << "Undergraduate::play() - grade = " << m_grade << std::endl;
//    }
//};


// ================【多继承体系下的构造函数调用】================ //

//// 学生
//class Student {
//    int m_score;
//public:
//    Student(int score) :m_score(score) { // 构造函数
//
//    }
//};
//
//// 工人
//class Worker {
//    int m_salary;
//public:
//    Worker(int salary) :m_salary(salary) { // 构造函数
//
//    }
//};
//
//// 大学生 多继承
//class Undergraduate: public Student, public Worker {
//    int m_grade; // 年级
//public:
//    // 构造函数
//    Undergraduate(int score, int salary, int grade)
//        :Student(score),
//        Worker(salary),
//        m_grade(grade) {
//
//    }
//};


// ================【多继承-虚函数】================ //
// 如果子类继承的多个父类都有虚函数，那么子类对象就会产生对应的【多张虚表】
class Student2 {
public:
    virtual void study() {
        std::cout << "Student2::study()" << std::endl;
    }
};

class Worker2 {
public:
    virtual void work() {
        std::cout << "Worker2::work()" << std::endl;
    }
};

// 大学生 多继承
class Undergraduate2: public Student2, public Worker2 {
public:
    // 重写父类希函数
    void study() {
        std::cout << "Undergraduate2::study()" << std::endl;
    }
    void work() {
        std::cout << "Undergraduate2::work()" << std::endl;
    }
    void play() {
        std::cout << "Undergraduate2::play()" << std::endl;
    }
};


// ================【多继承-同名函数】================ //
// 学生
struct Student {
    void eat() {
        cout << "Student::eat()" << endl;
    }
};

// 工人
struct Worker {
    void eat() {
        cout << "Worker::eat()" << endl;
    }
};

// 大学生
struct Undergraduate: Student, Worker {
    void eat() {
        cout << "Undergraduate::eat()" << endl;
    }
};

// ================【多继承-同名成员变量】================ //
struct Student1 {
    int m_age;
};

struct Worker1 {
    int m_age;
};

struct Undergraduate1 : Student1, Worker1 {
    int m_age;
};

int main() {

    // 暂用12个字节 4 * 3
    // m_score
    // m_salary
    // m_grade
    // 父类的成员变量的先后顺序只和继承的父类先后顺序有关
//    Undergraduate undergraduate;
//    undergraduate.m_score = 100;
//    undergraduate.m_salary = 2000;
//    undergraduate.m_grade = 4;
//    undergraduate.study();
//    undergraduate.work();
//    undergraduate.play();

    
//    Undergraduate undergraduate;
//    undergraduate.eat(); // Undergraduate::eat()
//    undergraduate.Student::eat(); // Student::eat()
//    undergraduate.Worker::eat(); // Worker::eat()
//    undergraduate.Undergraduate::eat(); // Undergraduate::eat()

//    Undergraduate1 undergraduate1;
//    undergraduate1.m_age = 10;
//    undergraduate1.Undergraduate1::m_age = 11;
//    undergraduate1.Student1::m_age = 12;
//    undergraduate1.Worker1::m_age = 13;
    
    Undergraduate2 undergraduate2;
    
    getchar();
    return 0;
}

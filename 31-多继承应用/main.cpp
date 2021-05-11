//
//  main.cpp
//  31-多继承应用
//
//  Created by XFB on 2021/5/11.
//

#include <iostream>

// 教师
class Teacher {
public:
    virtual void playBasketball() = 0;
    virtual void playBaseBall() = 0;
    virtual void playFootball() = 0;
};

// 保姆
class BabySitter {
public:
    virtual void clean() = 0; // 打扫
    virtual void cook() = 0; // 烹饪
};

class Student: public Teacher, public BabySitter {
    int m_score;
public:
    void playBasketball() {}
    void playBaseBall() {}
    void playFootball() {}
    void clean() {}
    void cook() {}
};

class Worker : public Teacher {
    int m_salary;
public:
    void playBasketball() {}
    void playBaseBall() {}
    void playFootball() {}
};


int main() {

    
    
    getchar();
    return 0;
}

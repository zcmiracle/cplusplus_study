//
//  main.cpp
//  12-封装
//
//  Created by XFB on 2021/5/7.
//

#include <iostream>
using namespace std;



struct Person {
    
private:
    int m_age;
    
public:
    void setAge(int age) {
        if (age <= 0) {
            m_age = 1;
        } else {
            m_age = age;
        }
    }

    int getAge() {
        return m_age;
    }
};


int main() {

    Person person;
    // what？报错，理解不了 
    person.setAge(10);
//    person.setAge(0);

    
//    cout << person.getAge() << endl;

    getchar();
    return 0;
}

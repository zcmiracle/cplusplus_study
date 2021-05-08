//
//  Person.hpp
//  19-类的声明和实现分离
//
//  Created by XFB on 2021/5/8.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>

class Person {
private:
    int m_age;
public:
    void setAge(int age);
    int getAge();
    Person();
    ~Person();
};


#endif /* Person_hpp */

//
//  main.cpp
//  45-仿函数
//
//  Created by XFB on 2021/5/13.
//

#include <iostream>
using namespace std;


class Sum {
public:
    int m_age;
    int operator()(int a, int b) {
        if (m_age) {
            
        }
        return a+b;
    }
    
    void func() {
        m_age = 10;
    }
};

int main() {

    Sum sum;
    sum.m_age = 10;
    cout << sum(10, 20) << endl;
    
    getchar();
    return 0;
}

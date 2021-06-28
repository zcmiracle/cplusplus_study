//
//  main.cpp
//  81-运算符重载-
//
//  Created by XFB on 2021/6/28.
//

#include <iostream>
using namespace std;

class Distance {
  
public:
    Distance(int i) {
        x = i;
    }
    
    Distance(int a, int b) {
        y = a;
        z = b;
    }
    
    // 重载运算符 负号-
    Distance operator -() {
        cout << "调用重载负号运算符函数" << endl;
        x = -x;
        cout << "调用负号运算符后的值" << x << endl;
        return Distance(x);
    }

    // 重载小于< 运算符
    bool operator < (const Distance &d) {
        cout << "调用重载小于运算符函数" << endl;
        
        if (y < d.x && (y == d.y && z < d.z)) {
            cout << "d3 < d4" << endl;
            return true;
        } else {
            cout << "d3 > d4" << endl;
            return false;
        }
    }
    
private:
    int x;
    int y;
    int z;
};


int main() {

    Distance d1(5);
    Distance d2(10);
    -d1;
    -d2;

    
    Distance d3(30, 40);
    Distance d4(40, 50);
    d3 <  d4;
    
    getchar();
    return 0;
}

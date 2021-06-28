//
//  main.cpp
//  79-函数的重载
//
//  Created by XFB on 2021/6/28.
//

#include <iostream>
using namespace std;

class PrintData {
public:
    void print(int i) {
        cout << "整数为：" << i << endl;
    }
    
    void print(char c[]) {
        cout << "字符为：" << c << endl;
    }
    
    void print(double f) {
        cout << "浮点为：" << f << endl;
    }
};


int main(int argc, const char * argv[]) {

    char c[] = "Fearless";
    PrintData printData;
    printData.print(c);
    printData.print(5);
    printData.print(100.00);

    
    getchar();
    return 0;
}

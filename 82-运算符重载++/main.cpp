//
//  main.cpp
//  82-运算符重载++
//
//  Created by XFB on 2021/6/28.
//

#include <iostream>
using namespace std;

class Time {
public:

    Time() {
        
    }
    
    Time(int h, int m) {
        hours = h;
        minutes = m;
    }
    
    void PrintTimeFunc() {
        cout << hours << ":" << minutes << endl;
    }
    
    // 重载前缀递增运算符 ++i
    Time operator ++ () {
        cout << "调用前置递增运算符重载函数" << endl;
        ++ minutes;
        
        if (minutes >= 60) {
            ++ hours;
            minutes = minutes - 60;
        }
        return Time(hours, minutes);
    }
    
    // 重载后缀递增运算符 ++i
    Time operator ++ (int) {
        cout << "调用前置递增运算符重载函数" << endl;
        Time t(hours, minutes);     // 先备份当前传入的时间
        ++ minutes;

        if (minutes >= 60) {
            ++ hours;
            minutes = minutes - 60;
        }
        return t;
    }
    
    
private:
    int hours;       // 时 24
    int minutes;    // 分 60
};


int main() {

    
    Time T1(20, 30);
    ++T1;
    ++T1;
    T1.PrintTimeFunc();
    
    
    Time T2(23, 59);
    Time T3;
    T3 = T2++;

    T2.PrintTimeFunc();
    T3.PrintTimeFunc();
    
    
    string str1 = "Fearless";
    string str2 = "C++";
    string str3;
    
    // 字符串复制
    str3 = str1;
    cout << str3 << endl;
    
    // 字符串连接
    str3 = str1 + str2;
    cout << str3 << endl;

    // 字符串长度
    int lenght = str3.size();
    cout << lenght << endl;
    
    
    getchar();
    return 0;
}

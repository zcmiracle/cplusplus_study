//
//  main.cpp
//  49-类模板
//
//  Created by XFB on 2021/5/14.
//

#include <iostream>
#include "Array.hpp"
using namespace std;

int main() {

    Array<int> array(5);
    array.add(10);
    array.add(20);
    array.add(30);
    array.add(40);
    array.add(50);

    cout << "array[0] = " << array[0] << endl;
    array.setData(0, 2000);
    cout << "array[0] = " << array[0] << endl;

    // 重点
//    cout << array << endl;
    
    
//    cout << array.get(0) << endl;
//    cout << array.size() << endl;
    
    // 运算符重载
    cout << "array[2] = " << array[2] << endl;
    cout << "array[3] = " << array[3] << endl;
    cout << "array[4] = " << array[4] << endl;

    getchar();
    return 0;
}

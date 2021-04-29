//
//  main.cpp
//  07-内联汇编
//
//  Created by XFB on 2021/4/29.
//

#include <iostream>
using namespace std;

int main() {

    // 内联汇编
//    int a = 10;
    asm {
        mov eax, 20
    }
    
    return 0;
}

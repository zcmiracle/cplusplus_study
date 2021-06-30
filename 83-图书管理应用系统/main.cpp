//
//  main.cpp
//  83-图书管理应用系统
//
//  Created by XFB on 2021/6/29.
//

#include <iostream>
#include "BMS.h"

int main(int argc, const char * argv[]) {
 
    
    mainDesk yourDesk;
    if (yourDesk.Login()) {
        
        cout << "================================================" << endl;
        cout << "===                                          ===" << endl;
        cout << "===           感谢使用高校图书管理系统            ===" << endl;
        cout << "===                                          ===" << endl;
        cout << "================================================" << endl;
    }
    
    return 0;
}

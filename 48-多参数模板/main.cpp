//
//  main.cpp
//  48-多参数模板
//
//  Created by XFB on 2021/5/14.
//

#include <iostream>

using namespace std;

template <class T1, class T2>
void display(const T1 &v1, const T2 &v2) {
    cout << v1 << endl;
    cout << v2 << endl;
}

int main() {

    display(20, 17.5);
    getchar();
    return 0;
}

//
//  main.cpp
//  80-函数运算符重载
//
//  Created by XFB on 2021/6/28.
//

#include <iostream>
using namespace std;

class Box {
public:
    double getVolume() {                // 计算盒子的体积
        return length * width * height;
    }
    
    void setLength(double len) {        // 盒子的长度
        length = len;
    }
    
    void setWidth(double wid) {         // 盒子的宽度
        width = wid;
    }
    
    void setHeight(double hei) {        // 盒子的高度
        height = hei;
    }
    
    // 重载运算符 +
    Box operator + (const Box &b) {
        Box box;
        box.length = this->length + b.length;
        box.width = this->width + b.width;
        box.height = this->height + b.height;
        return box;
    }
    
private:
    double length;      // 盒子的长度
    double width;       // 盒子的宽度
    double height;      // 盒子的高度
};


int main() {

    Box box1, box2, box3;
    
    // 设置box1的长宽高
    box1.setLength(10);
    box1.setWidth(10);
    box1.setHeight(10);
    cout << "box1的体积为：" << box1.getVolume() << endl;
   
    // 设置box2的长宽高
    box2.setLength(20);
    box2.setWidth(20);
    box2.setHeight(20);
    cout << "box2的体积为：" << box2.getVolume() << endl;
    
    // 将box1和box2相加，得到box3的体积
    box3 = box1 + box2;
    cout << "box3的体积为：" << box3.getVolume() << endl;
    
    getchar();
    return 0;
}

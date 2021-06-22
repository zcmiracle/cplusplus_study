//
//  main.cpp
//  57-通讯录增删
//
//  Created by Fearless on 2021/6/22.
//

#include <iostream>
using namespace std;

class AddrList {
public:
    void AddRecord();       // 增加通讯录信息
    void DeleteRecord();    // 删除通讯录信息
    void ShowData();        // 显示通讯录信息

private:
    char name[20];          // 姓名
    char address[50];       // 地址
    char postcode[10];      // 邮编
    char tel[20];           // 电话
};

// 增加通讯录信息
void AddrList::AddRecord() {
    cout << "请输入姓名：";
    cin >> name;
    cout << "请输入地址：";
    cin >> address;
    cout << "请输入邮编：";
    cin >> postcode;
    cout << "请输入电话：";
    cin >> tel;
    
    cout << "通讯录信息添加成功" << endl;
}

// 删除通讯录信息
void AddrList::DeleteRecord() {
    memset(name, 0, sizeof(name));
    memset(address, 0, sizeof(address));
    memset(postcode, 0, sizeof(postcode));
    memset(tel, 0, sizeof(tel));
    cout << "通讯录信息删除成功" << endl;
}

// 显示通讯录信息
void AddrList::ShowData() {
    cout << "----------" << endl;
 
    cout << "姓名：" << name << endl;
    cout << "地址：" << address << endl;
    cout << "邮编：" << postcode << endl;
    cout << "电话：" << tel << endl;

    cout << "----------" << endl;
}

int main() {

    AddrList A;
    
    A.AddRecord();
    A.ShowData();
    
    A.DeleteRecord();
    A.ShowData();
    
    getchar();
    return 0;
}

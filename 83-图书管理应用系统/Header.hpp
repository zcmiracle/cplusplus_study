//
//  Header.hpp
//  83-图书管理应用系统
//
//  Created by XFB on 2021/6/29.
//

#ifndef Header_hpp
#define Header_hpp

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MaxR = 1000;      // 最多只有1W人可以借书
const int MaxB = 100000;    // 最多可以存多少册书
const int MaxBook = 6;      // 每个人最多可以借多少本书


class Book {
public:
    Book() {
        
    }
    
    // Getter
    
    int getTag() {
        return tag;             // 获取删除标记
    }
    
    int getNo() {
        return no;              // 获取图书编号
    }
    
    char *getName() {
        return name;            // 获取书名
    }
    
    char *getAuthorName() {
        return author;          // 获取作者名
    }
    
    char *getClassification() {
        return classification;  // 获取分类
    }
    
    char *getPublisherName() {
        return publisher;       // 获取出版社
    }
    
    int getPublishTime() {      // 获取出版时间
        return publishTime;
    }

    // Setter
    
    void setName(char bookName[]) {
        strcpy(name, bookName);                             // 设置书名
    }
    
    void setAuthorName(char authorName[]) {
        strcpy(author, authorName);                         // 设置作者名
    }
    
    void setClassification(char classificationName[]) {
        strcpy(classification, classificationName);         // 设置分类
    }
    
    void setPublisher(char publisherName[]) {
        strcpy(publisher, publisherName);                   // 设置出版社
    }
    
    void setPublishTime(int time) {
        publishTime = time;                                 // 设置初版时间
    }
    
    void setPrice(double bookPirce) {
        price = bookPirce;                                  // 设置书籍价格
    }
    
    void setOnshelf(int onshelf) {
        onshelf = onshelf;                                  // 设置是否上架
    }
    
    
    // 删除书籍
    void deleteBook() {
        char i;
        cout << "你确定要删除此书吗？Y/N ？" << endl;
        cin >> i;
        if (i == 'y' || i == 'Y')  {
            tag = 1;
        }
    }
    
    // 添加or录入书籍
    void addBoook(int no, char* name, char* author, char* publisher, char* classification, int time, double price, int onshelf) {
        tag = 0;
        no = no;
        strcpy(name, name);
        strcpy(author, author);
        strcpy(publisher, publisher);
        strcpy(classification, classification);
        time = time;
        price = price;
        onshelf = onshelf;
    }
    
    // 借书
    int borrowBook() {
        if (onshelf > 0) {
            onshelf--;
            return 1;
        }
        return 0;
    }
    
    // 还书
    void retBook() {
        onshelf ++;
    }
    
    // 打印数据信息
    void display() {
        // setw(n) n的数值代表了打印后的空格数量
        cout << setw(3) << no << setw(10) << name;                  // 打印标号
        cout << setw(10) << author << setw(10) << classification;   //
        cout << setw(10) << price << setw(10) << publisher;         //
        cout << setw(10) << publishTime << setw(10) << onshelf;     //
    }
    
private:
    int tag;                    // 删除标记 0未删除 1删除
    int no;                     // 图书编号
    char name[50];              // 书名
    char author[20];            // 作者
    char classification[20];    // 分类
    char publisher[20];         // 出版社
    int publishTime;            // 出版时间
    double price;               // 书本价格
    int onshelf;                // 是否在架
};


// 图书管理系统维护、查找、删除功能
class BookDataBase {
    
public:
    BookDataBase() {        // 构造函数 将bookData.txt读到book[]中
        Book b;
        top = -1;
        fstream file("bookData.txt", ios::in);  // 读取书籍
        while (true) {
            file.read((char *)&b, sizeof(b));
            if (!file) {
                break;
            }
            top++;
            book[top] = b;
        }
        file.close();
    }
    
    ~BookDataBase() {       // 析构函数,将bookp[]写到bookdata.txt文件中
        fstream file("bookData.txt", ios::out);
        for (int i = 0; i <= top; i ++) {
            if (book[i].getTag() == 0) {    // 0未删除(写入) 1删除
                file.write((char *)&book[i], sizeof(book[i]));
            }
        }
        file.close();
    }
    
    // 全部删除
    void Clear() {
        char i;
        cout << "确认是否要删除全部的图书！Y/N ?" << endl;
        cin >> i;
        if (i == 'Y' || i == 'y') {
            top = -1;
        }
    }
    
    // 添加图书信息
    int addBook(int no, char* name, char* author, char* classification, char* publisher, int time, double price, int onshelf) {
        
        Book *p = Query1(no);
        if (p == NULL) {
            top ++;
            book[top].addBoook(no, name, author, publisher, classification, time, price, onshelf);
            return 1;;
        }
        return 0;
    }
    
    
    // 根据编号查找图书
    Book *Query1(int bookid) {
        for (int i = 0; i <= top; i ++) {
            if (book[i].getNo() == bookid && book[i].getTag() == 0) {
                return &book[i];
            }
        }
        return NULL;
    }
        
    
    // 根据书名查找
    Book *query2(char a[]) {
        Book *e;
        int r = 0;
        for (int i = 0; i <= top; i ++) {
            if (strcmp(book[i].getName(), a) == 0 && book[i].getTag() == 0) {
                if (r == 0) {
                    cout << setw(3) << "编号" << setw(10) << "书名";
                    cout << setw(10) << "作者" << setw(10) << "分类";
                    cout << setw(10) << "价格" << setw(10) << "出版社";
                    cout << setw(10) << "出版时间" << setw(10) << "库存量";
                }
                
                e = &book[i];
                e->display();
                r++;
            }
            
            if (r == 0) {
                cout << "找不到该书!" << endl;
            }
        }
        return NULL; // return 0;
    }
    
    // 按照作者名查找书籍
    Book *query3(char a[]) {
        Book *e;
        int r = 0;
        for (int i = 0; i <= top; i ++) {
            if (strcmp(book[i].getAuthorName(), a) == 0 && book[i].getTag() == 0) {
                if (r == 0) {
                    cout << setw(3) << "编号" << setw(10) << "书名";
                    cout << setw(10) << "作者" << setw(10) << "分类";
                    cout << setw(10) << "价格" << setw(10) << "出版社";
                    cout << setw(10) << "出版时间" << setw(10) << "库存量";
                }
                e = &book[i];
                e->display();
                r++;
            }
            if (r == 0) {
                cout << "找不到该书!" << endl;
            }
        }
        return NULL; // return 0; 因为NULL是宏 == 0
    }
    
    // 按照出版社查找
    Book *query4(char a[]) {
        Book *e;
        int r = 0;
        for (int i = 0; i <= top; i ++) {
            if (strcmp(book[i].getPublisherName(), a) == 0 && book[i].getTag() == 0) {
                if (r == 0) {
                    cout << setw(3) << "编号" << setw(10) << "书名";
                    cout << setw(10) << "作者" << setw(10) << "分类";
                    cout << setw(10) << "价格" << setw(10) << "出版社";
                    cout << setw(10) << "出版时间" << setw(10) << "库存量";
                }
                e = &book[i];
                e->display();
                r ++;
            }
            if (r == 0) {
                cout << "找不到该书!" << endl;
            }
        }
        return NULL; // return 0; 因为NULL是宏 == 0
    }
    
    // 显示书籍信息
    void display() {
        for (int i = 0; i <= top; i ++) {
            if (book[i].getTag() == 0) {
                book[i].display();
            }
        }
    }
    
    // 成员函数声明
    void bookData();    // 图书库的实际信息
    
    
    
    
private:
    int top;                // 图书记录的指针
    Book book[MaxB];        // 存书的记录量
    
    
    
};


// 成员函数实现
void BookDataBase::bookData() {
    
    char choice3 = 0;
    char book_name[50];
    char author_name[50];
    char book_classification[50];
    char book_publisher[50];
    int publish_time;
    double book_price;
    char ch;
    int choice4;
    int bookid;
    int bookod; // 书籍数量
    
    Book *b;
    
    while (choice3 != '0') {
        cout << "==============================================================" << endl;
        cout << "===                                                        ===" << endl;
        cout << "===                   图书管理系统：图书菜单模块                ===" << endl;
        cout << "===                                                        ===" << endl;
        cout << "==============================================================" << endl;
        cout << "===        1 增加图书       2 更改图书      3 删除图书          ===" << endl;
        cout << "===        4 查询图书       5 显示图书      6 清空图书          ===" << endl;
        cout << "===        0 返回上一级目录                                   ===" << endl;
        cout << "===                                                        ===" << endl;
        cout << "==============================================================" << endl;
        cout << "==============================================================" << endl;
        cout << "请选择操作项[0-6]:";
        cin >> choice3;
        
        switch (choice3) {
            case '1':   // 添加图书
                cout << "请输入图书编号:";
                cin >> bookid;
                
                b = Query1(bookid);
                if (b != NULL) {
                    cout << "该编号已存在，无法添加此书" << endl;
                    break;
                }
                cout << "请输入新书的书名：";
                cin >> book_name;
                
                cout << "请输入新书的作者名称：";
                cin >> author_name;
                
                cout << "请输入新书的分类：";
                cin >> book_classification;
                
                cout << "请输入新书的出版社：";
                cin >> book_publisher;
                
                cout << "请输入新书的出版时间：";
                cin >> publish_time;
                
                cout << "请输入新书的价格：";
                cin >> book_price;
                
                cout << "请输入新书的数量：";
                cin >> bookod;
                
                // 将用户从键盘上输入的书籍信息，通过调用添加图书信息函数作为实参传递给形参
                // 录入书籍
                addBook(bookid, book_name, author_name, book_classification, book_publisher, publish_time, book_price, bookod);
                
                // 数据的保存
                char choice2;
                
                {
                    cout << "==============================================================" << endl;
                    cout << "===                                                        ===" << endl;
                    cout << "===                是否保存录入的书籍信息到本地文件              ===" << endl;
                    cout << "===                                                        ===" << endl;
                    cout << "==============================================================" << endl;
                    cout << "===                                                        ===" << endl;
                    cout << "===                【1 Y 保存】    【0 N 取消】               ===" << endl;
                    cout << "===                                                        ===" << endl;
                    cout << "==============================================================" << endl;
                    cout << "请选择操作项[0-1]:";
                    cin >> choice2;
                    switch (choice2) {
                        case '1':
                            cout << "====================================================" << endl;
                            cout << "===                                              ===" << endl;
                            cout << "===                 图书信息添加成功                ===" << endl;
                            cout << "===                                              ===" << endl;
                            cout << "====================================================" << endl;
                            break;
                        case '0':
                            break;
                    }
                }
                
                getchar();
                break;
                
            case '2':   // 修改图书
                cout << "请输入图书信息的编号:";
                cin >> bookid;
                b = Query1(bookid);
                if (b == NULL) {
                    cout << "此书不存在，请重新检查" << endl;
                    break;
                }
                
                cout << "该书籍的信息如下：" << endl;
                cout << setw(3) << "编号" << setw(10) << "书名";
                cout << setw(10) << "作者" << setw(10) << "分类";
                cout << setw(10) << "价格" << setw(10) << "出版社";
                cout << setw(10) << "出版时间" << setw(10) << "库存量";
                
                // 打印书籍信息
                b->display();
                
                cout << "请问你是否需要更新图书信息？" << endl;
                cin >> ch;
                
                if (ch == 'y' || ch == 'Y') {
                    int a;
                    cout << "==============================================================" << endl;
                    cout << "===                                                        ===" << endl;
                    cout << "===                   图书管理系统：图书菜单模块                ===" << endl;
                    cout << "===                                                        ===" << endl;
                    cout << "==============================================================" << endl;
                    cout << "===        1 修改书名       2 修改作者      3 修改分类          ===" << endl;
                    cout << "===        4 修改出版社     5 修改出版时间   6 修改价格          ===" << endl;
                    cout << "===        7 修改图书信息    0 返回上级目录                     ===" << endl;
                    cout << "===                                                        ===" << endl;
                    cout << "==============================================================" << endl;
                    cout << "==============================================================" << endl;
                    cout << "请选择操作项[0-7]:";
                    
                    cin >> a;
                    switch (a) {
                        case '1':
                            cout << "请输入新书的书名:";
                            cin >> book_name;
                            b->setName(book_name);
                            break;
                        case '2':
                            cout << "请输入新书的作者:";
                            cin >> author_name;
                            b->setAuthorName(author_name);
                            break;
                        case '3':
                            cout << "请输入新书分类:";
                            cin >> book_classification;
                            b->setClassification(book_classification);
                            break;
                        case '4':
                            cout << "请输入新书的出版社:";
                            cin >> book_publisher;
                            b->setPublisher(book_publisher);
                            break;
                        case '5':
                            cout << "请输入新书的出版时间:";
                            cin >> publish_time;
                            b->setPublishTime(publish_time);
                            break;
                        case '6':
                            cout << "请输入新书的价格:";
                            cin >> book_price;
                            b->setPrice(book_price);
                            break;
                        case '7':
                            cout << "请输入新书的存量:";
                            cin >> bookod;
                            b->setOnshelf(bookod);
                            break;
                        case '0':
                            break;

                    }
                }
                
                cout << "====================================================" << endl;
                cout << "===                                              ===" << endl;
                cout << "===                 图书信息修改成功                ===" << endl;
                cout << "===                                              ===" << endl;
                cout << "====================================================" << endl;
                getchar();
                break;
                
            case '3':   // 删除图书
                cout << "请输入图书信息的编号:";
                cin >> bookid;
                b = Query1(bookid);
                if (b == NULL) {
                    cout << "此书不存在，请重新检查" << endl;
                    break;
                }
                // 删除图书
                b->deleteBook();
                
                cout << "====================================================" << endl;
                cout << "===                                              ===" << endl;
                cout << "===                 图书信息删除成功                ===" << endl;
                cout << "===                                              ===" << endl;
                cout << "====================================================" << endl;
                
                getchar();
                break;
                
            case '4':
                
                cout << "====================================================" << endl;
                cout << "===                                              ===" << endl;
                cout << "===                1 根据编号进行查询               ===" << endl;
                cout << "===                2 根据书名进行查询               ===" << endl;
                cout << "===                3 根据作者名进行查询             ===" << endl;
                cout << "===                4 根据作者名进行查询             ===" << endl;
                cout << "===                0 返回上级目录                  ===" << endl;
                cout << "===                                              ===" << endl;
                cout << "====================================================" << endl;
                
                cout << "请选择操作项[0-4]:";
                cin >> choice4;
                switch (choice4) {
                    case 1: // 1 根据编号进行查询
                        cout << "请输入图书编号:";
                        cin >> bookid;
                        b = Query1(bookid);
                        if (b == NULL) {
                            cout << "该图书不存在!" << endl;
                            break;
                        }
                        
                        cout << "该书籍的信息如下：" << endl;
                        cout << setw(3) << "编号" << setw(10) << "书名";
                        cout << setw(10) << "作者" << setw(10) << "分类";
                        cout << setw(10) << "价格" << setw(10) << "出版社";
                        cout << setw(10) << "出版时间" << setw(10) << "库存量";
                        
                        b->display();
                        break;
                        
                    case 2 : // 2 根据书名进行查询
                        cout << "请输入图书名:";
                        cin >> book_name;
                        b = query2(book_name);
                        if (b == NULL) {
                            cout << "该图书不存在!" << endl;
                            break;
                        }
                        cout << "该书籍的信息如下：" << endl;
                        cout << setw(3) << "编号" << setw(10) << "书名";
                        cout << setw(10) << "作者" << setw(10) << "分类";
                        cout << setw(10) << "价格" << setw(10) << "出版社";
                        cout << setw(10) << "出版时间" << setw(10) << "库存量";
                        
                        b->display();
                        break;
                        
                    case 3: // 3 根据作者名进行查询
                        cout << "请输入图书作者:";
                        cin >> author_name;
                        b = query3(author_name);
                        if (b == NULL) {
                            cout << "该图书不存在!" << endl;
                        }
                        
                        cout << "该书籍的信息如下：" << endl;
                        cout << setw(3) << "编号" << setw(10) << "书名";
                        cout << setw(10) << "作者" << setw(10) << "分类";
                        cout << setw(10) << "价格" << setw(10) << "出版社";
                        cout << setw(10) << "出版时间" << setw(10) << "库存量";
                        
                        b->display();
                        break;

                    case 4: // 4 根据作者名进行查询
                        cout << "请输入图书出版社:";
                        cin >> book_publisher;
                        b = query4(book_publisher);
                        if (b == NULL) {
                            cout << "该图书不存在!" << endl;
                        }
                        
                        cout << "该书籍的信息如下：" << endl;
                        cout << setw(3) << "编号" << setw(10) << "书名";
                        cout << setw(10) << "作者" << setw(10) << "分类";
                        cout << setw(10) << "价格" << setw(10) << "出版社";
                        cout << setw(10) << "出版时间" << setw(10) << "库存量";
                        
                        b->display();
                        break;
                    case 0: // 0 返回上级目录
                        break;
                    default:
                        break;
                }
                break;
                
            case '5':   // 显示图书
                cout << setw(3) << "编号" << setw(10) << "书名";
                cout << setw(10) << "作者" << setw(10) << "分类";
                cout << setw(10) << "价格" << setw(10) << "出版社";
                cout << setw(10) << "出版时间" << setw(10) << "库存量";
                
                display();
                getchar();
                break;

            case '6':   // 清空图书
                Clear();
                break;
            default:
                break;
        }
    }
    
}


// 读者类

class Reader {
  
public:
    Reader() {
        
    }
    
    // ostream 文件输出
    friend ostream &operator << (ostream &output, Reader &reader) {
        output << reader.no;
        output << " ";
        output << endl;
        return output;
    }
    
//    char *getname() // 获取读者姓名
    
private:
    int tag;                    // 删除标记
    int no;                     // 读者编号
    char name[40];              // 读者姓名
    int borbook[MaxBook];       // 所借书籍

};




// 读者库类








#endif /* Header_hpp */

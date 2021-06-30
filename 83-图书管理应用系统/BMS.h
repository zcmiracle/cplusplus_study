//
//  BMS.h
//  cplusplus_study
//
//  Created by XFB on 2021/6/30.
//

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
    char *setName(char bookName[]) {
        strcpy(name, bookName);                             // 设置书名
        return bookName;
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
    
    void setOnshelf(int ons) {
        onshelf = ons;                                      // 设置是否上架
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
    void addBoook(int book_no, char* book_name, char* book_author, char* book_publisher, char* book_classification, int book_time, double book_price, int book_onshelf) {
        this->tag = 0;
        no = book_no;
        strcpy(name, book_name);
        strcpy(author, book_author);
        strcpy(publisher, book_publisher);
        strcpy(classification, book_classification);
        publishTime = book_time;
        price = book_price;
        onshelf = book_onshelf;
        
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
            return 1;
        }
        return 0;
    }
    
    
    // 根据编号查找图书
    Book *Query1(int bookid) {
        for (int i = 0; i <= top; i ++) {
            if (book[i].getNo() == bookid && (book[i].getTag() == 0)) {
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
            if (strcmp(book[i].getName(), a) == 0 && (book[i].getTag() == 0)) {
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
            if (strcmp(book[i].getAuthorName(), a) == 0 && (book[i].getTag() == 0)) {
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
            if (strcmp(book[i].getPublisherName(), a) == 0 && (book[i].getTag() == 0)) {
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
    // ostream 文件输出
    friend ostream &operator << (ostream &output, Reader &reader) {
        output << reader.no;
        output << " ";
        output << endl;
        return output;
    }
    
    // 获取读者姓名
    char *getname() {
        return name;
    }
    
    // 获取读者标记
    int gettag() {
        return tag;
    }
    
    // 获取读者编号
    int getno() {
        return no;
    }
    
    // 设置读者姓名
    void setname(char na[]) {
        strcpy(name, na);
    }
    
    // 设置删除标记
    void setDeleteBookName() {
        char i;
        cout << "你确定要删除吗？ Y/N ?" << endl;
        cin >> i;
        if (i == 'y' || i == 'Y') {
            tag = 1;
        }
    }
    
    // 增加读者信息记录
    void addReader(int readerNo, char *readerName) {
        tag = 0;
        no = readerNo;
        strcpy(name, readerName);
        
        for (int i = 0; i < MaxBook; i ++) {
            borbook[i] = 0;
        }
    }
    
    // 读者借书操作
    void borrowBook(int bookid) {
        for (int i = 0; i < MaxBook; i ++) {
            if (borbook[i] == 0) {
                borbook[i] = bookid;
                return;
            }
        }
    }
     
    // 还书的操作
    int retBook(int bookid) {
        for (int i = 0; i < MaxBook; i ++) {
            if (borbook[i] == bookid) {
                borbook[i] = 0; // 此书的借书标记为0
                cout << "还书成功" << endl;
                return 1;
            }
        }
        cout << "此书未借出，还书失败!" << endl;
        return 0;
    }
    
    // 读出读者信息
    void display() {
        int hava = 0;           //
        int bz = 0;             //
        cout << setw(5) << no << setw(21) << name << setw(15);
        
        for (int i = 0; i < MaxBook; i ++) {
            if (borbook[i] != 0) { // 有借书
                if (bz == 0) {
                    hava = 1;
                    cout << "[" << borbook[i] << "]\t\t" << endl;
                    bz ++;
                } else {
                    cout << "\r\t\t\t\t\t""[" << borbook[i] << "]\t\t" << setw(15) << endl;
                }
            }
        }
        
        if (hava == 0) { // 还未借书
            cout << "\t  还未借书" << endl;
        }
    }
    
private:
    int tag;                    // 删除标记 1删除 0不删除
    int no;                     // 读者编号
    char name[40];              // 读者姓名
    int borbook[MaxBook];       // 所借书籍
};


// 读者库类，建立读者的个人借阅资料信息
class ReaderDataBase {
public:
    ReaderDataBase() {  // 构造函数，将reader.text读到read()中
        Reader reader;
        top = -1;
        // 操作文件和读取 ios::in
        fstream file("reader.txt", ios::in); // 打开一个而输入文件
        while(1) {
            // 读取
            file.read((char *)&reader, sizeof(reader));
            if (!file)  break;
            top ++;
            read[top] = reader;
        }
        file.close();   // 关闭 reader.txt 文件
    }
    
    ~ReaderDataBase() { // 析构函数 把read[] 记录写到 reader.txt文件当中
        // 写入文件 ios::out
        fstream file("reader.txt", ios::out); // 打开一个而输入文件
        for (int i = 0; i <= top; i ++) {
            if (read[i].gettag() == 0) {
                file.write((char *)&read[i], sizeof(read[i]));
            }
        }
        file.close();   // 关闭 reader.txt 文件
    }
    
    // 删除所有读者信息
    void clear() {
        char i;
        cout << "您确定要全部删除吗？Y/N ?" << endl;
        cin >> i;
        if (i == 'y' || i == 'Y') {
            top = -1;
        }
    }
    
    // 添加读者时 先查找是否存在
    int addReader(int readerNo, char *readerName) {
        Reader *p = queryID(readerNo);
        if (p == NULL) {
            top ++;
            read[top].addReader(readerNo, readerName);
            return 1;
        } else {
            cout << "该编号已存在!";
        }
        return 0;
    }
    
    // 按找读者编号查找读者
    Reader *queryID(int readerID) {
        for (int i = 0; i <= top; i ++) {
            if (read[i].getno() == readerID && (read[i].gettag() == 0)) {
                return &read[i];
            }
        }
        return NULL;
    }
    
    // 按找读者姓名查找读者
    Reader *queryName(char readerName[20]) {
        for (int i = 0; i <= top; i ++) {
            if (strcmp(read[i].getname(), readerName) == 0 && (read[i].gettag() == 0)) {
                return &read[i];
            }
        }
        return NULL;
    }
    
    // 输出所有读者信息
    void display() {
        for (int i = 0; i <= top; i++) {
            if (read[i].gettag() == 0) {
                read[i].display();
            }
        }
    }
    
    // 读者库信息
    void readerData();
    
private:
    int top;            // 读者记录指针
    Reader read[MaxR];  // 读者记录
};


// 类的实现
void ReaderDataBase::readerData() {
    
    char choice1 = 0;
    char reader_name[30];   // 读者名字
    int reader_id;
    char readMessage[20];   // 读信息名字
    
    int choice2;
 
    Reader *reader;
    while (choice1 != '0') {
        cout << "==============================================================" << endl;
        cout << "===                                                        ===" << endl;
        cout << "===                   图书管理系统：读者菜单模块                ===" << endl;
        cout << "===                                                        ===" << endl;
        cout << "==============================================================" << endl;
        cout << "===        1 增加数据       2 更改数据      3 删除数据          ===" << endl;
        cout << "===        4 查询数据       5 显示数据      6 清空数据          ===" << endl;
        cout << "===        0 返回上一级目录                                   ===" << endl;
        cout << "===                                                        ===" << endl;
        cout << "==============================================================" << endl;
        cout << "==============================================================" << endl;
        cout << "请选择操作项[0-6]:";
        cin >> choice1;
        
        switch (choice1) {
            case '1':
                cout << "请输入读者编号：";
                cin >> reader_id;
                
                cout << "请输入读者姓名：";
                cin >> reader_name;
                addReader(reader_id, reader_name);
                cout << "添加读者信息成功" << endl;
                getchar();
                break;
                
            case '2':
                cout << "请输入读者编号：";
                cin >> reader_id;
                reader = queryID(reader_id);
                if (reader == NULL) {
                    cout << "该读者不存在!" << endl;
                    break;
                }
                
                cout << "请输入读者姓名：";
                cin >> reader_name;
                reader->setname(reader_name);
                cout << "修改读者信息成功" << endl;
                getchar();
                break;
                
            case '3':
                cout << "请输入读者编号：";
                cin >> reader_id;
                reader = queryID(reader_id);
                if (reader == NULL) {
                    cout << "该读者不存在!" << endl;
                    break;
                }
                
                // 删除数据
                reader->setDeleteBookName();
                cout << "删除成功！" << endl;
                getchar();
                break;
                
            case '4':
                cout << "===================================================" << endl;
                cout << "===                                             ===" << endl;
                cout << "===                1 按读者编号查找                ===" << endl;
                cout << "===                2 按读者姓名查找                ===" << endl;
                cout << "===                0 返回上级目录                  ===" << endl;
                cout << "===                                              ===" << endl;
                cout << "===================================================" << endl;
                cout << "请选择操作项[0-2]:";
                cin >> choice2;
                
                switch (choice2) {
                    case '1':
                        cout << "请输入读者编号：";
                        cin >> reader_id;
                        
                        reader = queryID(reader_id);
                        if (reader == NULL) {
                            cout << "该读者不存在!" << endl;
                            break;
                        }
                        cout << setw(10) << "读者编号" << setw(17) << setw(20) << "已借书籍编号" << endl;
                        // 打印信息
                        reader->display();
                        break;
                    case '2':
                        cout << "请输入读者姓名：";
                        cin >> reader_name;
                        
                        reader = queryName(reader_name);
                        if (reader == NULL) {
                            cout << "该读者不存在!" << endl;
                            break;
                        }
                        cout << setw(10) << "读者姓名" << setw(17) << setw(20) << "已借书籍编号" << endl;
                        // 打印信息
                        reader->display();
                        break;
                    case '0':
                        break;
                    default:
                        break;
                }
                break;
            case '5':
                cout << setw(10) << "读者姓名" << setw(17) << setw(20) << "已借书籍编号" << endl;
                display();
                
                getchar();
                break;
            case '6':
                clear();
                cout << "成功删除所有数据" << endl;
                break;
            case '0':
                break;
            default:
                break;
        }
    }
    
}


// 实现程序的主界面
class mainDesk {
  
public:
    // 登录
    int Login() {
        int k = 0;
        
        cout << "===================================================" << endl;
        cout << "===                                             ===" << endl;
        cout << "===                                             ===" << endl;
        cout << "===             高校图书信息管理应用系统             ===" << endl;
        cout << "===                                             ===" << endl;
        cout << "===                                             ===" << endl;
        cout << "===================================================" << endl;
        cout << "===                                             ===" << endl;
        cout << "===              开发日期：2021-06-30             ===" << endl;
        cout << "===                                             ===" << endl;
        cout << "===================================================" << endl;
        
        while (choice2 != '0') {
            ++k;
            
            cout << "===================================================" << endl;
            cout << "===                                             ===" << endl;
            cout << "===            1 登录系统    2 退出系统            ===" << endl;
            cout << "===                                             ===" << endl;
            cout << "===================================================" << endl;
            cout << "请选择操作项[1-2]:";
            cin >> choice2;
            
            switch (choice2) {
                case '1':
                    cout << "请输入学号和密码" << endl;
                    cin >> xh >> mm;
                    
                    if (xh >= 123 && (xh <= 123) && (xh == mm)) {
                        cout << "登录成功" << endl;
                        // 进去主菜单
                        enterDesk();
                    }
                    
                    if (xh < 123321 || (xh > 123321) || xh != mm) {
                        cout << "登录失败，您还有" << 3-k << "次登录机会" << endl;
                        
                        if (k >= 3) {
                            cout << "输入错误次数操作2次，程序自动退出!" << endl;
                            return 1;
                        }
                        continue;
                    }
                    break;
                    
                case '2':
                    break;
            }

            return 1;
        }
        return 0;
    }
    
    // 主界面函数
    void enterDesk() {
        while (choice5 != '0') {
            
            cout << "================================================" << endl;
            cout << "===                                          ===" << endl;
            cout << "===           普通高校图书系统管理菜单            ===" << endl;
            cout << "===                                          ===" << endl;
            cout << "================================================" << endl;
            cout << "===         1 图书信息       2 读者信息         ===" << endl;
            cout << "===         3 借阅图书       4 归还图书         ===" << endl;
            cout << "===         0 退出系统                         ===" << endl;
            cout << "===                                          ===" << endl;
            cout << "================================================" << endl;
            cout << "================================================" << endl;
            cout << "请选择操作项[0-5]:";
            
            cin >> choice5;
            
            switch (choice5) {
                case '1':
                    bookDB->bookData();         // 显示图书库信息
                    break;
                case '2':
                    ReaderDB.readerData();      // 显示读者库信息
                    break;
                case '3':
                    cout << "   借书操作" << endl;
                    cout << "请输入借书读者的编号:";
                    cin >> readerid;
                    
                    reader = ReaderDB.queryID(readerid);
                    if (reader == NULL) {
                        cout << "该读者不存在!" << endl;
                        break;
                    }
                    
                    cout << "请输入要借图书的编号:";
                    cin >> bookid;
                    
                    book = bookDB->Query1(bookid);
                    if (book == NULL) {
                        cout << "该图书不存在" << endl;
                        break;
                    }
                    
                    if (book->borrowBook() == 0) {
                        cout << "改图书已借出，无法借阅" << endl;
                        break;
                    }
                    
                    cout << "读者借书成功！" << endl;
                    reader->borrowBook(book->getNo());
    
                    break;
                case '4':
                    
                    cout << "    还书操作" << endl;
                    cout << "请输入还书读者编号：";
                    cin >> readerid;
                    
                    reader = ReaderDB.queryID(readerid);
                    if (reader == NULL) {
                        cout << "不存在该读者，不能借书" << endl;
                        break;
                    }
                    
                    cout << "请输入要归还的图书编号:";
                    cin >> bookid;
                    
                    book = bookDB->Query1(bookid);
                    
                    if (book == NULL) {
                        cout << "该图书不存在，不能还书" << endl;
                        break;
                    }
                    
                    book->retBook();                // 还书操作
                    reader->retBook(book->getNo()); // 获取图书编号
                    break;
                case '0':
                    break;
            }
        }
    }
    
    
private:
    char choice5;
    char choice2;
    double xh;  // 学号
    double mm;  // 密码
    int bookid;
    int readerid;
    
    ReaderDataBase ReaderDB;
    Reader *reader;
    BookDataBase *bookDB;
    Book *book;
};

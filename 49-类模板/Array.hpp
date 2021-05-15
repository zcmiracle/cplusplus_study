//
//  Array.hpp
//  49-类模板
//
//  Created by XFB on 2021/5/14.
//

#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

template <typename Item>
//No candidate function template was found for dependent friend function template specialization

class Array {
    // 友元函数
//    friend ostream &operator<<<>(ostream&, const Array<Item>&);
    // 用于指向首元素
    Item *m_data;
    // 元素个数 初始化为0
    int m_size = 0;
    // 容量
    int m_capacity;
    // 检查索引是否正确
    void checkIndex(int index);
    
public:
    Array(int capacity = 0); // 构造函数
    Array(const Array &array); // 拷贝构造函数
    ~Array(); // 析构函数
    void setData(int index, Item value); // 赋值
    void add(Item value); // 添加
    void remove(int index); // 移除
    void insert(int index, Item value); // 插入
    Item get(int index); // 获取索引值
    int size();
    
    // 此处有点点问题
    Item operator[](int index); // 运算符重载[]
};

template <typename Item>
void Array<Item>::checkIndex(int index) {
//    if (index < 0 || index >= m_size) {
//        throw  "数组下标越界";
//    }
    if (index < 0 || index >= m_size) {
        cout << "\nError index = " << index << " out_of_range" <<endl;
        exit(1);
    }
}

// 构造函数
template <typename Item>
Array<Item>::Array(int capacity) {
    m_capacity = (capacity > 0) ? capacity : 10;
    // 申请堆空间
    m_data = new Item[capacity];
}

// 拷贝构造函数
template <typename Item>
Array<Item>::Array(const Array &array) {
    m_size = array.m_size;
    m_capacity = new int[array.m_size];
    for (int i = 0; i < array.m_size; i ++) {
        m_data[i] = array.m_data[i];
    }
}

// 析构函数
template <typename Item>
Array<Item>::~Array() {
    if (m_data == NULL) return;
    delete[] m_data;
}

// 赋值
template <typename Item>
void Array<Item>::setData(int index, Item value) {
    if (index < 0 || index >= m_size) {
        // 抛出异常
        throw "数组下标越界";
    }
    m_data[index] = value;
}

// 添加
template <typename Item>
void Array<Item>::add(Item value) {
    if (m_size == m_capacity) {
        // 扩容操作
        // 1、申请一块更大的堆空间
        // 2、讲旧空间的数据拷贝到新空间
        // 3、释放旧空间
        cout << "空间不够" << endl;
    }
    m_data[m_size++] = value;
}

template <typename Item>
void Array<Item>::remove(int index) {
    checkIndex(index);
}

template <typename Item>
void Array<Item>::insert(int index, Item value) {
    
}

// 获取索引值
template <typename Item>
Item Array<Item>::get(int index) {
//    if (index < 0 || index >= m_size) {
//        // 抛出异常
//        throw "数组下标越界";
//    }
    checkIndex(index);
    return m_data[index];
}

template <typename Item>
int Array<Item>::size() {
    return m_size;
}

template <typename Item>
Item Array<Item>::operator[](int index) {
    if (index < 0 || index >= m_size) {
        cout << "\nError index = " << index << " out_of_range" <<endl;
        exit(1);
    }
    return get(index);
}

//template <typename Item>
//// 友元函数有泛型 加上 <>
//ostream &operator<<<>(ostream& cout, const Array<Item>& array) {
//    cout << "[";
//    for (int i = 0; i < array.m_size; i ++) {
//        if (i != 0) {
//            cout << ",";
//        }
//        cout << array.m_data[i];
//    }
//    return cout << "]";
//}

#endif /* Array_hpp */

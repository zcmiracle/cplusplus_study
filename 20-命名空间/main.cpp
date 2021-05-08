//
//  main.cpp
//  20-命名空间
//
//  Created by XFB on 2021/5/8.
//

#include <iostream>
//using namespace std;

/**
 命名空间 可以用来避免命名冲突
 命名空间 不影响内存布局
 命名空间可以嵌套
 有个默认的全局命名空间，我们创建的命名空间默认都嵌套在它里面，是没有名字的
 命名空间的合并，可以写多次
 */

namespace TES {
    int g_age;
}

namespace TES {
    int g_height;
}

//// 等价于
//namespace TES {
//    int g_age;
//    int g_height;
//}


void func() {
    std::cout << "func()" << std::endl;
}

namespace FUNC {
    void func() {
        std::cout << "FUNC::func()" << std::endl;
    }
}


namespace OC {
    namespace SWIFT {
        int g_value;
    };
}


namespace CPlus1 {
    int g_num;
}

namespace CPlus2 {
    int g_num;
}


// Redefinition of 'Person'
class Person {
    int m_height;
};

namespace ZC {
    class Person {
        int m_age;
        int m_money;
    };
}

namespace LM {
    // 全局变量
    int g_age;
    
    void func() {
    
    }

    class Person {
        int m_age;
        int m_money;
    };

}


int main() {

//    ZC::Person person;
//    Person person;
//    std::cout << sizeof(person) << std::endl;
    
//    using namespace LM;
//    g_age = 10;
    
    using LM::g_age;
    g_age = 10;
    
    // 错误
//    func();
    
    using namespace CPlus1;
    using namespace CPlus2;

    // 有二义性
    // Reference to 'g_num' is ambiguous
//    g_num = 10;
    
    OC::SWIFT::g_value = 10;
    
    using namespace OC::SWIFT;
    g_value = 20;
    
    using OC::SWIFT::g_value;
    g_value = 30;
    
    
    using namespace FUNC;
    FUNC::func();
    
    // 默认有一个全局的命名空间，没有名字
    ::func();
    
    
    // 先找到全局的命名空间然后找到FUNC然后找到func() 调用
    ::FUNC::func();
    
    
    using namespace TES;
    g_age = 10;
    g_height = 20;
    
    getchar();
    return 0;
}

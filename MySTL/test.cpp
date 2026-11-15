#include <iostream>
#include "ArraryIterator.h" // 确保你的头文件名对得上
#include"List.h"
#include"ListIterator.h"
#include"vector.h"
#include<cstring>
using namespace mystl;

int main() {
    mystl::vector<std::string> dp; // 注意是 mystl

    try {
        std::cout << dp[0]; // 这一句会触发 throw
    }
    catch (const mystl::out_of_range& e) {
        std::cout << "成功拦截报错: " << e.what() << std::endl;
    }

    return 0;
}
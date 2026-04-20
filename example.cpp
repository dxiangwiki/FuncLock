#include <iostream>
#include "funclock.h"

moudle<void()> m("print_lock");

void print() {
    if (m.canUse()) {
        std::cout << "Hello" << std::endl;
    }
}

// 全局自动执行上锁
auto ___ = m.bind(print, [](auto c) {
    c();
    c();
    std::cout << "-" << std::endl;
    c();
});

int main() {
    // 外部调用全部无效
    print();
    print();
    print();
    print();

    // 查看锁状态
    std::cout << "Locked: " << ___ << std::endl;
    return 0;
}
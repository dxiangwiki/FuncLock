#ifndef FUNCLOCK_H
#define FUNCLOCK_H

#include <string>
#include <functional>
#include <iostream>

template<typename Func, typename... Args>
class moudle {
private:
    const std::string tar;
    std::string state = "default";

    std::string safe_target(const std::string& target) {
        if (target == "default") {
            return "default!";
        }
        return target;
    }

public:
    moudle(const std::string& target)
        : tar(safe_target(target)) {}

    std::string bind(Func&& func, std::function<void(Func)> callback, Args&&... args) {
        if (state != tar) {
            callback(std::forward<Func>(func));
        }
        state = tar;
        return tar;
    }

    bool canUse() {
        return state != tar;
    }

    void debug() {
        std::cout << "[FuncLock Debug]" << std::endl;
        std::cout << "state  : " << state << std::endl;
        std::cout << "target : " << tar << std::endl;
    }
};

#endif
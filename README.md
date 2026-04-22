# FuncLock 🚀
A tiny, magical C++ function permission & freeze library  
轻量级 C++ 函数权限锁、冻结保护库，实现函数内部可控调用，外部彻底隔离。

## ✨ 核心特性
✅ 单文件无依赖：仅一个头文件，无需额外编译、无第三方依赖，直接引入即可使用  
✅ 自动上锁机制：全局绑定后自动生效，无需手动调用初始化，零侵入集成  
✅ 严格隔离保护：绑定后函数永久冻结，外部调用完全无效，比传统模块化隔离更严谨  
✅ 安全不可篡改：返回状态副本，外界仅可查看锁标识，无法修改内部状态  
✅ 调试友好：语义化字符串标记，自带 debug 接口，快速定位锁状态  
✅ 鲁棒性保障：自动处理 default 标识冲突，避免异常场景导致锁失效  

## 🔧 适用场景
- 保护内部工具函数，禁止外部非法调用  
- 接口权限控制，仅允许内部模块触发执行  
- 模块化开发中，实现函数私有化隔离  
- 轻量级安全防护，防止函数滥用导致的逻辑异常  

## 📌 核心原理
1. 初始化：通过 `moudle<FuncType>` 声明函数管理器，传入唯一标识  
2. 绑定：调用 `bind()` 方法，传入目标函数和内部执行逻辑，自动完成上锁  
3. 权限判断：函数内部通过 `canUse()` 校验权限，仅内部绑定逻辑可触发执行  
4. 状态隔离：返回标识字符串（副本），外界可查看锁状态，无法篡改内部逻辑  

## 🚀 快速使用
### 1. 引入头文件
```cpp
#include "funclock.h"
```

### 2. 声明函数管理器
```cpp
// 模板参数为目标函数类型，构造参数为唯一锁标识
moudle<void()> func_lock("print_lock");
```

### 3. 定义需要保护的函数
```cpp
void print() {
    // 必须通过 canUse() 校验权限
    if (func_lock.canUse()) {
        std::cout << "Hello FuncLock" << std::endl;
    }
}
```

### 4. 绑定内部执行逻辑（自动上锁）
```cpp
// 全局自动执行，绑定后函数永久冻结
auto ___ = func_lock.bind(print, [](auto c) {
    // 仅此处可调用目标函数
    c();
    c();
});
```

### 5. 外部调用（无效）
```cpp
int main() {
    print(); // 无效，不会执行
    print(); // 无效，不会执行
    return 0;
}
```

## 📋 调试接口
通过 `debug()` 方法查看锁状态，快速定位问题：
```cpp
func_lock.debug();
// 输出示例：
// [FuncLock Debug]
// state  : print_lock
// target : print_lock
```

## 👨‍💻 作者信息
- **Name**: 董翔  
- **GitHub**: [dxiangwiki](https://github.com/dxiangwiki)  
- **Email**: 3631247406@qq.com  

## 📄 开源协议
本项目采用 MIT 许可证，详见 LICENSE 文件，可自由使用、修改、分发，无需额外授权。

### end
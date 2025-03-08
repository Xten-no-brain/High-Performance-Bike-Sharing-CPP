# 核心功能
### 用户管理：注册、登录、验证等功能完整实现
### 单车管理：添加、删除、状态更新等操作
### 骑行记录：记录用户骑行轨迹、时间、费用等信息
### 故障报修：用户上报故障，系统记录并处理
### 广播通知：服务器向客户端广播单车状态更新

# 技术栈
### 编程语言：C++11
### 网络框架：libevent
### 数据库：MySQL
### 序列化：Protocol Buffers
### 日志系统：log4cpp
### 构建工具：CMake

# 目录结构
```
bike-sharing-system/
├── src/                  # 源代码目录
│   ├── config/           # 配置文件解析
│   ├── logger/           # 日志系统
│   ├── network/          # 网络通信模块
│   ├── service/          # 业务逻辑服务
│   ├── database/         # 数据库操作
│   └── main.cpp          # 主程序入口
├── include/              # 头文件
├── proto/                # Protocol Buffers定义
├── CMakeLists.txt        # 构建配置
└── README.md             # 项目说明
```

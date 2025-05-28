# cpp_project_study
学习cmake构建项目，googletest测试框架，以及算法编程等

## 学习使用cmake构建项目
* 基础cmake框架

## 编译方法
* Debug 版本
```shell
make all MODE=debug
```
* Release 版本（默认）
```shell
make all MODE=realse
```

## X11 配置问题
### 配置方法
* [X11 配置方法](https://www.cnblogs.com/SkyXZ/p/18687026)
 * 服务器配置 DISPLAY 的时候需要将 localhost 修改成本机的 ip
 ```shell
 export DISPLAY="ip:0.0"
 ```
 * 连接不上需要在 Xlaunch 中选择 `No access control`
* [VScode 配置调试方法](https://www.cnblogs.com/HeisenbergUncertainty/p/17629757.html)
### Can't open display:0.0
* 服务器 ping 不通本地电脑，关闭本地防火墙




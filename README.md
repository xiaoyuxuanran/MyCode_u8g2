# 这是一个U8G2移植成功的的demo
## 使用SSD1306 4针IIC协议 0.96寸oled
## 已解决 no serch file or xxxxx <driver/i2c.h>的问题，方法为在Cmake文件夹添加对应语句
## 效果为启动之后进入进度条读条，上面显示欢迎使用，读条完毕显示welcome，之后显示一个框，关于温度湿度和时分秒是直接写的固定的，可以修改进而从传感器读取实现动态显示
## 开发环境使用的是vscode+idf 部分时候使用的clion

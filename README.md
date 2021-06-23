# gamectl
这个项目需要配合另一个项目[gamePlAY](https://github.com/pojdd/gamePlAY)使用
## 介绍
这是运行在arduino上的被控端程序，使用串口与pc通讯，利用arduino模拟HID设备，例如鼠标和键盘，来控制主机端。

## 注意
+ 从控制的角度来说，这也是主机端。

+ 需要使用支持HID和串口的arduino版本。

+ 可以利用usb协议传输控制命令，这样应该可以免驱动。

## 最后
+ 这个程序没有更新的计划
+ 如果有可能，把串口通信改成usb协议通讯

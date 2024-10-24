## 使用方法

首先参照`硬件连接.png`将所需硬件连接(当然您还可以根据需要进行调整), 接着将`keil`工程烧录进PAJ7620U2模块; 随后运行Python脚本`monitor.py`, 您可能还需要根据实际情况修改串口号, 程序默认监听COM3串口; 然后就可以通过做出不同的手势来控制电脑的操作了, 目前支持以下几种手势 

| 识别结果 | 发送信号              | 执行操作     |
| ---- | ----------------- | -------- |
| 向上   | Up                | PageUp   |
| 向下   | Down              | PageDown |
| 向左   | Left              | Left     |
| 向右   | Right             | Right    |
| 顺时针  | Clockwise         | Down     |
| 逆时针  | Counter_Clockwise | Up       |
| 摇摆   | Wave              | SPACE    |



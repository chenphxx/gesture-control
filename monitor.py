import serial
import time
import win32con
import win32api


# 打开串口 配置串口参数
ser = serial.Serial('COM3', 9600, bytesize=serial.EIGHTBITS, parity=serial.PARITY_NONE, 
                    stopbits=serial.STOPBITS_ONE, xonxoff=False, rtscts=False, timeout=1)


# 上下手势对应了 PageDown和PageUp按键事件(考虑到用户的一般操作习惯)
# 左右手势对应了LEFT和RIGHT按键事件
# 顺逆时针对应了Down和Up按键事件
# 摇摆对应了SPACE按键事件

# 从串口接收数据 并模拟键盘按键事件
while 1:
    data = ser.readline().decode('utf-8').strip()
    if data == "Down":  # PageUp
        print("Received:", data)
        win32api.keybd_event(win32con.VK_PRIOR, 0, 0, 0)  # 按下PageUp键
        time.sleep(0.1)  # 等待一段时间
        win32api.keybd_event(win32con.VK_PRIOR, 0, win32con.KEYEVENTF_KEYUP, 0)  # 释放PageUp键
    elif data == "Up":  # PageDown
        print("Received:", data)
        win32api.keybd_event(win32con.VK_NEXT, 0, 0, 0)
        time.sleep(0.1)
        win32api.keybd_event(win32con.VK_NEXT, 0, win32con.KEYEVENTF_KEYUP, 0) 
    elif data == "Left":  # Left
        print("Received:", data)
        win32api.keybd_event(win32con.VK_LEFT, 0, 0, 0)
        time.sleep(0.1)
        win32api.keybd_event(win32con.VK_LEFT, 0, win32con.KEYEVENTF_KEYUP, 0)
    elif data == "Right":  # Right
        print("Received:", data)
        win32api.keybd_event(win32con.VK_RIGHT, 0, 0, 0)
        time.sleep(0.1)
        win32api.keybd_event(win32con.VK_RIGHT, 0, win32con.KEYEVENTF_KEYUP, 0)
    elif data == "Counter_Clockwise":  # DOWN
        print("Received:", data)
        win32api.keybd_event(win32con.VK_DOWN, 0, 0, 0)
        time.sleep(0.1)
        win32api.keybd_event(win32con.VK_DOWN, 0, win32con.KEYEVENTF_KEYUP, 0)
    elif data == "Clockwise":  # UP
        print("Received:", data)
        win32api.keybd_event(win32con.VK_UP, 0, 0, 0)
        time.sleep(0.1)
        win32api.keybd_event(win32con.VK_UP, 0, win32con.KEYEVENTF_KEYUP, 0)
    elif data == "Wave":  # SPACE
        print("Received:", data)
        win32api.keybd_event(win32con.VK_SPACE, 0, 0, 0)
        time.sleep(0.1)
        win32api.keybd_event(win32con.VK_SPACE, 0, win32con.KEYEVENTF_KEYUP, 0)


time.sleep(1)
# 关闭串口
ser.close()

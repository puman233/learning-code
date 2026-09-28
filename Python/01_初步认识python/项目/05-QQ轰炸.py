# import time
# from pynput import mouse, keyboard
#
# time.sleep(5)
# m_mouse = mouse.Controller()  # 创建一个鼠标
# m_keyboard = keyboard.Controller()  # 创建一个键盘
# m_mouse.position = (850, 670)  # 将鼠标移动到指定位置
# m_mouse.click(mouse.Button.left)  # 点击鼠标左键
# while True:
#     m_keyboard.type("""import time
# from pynput import mouse, keyboard
#
# time.sleep(5)
# m_mouse = mouse.Controller()
# m_keyboard = keyboard.Controller()
# m_mouse.position = (850, 670)
# m_mouse.click(mouse.Button.left)
# while True:
#     m_keyboard.type('')
#     m_keyboard.type('Coming Baby. The Bad VBS, The good Python!')
#     m_keyboard.press(keyboard.Key.enter)
#     m_keyboard.release(keyboard.Key.enter)
#     time.sleep(0.5)
#
# # Last thing last
# # Do you know it?????
# """)
#     m_keyboard.type('Coming Baby. The Bad VBS, The good Python!')  # 打字
#     m_keyboard.press(keyboard.Key.enter)  # 按下enter
#     m_keyboard.release(keyboard.Key.enter)  # 松开enter
#     time.sleep(0.5)  # 等待 0.5秒

import time
from pynput import mouse, keyboard

time.sleep(5)
m_mouse = mouse.Controller()  # 创建一个鼠标
m_keyboard = keyboard.Controller()  # 创建一个键盘
m_mouse.position = (850, 670)  # 将鼠标移动到指定位置
m_mouse.click(mouse.Button.left)  # 点击鼠标左键
a = 0
for a in range(1, 10):
    m_keyboard.type("""import time
from pynput import mouse, keyboard

time.sleep(5)
m_mouse = mouse.Controller()
m_keyboard = keyboard.Controller()
m_mouse.position = (850, 670)
m_mouse.click(mouse.Button.left)
while True:
    m_keyboard.type('')
    m_keyboard.type('Coming Baby. The Bad VBS, The good Python!')
    m_keyboard.press(keyboard.Key.enter)
    m_keyboard.release(keyboard.Key.enter)
    time.sleep(0.5)

# Last thing last
# Do you know it?????
# Or, are you pig???
""")
    m_keyboard.type("Coming Baby. Don't run it again. ")  # 打字
    m_keyboard.press(keyboard.Key.enter)  # 按下enter
    m_keyboard.release(keyboard.Key.enter)  # 松开enter
    time.sleep(0.8)  # 等待 0.8秒


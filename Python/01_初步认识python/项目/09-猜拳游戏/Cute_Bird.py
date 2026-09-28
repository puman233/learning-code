import time
import random

class MyClass:
    @staticmethod
    def main():
        # 生成0到100之间的随机整数（包含0和100）
        num = random.randint(0, 100)
        print(""
              "猜数字游戏开始！"
              "已生成一个0~100之间的整数。"
              "")

        while True:
            user_input = int(input("请输入你猜测的整数："))

            # 检查合法
            if user_input < 0 or user_input > 100:
                print("输入数据错误！")
                time.sleep(0.2) # ？！启动！？
                continue


            # 比较大小
            if user_input == num:
                print("恭喜！你猜中了！")
                time.sleep(0.2)
                break
            elif user_input > num:
                print("过大！")
                time.sleep(0.2)
            else:
                print("过小！")
                time.sleep(0.2)



guess = MyClass()
guess.main()



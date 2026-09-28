"""
当删除对象时，Python解释器会默认调用__del__()方法
"""


class Washer():
    def __init__(self):
        self.width = 500

    def __del__(self):
        print('该对象已删除')


haier = Washer()

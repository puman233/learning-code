
"""
import模块名
from模块名     import 功能名
from模块名     import *
import模块名   as别名
from模块名     import功能名   as别名
"""

# 方法1
import math
print(int(math.sqrt(9)))


# 方法2
from math import sqrt
print(int(sqrt(9)))


# 方法3
from math import *
print(int(sqrt(9)))

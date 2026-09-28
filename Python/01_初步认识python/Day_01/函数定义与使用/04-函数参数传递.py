"""
    函数参数传递
·函数可以将一些复杂的操作进行封装，但是很多的函数往往都需要接受到一些外部传入的数据
    这时就可以在函数上进行相关的参数定义了
"""
# 定义带参数的函数
def echo(title,url):
    """
    实现数据的回显操作，在接受的数据前追加“【ECHO】”的信息
    :param titel:要回显的标题内容
    :param url:要回显的地址信息
    :return:处理后的 ECHO 信息
    """
    return "【ECHO】 网站名称：{}，主页地址：{}".format(title,url)
#在进行函数调用时最简化的模式就是根据参数的顺序进行配置
print(echo("CSDN-专业开发者社区","https://www.csdn.net/")) # 传入所需要的参数并且进行返回值输出
# 如果有需要现在也可以采用直接明确的指定函数参数名称的方式进行参数内容的传递
print(echo(url="https://www.csdn.net/",title="CSDN-专业开发者社区"))

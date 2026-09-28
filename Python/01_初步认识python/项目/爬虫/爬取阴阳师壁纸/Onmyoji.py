"""
    爬取 阴阳师壁纸
"""
import requests
from lxml import etree
# from fake_useragent import UserAgent
from fake_useragent import UserAgent
import os

path = 'D:/阴阳师'
if not os.path.exists(path):
    os.mkdir(path)

# 随机产生请求头
ua = UserAgent(verify_ssl=False, path='fake_useragent.json')

url = 'https://yys.163.com/media/picture.html'  # 原画壁纸的页面链接
response = requests.get(url=url).text
html = etree.HTML(response)
lists = html.xpath('/html/body/div[2]/div[3]/div[1]/div[3]/div[2]/div')
num = 1
for i in range(len(lists)):
    a = lists[i].xpath('./div/div/a[contains(text(), "1920x1080")]')[0]  # 根据文本内容锁定节点a
    image_url = a.xpath('./@href')[0]  # 获取原画壁纸链接
    image_data = requests.get(url=image_url).content
    image_name = '{}.jpg'.format(num)  # 给每张图片命名
    save_path = path + '/' + image_name  # 图片的保存地址
    with open(save_path, 'wb') as f:
        f.write(image_data)
        print(image_name, '=======================>下载成功！！！')
        f.close()
        num += 1

import json
from pyecharts.charts import Line
from pyecharts.options import TitleOpts, ToolboxOpts, LabelOpts

f_us = open("D:/Files/Python/01_初步认识python/可视化案例数据/折线图数据/美国.txt", "r", encoding="UTF-8")
updata_us = f_us.read()
# print(updata_us)
f_jp = open("D:/Files/Python/01_初步认识python/可视化案例数据/折线图数据/日本.txt", "r", encoding="utf-8")
updata_jp = f_jp.read()

f_in = open("D:/Files/Python/01_初步认识python/可视化案例数据/折线图数据/印度.txt", "r", encoding="utf-8")
updata_in = f_in.read()

# 删除指定内容
updata_us = updata_us.replace("jsonp_1629344292311_69436(", "")
updata_us = updata_us[:-2]

updata_jp = updata_jp.replace("jsonp_1629350871167_29498(", "")
updata_jp = updata_jp[:-2]

updata_in = updata_in.replace("jsonp_1629350745930_63180(", "")
updata_in = updata_in[:-2]
# 转换python字典
us_dict = json.loads(updata_us)
jp_dict = json.loads(updata_jp)
in_dict = json.loads(updata_in)
# print(type(us_dict))
# print(us_dict)

# 读取trend key
us_trend_data = us_dict['data'][0]['trend']
jp_trend_data = jp_dict['data'][0]['trend']
in_trend_data = in_dict['data'][0]['trend']

# print(type(us_trend_data))
# print(us_trend_data)

# 读取日期数据,取2020年日期数据
us_x_data = us_trend_data['updateDate'][:314]
jp_x_data = jp_trend_data['updateDate'][:314]
in_x_data = in_trend_data['updateDate'][:314]
# print(us_x_data)

# 取y轴，列表数据
us_y_data = us_trend_data['list'][0]['data']
jp_y_data = jp_trend_data['list'][0]['data']
in_y_data = in_trend_data['list'][0]['data']
# print(us_y_data)

# 构建图表
line = Line()
line.add_xaxis(us_x_data) # x轴共用，只使用一个国家的数据

line.add_yaxis("美国确诊人数：", us_y_data, label_opts=LabelOpts(is_show=False))
line.add_yaxis("日本确诊人数：", jp_y_data, label_opts=LabelOpts(is_show=False))
line.add_yaxis("印度确诊人数：", in_y_data, label_opts=LabelOpts(is_show=False))

line.set_global_opts(
    title_opts=TitleOpts(title='2020年确证人数', pos_left='center', pos_bottom='1%'),

)

line.render()

# 关闭文件
f_us.close()
f_in.close()
f_jp.close()


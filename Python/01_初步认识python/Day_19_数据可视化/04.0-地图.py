import json
from pyecharts.charts import Map
from pyecharts.options import VisualMapOpts, TitleOpts

# data = [
#     ("北京市", 99),
#     ("上海市", 19),
#     ("湖南省", 200),
#     ("台湾省", 39),
#     ("广东省", 300),
#     ("新疆维吾尔自治区", 999),
#     ("西藏自治区", 30)
# ]

f = open("D:/Files/Python/01_初步认识python/可视化案例数据/地图数据/疫情.txt", encoding="UTF-8")
data = f.read()

f.close()

# 取出字典
data_dict = json.loads(data)
# 取出省份数据
province_data_list = data_dict["areaTree"][0]["children"]

data_list = []

# 组装元组
for province_data in province_data_list:
    province_name = province_data["name"]
    province_confirm = province_data["total"]["confirm"]
    data_list.append((province_name, province_confirm))

print(data_list)

map = Map()

map.add("testMap", data_list)

map.set_global_opts(
    visualmap_opts=VisualMapOpts(
        is_show=True,  # 是否显示
        is_piecewise=True,  # 是否分段
        pieces=[
            {"min": 1, "max": 99, "label": "1-99", "color": "#CCFFFF"},
            {"min": 100, "max": 999, "label": "100-999", "color": "#FFFF99"},
            {"min": 1000, "max": 4999, "label": "1000-4999", "color": "#FF9966"},
            {"min": 5000, "max": 49999, "label": "5000-49999", "color": "FF6666"},
            {"min": 50000, "max": 99999, "label": "50000-99999", "color": "#CC3333"},
            {"min": 100000, "label": "100000+", "color": "#990033"}
        ]
    ),
    title_opts=TitleOpts(title="全国疫情地图")
)

map.render("全国疫情地图.html")

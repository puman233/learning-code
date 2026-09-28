from pyecharts.charts import Line
from pyecharts.options import TitleOpts, LegendOpts, ToolboxOpts, VisualMapOpts

line = Line()

line.add_xaxis(["原神", "星穹铁道", "崩坏3"])
line.add_yaxis("数据", [23, 2, 99])
# 全局配置
line.set_global_opts(
    title_opts=TitleOpts(title="miHoYo", pos_left="center", pos_top="20%"),
    # 图例
    legend_opts=LegendOpts(is_show=True),
    # 工具箱
    toolbox_opts=ToolboxOpts(is_show=True),
    # 视觉映射
    visualmap_opts=VisualMapOpts(is_show=True),
)


# 调用render方法转换图标
line.render()








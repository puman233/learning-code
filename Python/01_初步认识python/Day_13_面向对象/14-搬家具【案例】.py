"""
搬家具

需求：
    把小于房子剩余面积的家具搬到房子中去
"""


# 定义类
class Furniture:
    def __init__(self, name, area):
        # 家具名字
        self.name = name
        # 家具占地面积
        self.area = area


class Home:
    def __init__(self, address, area, free_area):
        # 地理位置
        self.address = address
        # 房屋面积
        self.area = area
        # 剩余面积
        self.free_area = free_area
        # 家具列表
        self.furniture = []

    def __str__(self):
        return f"房子地理位置在{self.address}，房屋面积是{self.area}，剩余面积：{self.free_area}，家具有{self.furniture}"

    def add_furniture(self, item):
        """容纳家具"""
        """
        如果家具占地面积 <= 房子剩余面积，可以搬入（家具列表添加家具名字和数据并更新房子剩余面积）
            房屋剩余面积 - 家具的占地面积
        否则：提示用户家具太大，剩余面积不足，无法容纳
        """
        if item.area <= self.free_area:
            self.furniture.append(item.name)
            self.free_area -= item.area
        else:
            print("用户家具太大，剩余面积不足，无法容纳")


# 家具
bed = Furniture("双人床", 6)
sofa = Furniture("沙发", 10)
playground = Furniture("操场", 1000)
# 房子
homeFirst = Home('北京', 1000, 500)

print(homeFirst)

homeFirst.add_furniture(bed)
homeFirst.add_furniture(sofa)
homeFirst.add_furniture(playground)
print(homeFirst)

import json

data1 = [{"name":"大伟","age":30}, {"name": "lcy", "age": 18}, {"name": "hrd", "age": 19}, {"name": "lhy", "age": 20}]

json_str = json.dumps(data1, ensure_ascii=False)
print(type(json_str))
print(json_str)

data2 = {"name":"大伟","age":30}
json_str2 = json.dumps(data2, ensure_ascii=False)
print(type(json_str2))
print(json_str2)

s = '[{"name":"大伟","age":30}, {"name": "lcy", "age": 18}, {"name": "hrd", "age": 19}, {"name": "lhy", "age": 20}]'
l = json.loads(s)
print(type(l))

s1 = '{"name":"大伟","age":30}'
d1 = json.loads(s1)
print(type(d1))


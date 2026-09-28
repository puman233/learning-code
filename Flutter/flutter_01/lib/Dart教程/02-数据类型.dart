void main() {
  //定义字符串类型
  var str1 = 'this is str1';
  var str2 = 'this is str2';

  print(str1);
  print(str2);

  String string1 = 'this is String string1';
  String string2 = 'this is String string2';

  print(string1);
  print(string2);

  //以上写单行，下面写多行
  String strMore = """this is str
  hello
  dart""";
  print(strMore);

  //字符串的拼接
  String str01 = 'hello';
  String str02 = 'dart';
  //方法1
  print("$str01 $str02"); //hello dart
  //方法2
  print(str01 + "" + str2); //hello dart

  //int
  int a = 123;
  print(a);

  //double  既可以是整形，也可以是浮点型
  double b = 3.1;
  print(b);

  //运算符
  var c = a + b;
  print(c);

  //布尔类型 bool声明 | 值：TRUE 或 False
  bool flag = true;
  print(flag);

  bool flag2 = false;
  print(flag2);

  //条件判断语句
  var flag3 = true;

  if (flag3) {
    print("真");
  } else {
    print("假");
  }

  var a3 = 132;
  var b3 = 439;
  if (a3 == b3) {
    print("a = b");
  } else {
    print("a != b");
  }

  //创建集合/数组
  var l1 = ['nihao', 20, true];
  print(l1);

  print(l1.length); //获取集合长度

  print(l1[0]); //通过下标找到第一个元素

  //第二种定义集合的方式 | 指定类型
  var l2 = <String>["张三", "李四"];
  print(l2);

  var l3 = <int>[
    1,
    3,
  ];
  print(l3);

  //第三种定义方式 | 增加数据
  var l4 = []; //定义空列表
  print(l4);
  print(l4.length);

  l4.add('张三');
  print(l4);

  var l5 = ['张三', 20, true];
  l5.add('李四');
  print(l5);

  //第四种定义方式 | 在新版本Dart里不法使用，Flutter V2版本可使用

  var l6 = List.filled(2, '你好'); //创建一个固定长度的集合
  print(l6);

  l6[0] = '张三';
  l6[1] = '李四';
  print(l6);

  var l7 = ['张三', '李四'];
  l7.length = 0; //改变长度
  print(l7);

  //第一种定义字典 Maps 方法
  var person = {'name': '张三', 'age': 20, 'job': '程序员'};
  print(person);
  //获取对应的值
  print(person['name']);
  print(person['age']);
  print(person['job']);

  //第二种定义 Maps 方法
  var p = new Map();

  p["name"] = '李四';
  p['age'] = 22;
  p['job'] = '程序员';
  print(p);
  print(p['name']);
  print(p['age']);
  print(p['job']);

  var ifstr = '123';
  if (ifstr is String) {
    print('这是String类型');
  } else if (ifstr is int) {
    print('这是Int类型');
  } else {
    print('其他类型');
  }

  var ifnum = 123;
  if (ifnum is String) {
    print('This is String type');
  } else if (ifnum is int) {
    print('This is Number type');
  } else {
    print('This is another type');
  }
}

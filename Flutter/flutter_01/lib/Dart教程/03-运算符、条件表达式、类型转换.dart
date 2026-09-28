void main() {
  int a = 12;
  int b = 6;

  print(a + b); //加
  print(a - b); //减
  print(a * b); //乘
  print(a / b); //除
  print(a % b); //取余
  print(a ~/ b); //取整

  print("--------");

  var c = a * b;
  print(c);

  print('-------');

  int a1 = 5;
  int b1 = 3;

  print(a == b); //判断是否相等
  print(a != b); //判断是否不相等
  print(a > b); //判断是否大于
  print(a < b); //判断是否小于
  print(a >= b); //判断是否大于小于
  print(a <= b); //判断是否小于等于

  print('--------');

  if (a > b) {
    print('a 大于 b');
  } else {
    print('a 小于 b');
  }

  print('--------');

  bool flag = false;
  print(!flag); //取反

  //全部为true时值为true，否则返回false
  bool c1 = true;
  bool d1 = false;

  print(c1 && d1);

  //全部为false时值为false，否则为true
  bool c2 = true;
  bool d2 = false;

  print(c2 || d2);

  print('--------');

  int age = 30;
  String sex = '女';
  if (age == 20 && sex == '女') {
    print('$age --- $sex');
  } else {
    print('None');
  }

  if (age == 20 || sex == '女') {
    print('$age --- $sex');
  } else {
    print('None');
  }
}

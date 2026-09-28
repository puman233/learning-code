// main() {
//   print('你好 Dart');
// }

//表示main方法没有返回值
void main() {
  //dart 定义变量可以使用 var 关键字
  //var 关键字不可以和类型关键字一起写
  //var 可以自动识别变量类型
  var myNum = 1234;
  print(myNum);
  print('');

  //字符串
  String str = '你好Dart';

  print(str);

  //数字类型
  int myNumber = 12345;
  print(myNum);

  //命名规则
  /*
      1、变量名称必须由数字、字母、下划线和美元符($)组成。
      2.注意:标识符开头不能是数字
      3.标识符不能是保留字和关键字。
      4.变量的名字是区分大小写的如: age和Age是不同的变量。在实际的运用中,也建议,不要用一个
      5、标识符(变量名称)一定要见名思意:变量名称建议用名词，方法名称建议用动词

   */

  //常量定义
  //常亮不可修改
  const PI = 3.14159;
  print(PI);

  final pai = 3.14159;
  print(pai);

  final now = new DateTime.now();
  print(now);
}

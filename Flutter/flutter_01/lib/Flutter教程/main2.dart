import 'package:flutter/material.dart';

void main() {
  runApp(MyAPP());
}

class MyAPP extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('Flutter'),
        ),
        body: HomeCentent(),
      ),
    );
  }
}

class HomeCentent extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Center(
        child: Container(
      child: Text(
        '你好世界',
        textAlign: TextAlign.center, //文本显示位置
        style: TextStyle(
            fontSize: 20.0,
            color: Colors.lightBlue,
            fontWeight: FontWeight.w800, //设置字体粗细
            fontStyle: FontStyle.italic, //设置字体倾斜
            decoration: TextDecoration.lineThrough, //设置删除线
            /**
             * decoration: TextDecoration.none  不设置任何线条穿过
             * decoration: TextDecoration.overline  上划线
             * decoration: TextDecoration.underline 下划线
             */
            decorationColor: Colors.black, //设置线条颜色
            decorationStyle: TextDecorationStyle.dashed, //设置线条虚线
            letterSpacing: 1.0 //设置字体间距
            ),
        overflow: TextOverflow.ellipsis, //表示文本超出容器范围后，最后的几个字符用...表示
        maxLines: 1, //设置文本最大显示几行
        textScaleFactor: 2, //表示文本放大几倍
      ),
      height: 300.0, //设置高度
      width: 300.0, //设置宽度
      //定义背景颜色
      decoration: BoxDecoration(
          //设置边框
          color: Colors.white,
          border: Border.all(color: Colors.lightBlue, width: 3.0),
          borderRadius: BorderRadius.all(Radius.circular(30))), //设置边框圆形
      // padding: EdgeInsets.all(10), //容器和内部的距离:内边距
      // padding: EdgeInsets.fromLTRB(10, 20, 10, 20),
      margin: EdgeInsets.fromLTRB(10, 10, 10, 10), //外边距
      // transform: Matrix4.translationValues(100, 0, 0)), //以X轴向右移动100个单位的距离
      transform: Matrix4.rotationZ(0.5), //设置旋转
      alignment: Alignment.center,  //设置文本位置
    ));
  }
}

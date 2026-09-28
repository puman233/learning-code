import 'package:flutter/material.dart';

void main() {
  runApp(MyAPP());
}

//自定义组件
//StatelessWidget是无状态组件，状态不可变的widget
//StatefulWidget是有状态组件，持有的状态可能在widget生命周期改变
class MyAPP extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text(
            'Flutter',
            style: TextStyle(color: Colors.white, fontStyle: FontStyle.normal),
          ),
        ),
        body: HomeContent(),
      ),
      theme: ThemeData(primarySwatch: Colors.lightBlue),
    );
  }
}

class HomeContent extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Center(
      child: new Text(
        'HelloWorld',
        //ltr:从左到右排列文本
        textDirection: TextDirection.ltr,
        //style:设置字体样式
        //fontSize:设置字体大小
        //color:设置字体颜色
        style: TextStyle(fontSize: 40.0, color: Colors.green),
      ),
    );
  }
}

import 'package:flutter/material.dart';

void main(List<String> args) {
  runApp(MyAPP());
}

class MyAPP extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(title: Text('Flutter')),
        body: HomeContent(),
      ),
    );
  }
}

class HomeContent extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return ListView(
      padding: EdgeInsets.all(10), //内边距是10
      children: [
        ListTile(
          leading: Icon(
            Icons.search,
            color: Colors.blue[200],
          ),
          title: Text(
            'HelloWorld',
            style: TextStyle(fontSize: 20.0),
          ),
          subtitle: Text("helloworld Flutter"),
        ),
        ListTile(
          //把图标放在前边（左边）
          leading: Icon(
            Icons.download, //定义图标
            color: Colors.green[300], //定义图标颜色
            size: 30, //定义图标大小
          ),
          title: Text(
            'Hello Flutter',
            style: TextStyle(fontSize: 20.0),
          ),
          subtitle: Text("helloworld 前端"),
          // trailing: Icon(
          //   Icons.download, //定义图标
          //   color: Colors.green[300], //定义图标颜色
          //   size: 30, //定义图标大小
          // )  //将图标放在后方（右边）
        ),
        //添加图片
        ListTile(
          leading: Image.asset('assets/images/look.jpg'),
          title: Text(
            '作者',
            style: TextStyle(fontSize: 20.0),
          ),
          subtitle: Text("我是一个呆萌萌的宝儿哦~"),
          trailing: Icon(
            Icons.home,
            color: Colors.blue[100],
          ), //前面和后面一起放图片或图标都可以，不会报错
        ),
      ],
    );
  }
}

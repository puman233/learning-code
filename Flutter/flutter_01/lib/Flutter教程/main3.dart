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
        body: HomeCenTent(),
      ),
      theme: ThemeData(primarySwatch: Colors.lightBlue),
    );
  }
}

//图片显示圆角 - 复杂写法
class HomeContent extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Center(
      // child: Text(
      //   'HelloWorld',
      //   //ltr:从左到右排列文本
      //   textDirection: TextDirection.ltr,
      //   //style:设置字体样式
      //   //fontSize:设置字体大小
      //   //color:设置字体颜色
      //   style: TextStyle(fontSize: 40.0, color: Colors.green)
      // ),
      child: Container(
        // child: Image.network(
        //   //从网络路径加载图片
        //   "https://p2.ssl.qhimg.com/d/inn/b886349a3672/LOGO_128x128.png",
        //   alignment: Alignment.center, //设置图片位置
        // color: Colors.blue[100], //设置图片背景颜色
        // colorBlendMode: BlendMode.screen, //设置颜色填充方式
        // fit: BoxFit.cover, //放最大显示
        /**
           * 在遇到不规则图片时，cover属性会把图片自适应容器，充满容器，出现部分裁剪的情况，不会变形
           * 而fill属性图片会变形，使整个图片充满容器，但图片不会出现裁剪的情况
           * contain为默认设置，图片不会变形，不会被裁减，但会和容器有空隙
           */
        // repeat: ImageRepeat.repeat, //使容器中出现多张重复图片
        //),
        width: 130,
        height: 130,
        decoration: BoxDecoration(
          color: Colors.yellow[200],
          // borderRadius: BorderRadius.all(Radius.circular(50.0))
          borderRadius: BorderRadius.circular(50), //简洁写法
          image: DecorationImage(
            image: NetworkImage(
                "https://p2.ssl.qhimg.com/d/inn/b886349a3672/LOGO_128x128.png"),
            fit: BoxFit.cover,
          ),
        ),
      ),
    );
  }
}

//图片显示圆角 - 超简洁写法
class HomeCenTent extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Center(
        child: Container(
      child: Image.asset(
        'assets/images/look.jpg',
        fit: BoxFit.cover,
      ),
      height: 1000,
      width: 1000,
    ));
  }
}

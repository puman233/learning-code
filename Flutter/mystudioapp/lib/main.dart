import 'dart:io';

import 'package:flutter/material.dart';

void main() {
  runApp(MyStudioApp());
}

class MyStudioApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text(
            '超永工作室 | Cy_Studio',
            textAlign: TextAlign.center,
            style: TextStyle(fontSize: 20.0, fontWeight: FontWeight.normal),
          ),
        ),
        body: FirstCenter(),
      ),
      theme: ThemeData(primarySwatch: Colors.lightBlue),
    );
  }
}

class FirstCenter extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Center(
      child: Container(
        child: Text(
          '董事长：'
          '李超永',
          textAlign: TextAlign.center,
          style: TextStyle(fontSize: 20.0),
        ),
        height: 50.0,
        width: 200.0,
        decoration: BoxDecoration(
            color: Colors.orangeAccent[100],
            borderRadius: BorderRadius.all(Radius.circular(30))),
        transform: Matrix4.translationValues(-400, -200, -200),
        alignment: Alignment.center,
      ),
    );
  }
}

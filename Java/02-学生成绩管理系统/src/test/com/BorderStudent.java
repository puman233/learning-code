package test.com;

import javax.swing.*;
import java.awt.*;

/*
- 边界布局 BorderLayout
- 尽可能充满整个所在的容器
 */

public class BorderStudent extends JFrame{
    JButton northBtn = new JButton("北边的按钮");
    JLabel southLabel = new JLabel("南边的按钮");
    JRadioButton westRadioBtn = new JRadioButton("西边的按钮");
    JTextArea eastArea = new JTextArea("输入内容",10,20);
    JButton centerBtn = new JButton("中间的");

    public BorderStudent () {
        super("测试边界布局");    //设置标题名称

        Container contenPane = getContentPane();

        //设置布局管理器
        contenPane.setLayout(new BorderLayout());
        contenPane.add(northBtn, BorderLayout.NORTH);
        contenPane.add(southLabel, BorderLayout.SOUTH);
        westRadioBtn.setPreferredSize(new Dimension(200, 10));
        contenPane.add(westRadioBtn, BorderLayout.WEST);
        contenPane.add(eastArea, BorderLayout.EAST);
//        contenPane.add(centerBtn,BorderLayout.CENTER);
        contenPane.add(centerBtn);  //默认在中间

        //基本窗口设置
        setSize(600, 400);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setResizable(true);
        setVisible(true);
    }

    public static void main(String[] args) {
        new BorderStudent();
    }
}

/*

 */
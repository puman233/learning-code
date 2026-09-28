package test.com;

import javax.swing.*;
import java.awt.*;
import java.net.URL;

public class student extends JFrame{
    JButton jButton;

    public student () {
        //容器组件：jframe,jpanel,jscrollpane    非容器组件：jbutton,jlable,jtextfield...
        JFrame jFrame = new JFrame("灰度测试中~（学生管理系统）");  //这里设置程序frame标题

        //设置按钮
        JButton jButton = new JButton("按钮");   //这里设置按钮名称
        Container contenPane = jFrame.getContentPane();
        contenPane.add(jButton);

        /*
        //设置窗体图标
        URL resource = student.class.getClassLoader().getResource("logo.jpg");    //定义图标位置
        Image image = new ImageIcon(resource).getImage();
        jFrame.setIconImage(image);
        */

        jFrame.setSize(600,400);    //单位：px


        //居中
        jFrame.setLocationRelativeTo(null);

        /*
        //还可以自己计算位置来居中
        Dimension screeSize = Toolkit.getDefaultToolkit().getScreenSize();
        int offsetX = (screeSize.width-600) / 2;
        int offsetY = (screeSize.height-600) / 2;
        jFrame.setLocation(offsetX,offsetY);
         */

        //关闭退出程序
        jFrame.setDefaultCloseOperation(jFrame.EXIT_ON_CLOSE);
        //窗口大小不可改变
        jFrame.setResizable(false);

        jFrame.setVisible(true);
    }
    public static void main(String[] args) {
        new student();
    }
}

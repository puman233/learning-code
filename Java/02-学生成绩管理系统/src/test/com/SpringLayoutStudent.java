package test.com;

import javax.swing.*;
import java.awt.*;

public class SpringLayoutStudent extends JFrame {
    //设置jpanel的布局管理器为SpringLayout
    SpringLayout springLayout = new SpringLayout();
    JPanel jPanel = new JPanel(springLayout);

    JLabel titleLabel = new JLabel("文章标题");
    JTextField titleText = new JTextField();
    JLabel authorLabel = new JLabel("作者");
    JTextArea authorText = new JTextArea();
    JLabel contLabel = new JLabel("请输入内容");
    JTextArea contArea = new JTextArea(4,10);

    public SpringLayoutStudent() {
        super("弹簧布局SpringLayout");

        Container contentPane = getContentPane();

        //加入到jpanel中
        jPanel.add(titleLabel);
        titleText.setPreferredSize(new Dimension(200,30));
        jPanel.add(titleText);
        jPanel.add(authorLabel);
        authorText.setPreferredSize(new Dimension(200,30));
        jPanel.add(authorText);
        jPanel.add(contLabel);
        jPanel.add(contArea);

        jPanel.setBackground(Color.gray);   //设置背景色为灰色

        /*
            SpringLayout:布局管理器
            SpringLayout.Constraints:使用弹簧布局的容器里面的组件的布局约束，每个组件对应一个
            Spring:可以理解为一个能够进行四则运算的整数
         */
        Spring titleLabelWidth = Spring.width(titleLabel);
        Spring titleTextWidth = Spring.width(titleText);
        Spring spaceWidth = Spring.constant(20);
        Spring childWidth = Spring.sum(Spring.sum(titleLabelWidth,titleTextWidth),spaceWidth);
        int offsetX = childWidth.getValue() / 2;

        SpringLayout.Constraints titleLabelC = springLayout.getConstraints(titleLabel);
        springLayout.putConstraint(SpringLayout.WEST,titleLabel,-offsetX,SpringLayout.HORIZONTAL_CENTER,jPanel);
        titleLabelC.setY(Spring.constant(50));


        //设置标题文本框：titleText东边距离titleLabel的西边20px，北边相同
        SpringLayout.Constraints titleTextC = springLayout.getConstraints(titleText);
        //edgeName:东南西北     s:值
        Spring titleLabelEastSpring = titleLabelC.getConstraint(SpringLayout.EAST);
        titleTextC.setConstraint(springLayout.WEST,Spring.sum(titleLabelEastSpring,Spring.constant(20)));
        titleTextC.setConstraint(SpringLayout.NORTH,titleLabelC.getConstraint(SpringLayout.NORTH));


        /*
            以上是使用约束的第一种方法，比较复杂

            以下是使用约束的第二种方法，相对简单
            e1:要设置组建的哪个边界(edgeName)
            c1:要设置的组件
            pad:距离值
            e2:参照的组件的组件名
            c2:参考物（组件）
         */
        //设置作者Label:authorLabel.东边和titleLabel对齐，北边距离titleLabel 南边20px
        springLayout.putConstraint(SpringLayout.EAST,authorLabel,0,SpringLayout.EAST,titleLabel);
        springLayout.putConstraint(SpringLayout.NORTH,authorLabel,20,SpringLayout.SOUTH,titleLabel);
        //设置authorText:authorText西边距离titleLabel的东边20px，北边相同
        springLayout.putConstraint(SpringLayout.WEST,authorText,20,SpringLayout.EAST,authorLabel);
        springLayout.putConstraint(SpringLayout.NORTH,authorText,0,SpringLayout.NORTH,authorLabel);

        //设置内容  contLabel
        springLayout.putConstraint(SpringLayout.EAST,contLabel,0,SpringLayout.EAST,titleLabel);
        springLayout.putConstraint(SpringLayout.NORTH,authorLabel,20,SpringLayout.SOUTH,authorLabel);

        //  contArea
        springLayout.putConstraint(SpringLayout.WEST,contArea,20,SpringLayout.EAST,contLabel);
        springLayout.putConstraint(SpringLayout.NORTH,contArea,0,SpringLayout.NORTH,contLabel);

        //  conArea 的南边和东边参照jpanel
        springLayout.putConstraint(SpringLayout.SOUTH,contArea,-20,SpringLayout.SOUTH,jPanel);
        springLayout.putConstraint(SpringLayout.EAST,contArea,-20,SpringLayout.EAST,jPanel);

        contentPane.add(jPanel);

        setSize(600,400);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setResizable(false);
        setVisible(true);
    }
    public static void main(String[] args) {
        new SpringLayoutStudent();
    }
}

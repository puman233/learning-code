package 练习.student;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import static 练习.student.Main.list;

public class addStu extends JFrame {
    public addStu() {

        setTitle("添加学生信息");
        setBounds(600, 300, 300, 360);
        setVisible(true);
//        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);

        JTextField t1,t2,t3,t4;
        JLabel l1,l2,l3,l4;
        JButton b1,b2;

        Container con = getContentPane();

        l1 = new JLabel("学号: ");
        l2 = new JLabel("姓名: ");
        l3 = new JLabel("性别: ");
        l4 = new JLabel("成绩: ");

        b1 = new JButton("确认");
        b2 = new JButton("取消");

        t1 = new JTextField(15);
        t2 = new JTextField(15);
        t3 = new JTextField(15);
        t4 = new JTextField(15);

        JPanel p1 = new JPanel();
        JPanel p2 = new JPanel();
        JPanel p3 = new JPanel();
        JPanel p4 = new JPanel();
        JPanel p5 = new JPanel();
        JPanel p6 = new JPanel();
        JPanel p7 = new JPanel();

        p1.add(l1);
        p1.add(t1);

        p2.add(l2);
        p2.add(t2);

        p3.add(l3);
        p3.add(t3);

        p4.add(l4);
        p4.add(t4);


        p5.add(b1);

        p6.add(b2);

        p7.add(p1);
        p7.add(p2);
        p7.add(p3);
        p7.add(p4);
        p7.add(p5);
        p7.add(p6);
        p7.setLayout(new FlowLayout(FlowLayout.CENTER,40,25)); //居中，水平距30，垂直距15
        con.add(p7);

        b1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String s1 = t1.getText();
                String s2 = t2.getText();
                String s3 = t3.getText();
                String s4 = t4.getText();
                student s = new student(s1, s2, s3, s4);
                boolean bool=true;
                for (student st : list) {//判断学号是否存在
                    if (st.getID().equals(s1)) {
                        JOptionPane.showMessageDialog(null, "你输入的学号已存在", "警告", JOptionPane.ERROR_MESSAGE);
                        bool=false;
                        return;
                    }
                }

                if(t1.getText().equals("") || t2.getText().equals("")||t3.getText().equals("")||t4.getText().equals("")){
                    JOptionPane.showMessageDialog(null, "请输入完整的信息", "警告", JOptionPane.ERROR_MESSAGE);
                    bool=false;
                }

                if (bool) {
                    JOptionPane.showMessageDialog(b1, "添加成功");  //消息对话框

                    list.add(s);

                    new Filew().writeStu(s);

                    t1.setText("");
                    t2.setText("");
                    t3.setText("");
                    t4.setText("");


                } else {
                    JOptionPane.showMessageDialog(null, "添加错误", "错误", JOptionPane.ERROR_MESSAGE);
                }


            }
        });
        b2.addActionListener(new ActionListener(){

            @Override
            public void actionPerformed(ActionEvent e) {
                new FileFrame();
                dispose();


            }
        });
    }

}
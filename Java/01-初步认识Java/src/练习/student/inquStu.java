package 练习.student;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import static 练习.student.Main.list;

public class inquStu extends JFrame {
    public inquStu() {

        setTitle("查询学生信息");
        setBounds(600, 300, 300, 360);
        setVisible(true);
        setResizable(false);

        JTextField t1;
        JLabel l1,l2;
        JButton b1,b2;

        Container con = getContentPane();


        l1 = new JLabel("学号: ");
        l2=new JLabel("请输入要修改学生的学号");
        l2.setFont(new Font("宋体", Font.PLAIN, 16));


        b1 = new JButton("查询");
        b2 = new JButton("取消");

        t1 = new JTextField(15);

        JPanel p1 = new JPanel();
        JPanel p2 = new JPanel();
        JPanel p5 = new JPanel();
        JPanel p6 = new JPanel();
        JPanel p7 = new JPanel();

        p1.add(l1);
        p1.add(t1);
        p2.add(l2);

        p5.add(b1);

        p6.add(b2);

        p7.add(p2);
        p7.add(p1);
        p7.add(p5);
        p7.add(p6);
        p7.setLayout(new FlowLayout(FlowLayout.CENTER,40,25));
        con.add(p7);

        b1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String inID = t1.getText();
                if (list.size()>0){
                    for (int i = 0; i < list.size(); i++) {
                        student stu = list.get(i);
                        if (inID.equals(stu.getID())){

                            String string = stu.getID()+"------------"+stu.getName()+"------------"+stu.getSex()+"------------"+stu.getGrade();

                            JOptionPane.showMessageDialog(null, string, "查询结果", JOptionPane.PLAIN_MESSAGE);

                            return;
                        }
                        if (i==list.size()-1){
                            JOptionPane.showMessageDialog(null, "该学生不存在", "警告", JOptionPane.ERROR_MESSAGE);
                        }
                    }
                }else{
                    JOptionPane.showMessageDialog(null, "没有数据", "警告", JOptionPane.ERROR_MESSAGE);

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
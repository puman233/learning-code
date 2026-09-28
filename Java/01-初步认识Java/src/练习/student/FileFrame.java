package 练习.student;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
/**
 * @author hyjhyq0507
 */
public class FileFrame extends JFrame {


    public FileFrame(){
        super();

        setTitle("CY.Studio----学生管理系统V1.0");
        setBounds(600,300,600,800);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
        setResizable(true);

        Container con = getContentPane();

        JButton b1 = new JButton("添加");
        JButton b2 = new JButton("删除");
        JButton b3 = new JButton("查询");
        JButton b4 = new JButton("修改");
        JButton b5 = new JButton("遍历");
        JButton b6 = new JButton("退出");

        JPanel p1 = new JPanel();
        JPanel p2 = new JPanel();
        JPanel p3 = new JPanel();
        JPanel p4 = new JPanel();
        JPanel p5 = new JPanel();
        JPanel p6 = new JPanel();
        JPanel p7 = new JPanel();

        p1.add(b1);
        b1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(e.getSource() == b1) {
                    addStu addStu = new addStu();//添加
                    dispose();
                }
            }
        });

        p2.add(b2);
        b2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(e.getSource() == b2) {

                    delStu delStu = new delStu();//删除
                    dispose();
                }
            }
        });

        p3.add(b3);
        b3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(e.getSource() == b3) {
                    inquStu inquStu = new inquStu();//查询
                    dispose();
                }
            }
        });

        p4.add(b4);
        b4.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(e.getSource() == b4) {
                    reStu reStu = new reStu();//修改
                    dispose();
                }
            }
        });

        p5.add(b5);
        b5.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(e.getSource() == b5) {
                    printfStuAll printfStuAll = new printfStuAll();//遍历
                    dispose();
                }
            }
        });

        p6.add(b6);
        b6.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(e.getSource() == b6) {
                    System.exit(0);  //退出
                    dispose();
                }
            }
        });

        p7.add(p1);
        p7.add(p2);
        p7.add(p3);
        p7.add(p4);
        p7.add(p5);
        p7.add(p6);
        p7.setLayout(new FlowLayout(FlowLayout.CENTER, 50, 60));
        con.add(p7);

    }

}
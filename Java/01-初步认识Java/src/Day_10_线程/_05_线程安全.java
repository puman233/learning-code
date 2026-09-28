package Day_10_线程;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/*
线程安全问题

产生原因：多个线程竞争同一资源（访问同一数据），可参考经典的生产者消费者问题。

解决方案：
    run 方法内：同步代码块 synchronized {}
    Public synchronized 返回值类型 方法名（）{} 自动释放对象锁

使用 Lock 锁

Lock 锁需要程序员（在 finally 代码块中）手动释放。
    Lock lock=new ReentranttLock()    // Reentrant（可重用的）

Lock 实现提供了比使用 synchronized 方法和语句可获得的更广泛的锁定操作，是 JDK1.5 之后出现的。

Lock 接口中的方法:

    void lock()   // 获取锁 
    void unlock() // 释放锁 

Lock 接口的实现类:
    java.util.concurrent.locks.ReentrantLock implements Lock


使用步骤:

 1.在成员位置创建一个 ReentrantLock 对象。
 2.在可能出现线程安全问题的代码前，调用 Lock 接口中的方法 lock 获取锁对象。
 3.在可能出现线程安全问题的代码后，调用 Lock 接口中的方法 unlock 释放锁对象。
 
*/

class RunnableImpl implements Runnable{
    //定义一个共享的票源
    private int ticket = 100;
    //1.在成员位置创建一个ReentrantLock对象
    Lock l = new ReentrantLock();
    //设置线程任务:卖票
    @Override
    public void run() {
        //使用死循环,让卖票重复的执行
        while(true){
            //2.在可能出现线程安全问题的代码前,调用Lock接口中的方法lock获取锁对象
            l.lock();
            //为了提高线程安全问题出现的几率,让程序睡眠10毫秒
            try {
                //判断票是否大于0
                if (ticket > 0) {
                //可能会产生异常的代码
                Thread.sleep(10);
                //进行卖票 ticket--
                System.out.println(Thread.currentThread().getName()+"正在卖第"+ticket+"张票!");
                ticket--;
            } else {
                System.out.println("线程：" + Thread.currentThread().getName() + "票已售完!");
                break;
            }
            } catch (InterruptedException e) {
                //异常的处理逻辑
                e.printStackTrace();
            }finally {
                //一定会执行的代码,一般用于资源释放(资源回收)
                //3.在可能出现线程安全问题的代码后,调用Lock接口中的方法unlock释放锁对象
                l.unlock();//无论程序是否有异常,都让锁对象释放掉,节约内存,提高程序的效率
            }
            
        }
    }
}

public class _05_线程安全 {

    public static void main(String[] args) {
        //创建Runnable接口的实现类对象
        RunnableImpl run = new RunnableImpl();
        //创建Thread类对象,构造方法中传递Runnable接口的实现类对象
        Thread t1 = new Thread(run);
        Thread t2 = new Thread(run);
        Thread t3 = new Thread(run);

        //调用start方法开启线程
        t1.start();
        t2.start();
        t3.start();



    }

}

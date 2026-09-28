package Day_10_线程;

public class _02_RunnableDemo {
    public static void main(String args[]) {
        RunnableDemo R1 = new RunnableDemo( "线程1");
        R1.start();
        
        RunnableDemo R2 = new RunnableDemo( "线程2");
        R2.start();
    }   
}


class RunnableDemo implements Runnable {
    // 线程对象
    private Thread t;
    // 线程名称
    private String threadName;
    
    // 传入线程名称作为参数
    RunnableDemo( String name) {
        threadName = name;
        System.out.println("创建 " +  threadName );
    }
    
    public void run() {
        System.out.println("运行 " +  threadName );

        try {
            // 线程运行4次，每次休眠50毫秒
            for(int i = 4; i > 0; i--) {
                System.out.println("线程: " + threadName + ", " + i);
                // 让线程睡眠一会
                Thread.sleep(50);
            }
        }catch (InterruptedException e) { // 捕获线程中断异常
            System.out.println("线程 " +  threadName + " 被中断。");
        }
        System.out.println("线程 " +  threadName + " 结束。");
    }
    
    // 运行线程
    public void start () {
        System.out.println("启动 " +  threadName );
        if (t == null) {
            t = new Thread (this, threadName);
            t.start ();
        }
    }
}

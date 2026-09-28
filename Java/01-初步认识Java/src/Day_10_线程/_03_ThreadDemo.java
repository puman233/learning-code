package Day_10_线程;


class ThreadDemo extends Thread {
   private Thread t;
   private String threadName;
   
   // 传入线程名称作为参数
   ThreadDemo( String name) {
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

   public void start () {
      System.out.println("启动 " +  threadName );
      if (t == null) {
         t = new Thread (this, threadName);
         t.start ();
      }
   }
}


public class _03_ThreadDemo {

    public static void main(String args[]) {
      ThreadDemo T1 = new ThreadDemo( "线程-1");
      T1.start();
      
      ThreadDemo T2 = new ThreadDemo( "线程-2");
      T2.start();
   }   
}

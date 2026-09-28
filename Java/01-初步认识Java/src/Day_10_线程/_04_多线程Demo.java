package Day_10_线程;


// 通过实现 Runnable 接口创建线程
class DisplayMessage implements Runnable {
   private String message;
   
   public DisplayMessage(String message) {
      this.message = message;
   }
   
   public void run() {
      while(true) {
         System.out.println(message);
      }
   }
}

/*
这是一个“猜数字”的任务。
它会不断生成 1~100 的随机数，直到猜中指定的数字（例如 27 或 75）才会结束运行。
 */
// 通过继承 Thread 类创建线程
class GuessANumber extends Thread {
    private int number;
    public GuessANumber(int number) {
        this.number = number;
    }
    
    public void run() {
        int counter = 0;
        int guess = 0;
        do {
            guess = (int) (Math.random() * 100 + 1);
            System.out.println(this.getName() + " 猜测数字： " + guess + "\t猜测次数：" + counter);   // 输出线程名称和猜测的数字
            counter++;
        } while(guess != number);
        System.out.println("** Correct!\t" + this.getName() + " 猜了 " + counter + "次 . **");
    }
}


public class _04_多线程Demo {

    public static void main(String [] args) {
        Runnable hello = new DisplayMessage("Hello");
        Thread thread1 = new Thread(hello);

        /*
        public final void setDaemon(boolean on)
            将该线程标记为守护线程或用户线程。
        */
        // 将线程设置为守护线程
        thread1.setDaemon(true);

        /*
        public final void setName(String name)
            改变线程名称，使之与参数 name 相同。
        */

        thread1.setName("hello");

        System.out.println("开始执行 hello 线程...");

        // thread1.start();

        Runnable bye = new DisplayMessage("Goodbye");
        Thread thread2 = new Thread(bye);

        /*
        public final void setPriority(int priority)
            更改线程的优先级。
        */
       
        thread2.setPriority(Thread.MIN_PRIORITY);   // 设置线程优先级为最低
        thread2.setDaemon(true);

        System.out.println("开始执行 goodbye 线程...");

        // thread2.start();

        System.out.println("开始执行 thread3...");
        Thread thread3 = new GuessANumber(27);

        thread3.setPriority(Thread.MAX_PRIORITY);   // 设置线程优先级为最高

        thread3.start();
        try {
            /*
            	public final void join(long millisec)
            等待该线程终止的时间最长为 millis 毫秒。
            */
            thread3.join(); // 等待 thread3 线程完成
        }catch(InterruptedException e) {
            System.out.println("线程被中断.");
        }

        System.out.println("开始执行 thread4...");

        Thread thread4 = new GuessANumber(75);
        thread4.start();
        System.out.println("main() 线程结束...");
        /*
        当 main() 线程结束时，所有的守护线程都会被强制终止。
        thread4 一瞬间就结束了，然后系统就没有任何非守护线程了，
        所以守护线程 hello 和 goodbye 也就被强制终止了。
         */
    }
    
}

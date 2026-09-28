package Day_06_OOP;

import java.util.Scanner;
// 集合与数学运算
import java.util.ArrayList;
import java.util.Collections;
// 处理现代日期和时间
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;


public class _07_包Packages {
/*
Java 包与API
    Java 中的包用于对相关类进行分组。
    可将其视为文件目录中的文件夹。
    我们使用包来避免名称冲突，并编写更好的可维护代码。

软件包分为两类:
    内置包（来自Java API的包)
    用户定义的包（创建自己的包）

内置软件包
    Java API 是Java开发环境中包含的一个预编写类库，可以免费使用。

    该库包含用于管理输入、数据库编程等的组件。
    完整列表可在Oracles网站上找到:
    https://docs.oracle.com/javase/8/docs/api/

    该库分为包和类。
    这意味着您可以导入单个类（及其方法和属性），
    也可以导入包含属于指定包的所有类的整个包。

    要使用库中的类或包，需要使用 import 关键字:


1. java.lang (核心语言包)
这是 Java 中最基础的包，默认自动导入，无需使用 import 语句。
    Object: 所有类的基类。
    String / StringBuilder / StringBuffer: 字符串操作。
    Math: 提供初等数学运算（如三角函数、对数、平方根）。
    System / Runtime: 提供与底层运行环境交互的功能。
    Thread: 多线程编程的核心类。
    包装类: 如 Integer, Double, Boolean 等。

2. java.util (工具包)
Java 开发中使用频率最高、功能最丰富的包之一。
    集合框架 (Collections Framework): ArrayList, HashMap, HashSet, LinkedList 等。
    日期与时间: Date, Calendar, 以及旧版本的日期处理（现代开发建议优先使用 java.time）。
    实用工具: Arrays (操作数组), Collections (操作集合), Optional (处理空指针)。
    Scanner: 用于简单的输入扫描。

3. java.io & java.nio (输入/输出)
用于处理文件、数据流及网络传输。
    java.io: 传统的阻塞式 I/O。包括 File, InputStream, OutputStream, Reader, Writer。
    java.nio: 非阻塞 I/O (New I/O)，引入了通道（Channel）和缓冲区（Buffer）的概念，性能更高。

4. java.net (网络通信)
提供了实现网络应用程序的类。
    Socket / ServerSocket: 用于 TCP 连接。
    DatagramPacket / DatagramSocket: 用于 UDP 协议。
    URL / URLConnection: 用于访问互联网资源。

5. java.sql (数据库访问)
即 JDBC (Java Database Connectivity) API。
    Connection: 建立与数据库的连接。
    Statement / PreparedStatement: 执行 SQL 语句。
    ResultSet: 存储并处理查询结果。

6. java.time (现代日期时间包)
在 Java 8 中引入，旨在彻底替代旧的 java.util.Date。
    LocalDate / LocalTime / LocalDateTime: 不带时区的日期时间。
    ZonedDateTime: 带时区的日期时间。
    Duration / Period: 计算时间差或日期差。

7. java.util.concurrent (并发工具包)
这是 Java 高并发编程的核心，由大师 Doug Lea 设计，位于 java.util 的子包下。
    ExecutorService / ThreadPoolExecutor: 线程池管理，避免频繁创建线程的开销。
    ConcurrentHashMap: 线程安全的哈希表，性能远高于 Hashtable。
    BlockingQueue: 阻塞队列，常用于生产者-消费者模型。
    Locks (java.util.concurrent.locks): 提供比 synchronized 更灵活的锁机制（如 ReentrantLock）。
    Atomic (java.util.concurrent.atomic): 原子类（如 AtomicInteger），利用 CAS 保证线程安全。


*/

    public static void main(String[] args) {
        // 使用 java.util.ArrayList 存储数据
        ArrayList<Integer> numbers = new ArrayList<>();
        numbers.add(5);
        numbers.add(2);
        numbers.add(8);

        // 使用 java.util.Collections 进行排序
        Collections.sort(numbers);

        // 使用 java.lang.Math (自动导入) 计算最大值的平方根
        int max = numbers.get(numbers.size() - 1);
        double result = Math.sqrt(max);

        System.out.println("排序后的列表: " + numbers);
        System.out.println("最大值的平方根: " + result);

        // 获取当前日期时间
        LocalDateTime now = LocalDateTime.now();

        // 格式化输出
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        String formattedDate = now.format(formatter);

        System.out.println("当前系统时间: " + formattedDate);
        System.out.println("三天后的时间: " + now.plusDays(3));


    }
}

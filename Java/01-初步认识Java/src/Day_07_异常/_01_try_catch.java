package Day_07_异常;

import java.io.IOException;
import java.io.*;

/*
    Java 异常
        在执行 Java 代码时，可能会出现不同的错误:
        程序员编写的编码错误、错误输入导致的错误或其他无法预料的事情。

        发生错误时，Java 通常会停止并生成错误消息。
        对此的技术术语是:Java 将抛出异常（抛出错误）。

    错误： 错误不是异常，而是脱离程序员控制的问题，错误在代码中通常被忽略。
        例如，当栈溢出时，一个错误就发生了，它们在编译也检查不到的。


    try：用于包裹可能会抛出异常的代码块。
    catch：用于捕获异常并处理异常的代码块。
    finally：用于包含无论是否发生异常都需要执行的代码块。
    throw：用于手动抛出异常。
    throws：用于在方法声明中指定方法可能抛出的异常。
    Exception类：是所有异常类的父类，它提供了一些方法来获取异常信息，
                如 getMessage()、printStackTrace() 等。


    Java try 和 catch
        try 语句允许您定义一个代码块，以便在执行时对其进行错误测试。
        如果 try 块中发生错误，catch 语句允许您定义要执行的代码块。

        try 和 catch 关键字成对出现:
            try {
              //  要尝试的代码块
            }
            catch(ExceptionName e1) {   // Catch 语句包含要捕获异常类型的声明。
              //  处理错误的代码块
            }
        // 如果发生的异常包含在 catch 块中，异常会被传递到该 catch 块，这和传递一个参数的方法是一样。


    Exception 类是 Throwable 类的子类(Throwable还有一个子类Error)

    多重捕获块
        一个 try 代码块后面跟随多个 catch 代码块的情况就叫多重捕获。
        try{
           // 程序代码
        }catch(异常类型1 异常的变量名1){
          // 程序代码
        }catch(异常类型2 异常的变量名2){
          // 程序代码
        }catch(异常类型3 异常的变量名3){
          // 程序代码

    如果抛出异常的数据类型与 ExceptionType1 匹配，
    它在这里就会被捕获
    如果不匹配，它会被传递给第二个 catch 块。


}

     */

public class _01_try_catch {

    public static void main(String[] args) {

        int[] nums = {1,2,3};
//        System.out.println(nums[10]);
        //  Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: Index 10 out of bounds for length 3
        //	at Day_07_异常._01_try_catch.main(_01_try_catch.java:30)

        // 使用捕捉错误
        try {
            int[] try_nums = {1,2,3};
            System.out.println(try_nums[10]);
        } catch (IndexOutOfBoundsException e) {
            System.out.println("抛出错误：" + e.getMessage());
        }


        // 多重异常捕获
        try {
            int[] numbers = {1, 2, 3};
            System.out.println(numbers[10]);  // ArrayIndexOutOfBoundsException
            int result = 10 / 0;              // ArithmeticException
        }
        catch (ArrayIndexOutOfBoundsException e) {  // 先于此异常类型匹配，捕获
            System.out.println("数组索引不存在:" + e.getMessage());
        }
        catch (ArithmeticException e) {
            System.out.println("不能除以零:" + e.getMessage());
        }
        catch (Exception e) {
            System.out.println("其他错误:" + e.getMessage());
        }
        


    }

}

/*
Java 的非检查性异常。

异常	                            描述
ArithmeticException	            当出现异常的运算条件时，抛出此异常。例如，一个整数"除以零"时，抛出此类的一个实例。
ArrayIndexOutOfBoundsException	用非法索引访问数组时抛出的异常。如果索引为负或大于等于数组大小，则该索引为非法索引。
ArrayStoreException	            试图将错误类型的对象存储到一个对象数组时抛出的异常。
ClassCastException	            当试图将对象强制转换为不是实例的子类时，抛出该异常。
IllegalArgumentException	    抛出的异常表明向方法传递了一个不合法或不正确的参数。
IllegalMonitorStateException	抛出的异常表明某一线程已经试图等待对象的监视器，或者试图通知其他正在等待对象的监视器而本身没有指定监视器的线程。
IllegalStateException	        在非法或不适当的时间调用方法时产生的信号。换句话说，即 Java 环境或 Java 应用程序没有处于请求操作所要求的适当状态下。
IllegalThreadStateException	    线程没有处于请求操作所要求的适当状态时抛出的异常。
IndexOutOfBoundsException	    指示某排序索引（例如对数组、字符串或向量的排序）超出范围时抛出。
NegativeArraySizeException	    如果应用程序试图创建大小为负的数组，则抛出该异常。
NullPointerException	        当应用程序试图在需要对象的地方使用 null 时，抛出该异常
NumberFormatException	        当应用程序试图将字符串转换成一种数值类型，但该字符串不能转换为适当格式时，抛出该异常。
SecurityException	            由安全管理器抛出的异常，指示存在安全侵犯。
StringIndexOutOfBoundsException	此异常由 String 方法抛出，指示索引或者为负，或者超出字符串的大小。
UnsupportedOperationException	当不支持请求的操作时，抛出该异常。


下面的表中列出了 Java 定义在 java.lang 包中的检查性异常类。

异常	                        描述
ClassNotFoundException	    应用程序试图加载类时，找不到相应的类，抛出该异常。
CloneNotSupportedException	当调用 Object 类中的 clone 方法克隆对象，但该对象的类无法实现 Cloneable 接口时，抛出该异常。
IllegalAccessException	    拒绝访问一个类的时候，抛出该异常。
InstantiationException	    当试图使用 Class 类中的 newInstance 方法创建一个类的实例，而指定的类对象因为是一个接口或是一个抽象类而无法实例化时，抛出该异常。
InterruptedException	    一个线程被另一个线程中断，抛出该异常。
NoSuchFieldException	    请求的变量不存在
NoSuchMethodException	    请求的方法不存在
 */


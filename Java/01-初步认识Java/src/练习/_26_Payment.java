package 练习;

//abstract class Payment{
//    abstract void pay(double amount);
//}
//
//class Alipay extends Payment{
//    @Override
//    void pay(double amount) {
//        // “支付宝支付：[金额]”
//        System.out.println("支付宝支付：" + amount);
//    }
//}
//
//class WeChatPay extends Payment{
//    @Override
//    void pay(double amount) {
//        // “微信支付：[金额]”
//        System.out.println("微信支付：" + amount);
//    }
//}
//
//class CreditCard extends Payment{
//    @Override
//    void pay(double amount) {
//        System.out.println("信用卡支付：" + amount);
//    }
//}
//
//class PaymentProcessor{
//    void processPayment(Payment p, double amount){
//        p.pay(amount);
//    }
//}
//
//public class _26_Payment {
//
//    public static void main(String[] args) {
//
//        PaymentProcessor p = new PaymentProcessor();
//
//        Alipay A = new Alipay();
//        WeChatPay W = new WeChatPay();
//
//        CreditCard C = new CreditCard();
//
//        p.processPayment(A, 50);
//        p.processPayment(W, 100);
//
//        p.processPayment(C, 500);
//    }
//
//}

interface Payment{
    abstract void pay(double amount);
}

class Alipay implements Payment{
    @Override
    public void pay(double amount) {
        // “支付宝支付：[金额]”
        System.out.println("支付宝支付：" + amount);
    }
}

class WeChatPay implements Payment{
    @Override
    public void pay(double amount) {
        // “微信支付：[金额]”
        System.out.println("微信支付：" + amount);
    }
}

class CreditCard implements Payment{
    @Override
    public void pay(double amount) {
        System.out.println("信用卡支付：" + amount);
    }
}

class PaymentProcessor{
    void processPayment(Payment p, double amount){
        p.pay(amount);
    }
}

public class _26_Payment {

    public static void main(String[] args) {

        PaymentProcessor p = new PaymentProcessor();

        Alipay A = new Alipay();
        WeChatPay W = new WeChatPay();

        CreditCard C = new CreditCard();

        p.processPayment(A, 50);
        p.processPayment(W, 100);

        p.processPayment(C, 500);
    }

}

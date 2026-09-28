package 练习;

//abstract class Device{
//    abstract void turnOn();
//    abstract void turnOff();
//}
//
//class Light extends Device{
//    @Override
//    void turnOn(){
//        System.out.println("灯已打开");
//    }
//    @Override
//    void turnOff(){
//        System.out.println("灯已关闭");
//    }
//}
//
//class Thermostat extends Device{
//    @Override
//    void turnOn(){
//        System.out.println("恒温器启动");
//    }
//    @Override
//    void turnOff(){
//        System.out.println("恒温器关闭");
//    }
//}
//
//class TV extends Device{
//    @Override
//    void turnOn(){
//        System.out.println("电视开机");
//    }
//    @Override
//    void turnOff(){
//        System.out.println("电视关机");
//    }
//}
//
//class RemoteControl {
//    public void controlDevice(Device d){
//        d.turnOn();
//        d.turnOff();
//    }
//}
//
//public class _27_智能家居控制 {
//
//    public static void main(String[] args) {
//
//        RemoteControl r = new RemoteControl();
//
//        Device light = new Light();
//        Device thermostat = new Thermostat();
//        Device tv = new TV();
//
//        r.controlDevice(light);
//        r.controlDevice(thermostat);
//        r.controlDevice(tv);
//
//
//
//    }
//}

interface Device{
    abstract void turnOn();
    abstract void turnOff();
}

class Light implements Device{
    @Override
    public void turnOn(){
        System.out.println("灯已打开");
    }
    @Override
    public void turnOff(){
        System.out.println("灯已关闭");
    }
}

class Fan implements Device{
    @Override
    public void turnOn(){
        System.out.println("风扇启动");
    }
    @Override
    public void turnOff(){
        System.out.println("风扇停止");
    }
}

class TV implements Device{
    @Override
    public void turnOn(){
        System.out.println("电视开机");
    }
    @Override
    public void turnOff(){
        System.out.println("电视关机");
    }
}

class RemoteControl {
    public void controlDevice(Device d){
        d.turnOn();
        d.turnOff();
    }
}

public class _27_智能家居控制 {

    public static void main(String[] args) {

        RemoteControl r = new RemoteControl();

        Device light = new Light();
        Device fan = new Fan();
        Device tv = new TV();

        r.controlDevice(light);
        r.controlDevice(fan);
        r.controlDevice(tv);

    }
}


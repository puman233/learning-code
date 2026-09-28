package Day_06_OOP;


class Animal {
    public void animalSound() {
        System.out.println("The animal makes a sound");
    }
}

class Pig extends Animal {
    @Override
    public void animalSound() {
        System.out.println("The pig says: wee wee");
    }
}

class Dog extends Animal {
    @Override
    public void animalSound() {
        System.out.println("The dog says: bow wow");
    }
}

abstract class Animal1 {
    abstract void eat();
}

class Cat1 extends Animal1 {
    @Override
    public void eat() {
        System.out.println("猫吃鱼");
    }
    public void work(){
        System.out.println("猫抓老鼠");
    }
}

class Dog1 extends Animal1{
    @Override
    public void eat() {
        System.out.println("狗吃骨头");
    }
    public void work(){
        System.out.println("狗看家");
    }
}


public class _09_多态 {

/*
Java 多态
    多态意味着"多种形式"，
    当我们有许多通过继承相互关联的类时，就会产生多态性。

    继承 允许我们从另一个类继承属性和方法。
    多态性使用这些方法来执行不同的任务。
    这允许我们以不同的方式执行单个操作。

意义：
    因为它对于代码的可重用性很有用:
    在创建新类时可以重用现有类的属性和方法。


 */
    public static void main(String[] args) {
        Animal myAnimal = new Animal();  // 创建一个 Animal 对象
        Animal myPig = new Pig();  // 创建 Pig 对象
        Animal myDog = new Dog();  // 创建一个 Dog 对象

        myAnimal.animalSound();
        myPig.animalSound();
        myDog.animalSound();


        // 向上转型：
        // 1. 向上转型是指将子类对象赋值给父类引用变量。
        // 2. 向上转型是安全的，因为子类对象是父类对象的一种特殊类型。
        // 3. 向上转型后，父类引用变量只能访问父类中定义的方法和属性，不能访问子类中定义的方法和属性。
        // 4. 向上转型可以实现多态性，因为父类引用变量可以指向不同的子类对象，从而实现不同的行为。
        // 5. 向上转型的语法是：父类类型 变量名 = new 子类类型();
        Animal1 a1 = new Cat1();    // 向上转型
        Animal1 a2 = new Dog1();    // 向上转型
        a1.eat();   // 调用的是 Cat1 的 eat 方法
        a2.eat();   // 调用的是 Dog1 的 eat 方法

        // 由于 Animal1 是抽象类，无法直接实例化，所以无法调用 work 方法
        // a1.work();  // 调用的是 Cat1 的 work 方法
        // a2.work();  // 调用的是 Dog1 的 work 方法
        
        // 向下转型：
        // 1. 向下转型是指将父类引用变量赋值给子类对象。
        // 2. 向下转型是不安全的，因为父类对象可能不是子类对象的一种特殊类型。
        // 3. 向下转型后，子类对象可以访问父类中定义的方法和属性，也可以访问子类中定义的方法和属性。
        // 4. 向下转型的语法是：子类类型 变量名 = (子类类型) 父类引用变量;
        Cat1 c = (Cat1) a1;  // 向下转型
        c.work();  // 调用的是 Cat1 的 work 方法
        Dog1 d = (Dog1) a2;  // 向下转型
        d.work();  // 调用的是 Dog1 的 work 方法

        // instanceof 运算符：
        // 1. instanceof 运算符用于测试一个对象是否是一个类的实例。
        // 2. instanceof 运算符的语法是：对象 instanceof 类名; 
        // 3. instanceof 运算符返回一个布尔值，
        //    如果对象是类的实例，则返回 true，否则返回 false。
        System.out.println(a1 instanceof Cat1);  // true
        System.out.println(a2 instanceof Dog1);  // true

        Cat1 c1 = new Cat1();
        Dog1 d1 = new Dog1();

        d1.eat();  // 调用的是 Dog1 的 eat 方法
        c1.eat();  // 调用的是 Cat1 的 eat 方法
        

    }

}



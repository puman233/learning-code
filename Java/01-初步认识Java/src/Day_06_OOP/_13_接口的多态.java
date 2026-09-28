package Day_06_OOP;

public class _13_接口的多态 {

    public static void main(String[] args) {

        Pig41 pig41 = new Pig41();
        pig41.eat();

        Dog41 dog41 = new Dog41();
        dog41.eat();

    }

}

interface Eat2 {
    public void eat();
}

class Pig41 implements Eat2 {
    @Override
    public void eat() {
        System.out.println("吃猪");
    }
}

class Dog41 implements Eat2 {
    @Override
    public void eat() {
        System.out.println("吃狗");
    }
}





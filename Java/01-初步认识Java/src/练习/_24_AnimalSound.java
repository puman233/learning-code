package 练习;

//abstract class Animal {
//    public void sound(){};
//}
//
//class Cat extends Animal {
//    @Override
//    public void sound(){
//        System.out.println("喵喵喵");
//    };
//}
//
//class Dog extends Animal {
//    @Override
//    public void sound(){
//        System.out.println("汪汪汪");
//    };
//}
//
//
//public class _24_AnimalSound {
//
//    public static void main(String[] args) {
//
//        Animal[] animals = new Animal[2];
//
//        animals[0] = new Cat();
//        animals[1] = new Dog();
//
//        for (int i = 0; i < animals.length; i++) {
//            animals[i].sound();
//        }
//
//    }
//}


interface Animal {
    abstract void sound();
}

class Cat implements Animal {
    @Override
    public void sound(){
        System.out.println("喵喵喵");
    }
}

class Dog implements Animal {
    @Override
    public void sound(){
        System.out.println("汪汪汪");
    }
}


public class _24_AnimalSound {

    public static void main(String[] args) {

        Animal[] animals = new Animal[2];

        animals[0] = new Cat();
        animals[1] = new Dog();

        for (int i = 0; i < animals.length; i++) {
            animals[i].sound();
        }

    }
}
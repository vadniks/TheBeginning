/**
 * @author Vad Nik.
 * @version dated Dec 15, 2017.
 * @link https://github.com/Vadniks
 */
public class HW7 { //NOTICE! METHODS BELOW AREN'T UNIVERSAL! REMEMBER IT! But I've tried for a long time to make them such.
// And I haven't enough time to make it in GUI. Next time I'll tri to make all homeworks in GUI if it's necessary.
    Plate plate = new Plate(50);

    public static void main(String[] args) {
        Cat[] cats = {new Cat("Ivan", 10, false), new Cat("Peter", 15, false)};
        HW7 hw7 = new HW7();
        System.out.println();
        for (Cat cat4 : cats) {
            System.out.println(cat4);
        }
        System.out.println();
        System.out.println("Variable 'food' by default is " + hw7.plate.food);
        System.out.println();
        System.out.println("Program has just begun to feel the cats.");
        for (Cat cat3 : cats) {
            cat3.feelingCat(cat3, hw7);
            System.out.println();
            System.out.println(cat3 + " . He has just eaten.");
            hw7.plate.afterFoodWasDecreased();
        }
        hw7.plate.addFood(10);
        System.out.println();
        System.out.println("-------------------------REPEATING-------------------------");
        System.out.println("Program will add 10 food units and repeat the feeling loop.");
        System.out.println();
        System.out.println("Variable 'food' is now " + hw7.plate.food + ".");
        System.out.println();
        for (Cat cat5 : cats) {
            cat5.setSatiety(false);
            System.out.println(cat5);
        }
        for (Cat cat6 : cats) {
            cat6.feelingCat(cat6, hw7);
            System.out.println();
            System.out.println(cat6 + " . He has just eaten.");
            hw7.plate.afterFoodWasDecreased();
        }
    }
}

class Cat {

    String name;
    int appetite;
    boolean satiety;

    Cat(String name, int appetite, boolean satiety) {
        this.name = name;
        this.appetite = appetite;
        this.satiety = satiety;
    }

    public void feelingCat(Cat cat, HW7 hw7) {
        hw7.plate.decreaseFood(cat);
        setSatiety(true);
    }

    public void setSatiety(boolean satiety1) {
        satiety = satiety1;
    }

    @Override
    public String toString() {
        return "Cat's name is " + name + ", cat's appetite is " + appetite + ", is cat full: " + satiety;
    }
}

class Plate {

    int food;

    Plate(int food) {
        this.food = food;
    }

    public void decreaseFood(Cat cat) {
        if (food >= cat.appetite) {
            food -= cat.appetite;
        }
    }

    public void afterFoodWasDecreased() {
        System.out.println("Variable food after it was decreased: " + food);
    }

    public void addFood(int food1) {
        if (food < 50) {
            food += food1;
        }
    }
}
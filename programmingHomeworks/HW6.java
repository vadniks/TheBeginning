/**
 * @author Vad Nik.
 * @version dated Dec 09, 2017.
 * @link @VadNiks or https://github.com/VadNiks. // My account on GitHub.
 */
public class HW6 {
    public static void main(String[] args) {
        Animal cat = new Cat(200, 2, false, 0, "Cat");
        Animal dog = new Dog(500, 0.5, true, 10, "Dog");
        String a = "Cat";
        String  b = (String) Animal.getWhoLikeObject();
        if (a.equals(b)) {
            getStringForCat();
        }
    }
    public static String getStringForCat() {
        return "According to the condition cat cannot swim.";
    }
}

class Animal {
    private int long1; // IDEA doesn't like word "long", perhaps because it's reserved in lang, like variable long for example.
    private double height;
    private boolean isSwim;
    public int swimLong;
    private static String who;

    Animal(int long1, double height, boolean isSwim, String who, int swimLong) {
        this.long1 = long1;
        this.height = height;
        this.isSwim = isSwim;
        this.swimLong = swimLong;
        this.who = who;
        space();
        run(long1, who);
        swim(isSwim, this.swimLong, who);
        jump(height, who);
        space();
    }

    public void run(int long1, String who) {
        System.out.println();
    }
    public void swim(boolean isSwim, int swimLong, String who) {
        System.out.println();
    }
    public void jump(double height, String who) {
        System.out.println();
    }
    public void space() {
        System.out.println();
    }

    public String getWho() {
        return who;
    }

    public static Object getWhoLikeObject() {
        return who;
    }
}

class Cat extends Animal {
    Cat(int long1, double height, boolean isSwim, int swimLong, String who) {
        super(long1, height, isSwim, who, swimLong);
    }

    @Override
    public void run(int long1, String who) {
        System.out.println(who + " runs " + long1);
    }

    @Override
    public void swim(boolean isSwim, int swimLong, String who) {
        System.out.println(who + " swims " + swimLong + " " + HW6.getStringForCat());
    }

    @Override
    public void jump(double height, String who) {
        System.out.println(who + " jumps " + height);
    }

    //    @Override // It's for me, like an example of how it may be.
//    public void jump(int height) {
//        super.jump(height);
//    } // End.
}

class Dog extends Animal {
    Dog(int long1, double height, boolean isSwim, int swimLong, String who) {
        super(long1, height, isSwim, who, swimLong);
    }

    @Override
    public void run(int long1, String who) {
        System.out.println(who + "runs " + long1);
    }

    @Override
    public void swim(boolean isSwim, int swimLong, String who) {
        System.out.println(who + " swims " + swimLong);
    }

    @Override
    public void jump(double height, String who) {
        System.out.println(who + " jumps " + height);
    }
}
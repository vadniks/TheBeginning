import java.util.ArrayList;
import java.util.Arrays;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.Semaphore;

/**
 * @author Vad Nik.
 * @version dated Feb 28, 2018.
 * @link https://github.com/vadniks
 */
public class HW5J3 {
    private static final int CARS_COUNT = 4;
    static final CyclicBarrier cb = new CyclicBarrier(CARS_COUNT);
    static final CountDownLatch cdl = new CountDownLatch(CARS_COUNT);
    static final CountDownLatch cdl2 = new CountDownLatch(CARS_COUNT);
    static final CountDownLatch cdl3 = new CountDownLatch(CARS_COUNT);
    static final CountDownLatch cdl4 = new CountDownLatch(CARS_COUNT);
    //static final CountDownLatch cdl5 = new CountDownLatch(CARS_COUNT);
    static Semaphore smp = new Semaphore(2);
    static final CountDownLatch cdl6 = new CountDownLatch(CARS_COUNT);
    static final CountDownLatch cdl7 = new CountDownLatch(CARS_COUNT);
    static final CountDownLatch cdl8 = new CountDownLatch(CARS_COUNT);

    public static void main(String[] args) throws InterruptedException {
        System.out.println("ВАЖНОЕ ОБЪЯВЛЕНИЕ >>> Подготовка!!!");
        Race race = new Race(new Road(60), new Tunnel(), new Road(40));
        Car[] cars = new Car[CARS_COUNT];
        for (int i = 0; i < cars.length; i++) {
            cars[i] = new Car(race, 20 + (int) (Math.random() * 10));
        }
        for (Car car : cars) {
            new Thread(car).start();
        }
        cdl.await();
        System.out.println("ВАЖНОЕ ОБЪЯВЛЕНИЕ >>> Гонка началась!!!");
        cdl2.await();
        cdl3.await();
        cdl8.await();
        System.out.println("ВАЖНОЕ ОБЪЯВЛЕНИЕ >>> Гонка закончилась!!!");
    }
}

class Car implements Runnable {
    private static int CARS_COUNT;
    static {
        CARS_COUNT = 0;
    }
    private Race race;
    private int speed;
    private String name;
    String getName() {
        return name;
    }
    int getSpeed() {
        return speed;
    }
    Car(Race race, int speed) {
        this.race = race;
        this.speed = speed;
        CARS_COUNT++;
        this.name = "Участник #" + CARS_COUNT;
    }
    @Override
    public void run() {
        try {
            System.out.println(this.name + " готовится");
            Thread.sleep(500 + (int)(Math.random() * 800));
            HW5J3.cb.await();
            System.out.println(this.name + " готов");
            HW5J3.cdl.countDown();
            HW5J3.cdl6.countDown();
        } catch (Exception e) {
            e.printStackTrace();
        }
        for (int i = 0; i < race.getStages().size(); i++) {
            race.getStages().get(i).go(this);
        }
    }
}

abstract class Stage {
    int length;
    String description;
    String getDescription() {
        return description;
    }
    public abstract void go(Car c);
}

class Road extends Stage {
    Road(int length) {
        this.length = length;
        this.description = "Дорога " + length + " метров";
    }
    @Override
    public void go(Car c) {
        try {
            //if (this.description.equals("Дорога 40 метров"))
                //HW5J3.cdl5.await();
            if (this.description.equals("Дорога 60 метров"))
                HW5J3.cdl6.await();
            System.out.println(c.getName() + " начал этап: " + description);
            Thread.sleep(length / c.getSpeed() * 1000);
            System.out.println(c.getName() + " закончил этап: " + description);
            HW5J3.cdl2.countDown();
            //if (this.description.equals("Дорога 60 метров"))
                HW5J3.cdl4.countDown();
            if (this.description.equals("Дорога 40 метров"))
                HW5J3.cdl3.countDown();
            if (this.description.equals("Дорога 40 метров"))
                HW5J3.cdl7.countDown();
            if (this.description.equals("Дорога 40 метров") && HW5J3.cdl7.getCount() == 3) {
                HW5J3.cdl7.await();
                System.out.println(c.getName() + " WIN");
                HW5J3.cdl7.countDown();
            }
            if (this.description.equals("Дорога 40 метров"))
                HW5J3.cdl8.countDown();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Tunnel extends Stage {
    Tunnel() {
        this.length = 80;
        this.description = "Тоннель " + length + " метров";
    }
    @Override
    public void go(Car c) {
        try {
            try {
                HW5J3.cdl4.await();
                System.out.println(c.getName() + " готовится к этапу(ждет): " + description);
                HW5J3.smp.acquire();
                System.out.println(c.getName() + " начал этап: " + description);
                Thread.sleep(length / c.getSpeed() * 1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                System.out.println(c.getName() + " закончил этап: " + description);
                HW5J3.smp.release();
                //HW5J3.cdl5.countDown();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

class Race {
    private ArrayList<Stage> stages;
    ArrayList<Stage> getStages() { return stages; }
    Race(Stage... stages) {
        this.stages = new ArrayList<>(Arrays.asList(stages));
    }
}
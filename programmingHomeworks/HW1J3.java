/**
 * @author Vad Nik
 * @version dated Jan 28, 2018
 * @link http://github.com/vadniks
 */
import java.util.ArrayList;
import java.util.Arrays;
//import java.util.Random;
/*
A random-using and a generic-using version.
 */
public class HW1J3<T> { // Means Homework 1 Java 3.

    private T[] arr; //= (T[])(new Object[4]);
    private ArrayList<T> arr2 = new ArrayList<>();
    //private static Random rand = new Random();

    public static void main(String[] args) {
        HW1J3<Integer> hw1J3 = new HW1J3<>();
        //hw1J3.arr = new Integer[]{1, 2, 3, 4};
        hw1J3.initArr();
        hw1J3.changeArray();
        hw1J3.arrayToArrayList();
        hw1J3.task3();
        //System.out.println(rand(0.7f, 1.0f));  // <-- For debug;
    }

    private void initArr() {
        Integer[] ar = {1, 2, 3, 4};
        arr = (T[]) ar;
    }

    private void changeArray() {
        System.out.println("\nArray before changing: " + Arrays.toString(arr));
        //for (int i = 0; i < arr.length; i++)
        //arr[i] = arr.length+1 - arr[i];
        T j = arr[0];
        arr[0] = arr[1];
        arr[1] = j;
        System.out.println("Array after changing: " + Arrays.toString(arr));
    }

    private void arrayToArrayList() {
        arr2.addAll(Arrays.asList(arr));
        System.out.println("Collection after array was added to it: " + arr2 + "\n");
    }

    //--------------------------------------------------------------------------------Task3:

    private static float rand(float min, float max) {
        int i = (int) (Math.random() * 10);
        float r = min;
        switch (i) {
            case 1 :
                r = max;
                break;
            case 2 :
                r = min + 0.1f;
                break;
            case 3 :
                r = max - 0.1f;
                break;
            case 4 :
                r = min + 0.2f;
                break;
            case 5 :
                break;
        }
        return r;
    }

//    private static float rand2(float min, float max) {
//        max -= min;
//        float n = ((float) Math.random() * ++max) + min;
//        return n;
//
//        float r = rand.nextFloat();
//        if (r < min && r > max)
//            return min;
//        else if (r < min || r > max)
//            return min + 0.1f;
//        else if (r >= min && r <= 1.0f)                  // <-- Not working correctly;
//            return r;
//        return max;
//
//        float r = rand.nextFloat();
//        while (!(r >= 0.7f && r <= 1.0f))
//            r = rand.nextFloat();
//        if (r >= 0.7f && r <= 1.0f)
//            return r;
//        else
//            return 1.0f;
//    }

    private void task3() {
        System.out.println("Task3:\n");
        Apple apple = new Apple();
        Orange orange = new Orange();
        Box<Apple> box1 = new Box<>(apple);
        Box<Orange> box2 = new Box<>(orange);
        System.out.println(box1.getWeight());
        System.out.println(box2.getWeight());
        System.out.println(box1.compare(box2));
        System.out.println(box2.compare(box1));
        Box<Apple> box3 = new Box<>(apple);
        System.out.println(box1.compare(box3));
        box3.addToBox(box1, apple);
        System.out.println(box3.getWeight());
        System.out.println(box1.getWeight());
    }

    abstract class Fruit {
        abstract float getWeight();
    }

    class Apple extends Fruit {
        @Override
        float getWeight() {
            return rand(0.7f, 1.0f);
            //return 0.7f;
        }
    }

    class Orange extends Fruit {
        @Override
        float getWeight() {
            return rand(1.2f, 1.5f);
            //return 1.2f;
        }
    }

    class Box<T extends Fruit> {

        private T ob;
        private ArrayList<T> arr = new ArrayList<>();
        private float result;

        Box(T ob) {
            this.ob = ob;
            result += ob.getWeight();
            add(ob);
        }

        void add(T ob) {
            arr.add(ob);
        }

        float getWeight() {
            return result;
        }

        boolean compare(Box box) {
            return result == box.result;
            //return getWeight == box.getWeight;
        }

        void addToBox(Box box, T ob) {
            if (result == box.result) {
                box.add(ob);
                arr.remove(ob);
                result = 0;
                box.result += ob.getWeight();
            }
        }
    }
}
package geekbrains.lessons.homework;

/**
 * @author Vad Nik.
 * @version 2.0 dated Nov 23, 2017.
 * @Homeworkversion homework for lesson 1 (Modified: added task 8, added literals).
 */

public class Main {

    public static void main(String[] args) {
        byte a1 = 1;
        short a2 = 2;
        long a3 = 3;
        float a4 = 4;
        double a5 = 5;
        char a6 = 6;
        boolean a7 = true;
        System.out.println("\n\tJava Variables:\n" + a1 + " " + a2 + " " + a3 + " " + a4 + " " + a5 + " " + a6 + " " + a7 +
        "\n'1' is Byte, '2' is Short, '3' is Long, '4' is Float, '5' is Double, '6' is Char, 'true' is Boolean\n");
        int a = 1;
        int b = 2;
        int c = 4;
        int d = 5;
        int res = a + b + c + d;
        System.out.println("Result of test variables is " + res);
        System.out.println("Result = " + calculate(a, b, c, d));
        task10and20(5, 6);
        isPositiveOrNegative(-30);
        isNegative(-2);
        greetings("Lorem Ipsum");
        years(100);
    }

    public static int calculate(int a, int b, int c, int d) {
        return a * (b + (c / d));
    }

    public static boolean task10and20(int x1, int x2) {
        if (x1 > 10 && x2 < 20) {
            return true;
        } else {
            return false;
        }
    }

    public static void isPositiveOrNegative(int x) {
        if(x < 0) {
            System.out.println(x + " is negative");
        } else {
            System.out.println(x + " is positive");
        }
    }

    public static boolean isNegative(int x) {
        if(x < 0) {
            return true;
        }
        return false;
    }

    public static void greetings(String name) {
        System.out.println("Hello, " + name);
    }

    public static void years(int whichYear) {
        int x = 4;
        int y = 100;
        int z = 400;
        if (whichYear % x == 0) {
            if ((whichYear % y != 0) || (whichYear % z == 0)){
                System.out.println(whichYear + " is a leap year.");
            } else {
                System.out.println(whichYear + " is not a leap year.");
            }
        } else {
            System.out.println(whichYear + " is not a leap year.");
        }
    }
}

/**
 * @author Vad Nik.
 * @version dated Nov 29, 2017.
 */
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        task1();
        task2();
    }

    public static void task1() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("You need to guess the number");
        int a = 10;
        int number = (int)(Math.random() * a);
        int count = 0;
        int count2 = 0;
        String repeat = "1";
        while(count < 3 && count2 != number) {
            System.out.println("Guess the number from 1 to " + a);
            int inputNumber = scanner.nextInt();
            if (inputNumber == number) {
                System.out.println("You guessed right.");
                break;
            } else if (inputNumber > number) {
                System.out.println("Number is less.");
            } else {
                System.out.println("Number is increase.");
                count++;
            }
            if (count == 3) {
                System.out.println("You lose! Would you like to repeat? 1 - yes, 2 - no.");
                Scanner scanner2 = new Scanner(System.in);
                repeat = scanner2.next();
                while (repeat.equals("1")) {
                    task1();
                    break;
                }
                break;
            }
        }
    }

    public static void task2() {                         // Task that was in bold.
        String[] words = {"apple\norange\nlemon\nbanana\napricot\navocado\nbroccoli" +
                "\ncarrot\ncherry\ngarlic\ngrape\nmelon\nleak" +
                "\nkiwi\nmango\nmushroom\nnut\nolive\npea\npeanut\npear" +
                "\npepper\npineapple\npumpkin\npotato"};

        try {
            FileWriter fileWriter = new FileWriter("text1.txt");
            for (int i = 0; i < words.length; i++) {
                fileWriter.write(words[i]);
            }
            fileWriter.close();
         } catch (IOException ex) {
            ex.printStackTrace();
        }

        try {
            FileReader fileReader = new FileReader("text1.txt");
            for (int i = words.length-1; i > words.length; i--) {
                fileReader.read();
            }
            int a;
            while ((a = fileReader.read()) != -1) {
                System.out.println("Text WriterReadFromFile method:");
                System.out.println(Arrays.asList(words));
                System.out.println();
                break;
            }
            fileReader.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }                                                                    // End.
}
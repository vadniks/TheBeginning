import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
/**
 * @author Vad Nik.
 * @version dated Dec 23, 2017.
 * @link http://github.com/Vadniks
 */
public class HW2J2 {
    private String[][] arr = {{"1", "2", "3", "4"}};
    private int a;
    private int c;
    private List<Character> arr2 = new ArrayList<>();

    public static void main(String[] args) {
        HW2J2 hw2J2 = new HW2J2();
        hw2J2.doArr(hw2J2.arr);
        System.out.println("\nThe result of added up array's elements is " + hw2J2.a + ".");
        System.out.println("All the array's elements: " + Arrays.deepToString(hw2J2.arr) + ".");
        hw2J2.writeFile(hw2J2.arr);
        hw2J2.readFile();
        hw2J2.displayList();
    }

    public void writeFile(String[][] arr) {
        try {
            FileWriter fileWriter = new FileWriter("New");
            for (int i = 0; i < arr.length; i++) {
                for (int j = 3; j >= 0; j--) {
                    fileWriter.write(arr[i][j]);
                }
            }
            fileWriter.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    public void readFile() {
        int d;
        try {
            FileReader fileReader = new FileReader("New");
            while ((d = fileReader.read()) != -1) {
                arr2.add((char) d);
                //System.out.println((char) d); // <-- For debug.
            }
            fileReader.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    public void displayList() {
        System.out.println("After list was rewrited: " + arr2 + ".");
    }

    public void doArr(String arr[][]) {
        for (int b = 0; b < arr.length; b++) {
            if (arr.length > 4 || arr[b].length > 4) {
                throw new ArrayIndexOutOfBoundsException("Array index out of Bounds.");
            } else {
                for (int i = 0; i < arr.length; i++) {
                    for (int j  = 0; j < arr[i].length; j++) {
                        try {
                            a += Integer.parseInt(arr[i][j]); // This line adds array's elements up (it summarizes them).
                            c = Integer.parseInt(arr[i][j]);
                        } catch (NumberFormatException ex) {
                            ex.printStackTrace();
                            throw new NumberFormatException((i + 1) + " " + (j + 1));
                        }
                    }
                }
            }
        }
    }
}
import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

/**
 * @author Vad nik
 * @version dated Feb 10, 2018
 */
public class HW3J3 {
    private String pathFinal2;

    public static void main(String[] args) {
        HW3J3 hw3J3 = new HW3J3();
        hw3J3.readBytesFromFile();
        hw3J3.filesToFile();
        hw3J3.startEmployee();
        hw3J3.startTask3();
    }

    private void startEmployee() {
        final String DIR_ADV_TK = "forAdvancedTask";
        final String FILE_ADV_TK = "\\advancedTask.txt";
        Employee employee = new Employee("Bob", "engineer", "bob@email.com", "111 111 11 11", 40000, 30);
        try(ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(pathFinal2 + DIR_ADV_TK + FILE_ADV_TK))) {
            out.writeObject(employee);
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        Employee employee2;
        try(ObjectInputStream in = new ObjectInputStream(new FileInputStream(pathFinal2 + DIR_ADV_TK + FILE_ADV_TK))) {
            employee2 = (Employee) in.readObject();
            System.out.println(employee2.info());
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private void startTask3() {
        System.out.println("Would you like to start task3? y/n");
        Scanner sca = new Scanner(System.in);
        String f = sca.next();
        switch (f) {
            case "y":
                new Task3();
                break;
            case "n":
                System.exit(0);
                break;
        }
        sca.close();
    }

    private void readBytesFromFile() {
        byte[] arr = {};
        int y = 0;
        try(FileReader fRead = new FileReader("new.txt")) {
            while (fRead.read() != -1)
                y++;
            arr = new byte[y];
            //fRead.reset(); "isn't supported" - IDEA says.
            FileReader fRead2 = new FileReader("new.txt");
            int i = 0;
            int x;
            while ((x = fRead2.read()) != -1) {
                arr[i] = (byte) x;
                i++;
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        ByteArrayInputStream in = new ByteArrayInputStream(arr);
        int x;
        int[] arr2 = new int[y];
        int j = 0;
        while ((x = in.read()) != -1) {
            arr2[j] = x;
            j++;
            // or System.out.print(x + " ");
        }
        System.out.println("\n" + Arrays.toString(arr2) + "\n");
    }

    private void filesToFile() {
        final String P = "HW3J3.java";
        File file  = new File(P);
        String path = file.getAbsolutePath();
        IntStream j = path.chars();
        int[] ip = j.toArray();
        int iip = ip.length;
        iip = iip - P.trim().length();
        String pathFinal = path.trim().substring(0, iip);
        pathFinal2 = pathFinal;
        final String PA = "news\\";
        pathFinal = pathFinal.trim().concat(PA);
        //System.out.println(pathFinal);
        String[] filesData = new String[5];
        File dir = new File(pathFinal);

        int t = 0;
        for (File fileR : dir.listFiles()) {
            try(Scanner sc = new Scanner(fileR)) {
                while (sc.hasNext()) {
                    filesData[t] = sc.next();
                    t++;
                }
            } catch (Exception ex) {
                ex.printStackTrace();
            }
//            try(FileReader fileReader = new FileReader(fileR)) {
//                int x;
//                int i = 0;
//                while ((x = fileReader.read()) != -1) {            // <-- For the future.
//                    filesData[i] += (char) x;
//                    i++;
//                }
//            } catch (Exception ex)  {
//                ex.printStackTrace();
//            }
        }
        //System.out.println(Arrays.toString(filesData));

        final String PAA = "newFinal.txt";
        try(FileWriter writer = new FileWriter(pathFinal2 + PAA)) {
            for (String aFilesData : filesData) {
                writer.write(aFilesData);
            }
//            for (int i = 0; i < filesData.length; i++) {
//                writer.write(filesData[i]);
//            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    class Task3 {
        private final String NAME = "ft3.txt";
        private final String PAAA = "forTask3\\";
        private int o = 1800;
        private int tw = 3600;
        private int th = 5400;
        private int f = 7200;
        private int fi = 9000;
        private long time = System.currentTimeMillis();

        Task3() {
            //fillTxt();
            fillTxt2();
            printPage();
        }

        private void fillTxt2() {
            System.out.println("Time is " + time);
            final String PSEUDO_TEXT = "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq" +
                    "qwertyuiopasdfgqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq";
            try(FileWriter fw = new FileWriter(pathFinal2 + PAAA + NAME)) {
                fw.write(PSEUDO_TEXT);
            } catch (Exception ex) {
                ex.printStackTrace();
            }
            time = System.currentTimeMillis();
            System.out.println("Time is " + time);
        }

        private void fillTxt() {
            System.out.println("Time is " + time);
//            for (int j = 0; j < 4; j++) {
//                try(FileWriter fw = new FileWriter(pathFinal2 + PAAA + NAME)) {
//                    for (int i = 0; i < 1799; i++) {
//                        fw.write("q");
//                    }
//                } catch (Exception ex) {
//                    ex.printStackTrace();
//                }
//            }
            try(FileWriter fw = new FileWriter(pathFinal2 + PAAA + NAME)) {
                int count = 0;
                int count2 = 0;
                int chCount = 0;
                while (count != 4) {
                    while (count2 != 1799) {
                        assert chCount < 10;
                        fw.write((char) chCount);
                        chCount++;
                        count2++;
                    }
                    count++;
                }
            } catch (Exception ex) {
                ex.printStackTrace();
            }
            time = System.currentTimeMillis();
            System.out.println("Time is " + time);
        }

        private void printPage() {
            time = System.currentTimeMillis();
            System.out.println("Time is " + time);
            try(FileReader fr = new FileReader(pathFinal2 + PAAA + NAME)) {
                int ti;
                char[] arr = new char[fi];
                String g = null;
                int h = 0;
                while ((ti = fr.read()) != -1) {
                    arr[h] += (char) ti;
                    h++;
                }
                for (char anArr : arr) {
                    g += String.valueOf(anArr);
                }
                String gFinal = null;
                assert g != null;
                if (g.contains("null")) {
                    g = g.substring(4);
                    gFinal = g;
                }
                final String G_FINAL = gFinal;
                if (g.length() == fi) {
                    task3Print(g, G_FINAL);
                }
            } catch (Exception ex) {
                ex.printStackTrace();
            }
            time = System.currentTimeMillis();
            System.out.println("Time is " + time);
        }

        private void task3Print(String g, final String G_FINAL) {
            time = System.currentTimeMillis();
            System.out.println("Time is " + time);
            Scanner sc = new Scanner(System.in);
            System.out.println("Type 1 - 5 to get it's number page, 6 to exit.");
            int t = sc.nextInt();
            g = G_FINAL;
            //System.out.println(g.length());
            switch (t) {
                case 1:
                    System.out.println("0 - " + o + " " + g.substring(0, o).length() + " " + " " + (g.substring(0, 0) == null) + " "  + g.substring(0, o));
                    g = G_FINAL;
                    break;
                case 2:
                    System.out.println(o + " - " + tw + " " + g.substring(o, tw).length() + " " + (g.substring(0, 0) == null) + " "  + g.substring(o, tw));
                    g = G_FINAL;
                    break;
                case 3:
                    System.out.println(tw + " - " + th + " " + g.substring(tw, th).length() + " " + (g.substring(0, 0) == null) + " "  + g.substring(tw, th));
                    g = G_FINAL;
                    break;
                case 4:
                    System.out.println(th + " - " + f + " " + g.substring(th, f).length() + " " + (g.substring(0, 0) == null) + " "  + g.substring(th, f));
                    g = G_FINAL;
                    break;
                case 5:
                    System.out.println(f + " - " + fi + " " + g.substring(f, fi).length() + " " + (g.substring(0, 0) == null) + " " + g.substring(f, fi));
                    g = G_FINAL;
                    break;
                case 6:
                    System.exit(0);
                    break;
            }
            time = System.currentTimeMillis();
            System.out.println("Time is " + time);

            /*
            I have no idea why only in first case substring prints symbols
            and in other cases null-checking displays false, but doesn't print symbols,
            and IDEA displays that null-checking is always false (means substring contains something).
            Or I just don't understand something?

            And I measure time, and it was less than 3 seconds in runtime.

            I finally found out why it's like I wrote below, I think that's something with the 'fillTxt()' method,
            but I don't understand why it's this way? When I filled it myself program begun working the right way.
            I think my algorithm writes less than 9000 symbols, but if it's true, I don't understand why is it like this.
            According to my imagine of how it should be, algorithm writes 1800 symbols first and than repeats this operation 3 times.

            So I'll try make it working normally, I hope...
             */

            task3Print(g, G_FINAL);
        }
    }
}

class Employee implements Serializable {
    private String name;
    private String position;
    private String email;
    private String phone;
    private int salary;
    private int age;

    Employee(String name, String position, String email, String phone, int salary, int age) {
        this.name = name;
        this.position = position;
        this.email = email;
        this.phone = phone;
        this.salary = salary;
        this.age = age;
    }

    String info() {
        return ("\nAdvanced Task:\n" + name +
                "\n| Position: " + position +
                "\n| Email: " + email +
                "\n| Phone: " + phone +
                "\n| Salary: " + salary +
                "\n| Age: " + age + "\n");
    }
}
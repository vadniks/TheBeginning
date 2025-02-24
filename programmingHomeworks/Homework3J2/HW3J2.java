import java.io.*;
import java.util.*;
/**
 * @author Vad Nik.
 * @version dated Dec 27, 2017.
 * @link http://github.com/vadniks
 */

/*
Please don't touch the file named 'New', it's need to be there where he is by default.
 */

public class HW3J2 {
    
    public static void main(String[] args) {
        HW3J2 hw3J21 = new HW3J2();
        hw3J21.read();
        Phones phones = new Phones(); // <-- For debug.
    }

    public void read() {
        StringBuffer sb = new StringBuffer();
        try (BufferedReader br = new BufferedReader(new FileReader("New"))) {
            while (br.ready()) {
                sb.append(br.readLine() + "\n");
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        //System.out.println("\n" + sb.toString()); // <-- For debug.
        task1(sb);
    }

    public void task1(StringBuffer sb) {
        System.out.println("\nTask one: ");
        List<Character> list = new ArrayList<>();
        for (int i = 0; i < sb.length(); i++) {
            list.add(sb.charAt(i));
        }
//        list.add("a");
//        list.add("as");
//        list.add("aq");
//        list.add("az");
//        list.add("ax");
//        list.add("aw");  // <-- For debug.
//        list.add("ae");
//        list.add("as");
//        list.add("ax");
//        list.add("a");
        System.out.println("All array's elements: " + list + ".\n");
        Integer item;
        Map<Character, Integer> hm = new HashMap<>();
        for (Character wrd : list) {
            item = hm.get(wrd);
            //hm.merge(wrd, 1, (a, b) -> a + b); // <-- Different solution.
            if (item == null) {
                hm.put(wrd, 1);
            } else {
                hm.put(wrd, item + 1);
            }
//            Set<Map.Entry<String, Integer>> set = hm.entrySet();
//            for (Map.Entry<String, Integer> o : set) {
//                //System.out.println(o.getKey() + " " + o.getValue());
//                if (o.getKey() != "1") {                                    // <-- It's for me.
//                    System.out.println(hm);
//                }
//            }
//            System.out.println(hm);
        }
        String a = String.valueOf(hm.entrySet());
        for (Object key : hm.keySet().toArray()) {
            if (hm.get(key) == 2) {
                hm.remove(key);
            }
        }
        System.out.println("Unique arrays' values: " + hm + ".\n");
        System.out.println("Amount of counting every word in the array: " + a + ".");
        System.out.println("----------------------------End.");
    }
}

class Phones {
    //String name, phone;
    String[] names = {"Ivanov", "Nikonov", "Petrov", "Ivanov"};
    String[] phones = {"1234", "2341", "3412", "4123"};
    List<String> list = new ArrayList<>();
    Map<Integer, String> hm = new HashMap<>();
    String filename = "New2";

    Phones() {
        System.out.println("\nTask2: ");
        add();
        System.out.println("\n" + list + "\n");
        get("Ivanov");
        get("Nikonov");
        get("Petrov");
        export(filename);
    }

    public void add() {
        for (int i = 0; i < names.length; i++) {
            list.add(names[i]);
            hm.put(i, phones[i]);
        }
    }

    public void get(String name) {
        if (name == names[0]) {
            System.out.println(names[0] + " phone is " + hm.get(0) + " " + hm.get(3));
        } else if (name == names[1]) {
            System.out.println(names[1] + " phone is " + hm.get(1));
        } else if (name == names[2]) {
            System.out.println(names[2] + " phone is " + hm.get(2));
        }
    }

    public void export(String filename) {
        try (FileWriter fw = new FileWriter(filename)) {
            fw.write("Names are: " + String.valueOf(list) + ".\nPhones are: " + hm.values());
            System.out.println("\nData has just successfully uploaded to '" + filename + "' file.");
        } catch (IOException ex) {
            System.out.println("\nData hasn't been uploaded because of: ");
            ex.printStackTrace();
        }
    }
}
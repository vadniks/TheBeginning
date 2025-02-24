import java.io.FileWriter;
import java.util.Scanner;

/**
 * @author Vad Nik
 * @version dated Feb 17, 2018
 */
/*
Please read code till the end and then run it.
 */
public class HW4J3 {

    public static void main(String[] args) {
        //new Start(); // Task1

        /*
        I didn't understand is cycling in task2 needed,
        so I did it not in cycle. There isn't told to do
        the task in cycle, hop you'll understand,
        what did I mean by 'in cycle'.
         */
        new Start2(); // Task2
    }
}

/*
'aed', 'bed', 'ced' like printed, means a + ed.
 */

class Writer {
    String state = "default";
    FileWriter fw;
    private int count = 0;

    Writer() {
        try {
            fw = new FileWriter("task2.txt");
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    synchronized void A(boolean isRunning) throws Exception {
        if (state.equals("default")) {
            if (!isRunning) {
                state = "aed";
                notify();
                return;
            }
            fw.write("aed\n");
            System.out.println("Aed");
            state = "aed";
            notify();
            Thread.sleep(20);
            count++;
//            while (!state.equals("ced")) {
//                wait();
//            }
//            if (state.equals("bed")) {          // <-- If cycling.
//                while (state.equals("bed"))
//                    wait();
//            }
        }
    }

    synchronized void B(boolean isRunning) throws Exception {
        if (!state.equals("default")) {
            if (!isRunning) {
                state = "bed";
                notify();
                return;
            }
            if (!state.equals("bed")) {
                if (!state.equals("ced")) {
                    fw.write("bed\n");
                    System.out.println("Bed");
                    state = "bed";
                    notify();
                    Thread.sleep(20);
                }
            }
            if (count > 1) {
                while (!state.equals("aed")) //{
                    wait();
//                while (state.equals("ced")) // <-- If cycling.
//                    wait();
            }
            count++;
        } //else {
//            while (!state.equals("aed")) {
//                wait();
//            }
//            if (state.equals("ced")) {
//                while (state.equals("ced"))
//                    wait();
//            }
//            //this.A(true);
//        }
    }

    synchronized void C(boolean isRunning) throws Exception {
        if (!state.equals("default")) {
            if (!isRunning) {
                state = "ced";
                notify();
                return;
            }
            if (!state.equals("aed")) {
                if (!state.equals("ced")) {
                    fw.write("ced");
                    System.out.println("Ced");
                    state = "ced";
                    notify();
                    Thread.sleep(20);
                }
            }
            if (count > 2) {
                while (!state.equals("aed")) {
                    wait();
                    while (!state.equals("bed"))  // <-- If cycling.
                        wait();
                }
            }
            count++;
        } //else {
//            while (!state.equals("bed")) {
//                wait();
//            }
//            if (state.equals("aed")) {
//                while (state.equals("aed"))
//                    wait();
//            }
//            //this.A(true);
//        }
    }
}

class MyThread2 implements Runnable {
    Thread thread;
    private Writer writert;

    MyThread2(String name, Writer writer) {
        thread = new Thread(this, name);
        writert = writer;
        thread.start();
    }

    @Override
    public void run() {
        try {
            if (thread.getName().compareTo("a") == 0) {
                writert.A(true);
                writert.A(false);
            } else if (thread.getName().compareTo("b") == 0) {
                writert.B(true);
                writert.B(false);
            } else {
                writert.C(true);
                writert.C(false);
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}

class Start2 {
    Start2() {
        Writer writer = new Writer();
        MyThread2 t1 = new MyThread2("a", writer);
        MyThread2 t2 = new MyThread2("b", writer);
        MyThread2 t3 = new MyThread2("c", writer);

        Thread check = new Thread(() -> {
            while (t1.thread.isAlive() || t2.thread.isAlive() || t3.thread.isAlive()) lb : {
                Scanner sc = new Scanner(System.in);
                String s = sc.nextLine();
                if (s.equals("a")) {
                    System.out.println(t1.thread.getState() + " " + t2.thread.getState() + " " + t3.thread.getState());
                    System.out.println(writer.state);
                } else if (s.equals("b")) {
                    try {
                        writer.fw.close();
                        System.out.println("...");
                        System.exit(0);
                    } catch (Exception ex) {
                        ex.printStackTrace();
                    }
                }
                sc.reset();
                break lb;
            }
        });
        check.start();

        try {
            t1.thread.join();
            t2.thread.join();
            t3.thread.join();
            writer.fw.close();
            check.join();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}

// ---------------------------------------------------Task1---------------------------------------------------------- \\

/*
Run task1 a few times, ~5 times should be enough, because sometimes it works well, and sometimes it works not good.
I'm trying to fix it.
 */

class ABC {
    String state = "default"; // It should be 'private' but I check the value of these vars.
    int count = 0;            // I don't have much time to learn how to use the idea debugger.

    synchronized void A(boolean isRunning) throws Exception {
        if (count == 0) {
            if (state.equals("default")) {
                if (!isRunning) {
                    state = "aed";
                    notify();
                    return;
                }
                System.out.println("A");
                state = "aed";
                notify();
                count++;
                while (!state.equals("ced")) {
                    wait();
                }
                if (state.equals("bed")) {
                    while (state.equals("bed"))
                        wait();
                }
            }
        } else {
            if (state.equals("ced")) {
                if (!isRunning) {
                    state = "aed";
                    notify();
                    return;
                }
                System.out.println("A");
                state = "aed";
                notify();
                count++;
                while (!state.equals("ced")) {
                    wait();
                }
                if (state.equals("bed")) {
                    while (state.equals("bed"))
                        wait();
                }
            }
        }
    }

    synchronized void B(boolean isRunning) throws Exception {
        if (!state.equals("default")) {
            if (!isRunning) {
                state = "bed";
                notify();
                return;
            }
            System.out.println("B");
            state = "bed";
            notify();
            while (!state.equals("aed")) {
                wait();
                while (state.equals("ced"))
                    wait();
            }
        } else {
            while (!state.equals("aed")) {
                wait();
            }
            if (state.equals("ced")) {
                while (state.equals("ced"))
                    wait();
            }
            //this.A(true);
        }
    }

    synchronized void C(boolean isRunning) throws Exception {
        if (!state.equals("default")) {
            if (!isRunning) {
                state = "ced";
                notify();
                return;
            }
            if (!state.equals("aed")) {
                System.out.println("C");
                state = "ced";
                notify();
            }
            while (!state.equals("bed")) {
                wait();
                while (state.equals("aed"))
                    wait();
            }
        } else {
            while (!state.equals("bed")) {
                wait();
            }
            if (state.equals("aed")) {
                while (state.equals("aed"))
                    wait();
            }
            //this.A(true);
        }
    }
}

class MyThread implements Runnable {
    Thread thread;
    private ABC abct;

    MyThread(String name, ABC abc) {
        thread = new Thread(this, name);
        abct = abc;
        thread.start();
    }

    @Override
    public void run() {
        try {
            if (thread.getName().compareTo("a") == 0) {
                for (int i = 0; i < 5; i++) abct.A(true);
                abct.A(false);
            } else if (thread.getName().compareTo("b") == 0) {
                for (int i = 0; i < 5; i++) abct.B(true);
                abct.B(false);
            } else {
                for (int i = 0; i < 5; i++) abct.C(true);
                abct.C(false);
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}

class Start {
    Start() {
        ABC abc = new ABC();
        MyThread t1 = new MyThread("a", abc);
        MyThread t2 = new MyThread("b", abc);
        MyThread t3 = new MyThread("c", abc);

        Thread check = new Thread(() -> {
            while (t1.thread.isAlive() || t2.thread.isAlive() || t3.thread.isAlive()) lb : {
                Scanner sc = new Scanner(System.in);
                String s = sc.nextLine();
                if (s.equals("0")) {
                    System.out.println(t1.thread.getState() + " " + t2.thread.getState() + " " + t3.thread.getState());
                    System.out.println(abc.state);
                    System.out.println(abc.count);
                } else if (s.equals("1"))
                    System.exit(0);
                sc.reset();
                break lb;
            }
        });
        check.start();

        try {
            t1.thread.join();
            t2.thread.join();
            t3.thread.join();
            check.join();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
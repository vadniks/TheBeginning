/**
 * @author Vad Nik.
 * @version dated Jan 10, 2018.
 * @link http://github.com/vadniks.
 */
/*
Result of volotile variable execution is visible for all of threads, for example:
First thread made var a1 contains '1', next the second thread made it as '2'.
If threre isn't volotile next time inthe first thread var a1 will contains '1',
but if we make it volotile after the second thread will be done result of his work 
will be visible to first thread and it'll contain not '1' for first thread but '2'.
I know the explonation isn't so good but I understand it this way, so sorry if
it is hard to undersand, I tried.

NullPointerException... But think I fixed it, so it seems to be good.
 */
public class HW5J2New {
    private static final int SIZE = 10000000;
    private static final int H = SIZE / 2;

    private float[] arr = new float[SIZE]; // Prime array.

    private final long A = System.currentTimeMillis(); // Time.

    private float[] a1 = new float[SIZE]; // <-- Those to which prime array is divided (separateArray()).
    private float[] a2 = new float[SIZE]; // <--^^^
    
    public static void main(String[] args) {
        System.out.println("\nMain has been started...\n");

        HW5J2New hw5J2New = new HW5J2New();
        hw5J2New.createArr();
        hw5J2New.separateArr();

        Thread1 t1 = new Thread1("Child1", hw5J2New.arr, SIZE, hw5J2New.A);
        System.out.println("First thread has been started...\n");
        Thread2 t2 = new Thread2("Child2", hw5J2New.arr, SIZE, hw5J2New.A);
        System.out.println("Second thread has been started...\n");

//        do {
//            for (int i = 0; i < SIZE; i++) {
//                System.out.println("." + i);                     // <-- It's not working correctly.
//            }                                                    // Don't uncomment it! It leads to a hangup.
//        } while (t1.thread.isAlive() || t2.thread2.isAlive());

        try {
            t1.thread.join();
            System.out.println("First thread was stoped.\n");
            t2.thread2.join();
            System.out.println("Second thread was stoped.\n");
        } catch (InterruptedException ex) {
            ex.printStackTrace();
        }

        hw5J2New.glueArr();

        System.out.println("Main was stoped.");
    }
    
    private void createArr() {
        for (int i = 0; i < arr.length; i++) {
            arr[i] += 1;
        }
        for (int i = 0; i < arr.length; i++) {
            arr[i] = (float)(arr[i] * Math.sin(0.2f + i / 5) * Math.cos(0.2f + i / 5) * Math.cos(0.4f + i / 2));
        }
        System.out.println("Miscalculated " + (System.currentTimeMillis() - A) + "\n");
    }
    
    private void separateArr() {
        try {
            if (arr != null && arr.length > 0 || arr != null) {
                //System.out.println("Not null.");
                System.arraycopy(arr, 0, a1, 0, H);
                System.arraycopy(arr, H, a2, 0, H);
            } else {
                //assert arr != null;
                //arr = new float[arr != null ? arr.length : 0];
                //arr = new float[arr != null ? arr.length : 1];
                //if (arr != null) {
                    //arr = new float[arr.length];
                //}
                assert false;
                arr = new float[arr.length];
            }
        } catch (NullPointerException ex) {
            System.out.println("NPE was catched. Failed to separate the array.\n");
            //ex.printStackTrace();
        }
        System.out.println("Separated " + (System.currentTimeMillis() - A) + "\n");
    }
    
    private void glueArr() {
        try {
            if (a1 != null && a1.length > 0
                    && a2 != null && a2.length > 0
                    || a1 != null && a2 != null) {
                //System.out.println("Not null2");
                System.arraycopy(a1, 0, arr, 0, H);
                System.arraycopy(a2, 0, arr, H, H);
            } else {
                //a1 = new float[a1 != null ? a1.length : 1];
                //a2 = new float[a2 != null ? a2.length : 1];
                assert a1 != null;
                a1 = new float[a1.length];
                assert false;
                a2 = new float[a2.length];
            }
        } catch (NullPointerException ex) {
            System.out.println("NPE was catched. Failed to glue the arrays together.\n");
            //ex.printStackTrace();
        }
        System.out.println("Glued " + (System.currentTimeMillis() - A) + "\n");
    }
}

class Thread1 implements Runnable {
    Thread thread;
    private float[] ar;
    private int size;
    private long a;

    Thread1(String name, float[] arr, int SIZE, long A) {
        ar = arr;
        size = SIZE;
        a = A;
        thread = new Thread(this, name);
        thread.start();
    }

    @Override
    public void run() {
        for (int i = 0; i < size; i++) {
            ar[i] = (float)(ar[i] * Math.sin(0.2f + i / 5) * Math.cos(0.2f + i / 5) * Math.cos(0.4f + i / 2));
        }
        System.out.println("First thread, miscalculated " + (System.currentTimeMillis() - a) + "\n");
    }
}

class Thread2 implements Runnable {
    Thread thread2;
    private float[] ar;
    private int size;
    private long a;

    Thread2(String name, float[] arr, int SIZE, long A) {
        ar = arr;
        size = SIZE;
        a = A;
        thread2 = new Thread(this, name);
        thread2.start();
    }

    @Override
    public void run() {
        for (int i = 0; i < size; i++) {
            ar[i] = (float)(ar[i] * Math.sin(0.2f + i / 5) * Math.cos(0.2f + i / 5) * Math.cos(0.4f + i / 2));
        }
        System.out.println("Second thread, miscalculated " + (System.currentTimeMillis() - a) + "\n");
    }
}
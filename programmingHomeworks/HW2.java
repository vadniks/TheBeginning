public class HW2 {
/**
 * @Author Vad Nik.
 * @Version dated Nov 25, 2017.
 */
    public static void main(String[] args) {
        invertArray();
        System.out.println();
        fillArray();
        System.out.println();
        changeArray();
        System.out.println();
        task4();
        System.out.println();
//        task4diff(); // Different solution.
        System.out.println();
        task5();
        System.out.println();
    }

    public static void invertArray() {
        int[] arr = {1, 0, 1, 0, 0, 1};
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 0) {
                arr[i] = 1 + 0;
            } else {
                arr[i] = 1 - 1;
            }
            System.out.println(arr[i]);
        }
    }

    public static void fillArray() {
        int[] arr = new int[8];
        int[] arr2 = {0, 3, 6, 9, 12 ,15, 18, 21};
        int i;
        for (i = 0; i < arr.length; i++) {
            arr[i] = i;
        }
        if (arr.length == arr2.length) {
            for (i = 0; i < arr2.length; i++) {
                arr[i] = arr2[i];
                System.out.println(arr[i]);
            }
        }
    }

    public static void changeArray() {
        int[] arr = {1, 5, 3, 2, 11, 4, 5, 2, 4, 8, 9, 1};
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < 6) {
                arr[i]  = arr[i] * 2;
            }
            System.out.println(arr[i]);
        }
    }

    public static void task4() {
        int[][] arr = new int[2][2];
        for (int i = 0; i <= arr[0].length-1; i++) {
            for (i = 0; i <= arr.length-1; i++) {
                arr[i][i] = 1;
            }
        }
        System.out.println(arr[0][0] + " " + arr[0][1]);
        for (int i = 0; i <= arr[1].length-1; i++) {
            for (i = 0; i <= arr.length-1; i++) {
                arr[i][i] = 1;
            }
        }
        System.out.println(arr[1][0] + " " + arr[1][1]);
    }

//    public static void task4diff()  { // Different solution of 4th exercise.
//        int[][] arr = new int[2][2];
//        for (int i = 0, t = 0; i <= arr[0].length-1; i++, t++) {
//            for (i = 0; i <= arr.length-1; i++) {
//                arr[i][t] += arr[t][i] += arr[i][i] = 1;
//            }
//        }
//        System.out.println(arr[0][0] + " " + arr[0][1] + " " + arr[1][0] + " " + arr[1][1]);
//    }                                 // End.

    public static void task5() {
        int[] arr = {0, 10, 20, 30, -10, -20, -30};
        int min;
        int max;
        min = max = arr[0];
        for (int i = 1; i < 7; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        System.out.println(min + " " + max);
    }
}

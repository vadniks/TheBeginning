/**
 * @Author Vad Nik.
 * @Version dated Dec 03, 2017.
 */

import java.util.Random;
import java.util.Scanner;

public class NoughtsAndCrosses {

    final int SIZE = 3;
    final char D_X = 'x';
    final char D_O = 'O';
    final char D_EMPTY = '*';
    char[][] map = new char[SIZE][SIZE];
    Scanner scanner = new Scanner(System.in);
    Random random = new Random();

    public static void main(String[] args) {
        new NoughtsAndCrosses();
    }

    NoughtsAndCrosses() {
        initMap();
        while (true) {
            humanTurn();
            printMap();
            if (checkWin(D_X)) {
                System.out.println("YOU WON!");
                break;
            }
            if (isMapFull()) {
                System.out.println("Sorry, DRAW!");
                break;
            }
            aiTurn();
            printMap();
            if (checkWin(D_O)) {
                System.out.println("AI WON!");
                break;
            }
            if (isMapFull()) {
                System.out.println("Sorry, DRAW!");
                break;
            }
        }
        System.out.println("GAME OVER.");
    }

    void initMap() {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                map[i][j] = D_EMPTY;
    }

    void printMap() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++)
                System.out.print(map[i][j] + " ");
            System.out.println();
        }
        System.out.println();
    }

    void humanTurn() {
        int x, y;
        do {
            System.out.println("Enter X and Y (1..3):");
            x = scanner.nextInt() - 1;
            y = scanner.nextInt() - 1;
        } while (!isCellValid(x, y));
        map[y][x] = D_X;
    }

    void aiTurn() {
        int x, y;
        for (x = 0; x < SIZE; x++) {
            for (y = 0; y < SIZE; y++) {
                if (isCellValid(x, y)) {
                    map[y][x] = D_X;
                    if (isCellValid(x, y)) {
                        map[y][x] = D_O;
                        return;
                    }
                    map[y][x] = D_EMPTY;
                }
            }
        }
        do {
            x = random.nextInt(SIZE);
            y = random.nextInt(SIZE);
        } while (!isCellValid(x, y));
        map[y][x] = D_O;
    }

    boolean checkWin(char dot) {
//                        -----------Example----------
        // check horizontals
//        if (map[0][0] == dot && map[0][1] == dot && map[0][2] == dot) return true;
//        if (map[1][0] == dot && map[1][1] == dot && map[1][2] == dot) return true;
//        if (map[2][0] == dot && map[2][1] == dot && map[2][2] == dot) return true;
//        // check verticals
//        if (map[0][0] == dot && map[1][0] == dot && map[2][0] == dot) return true;
//        if (map[0][1] == dot && map[1][1] == dot && map[2][1] == dot) return true;
//        if (map[0][2] == dot && map[1][2] == dot && map[2][2] == dot) return true;
//        // check diagonals
//        if (map[0][0] == dot && map[1][1] == dot && map[2][2] == dot) return true;
//        if (map[2][0] == dot && map[1][1] == dot && map[0][2] == dot) return true;
//                       --------------End-------------
        for (int i = 0; i < SIZE; i++) {
            if (map[i][0] == dot && map[i][1] == dot && map[i][2] == dot) {
                return true;
            } else if (map[0][i] == dot && map[1][i] == dot && map[2][i] == dot) {
                return true;
            }
            // check diagonals
                if (map[0][0] == dot && map[1][1] == dot && map[2][2] == dot) {
                    return true;
                } else if (map[2][0] == dot && map[1][1] == dot && map[0][2] == dot) {
                    return true;
                }
        }
        return false;
    }

    boolean isMapFull() {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (map[i][j] == D_EMPTY)
                    return false;
        return true;
    }

    boolean isCellValid(int x, int y) {
        if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
            return false;
        if (map[y][x] == D_EMPTY)
            return true;
        return false;
    }
}

/**
 * @author Vad Nik
 * @version dated February 4, 2018
 */
import java.io.File;
import java.sql.*;
import java.util.Scanner;

public class HW2J3 implements IConstantsJDBC {

    private static Statement stm;
    private static boolean canProceed;

    public static void main(String[] args) {
        start(args);
        Scanner sca = new Scanner(System.in);
        String st;

        if (args.length == 0) {
            System.out.print("Type exit to quit, press enter to repeat.>> ");
            st = sca.nextLine();
            while (!st.equals("exit"))
                start(args);
        }
    }

    private static void start(String[] args) {
        try {
            Class.forName(JDBC_NAME);
            Connection connection = DriverManager.getConnection(DATABASE_CONNECTION);
            stm = connection.createStatement();
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        Scanner sc = new Scanner(System.in);

        if (args.length == 0) {
            System.out.print(">> ");
            String line = sc.nextLine();
            args = line.split(" ");
        }

        switch (args[0]) {
            case "-create":
                createTable();
                break;
            case "-init":
                canProceed = false;
                initTable(args[1], args[2], Integer.parseInt(args[3]), Integer.parseInt(args[4]));
                if (canProceed)
                    break;
            case "-fill":
                fillTable(args[1], args[2], args[3]);
                break;
            case "-clear":
                clearTable();
                break;
            case "exit":
                System.exit(0);
                break;
            case "-getprice":
                getPrice(args[1]);
                break;
            case "-setprice":
                setPrice(args[1], Integer.parseInt(args[2]));
                break;
            case "-list":
                printList(Integer.parseInt(args[1]), Integer.parseInt(args[2]));
                break;
            case "-seeall":
                seeAll();
                break;
            case "-reset":
                reset(); // Not working.
                break;
            default:
                System.out.println("Unknown command.");
                break;
        }
//        try {
//            stm.close();
//            connection.close();
//        } catch (Exception ex) {
//            ex.printStackTrace();
//        }
    }

    private static void createTable() {
        try {
            stm.executeUpdate(CREATE_TABLE);
            System.exit(0);
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private static void clearTable() {
        try {
            stm.executeUpdate(DELETE);
            stm.executeUpdate("DROP TABLE " + TABLE_NAME + ";");
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private static void initTable(String value1, String value2, int price, int count) {
//        while (count != 0) {
//            count--;
//        }

        for (; count-1 >= 0; count--) {
            try {
                stm.executeUpdate("INSERT INTO " + TABLE_NAME + " (" + COLUMN_PRODIT + ", " + COLUMN_TITLE + ", " + COLUMN_COST + " ) VALUES ( '" +
                        value1 + "', '" + value2 + "', " + price + " );");
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }
        canProceed = true;
    }

    private static void fillTable(String value1, String value2, String value3) {
        try {
            stm.executeUpdate("INSERT INTO " + TABLE_NAME + " (" + COLUMN_PRODIT + ", " + COLUMN_TITLE + ", " + COLUMN_COST + " ) VALUES ( '" +
                    value1 + "', '" + value2 + "', '" + value3 + "' );");
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private static void getPrice(String product) {
        try {
            ResultSet rs = stm.executeQuery("SELECT " + COLUMN_TITLE + ", " + COLUMN_COST + " FROM " + TABLE_NAME +
            " WHERE " + COLUMN_TITLE + " = '" + product + "';");
            boolean b = rs.next();
            while (b) {
                System.out.println(rs.getString(COLUMN_TITLE) + "\t" + rs.getString(COLUMN_COST));
                break;
            }
            if (!b)
                System.out.println("There isn't any product like you typed.");
            rs.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private static void setPrice(String product, int price) {
        try {
            stm.executeUpdate("UPDATE " + TABLE_NAME + " SET " + COLUMN_COST + " = '" + price + "' \nWHERE " + COLUMN_TITLE + " = '" + product + "'");
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private static void printList(int range1, int range2) {
        try {
            ResultSet rs = stm.executeQuery("SELECT " + COLUMN_TITLE + " FROM " + TABLE_NAME + " WHERE " + COLUMN_COST + " BETWEEN " +
            range1 + " AND " + range2 + ";");
            boolean c = false;
            while (rs.next()) {
                System.out.println(rs.getString(COLUMN_TITLE));
                c = true;
            }
            if (!c)
                System.out.println("There isn't any element matches your request.");
            rs.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private static void seeAll() {
        try {
            ResultSet rs = stm.executeQuery("SELECT * FROM " + TABLE_NAME + ";");
            while (rs.next()) {
                System.out.println(rs.getString(COLUMN_ID) + "\t" + rs.getString(COLUMN_PRODIT) + "\t" + rs.getString(COLUMN_TITLE) +
                        "\t" + rs.getString(COLUMN_COST));
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private static void reset() {
        File dbFile = new File(DATABASE_NAME);
        //System.out.println(dbFile.exists());
        System.out.println(dbFile.getAbsolutePath());
        System.out.println(dbFile.delete());
//        if (dbFile.exists()) {
//            if (dbFile.delete())
//                System.out.println("FileDB has been deleted.");
//        }
    }
}
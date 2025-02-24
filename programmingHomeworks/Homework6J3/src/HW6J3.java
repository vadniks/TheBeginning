import java.io.File;
import java.sql.*;
import java.util.Arrays;

/**
 * @author Vad Nik.
 * @version Dated Mar 05, 2018.
 * @link https://github.com/vadniks
 */
public class HW6J3 {
    int[] task1(int[] arr) {
        boolean contains4 = false;
        int count = 0;
        for (int anArr : arr) {
            if (anArr == 4) {
                contains4 = true;
                count++;
            }
        }
        if (contains4) {
            String[] arr2;
            String ar = null;
            for (int anArr : arr)
                ar += String.valueOf(anArr);
            ar = ar.substring(4);
            arr2 = ar.split("4");
            String[] arr3;
            if (count == 1)
                arr3 = arr2[count].split("");
            else
                arr3 = arr2[count].split("");
            int[] arr6 = new int[arr3.length];
            for (int i = 0; i < arr3.length; i++)
                arr6[i] = Integer.parseInt(arr3[i]);
            return arr6;
        } else
            throw new RuntimeException();
    }

    boolean task2(int[] arr) {
        boolean norm = false;
        if (Arrays.toString(arr).contains("1") && Arrays.toString(arr).contains("4") && !(Arrays.toString(arr).contains("0") ||
                Arrays.toString(arr).contains("2") || Arrays.toString(arr).contains("3") || Arrays.toString(arr).contains("5") ||
                Arrays.toString(arr).contains("6") || Arrays.toString(arr).contains("7") || Arrays.toString(arr).contains("8") ||
                Arrays.toString(arr).contains("9")))
            norm = true;
        return norm;
    }
}

class SQLite {

    private static final String DRIVER_NAME = "org.sqlite.JDBC";
    Connection connect = null;
    private static String nameDB = "students.db";
    private static String tableDB = "students";

    void openDB() {
        try {
            Class.forName(DRIVER_NAME);
            connect = DriverManager.getConnection("jdbc:sqlite:" + nameDB);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    boolean createTable() {
        if (!new File(nameDB).exists()) {
            try {
                Statement stmt = connect.createStatement();
                String sql = "CREATE TABLE " + tableDB +
                        "(ID INT PRIMARY KEY NOT NULL," +
                        " LAST_NAME TEXT NOT NULL," +
                        " SCORE INT NOT NULL)";
                stmt.executeUpdate(sql);
                stmt.close();

                insertRecords();
                return true;
            } catch (Exception e) {
                e.printStackTrace();
                return false;
            }
        } else return true;
    }

    private void insertRecords() {
        try {
            Statement stmt = connect.createStatement();
            String sql = "INSERT INTO " + tableDB +
                    " (ID, LAST_NAME, SCORE) " +
                    "VALUES (1, 'Paul', 10);";
            stmt.executeUpdate(sql);
            stmt.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    String selectRecords() {
        String res = null;
        try {
            Statement stmt = connect.createStatement();
            ResultSet rs = stmt.executeQuery( "SELECT * FROM " + tableDB + ";" );
            while (rs.next()) {
                int id = rs.getInt("id");
                String name = rs.getString("last_name");
                int age = rs.getInt("score");
                res =  "ID = " + id + "\n" + "LAST_NAME = " + name + "\n" + "SCORE = " + age + "\n";
            }
            rs.close();
            stmt.close();
            return res;
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    boolean updateRecord() {
        try {
            Statement stmt = connect.createStatement();
            String sql = "UPDATE " + tableDB + " set SCORE = 20 where ID=1;";
            stmt.executeUpdate(sql);
            stmt.close();
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }
}
/**
 * @author Vad Nik
 * @version dated February 3, 2018
 */
public interface IConstantsJDBC {

    String TABLE_NAME = "goods";
    String COLUMN_ID = "id";
    String COLUMN_PRODIT = "prodit";
    String COLUMN_TITLE = "title";
    String COLUMN_COST = "cost";
    String TYPE_INTEGER = "INTEGER";
    String TYPE_STRING = "TEXT";
    String AUTO_INCREMENT = "AUTOINCREMENT";
    String PRIMARY_KEY = "PRIMARY KEY";
    String NOT_NULL = "NOT NULL";
    String JDBC_NAME = "org.sqlite.JDBC";
    String DATABASE_NAME = "mydatabase.db";
    String DATABASE_CONNECTION = "jdbc:sqlite:" + DATABASE_NAME;
    String SELECT = "SELECT * FROM " + TABLE_NAME;
    String DELETE = "DELETE FROM " + TABLE_NAME;

    String CREATE_TABLE = "CREATE TABLE IF NOT EXISTS " + TABLE_NAME + " (\n" +
            COLUMN_ID + " " + TYPE_INTEGER + " " + PRIMARY_KEY + " " + AUTO_INCREMENT + " " + NOT_NULL + ",\n" +
            COLUMN_PRODIT + " " + TYPE_STRING + " " + NOT_NULL + ",\n" +
            COLUMN_TITLE + " " + TYPE_STRING + " " + NOT_NULL + ",\n" +
            COLUMN_COST + " " + TYPE_INTEGER + " " + NOT_NULL + "\n)";
}
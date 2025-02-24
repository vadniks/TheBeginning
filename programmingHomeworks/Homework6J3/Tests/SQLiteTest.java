import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

/**
 * @author Vad Nik.
 * @version Dated Mar 05, 2018.
 * @link https://github.com/vadniks
 */
/*
 * ONLY JUNIT 4!!!
 * DO NOT EDIT!!!
 */
public class SQLiteTest {
    private SQLite sqLite;

    @Before
    public void init() {
        sqLite = new SQLite();
        sqLite.openDB();
    }

    @Test
    public void testCreate() {
        assertEquals(true, sqLite.createTable());
    }

    @Test
    public void testSelect() {
        assertNotNull(sqLite.selectRecords());
    }

    @Test
    public void testUpdate() {
        assertEquals(true, sqLite.updateRecord());
    }

    @After
    public void close() {
        try {
            sqLite.connect.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
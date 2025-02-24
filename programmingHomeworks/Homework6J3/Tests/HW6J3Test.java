import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;

import java.util.Arrays;
import java.util.Collection;

import static org.junit.Assert.assertEquals;

/**
 * @author Vad Nik.
 * @version Dated Mar 05, 2018.
 * @link https://github.com/vadniks
 */
/*
 * ONLY JUNIT 4!!!
 * DO NOT EDIT!!!
 */
@RunWith(Parameterized.class)
public class HW6J3Test {
    private HW6J3 hw6J3;
    private int[] test1;
    private int[] expected1;
    private int[] test2;
    private boolean expected2;

    @Parameterized.Parameters
    public static Collection<Object[]> data() {
        return Arrays.asList(new Object[][]{
                {new int[]{1, 2, 4, 4, 2, 3, 4, 1, 7}, new int[]{1, 7}, new int[]{1, 4, 1, 4}, true},
                {new int[]{1, 2, 3, 4, 5, 6}, new int[]{5, 6}, new int[]{1, 4, 2, 3}, false},
                {new int[]{1, 2, 3, 4, 5}, new int[]{5}, new int[]{1, 2, 3, 4}, false},
        });
    }

    public HW6J3Test(int[] test1, int[] expected1, int[] test2, boolean expected2) {
        this.test1 = test1;
        this.expected1 = expected1;
        this.test2 = test2;
        this.expected2 = expected2;
    }

    @Before
    public void init() {
        hw6J3 = new HW6J3();
    }

    @Test
    public void testTask1() {
        assertEquals(Arrays.toString(expected1), Arrays.toString(hw6J3.task1(test1)));
    }

    @Test
    public void testTask2() {
        assertEquals(expected2, hw6J3.task2(test2));
    }

    @Test(expected = RuntimeException.class)
    public void testTask1Ex() {
        hw6J3.task1(new int[]{1, 7});
    }
}
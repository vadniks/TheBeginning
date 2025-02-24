import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;
import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.*;

/**
 * @author Vad Nik.
 * @version dated Mar 07, 2018.
 */
public class HardTask {

    public static void main(String[] args) {
        try {
            start(Test1.class);
        } catch (InstantiationException | IllegalAccessException | InvocationTargetException ex) {
            ex.printStackTrace();
        }
    }

    static void start(Class classS) throws InstantiationException, IllegalAccessException, InvocationTargetException {
        Object object = null;
        Constructor[] constructors = classS.getDeclaredConstructors();
        if (constructors == null)
            throw new RuntimeException();
        for (Constructor o : constructors)
            object = o.newInstance();

        boolean isBeforeDone = false;
        boolean isTestsDone = false;

        if (!getBeforeMethods(classS).isEmpty()) {
            for (Method method : getBeforeMethods(classS)) {
                method.setAccessible(true);
                method.invoke(object);
            }
            isBeforeDone = true;
        } else isBeforeDone = true;

        if (isBeforeDone && !getTestMethods(classS).isEmpty()) {
            int index = getTestMethods(classS).size();
            ChIn[] ci = new ChIn[index];
            index = 0;
            for (Map.Entry<Method, Integer> entry:getTestMethods(classS).entrySet()) {
                ci[index++] = new ChIn(entry.getKey(), entry.getValue());
            }
            Arrays.sort(ci);

            for (ChIn cin : ci) {
                cin.method.setAccessible(true);
                cin.method.invoke(object);
            }

            isTestsDone = true;
        }

        if (isTestsDone && !getAfterMethods(classS).isEmpty()) {
            for (Method method : getAfterMethods(classS)) {
                method.setAccessible(true);
                method.invoke(object);
            }
        }
    }

    static class ChIn implements Comparable {
        private Method method;
        private Integer i;

        private ChIn(Method method, Integer i) {
            this.method = method;
            this.i = i;
        }

        @Override
        public int compareTo(Object o) {
            if (o instanceof ChIn) {
                final int diff = i - ((ChIn) o).i;
                return Integer.compare(0, diff);
            } else {
                return 0;
            }
        }
    }

    private static HashMap<Method, Integer> getTestMethods(Class clasS) {
        Method[] methods = clasS.getDeclaredMethods();
        HashMap<Method, Integer> returns = new HashMap<>();
        Test test = null;
        for (Method o : methods) {
            if (o.getAnnotation(Test.class) != null) {
                test = o.getAnnotation(Test.class);
                if (test.priority() > 10 || test.priority() < 1)
                    throw new RuntimeException("Priority must be less than 10 and greater then 1.");
                returns.put(o, test.priority());
            }
        }
        return returns;
    }

    private static ArrayList<Method> getBeforeMethods(Class clasS) {
        Method[] methods = clasS.getDeclaredMethods();
        ArrayList<Method> returns = new ArrayList<>();
        for (Method o : methods) {
            if (o.getAnnotation(BeforeSuite.class) != null) {
                returns.add(o);
            }
        }
        return returns;
    }

    private static ArrayList<Method> getAfterMethods(Class clasS) {
        Method[] methods = clasS.getDeclaredMethods();
        ArrayList<Method> returns = new ArrayList<>();
        for (Method o : methods) {
            if (o.getAnnotation(AfterSuite.class) != null) {
                returns.add(o);
            }
        }
        return returns;
    }
}

class Test1 {

    @BeforeSuite
    void bef() {
        System.out.println("BeforeSuite");
    }

    Test1() { }

    @Test
    void tes() {
        System.out.println("Test");
    }

    @Test(priority = 2)
    void tes2() {
        System.out.println("Test2");
    }

    @Test(priority = 3)
    void tes3() {
        System.out.println("Test3");
    }

    @AfterSuite
    void aft() {
        System.out.println("AfterSuite");
    }
}

@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
@interface Test {
    int priority() default 1;
}

@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
@interface BeforeSuite {
}

@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
@interface AfterSuite {
}
import java.lang.reflect.*;
import java.util.Arrays;

/**
 * @author Vad Nik.
 * @version dated Mar 07, 2018.
 */
public class HW7J3 {

    public static void main(String[] args) {
        explorer(ExploredClass.class);
    }

    private static void explorer(Class classS) {
        String name = classS.getName();
        System.out.println("Full class name: " + name + ", simple class name: " + classS.getSimpleName() + "\n");
        int modifiers = classS.getModifiers();
        if (Modifier.isAbstract(modifiers))
            System.out.println(name + " is abstract");
        if (Modifier.isFinal(modifiers))
            System.out.println(name + " is final");
        if (Modifier.isInterface(modifiers))
            System.out.println(name + " is interface");
        if (Modifier.isPublic(modifiers))
            System.out.println(name + " is public");
        if (Modifier.isNative(modifiers))
            System.out.println(name + " is native\n");

        Field[] pubFields = classS.getFields();
        String pubFl = null;
        for (Field o: pubFields) {
            System.out.println(name + " public fields: " + o);
            pubFl += o.getName();
        }

        System.out.println();
        Field[] decFields = classS.getDeclaredFields();
        for (Field o: decFields) {
            if (!pubFl.contains(o.getName()))
                System.out.println(name + " declared fields: " + o);
        }

        System.out.println();
        String pubCon = null;
        Constructor[] pubConstructors = classS.getConstructors();
        for (Constructor o : pubConstructors) {
            System.out.println(name + " public constructors: " + o);
            pubCon += o.getName();
        }

        System.out.println();
        Constructor[] decConstructors = classS.getDeclaredConstructors();
        for (Constructor o : decConstructors) {
            if (pubCon != null) {
                if (!pubCon.contains(o.getName()))
                    System.out.println(name + " declared constructors: " + o);
            } else System.out.println(name + " declared constructors: " + o);
        }

        Method[] objectClassMethods = Object.class.getDeclaredMethods();
        String objClassMethods = null;
        for (Method o : objectClassMethods)
            objClassMethods += o.getName();

        System.out.println();
        String pubMethods = null;
        Method[] methods = classS.getMethods();
        for (Method o : methods) {
            if (!objClassMethods.contains(o.getName()))
                System.out.println(name + " public methods: " + o);
            pubMethods += o.getName();
        }

        System.out.println();
        Method[] decMethods = classS.getDeclaredMethods();
        for (Method o : decMethods) {
            if (!pubMethods.contains(o.getName()))
                System.out.println(name + " declared methods: " + o);
        }

        System.out.println(Arrays.toString(classS.getAnnotations()));
    }
}

final class ExploredClass {
    //Fields
    public int pub = 1;
    int pak_pr = 2;
    private int pr = 3;
    public final int pubF = 4;
    final int pak_prF = 5;
    private final int prF = 6;
    public static int pubS = 7;
    static int pak_prS = 8;
    private static int prS = 9;
    protected int pt = 10;
    protected static int ptS = 11;

    //Constructors
    //public ExploredClass() { }
    //ExploredClass() { }         //There must be only one unoverloaded constructor, otherwise explorer won't see overloaded constructors.
    //private ExploredClass() { }
    //protected ExploredClass(int someInt) { }
    public ExploredClass() { }

    //Methods
    public void methodPV() { }
    void methodV() { }
    private void methodPrV() { }
    public static void methodPSV() { }
    static void methodSV() { }
    private static void methodPrSV() { }
    protected void methodPtV() { }
    protected static void MethodPtSV() { }
}
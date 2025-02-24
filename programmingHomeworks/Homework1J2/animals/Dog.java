package animals;
/**
 * @author Vad Nik.
 * @version dated Dec 20, 2017.
 */
public class Dog extends Animal implements Jumpable, Swimable {
    private int swim_limit;
    private float jump_limit;

    public Dog(String name) {
        this.name = name;
        this.run_limit = 200;
        swim_limit = 150;
        jump_limit = 4.5f;
    }

    public String voice() {
        return "bow-wow";
    }

    public boolean swim(int length) {
        return swim_limit >= length;
    }

    public boolean jump(float height) {
        return jump_limit >= height;
    }
}

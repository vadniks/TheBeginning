package obstacles;
import animals.*;
/**
 *@author Vad Nik.
 * @version dated Dec 20, 2017.
 */
public class Water extends Obstacle{
    private int length;

    public Water(int length) {
        this.length = length;
    }

    @Override
    public boolean doIt(Animal animal) {
        if (animal instanceof Swimable)
            return ((Swimable) animal).swim(length);
        else {
            return false;
        }
    }
}
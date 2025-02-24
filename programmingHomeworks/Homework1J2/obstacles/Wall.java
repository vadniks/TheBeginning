package obstacles;
import animals.*;
/**
 *@author Vad Nik.
 * @version dated Dec 20, 2017.
 */
public class Wall extends Obstacle{
    private float height;

    public Wall(float height) {
        this.height = height;
    }

    @Override
    public boolean doIt(Animal animal) {
        if (animal instanceof Jumpable)
            return ((Jumpable) animal).jump(height);
        else {
            return false;
        }
    }
}
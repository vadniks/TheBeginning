package obstacles;
import animals.*;
/**
 *@author Vad Nik.
 * @version dated Dec 20, 2017.
 */
public class Track extends Obstacle{
    private int length;

    public Track(int length) {
        this.length = length;
    }

    @Override
    public boolean doIt(Animal animal) {
        return animal.run(length);
    } 
}
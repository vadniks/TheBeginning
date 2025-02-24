package executing;

import obstacles.*;
import animals.*;
/**
 * @author Vad Nik.
 * @version dated Dec 20, 2017.
 */
public class Course {
    private Obstacle[] obstacles = {new Track(80), new Wall(3), new Water(10)};
    private Track track1;
    private Wall wall1;
    private Water water1;
//    private Team team1;

    public Course(Animal[] zoo) {
        for (Animal animal : zoo) {
            for (Obstacle obstacle : obstacles) {
                //System.out.println("Class " + animal + " says: " + animal.voice()); // <-- For debug.
                if (obstacle == obstacles[0]) {
                    //System.out.println("runs:1 " + obstacle.doIt(animal)); // <-- For debug.
                    obstacle.doIt(animal);
                    this.track1 =(Track)obstacles[0];
                }
                if (obstacle == obstacles[1]) {
                    //System.out.println(" jumps:2 " + obstacle.doIt(animal)); // <-- For debug.
                    obstacle.doIt(animal);
                    this.wall1 =(Wall)obstacles[1];
                }
                if (obstacle == obstacles[2]) {
                    //System.out.println(" swims:3 " + obstacle.doIt(animal) + "\n"); // <-- For debug.
                    obstacle.doIt(animal);
                    this.water1 =(Water)obstacles[2];
                }
            }
        }
        //team1.displayNameOfTeam();
        //team1.resultsWhoPassed(zoo, track1, wall1, water1);
        //team1.resultsAllMembers(zoo, track1, wall1, water1);
    }

    public Track getObstacleTrack() {
        return track1;
    }
    public Wall getObstacleWall() {
        return wall1;
    }
    public Water getObstacleWater() {
        return water1;
    }
}

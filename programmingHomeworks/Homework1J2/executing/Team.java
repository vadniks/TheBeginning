package executing;

import animals.*;
import obstacles.*; // <-- For debug.
/**
 * @author Vad Nik.
 * @version dated Dec 20, 2017.
 */
public class Team {
    private String name;
    private int i = 1;
    Animal[] zoo = {new Cat("Murzik"), new Dog("Sharik"), new Hen("Izzy"), new Hippo("Hippopo")};

    public Team() {
        this.name = "Team" + i;
        i++; // This is for count objects, but it is necessary here.
//        Track track = new Track(80);
//        Wall wall = new Wall(3);                              //  <-- For debug.
//        Water water = new Water(10);
        displayNameOfTeam();
        Course course = new Course(zoo);
        resultsWhoPassed(zoo, course);
        resultsAllMembers(zoo, course);
    }

    public void displayNameOfTeam() {
        System.out.println("\n" + name);
    }

    public void resultsWhoPassed(Animal[] zoo, Course course) {
        System.out.println("\nThis method displays info only about animals who have just passed the obstacle course.\n");
        for (Animal animal : zoo) {
            if (animal instanceof Swimable && animal instanceof Jumpable) {
                System.out.println("Class " + animal + " says: " + animal.voice());
                System.out.println(" runs: " + course.getObstacleTrack().doIt(animal));
                System.out.println(" jumps: " + course.getObstacleWall().doIt(animal));
                System.out.println(" swims: " + course.getObstacleWater().doIt(animal));
            }
        }
        System.out.println("\n----------------------------------------------------");
    }

    public void resultsAllMembers(Animal[] zoo, Course course) {
        System.out.println("\nThis method displays info about all of animals except those who passed.\n");
        for (Animal animal : zoo) {
            if (!(animal instanceof Swimable) || !(animal instanceof Jumpable)) {
                System.out.println("Class " + animal + " says: " + animal.voice());
                System.out.println(" runs: " + course.getObstacleTrack().doIt(animal));
                System.out.println(" jumps: " + course.getObstacleWall().doIt(animal));
                System.out.println(" swims: " + course.getObstacleWater().doIt(animal));
            }
        }
    }
}

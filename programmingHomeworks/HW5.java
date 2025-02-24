import java.util.Arrays;

/**
 * @author Vad Nik.
 * @version dated Dec 6, 2017.
 * This homework is called "New" because I've lost previous file.
 */
public class HW5 {

    public static void main(String[] args) {
        Person[] persArray = new Person[5];
        persArray[0] = new Person("Ivanov Ivan", "Engineer", "ivivan@mailbox.com", "892312312", "30000", 30);
        persArray[1] = new Person("Ivanov Pavel", "Booker", "ivpavel@mailbox.com", "892312313", "30000", 31);
        persArray[2] = new Person("Ivanov Alex", "Secretary", "ivalex@mailbox.com", "892312314", "30000", 32);
        persArray[3] = new Person("Ivanov Sergey", "Guard", "ivsergey@mailbox.com", "892312315", "30000", 33);
        persArray[4] = new Person("Ivanov Denis", "Manager", "ivdenis@mailbox.com", "892312316", "30000", 40);
        int i = 40; // What age is person over years old.
        for (Person arr : persArray) {
            if (arr.getAge() < i) {
                System.out.println(arr + " He/she passed.");
            } else {
                System.out.println("\n" + arr + " He is over " + i + " years old. He/she didn't pass.");
            }
        }
    }
}

class Person {
    private String name;
    private String position;
    private String email;
    private String phone;
    private String salary;
    private int age;

    Person(String name, String position, String email, String phone, String  salary, int age) {
        this.name = name;
        this.position = position;
        this.email = email;
        this.phone = phone;
        this.salary = salary;
        this.age = age;
    }

    int getAge() {
        return age;
    }

    @Override // Else compiler displays unknown symbols.
    public String toString() {
        return (" Name is " + name + " " + " Position is " + position + " " + "Email is " + email + " " + "Phone is "
                + phone + " " + "Salary is " + salary + " " + "Age is " + age + ".");
    }
}
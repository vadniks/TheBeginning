/**
 * @author Vad Nik.
 * @version dated Jan 15.
 * @link http://github.com/vadniks
 */
import java.net.*;
import java.io.*;
/*
Modified for attack the HelloServer.
 */
class AttackingHelloClient {

    public static void main(String[] args) {
        new AttackingHelloClient();
        newSocket(); // This method
    }

    AttackingHelloClient() {
        try (Socket socket = new Socket("", 1024);
            BufferedReader reader =
                new BufferedReader(
                    new InputStreamReader(socket.getInputStream()))) {

            System.out.println(
                reader.readLine());

        } catch (IOException ex) {
            System.out.println(ex);
        }
    }

    static void newSocket() {
        try (Socket socket2 = new Socket("", 1024);
        BufferedReader reader
                = new BufferedReader(
                        new InputStreamReader(socket2.getInputStream()))){

            System.out.println(
                    reader.readLine());

        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
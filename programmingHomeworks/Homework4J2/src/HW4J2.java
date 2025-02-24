/**
 * @author Vad Nik.
 * @version dated Dec 30, 2017.
 * @link http://github.com/vadniks
 */

/*
This class uses third-party class and file,
all those files are in the 'bot' package.

But IDEA unsupportes Russian language or something like that.
There are some incoding problems, so I decided not to use it.

I don't know how to fix it, so sorry.

NOTICE: the SimpleBot class is commented, so
DO NOT UNCOMMENT ALL THAT ASSOCIATED WITH IT (Class SimpleBot)!!!
 */
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Date;
//import bot.*;

public class HW4J2 extends JFrame implements ActionListener{
    final String TITLE_OF_PROGRAM = "Chatter: simple chatbot";
    final int START_LOCATION = 200;
    final int WINDOW_WIDTH = 350;
    final int WINDOW_HEIGHT = 450;
    final String CHB_AI = "AI";
    final String BTN_ENTER = "Enter";

    JTextArea dialogue;
    JCheckBox ai;
    JTextField message;
    JScrollPane scrollBar;
    Date date;
    //SimpleBot sbot;

    public static void main(String[] args) {
        new HW4J2();
    }

    HW4J2() {
        setTitle(TITLE_OF_PROGRAM);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setBounds(START_LOCATION, START_LOCATION, WINDOW_WIDTH, WINDOW_HEIGHT);

        dialogue = new JTextArea();
        ai = new JCheckBox(CHB_AI);
        message = new JTextField();
        scrollBar = new JScrollPane(dialogue);

        dialogue.setEditable(false);

        JPanel bp = new JPanel();
        bp.setLayout(new BoxLayout(bp, BoxLayout.X_AXIS));
        ai.doClick();
        message.addActionListener(this);
        JButton enter = new JButton(BTN_ENTER);
        enter.addActionListener(this);

        bp.add(ai);
        bp.add(message);
        bp.add(enter);
        add(BorderLayout.CENTER, scrollBar);
        add(BorderLayout.SOUTH, bp);
        setVisible(true);

        date = new Date();
        //sbot = new SimpleBot();
    }

    public void actionPerformed(ActionEvent event) {
        if (message.getText().trim().length() > 0) {
            dialogue.append("User: " + message.getText() + "\n");
            //dialogue.append("Bot: " + sbot.sayInReturn(message.getText(), ai.isSelected()));
            dialogue.append("Bot isn't running now." + "\n");
            log(message.getText());
        }
        message.setText("");
        message.requestFocusInWindow();
    }

    public void log(String message) {
        try {
            FileWriter fw = new FileWriter("log", true); // <--                            <--^
            // If where the 'HW4J2' class (HW4J2.java) is, there isn't file named 'log', replace 'true' with 'false' or delete it.
            fw.write(date.toString() + " | Message is: " + message + " .|\n");
            fw.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
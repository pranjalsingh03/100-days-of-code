package Week_1;

import javax.swing.JButton;
import javax.swing.JFrame;

public class day2{
    public static void main(String[] args){
        JFrame frame = new JFrame("My First GUI");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 300);
        frame.setVisible(true);
        JButton button = new JButton("Press");
        frame.getContentPane().add(button);
        
    }
}
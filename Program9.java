import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.GridLayout;

public class MyFrameAdd extends JFrame
{
    private JTextField textfield1, textfield2, textfield3;

    public MyFrameAdd()
    {
        setTitle("Calculator");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        textfield1 = new JTextField(10);
        textfield2 = new JTextField(10);
        textfield3 = new JTextField(10);

        JButton myButton = new JButton("Calculate");

        myButton.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                try
                {
                    double num1 = Double.parseDouble(textfield1.getText());
                    double num2 = Double.parseDouble(textfield2.getText());
                    double num3 = Double.parseDouble(textfield3.getText());

                    double sum = num1 + num2 + num3;
                    double avg = sum / 3;
                    double largest = Math.max(Math.max(num1, num2), num3);

                    String result_message = "Sum : " + sum + "\nAverage : " + avg + "\nLargest : " + largest;
                    JOptionPane.showMessageDialog(null, result_message, "Result", JOptionPane.INFORMATION_MESSAGE);
                }
                catch(NumberFormatException ex)
                {
                    JOptionPane.showMessageDialog(null, "Invalid input", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }   
        });

        JPanel panel = new JPanel(new GridLayout(4, 2));
        panel.add(new JLabel("Number 1 : "));
        panel.add(textfield1);
        panel.add(new JLabel("Number 2 : "));
        panel.add(textfield2);
        panel.add(new JLabel("Number 3 : "));
        panel.add(textfield3);
        panel.add(new JLabel());
        panel.add(myButton);

        getContentPane().add(panel);
        setSize(300, 200);
        setVisible(true);
    }

    public static void main(String[] args)
    {
        MyFrameAdd myframe = new MyFrameAdd();
    }
}

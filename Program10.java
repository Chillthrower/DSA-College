import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class test2 extends JFrame
{
    private JComboBox<String> cityCombo;
    private JTextField textfield1, textfield2;
    private JRadioButton maleRadioButton, femaleRadioButton;
    private JCheckBox reading, sports, music;

    public test2()
    {
        setTitle("User Information form");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        cityCombo = new JComboBox<>(new String[]{"Select City", "New york", "London"});
        textfield1 = new JTextField(10);
        textfield2 = new JTextField(10);
        maleRadioButton = new JRadioButton("Male");
        femaleRadioButton = new JRadioButton("Female");
        reading = new JCheckBox("Reading");
        sports = new JCheckBox("Sports");
        music = new JCheckBox("Music");

        JButton myButton = new JButton("Submit");

        myButton.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                JOptionPane.showMessageDialog(null,
                "User Information\n" +
                        "City: " + cityCombo.getSelectedItem() + "\n" +
                        "Name: " + textfield1.getText() + "\n" +
                        "Phone: " + textfield2.getText() + "\n" +
                        "Gender: " + (maleRadioButton.isSelected() ? "Male" : femaleRadioButton.isSelected() ? "Female" : "") + "\n" +
                        "Hobbies: " + (sports.isSelected() ? "Sports " : "") + (reading.isSelected() ? "Reading " : "") + (music.isSelected() ? "Music" : ""),
                "User Info",
                JOptionPane.INFORMATION_MESSAGE);
            }
        });

        JPanel panel = new JPanel(new GridLayout(7, 2, 10, 10));
        panel.add(new JLabel("City"));
        panel.add(cityCombo);
        panel.add(new JLabel());
        panel.add(new JLabel());
        panel.add(new JLabel("Name"));
        panel.add(textfield1);
        panel.add(new JLabel());
        panel.add(new JLabel());
        panel.add(new JLabel("Phone"));
        panel.add(textfield2);
        panel.add(new JLabel());
        panel.add(new JLabel());
        panel.add(new JLabel("Gender"));
        panel.add(maleRadioButton);
        panel.add(femaleRadioButton);
        panel.add(new JLabel());
        panel.add(new JLabel());
        panel.add(new JLabel("Hobbies"));
        panel.add(reading);
        panel.add(music);
        panel.add(sports);
        panel.add(new JLabel());
        panel.add(myButton);

        getContentPane().add(panel);
        setSize(300, 200);
        setVisible(true);
    }

    public static void main(String[] args)
    {
        test2 test = new test2();
    }
}

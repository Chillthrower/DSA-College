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

// import javax.swing.*;
// import java.awt.*;
// import java.awt.event.ActionEvent;
// import java.awt.event.ActionListener;

// public class UserInformationForm extends JFrame {
//     private JComboBox<String> cityComboBox;
//     private JTextField nameField, phoneField;
//     private JRadioButton maleRadioButton, femaleRadioButton;
//     private JCheckBox readingCheckBox, sportsCheckBox, musicCheckBox;

//     public UserInformationForm() {
//         setTitle("User Information Form");
//         setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

//         // Create components
//         cityComboBox = new JComboBox<>(new String[]{"Select City", "New York", "London", "Tokyo", "Paris", "Berlin"});
//         nameField = new JTextField(20);
//         phoneField = new JTextField(20);

//         maleRadioButton = new JRadioButton("Male");
//         femaleRadioButton = new JRadioButton("Female");

//         readingCheckBox = new JCheckBox("Reading");
//         sportsCheckBox = new JCheckBox("Sports");
//         musicCheckBox = new JCheckBox("Music");

//         JButton submitButton = new JButton("Submit");

//         submitButton.addActionListener(new ActionListener() {
//             @Override
//             public void actionPerformed(ActionEvent e) {
//                 // Display the alert directly without using StringBuilder
//                 JOptionPane.showMessageDialog(null,
//                         "User Information:\n" +
//                                 "City: " + cityComboBox.getSelectedItem() + "\n" +
//                                 "Name: " + nameField.getText() + "\n" +
//                                 "Phone: " + phoneField.getText() + "\n" +
//                                 "Gender: " + (maleRadioButton.isSelected() ? "Male" : femaleRadioButton.isSelected() ? "Female" : "") + "\n" +
//                                 "Hobbies: " +
//                                 (readingCheckBox.isSelected() ? "Reading " : "") +
//                                 (sportsCheckBox.isSelected() ? "Sports " : "") +
//                                 (musicCheckBox.isSelected() ? "Music" : ""),
//                         "User Information",
//                         JOptionPane.INFORMATION_MESSAGE
//                 );
//             }
//         });

//         // Create layout
//         JPanel panel = new JPanel(new GridLayout(7, 2, 10, 10));
//         panel.add(new JLabel("City:"));
//         panel.add(cityComboBox);
//         panel.add(new JLabel("Name:"));
//         panel.add(nameField);
//         panel.add(new JLabel("Phone:"));
//         panel.add(phoneField);
//         panel.add(new JLabel("Gender:"));
//         panel.add(maleRadioButton);
//         panel.add(new JLabel());
//         panel.add(femaleRadioButton);
//         panel.add(new JLabel("Hobbies:"));
//         panel.add(readingCheckBox);
//         panel.add(sportsCheckBox);
//         panel.add(musicCheckBox);
//         panel.add(new JLabel());
//         panel.add(submitButton);

//         // Add the panel to the JFrame's content pane
//         getContentPane().add(panel);

//         setSize(400, 300);
//         setVisible(true);
//     }

//     public static void main(String[] args) {
//         new UserInformationForm();
//     }
// }


import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class UserInformationForm extends JFrame {
    private JComboBox<String> cityCombo;
    private JTextField textfield1, textfield2;
    private JRadioButton maleRadioButton, femaleRadioButton;
    private JCheckBox reading, sports, music;

    public UserInformationForm() {
        setTitle("User Information form");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        cityCombo = new JComboBox<>(new String[]{"Select City", "New York", "London"});
        textfield1 = new JTextField(10);
        textfield2 = new JTextField(10);
        maleRadioButton = new JRadioButton("Male");
        femaleRadioButton = new JRadioButton("Female");
        reading = new JCheckBox("Reading");
        sports = new JCheckBox("Sports");
        music = new JCheckBox("Music");

        JButton submitButton = new JButton("Submit");

        submitButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
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
        panel.add(submitButton);

        // Adding a JTabbedPane
        JTabbedPane tabbedPane = new JTabbedPane();
        tabbedPane.addTab("User Info", panel);

        // Adding a JScrollPane with JList
        String[] listData = {"Item 1", "Item 2", "Item 3", "Item 4", "Item 5"};
        JList<String> myList = new JList<>(listData);
        JScrollPane listScrollPane = new JScrollPane(myList);
        tabbedPane.addTab("List Example", listScrollPane);

        // Adding a JScrollPane with JTable
        String[][] tableData = {{"1", "John Doe", "25"}, {"2", "Jane Smith", "30"}, {"3", "Bob Johnson", "22"}};
        String[] columnNames = {"ID", "Name", "Age"};
        JTable myTable = new JTable(tableData, columnNames);
        JScrollPane tableScrollPane = new JScrollPane(myTable);
        tabbedPane.addTab("Table Example", tableScrollPane);

        getContentPane().add(tabbedPane);
        setSize(500, 300);
        setVisible(true);
    }

    public static void main(String[] args) {
        UserInformationForm userForm = new UserInformationForm();
    }
}

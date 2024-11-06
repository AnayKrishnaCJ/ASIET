import javax.swing.*;

import java.awt.*;

import java.awt.event.ActionEvent;

import java.awt.event.ActionListener;

public class SimpleCalculator extends JFrame implements ActionListener {

    private JTextField textField;
    private String operator = ""; // Initialize operator as an empty string
    private double num1, num2;

    public SimpleCalculator() {
        // Create a text field
        textField = new JTextField();
        textField.setEditable(false);
        textField.setFont(new Font("Arial", Font.PLAIN, 24));
        textField.setPreferredSize(new Dimension(300, 50));

        // Create buttons for digits and operations
        JButton[] numberButtons = new JButton[10];
        for (int i = 0; i < 10; i++) {
            numberButtons[i] = new JButton(String.valueOf(i));
            numberButtons[i].addActionListener(this);
        }

        JButton addButton = new JButton("+");
        JButton subButton = new JButton("-");
        JButton mulButton = new JButton("*");
        JButton divButton = new JButton("/");
        JButton modButton = new JButton("%");
        JButton equalButton = new JButton("=");
        JButton clearButton = new JButton("C");
        JButton decimalButton = new JButton(".");

        // Add action listeners for operators and other buttons
        addButton.addActionListener(this);
        subButton.addActionListener(this);
        mulButton.addActionListener(this);
        divButton.addActionListener(this);
        modButton.addActionListener(this);
        equalButton.addActionListener(this);
        clearButton.addActionListener(this);
        decimalButton.addActionListener(this);

        // Create a panel for buttons (GridLayout 4x4 + row for 0)
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(5, 4, 10, 10)); // Adjusted to add a row for 0

        // Add buttons to the panel
        panel.add(numberButtons[1]);
        panel.add(numberButtons[2]);
        panel.add(numberButtons[3]);
        panel.add(addButton);
        panel.add(numberButtons[4]);
        panel.add(numberButtons[5]);
        panel.add(numberButtons[6]);
        panel.add(subButton);
        panel.add(numberButtons[7]);
        panel.add(numberButtons[8]);
        panel.add(numberButtons[9]);
        panel.add(mulButton);
        panel.add(decimalButton);
        panel.add(numberButtons[0]);
        panel.add(equalButton);
        panel.add(clearButton);
        panel.add(divButton);
        panel.add(modButton);

        // Add components to the frame
        this.setLayout(new BorderLayout());
        this.add(textField, BorderLayout.NORTH);
        this.add(panel, BorderLayout.CENTER);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Simple Calculator");
        this.pack();
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        // If the command is a number or decimal, append it to the text field
        if (command.charAt(0) >= '0' && command.charAt(0) <= '9' || command.equals(".")) {
            textField.setText(textField.getText() + command);
        } 
        // If the command is 'C' (Clear)
        else if (command.equals("C")) {
            textField.setText("");
            operator = ""; // Reset operator when clearing
        } 
        // If the command is '=' (equals)
        else if (command.equals("=")) {
            try {
                num2 = Double.parseDouble(textField.getText());
                double result = 0;

                switch (operator) {
                    case "+":
                        result = num1 + num2;
                        break;
                    case "-":
                        result = num1 - num2;
                        break;
                    case "*":
                        result = num1 * num2;
                        break;
                    case "/":
                        if (num2 == 0) throw new ArithmeticException("Division by zero");
                        result = num1 / num2;
                        break;
                    case "%":
                        result = num1 % num2;
                        break;
                    default:
                        throw new IllegalArgumentException("No operator selected");
                }
                textField.setText(String.valueOf(result));
                operator = ""; // Reset operator after calculation
            } catch (Exception ex) {
                textField.setText("Error: " + ex.getMessage());
            }
        } 
        // If the command is an operator (+, -, *, /, %)
        else {
            if (!textField.getText().isEmpty() && operator.isEmpty()) {
                num1 = Double.parseDouble(textField.getText());
                operator = command;
                textField.setText(""); // Clear the text field for the next number input
            }
        }
    }

    public static void main(String[] args) {
        new SimpleCalculator();
    }
}


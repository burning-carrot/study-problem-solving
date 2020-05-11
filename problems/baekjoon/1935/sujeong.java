import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int operandNumber = Integer.parseInt(br.readLine());

        Stack<Double> operands = new Stack<>();

        String[] operations = br.readLine().split("");
        String[] operandNumbers = new String[operandNumber];

        for (int i = 0; i < operandNumber; i++) {
            operandNumbers[i] = br.readLine();
        }

        for (int i = 0; i < operations.length; i++) {
            int ascii = operations[i].charAt(0);

            if (ascii >= 65 && ascii <= 90) {
                operations[i] = operandNumbers[ascii - 65];
            }
        }

        for (int i = 0; i < operations.length; i++) {
            try {
                double number = Integer.parseInt(operations[i]);
                operands.push(number);
            } catch (Exception e) {
                double secondOperand = operands.pop();
                double firstOperand = operands.pop();

                double result = calculate(firstOperand, secondOperand, operations[i]);
                operands.push(result);
            }
        }

        bw.write(String.format("%.2f", operands.pop()));

        bw.flush();
        bw.close();
    }

    public static double calculate(double number1, double number2, String operator) {
        double result = 0;

        switch (operator.charAt(0)) {
            case '*':
                result = number1 * number2;
                break;
            case '-':
                result = number1 - number2;
                break;
            case '+':
                result = number1 + number2;
                break;
            case '/':
                result = number1 / number2;
                break;
        }

        return result;
    }
}
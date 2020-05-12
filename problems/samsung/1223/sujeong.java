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

        int testCase = 10;

        for (int i = 0; i < testCase; i++) {
            br.readLine(); // 문자열 길이 입력 날림
            char[] operations = br.readLine().toCharArray();
            char[] posteriorOperations = makePosteriorOperation(operations);
            Stack<Integer> operands = new Stack<>();

            for (char operation : posteriorOperations) {
                if (operation >= '0' && operation <= '9') {
                    operands.push(operation - '0');
                } else {
                    int number2 = operands.pop();
                    int number1 = operands.pop();

                    int result = calculate(number1, number2, operation);
                    operands.push(result);
                }
            }

            StringBuilder sb = new StringBuilder();

            sb.append('#');
            sb.append(Integer.toString(i + 1));
            sb.append(" ");
            sb.append(Integer.toString(operands.pop()));
            sb.append("\n");

            bw.write(sb.toString());
        }

        bw.flush();
        bw.close();
    }

    public static int calculate(int number1, int number2, char operator) {
        int result = 0;

        switch (operator) {
            case '*':
                result = number1 * number2;
                break;
            case '+':
                result = number1 + number2;
                break;
        }

        return result;
    }

    public static char[] makePosteriorOperation(char[] operations) {
        StringBuilder posteriorOperation = new StringBuilder();
        Stack<Character> operators = new Stack<>();

        for (char operation : operations) {
            if (operation >= '0' && operation <= '9') {
                posteriorOperation.append(operation);
                continue;
            }

            if (operators.isEmpty()) {
                operators.push(operation);
                continue;
            }

            char operator = operators.peek();

            posteriorOperation.append(comparePriority(operator, operation, operators));
        }

        while (!operators.isEmpty()) {
            posteriorOperation.append(operators.pop());
        }

        return posteriorOperation.toString().toCharArray();
    }

    public static String comparePriority(char operator1, char operator2, Stack<Character> operators) {
        int priorityGap = getPriority(operator1) - getPriority(operator2);
        String result = "";

        if (priorityGap < 0) {
            operators.push(operator2);
        } else {
            result += operators.pop();

            if (operators.isEmpty()) {
                operators.push(operator2);
                return result;
            }

            char nextOperator = operators.peek();
            result += comparePriority(nextOperator, operator2, operators);
        }

        return result;
    }

    public static int getPriority(char operator) {
        int priority = 0;

        if (operator == '*') {
            priority = 1;
        }

        return priority;
    }
}
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

        char[] infixOperations = br.readLine().toCharArray();
        String postfixOperations = makePosfix(infixOperations);

        bw.write(postfixOperations);
        bw.flush();
        bw.close();
    }

    public static String makePosfix(char[] infixOperations) {
        StringBuilder postfixOperations = new StringBuilder();
        Stack<Character> operators = new Stack<>();

        for (char operation : infixOperations) {
            if (operation >= 'A' && operation <= 'Z') {
                postfixOperations.append(operation);
                continue;
            }

            if (operators.isEmpty() || operation == '(') {
                operators.push(operation);
                continue;
            }

            while (!operators.isEmpty()) {
                if (operation != ')') {
                    int priorityGap = getPriority(operators.peek()) - getPriority(operation);

                    if (priorityGap < 0) {
                        break;
                    }
                }

                char operator = operators.pop();

                if (operator == '(') {
                    break;
                }

                postfixOperations.append(operator);
            }

            if (operation == ')') {
                continue;
            }

            operators.push(operation);
        }

        while (!operators.isEmpty()) {
            postfixOperations.append(operators.pop());
        }

        return postfixOperations.toString();
    }

    public static int getPriority(char operator) {
        int priority = 0;

        if (operator == '*' || operator == '/') {
            return 1;
        }

        if (operator == '(') {
            return -1;
        }

        return priority;
    }
}
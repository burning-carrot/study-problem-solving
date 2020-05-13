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
            char[] infixOperations = br.readLine().toCharArray();
            char[] postfixOperations = makePosfix(infixOperations);
            Stack<Integer> operands = new Stack<>();

            for (char operation : postfixOperations) {
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

    public static char[] makePosfix(char[] infixOperations) {
        StringBuilder postfixOperations = new StringBuilder();
        Stack<Character> operators = new Stack<>();

        for (char operation : infixOperations) {
            if (operation >= '0' && operation <= '9') {
                postfixOperations.append(operation);
                continue;
            }

            if (operators.isEmpty()) {
                operators.push(operation);
                continue;
            }

            while(!operators.isEmpty()){
                int priorityGap = getPriority(operators.peek()) - getPriority(operation);

                if(priorityGap < 0){
                    break;
                }

                postfixOperations.append(operators.pop());
            }

            operators.push(operation);
        }

        while (!operators.isEmpty()) {
            postfixOperations.append(operators.pop());
        }

        return postfixOperations.toString().toCharArray();
    }
    
    public static int getPriority(char operator) {
        int priority = 0;

        if (operator == '*') {
            priority = 1;
        }

        return priority;
    }
}
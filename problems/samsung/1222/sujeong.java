import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int testCase = 10;

        for (int i = 0; i < testCase; i++) {
            br.readLine(); // 문자열 길이 입력 날림
            char[] operations = br.readLine().toCharArray();
            int result = 0;

            for (char operation : operations) {
                if (operation >= '0' && operation <= '9') {
                    result += operation - '0';
                }
            }

            StringBuilder sb = new StringBuilder();
            sb.append("#");
            sb.append(Integer.toString(i + 1));
            sb.append(" ");
            sb.append(Integer.toString(result));
            sb.append("\n");

            bw.write(sb.toString());
        }

        bw.flush();
        bw.close();
    }
}
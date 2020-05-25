import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int totalCount = Integer.parseInt(br.readLine());
        int[] numbers = new int[100001];

        for (int i = 0; i < totalCount; i++) {
            int currentNumber = Integer.parseInt(br.readLine());

            numbers[currentNumber] += 1;
        }

        for (int i = 1; i < numbers.length; i++) {
            for (int j = 0; j < numbers[i]; j++) {
                bw.write(Integer.toString(i) + "\n");
            }
        }

        bw.flush();
        bw.close();
    }
}
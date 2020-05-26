import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int testCase = Integer.parseInt(br.readLine());

        for (int i = 0; i < testCase; i++) {
            int number = Integer.parseInt(br.readLine());
            int[] callNumberOfN = getCallNumber(number);

            bw.write(String.valueOf(callNumberOfN[0]) + " " + String.valueOf(callNumberOfN[1]) + "\n");
        }

        bw.flush();
        bw.close();
    }

    public static int[] getCallNumber(int n) {
        int[][] callNumberOfZeroNOne = new int[41][2];

        callNumberOfZeroNOne[0][0] = 1;
        callNumberOfZeroNOne[1][1] = 1;

        for (int i = 2; i <= n; i++) {
            callNumberOfZeroNOne[i][0] = callNumberOfZeroNOne[i - 1][0] + callNumberOfZeroNOne[i - 2][0];
            callNumberOfZeroNOne[i][1] = callNumberOfZeroNOne[i - 1][1] + callNumberOfZeroNOne[i - 2][1];
        }

        return callNumberOfZeroNOne[n];
    }
}
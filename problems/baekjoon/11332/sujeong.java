import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

public class Main {
    private static final String FAIL = "TLE!\n";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int testCase = Integer.parseInt(br.readLine());

        for (int i = 0; i < testCase; i++) {
            String[] situation = br.readLine().split(" ");
            String bigO = situation[0];
            BigInteger inputLength = new BigInteger(situation[1]);
            BigInteger executeCount = new BigInteger(situation[2]);
            BigInteger timeLimit = BigInteger.valueOf(Integer.parseInt(situation[3]) * 100000000);

            if (bigO.equals("O(N)")) {
                if (inputLength.multiply(executeCount).compareTo(timeLimit) == 1) {
                    bw.write(FAIL);
                    continue;
                }
            } else if (bigO.equals("O(N^2)")) {
                if (inputLength.pow(2).multiply(executeCount).compareTo(timeLimit) == 1) {
                    bw.write(FAIL);
                    continue;
                }
            } else if (bigO.equals("O(N^3)")) {
                if (inputLength.pow(3).multiply(executeCount).compareTo(timeLimit) == 1) {
                    bw.write(FAIL);
                    continue;
                }
            } else if (bigO.equals("O(2^N)")) {
                BigInteger base = new BigInteger("2");
                if (base.pow(inputLength.intValue()).multiply(executeCount).compareTo(timeLimit) == 1) {
                    bw.write(FAIL);
                    continue;
                }
            } else {
                int n = inputLength.intValue();

                while (n-- > 1) {
                    inputLength = inputLength.multiply(new BigInteger(Integer.toString(n)));
                    if (inputLength.compareTo(timeLimit) == 1) {
                        break;
                    }
                }

                if (inputLength.multiply(executeCount).compareTo(timeLimit) == 1) {
                    bw.write(FAIL);
                    continue;
                }
            }

            bw.write("May Pass.\n");
        }

        bw.flush();
        bw.close();
    }
}
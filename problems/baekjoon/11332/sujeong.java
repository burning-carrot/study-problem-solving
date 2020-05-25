import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int testCase = Integer.parseInt(br.readLine());

        for (int i = 0; i < testCase; i++) {
            String[] situation = br.readLine().split(" ");

            if (isTimeout(situation)) {
                bw.write("TLE!\n");
            } else {
                bw.write("May Pass.\n");
            }

        }

        bw.flush();
        bw.close();
    }

    private static boolean isTimeout(String[] inputs) {
        String bigO = inputs[0];
        BigInteger inputLength = new BigInteger(inputs[1]);
        BigInteger executeCount = new BigInteger(inputs[2]);
        BigInteger timeLimit = BigInteger.valueOf(Integer.parseInt(inputs[3]) * 100000000);

        switch (bigO) {
            case "O(N)":
                if (inputLength.multiply(executeCount).compareTo(timeLimit) == 1) {
                    return true;
                }
                break;
            case "O(N^2)":
                if (inputLength.pow(2).multiply(executeCount).compareTo(timeLimit) == 1) {
                    return true;
                }
                break;
            case "O(N^3)":
                if (inputLength.pow(3).multiply(executeCount).compareTo(timeLimit) == 1) {
                    return true;
                }
                break;
            case "O(2^N)":
                if (BigInteger.valueOf(2).pow(inputLength.intValue()).multiply(executeCount)
                        .compareTo(timeLimit) == 1) {
                    return true;
                }
                break;
            case "O(N!)":
                int n = inputLength.intValue();

                while (n-- > 1) {
                    inputLength = inputLength.multiply(BigInteger.valueOf(n));

                    if (inputLength.compareTo(timeLimit) == 1) {
                        return true;
                    }
                }

                if (inputLength.multiply(executeCount).compareTo(timeLimit) == 1) {
                    return true;
                }

                break;
        }

        return false;
    }
}
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
            CallNumber callNumberOfN = getCallNumber(number);

            bw.write(callNumberOfN.toString());
        }

        bw.flush();
        bw.close();
    }

    public static CallNumber getCallNumber(int n) {
        CallNumber[] zeroNOne = new CallNumber[41];

        zeroNOne[0] = new CallNumber(1, 0);
        zeroNOne[1] = new CallNumber(0, 1);

        for (int i = 2; i <= n; i++) {
            int zero = zeroNOne[i - 1].zero + zeroNOne[i - 2].zero;
            int one = zeroNOne[i - 1].one + zeroNOne[i - 2].one;

            zeroNOne[i] = new CallNumber(zero, one);
        }

        return zeroNOne[n];
    }
}

class CallNumber {
    int zero;
    int one;

    public CallNumber(int zero, int one) {
        this.zero = zero;
        this.one = one;
    }

    public String toString() {
        StringBuffer sb = new StringBuffer();

        sb.append(String.valueOf(zero));
        sb.append(" ");
        sb.append(String.valueOf(one));
        sb.append("\n");

        return sb.toString();
    }
}
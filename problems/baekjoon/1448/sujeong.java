import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int strawNumber = Integer.parseInt(br.readLine());
        int[] straws = new int[strawNumber];

        for (int i = 0; i < strawNumber; i++) {
            straws[i] = Integer.parseInt(br.readLine());
        }

        bw.write(String.valueOf(findMaxTriangle(strawNumber, straws)));

        bw.flush();
        bw.close();
    }

    public static int findMaxTriangle(int strawNumber, int[] straws) {
        Arrays.sort(straws);

        for (int i = strawNumber - 1; i > 1; i--) {
            if (canTriangle(straws[i], straws[i - 1], straws[i - 2])) {
                return straws[i] + straws[i - 1] + straws[i - 2];
            }
        }

        return -1;
    }

    public static boolean canTriangle(int a, int b, int c) {
        if (a < b + c) {
            return true;
        }

        return false;
    }
}
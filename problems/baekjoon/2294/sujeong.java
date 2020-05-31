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

        String[] information = br.readLine().split(" ");
        int coinNumber = Integer.parseInt(information[0]);
        int price = Integer.parseInt(information[1]);
        int[] coins = new int[coinNumber];
        int[] coinNumberOfValue = new int[price + 1];

        for (int i = 0; i < coinNumber; i++) {
            coins[i] = Integer.parseInt(br.readLine());
        }

        Arrays.fill(coinNumberOfValue, 100001);
        coinNumberOfValue[0] = 0;

        for (int i = 0; i < coinNumber; i++) {
            for (int j = coins[i]; j <= price; j++) {
                coinNumberOfValue[j] = Math.min(coinNumberOfValue[j], coinNumberOfValue[j - coins[i]] + 1);
            }
        }

        bw.write(String.valueOf(coinNumberOfValue[price] == 100001 ? -1 : coinNumberOfValue[price]));

        bw.flush();
        bw.close();
    }
}
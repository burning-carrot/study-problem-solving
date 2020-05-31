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

        int wineNumber = Integer.parseInt(br.readLine());
        int[] wines = new int[10001];
        int[] drinks = new int[10001];

        for (int i = 1; i <= wineNumber; i++) {
            wines[i] = Integer.parseInt(br.readLine());
        }

        drinks[1] = wines[1];
        drinks[2] = wines[1] + wines[2];

        for (int i = 3; i <= wineNumber; i++) {
            drinks[i] = Math.max(drinks[i - 1],
                    Math.max(drinks[i - 2] + wines[i], drinks[i - 3] + wines[i - 1] + wines[i]));
        }

        bw.write(Integer.toString(drinks[wineNumber]));

        bw.flush();
        bw.close();
    }
}
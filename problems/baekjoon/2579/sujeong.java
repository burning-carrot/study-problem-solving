import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int stairNumber = Integer.parseInt(br.readLine());
        int[] stairs = new int[stairNumber];

        for (int i = 0; i < stairNumber; i++) {
            stairs[i] = Integer.parseInt(br.readLine());
        }

        int[] score = new int[stairNumber + 2];

        score[0] = stairs[0];
        score[1] = stairNumber > 1 ? stairs[0] + stairs[1] : 0;
        score[2] = stairNumber > 2 ? Math.max(stairs[0] + stairs[2], stairs[1] + stairs[2]) : 0;

        for (int i = 3; i < stairNumber; i++) {
            score[i] = Math.max(score[i - 2] + stairs[i], score[i - 3] + stairs[i - 1] + stairs[i]);
        }

        bw.write(String.valueOf(score[stairNumber - 1]));

        bw.flush();
        bw.close();
    }
}
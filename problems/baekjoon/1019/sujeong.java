import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int lastPage = Integer.parseInt(br.readLine());
        int[] countNumber = new int[10];
        int startPage = 1;
        int point = 1;

        while (startPage <= lastPage) {
            while (lastPage % 10 != 9 && startPage <= lastPage) {
                calculate(lastPage, countNumber, point);
                lastPage--;
            }

            if (lastPage < startPage) {
                break;
            }

            while (startPage % 10 != 0 && startPage <= lastPage) {
                calculate(startPage, countNumber, point);
                startPage++;
            }

            lastPage /= 10;
            startPage /= 10;

            for (int i = 0; i < 10; i++) {
                countNumber[i] += (lastPage - startPage + 1) * point;
            }

            point *= 10;
        }

        for (int count : countNumber) {
            bw.write(Integer.toString(count) + " ");
        }

        bw.flush();
        bw.close();
    }

    public static void calculate(int page, int[] countNumber, int point) {
        while (page > 0) {
            countNumber[page % 10] += point;
            page /= 10;
        }
    }
}
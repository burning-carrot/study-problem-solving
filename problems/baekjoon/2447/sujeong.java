import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
    private static int patternSize;
    private static char[][] patterns;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        patternSize = Integer.parseInt(br.readLine());
        patterns = new char[patternSize][patternSize];

        for (char[] patternRow : patterns) {
            Arrays.fill(patternRow, ' ');
        }

        makePattern(0, 0, patternSize);

        for (char[] patternRow : patterns) {
            bw.write(patternRow);
            bw.write("\n");
        }

        bw.flush();
        bw.close();
    }

    public static void makePattern(int row, int col, int size) {
        if (size == 1) {
            patterns[row][col] = '*';
            return;
        }

        int newSize = size / 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }

                makePattern(row + (i * newSize), col + (j * newSize), newSize);
            }
        }
    }
}

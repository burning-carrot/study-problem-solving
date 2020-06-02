import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        char[] information = br.readLine().toCharArray();
        Queue<int[]> ripenTomatoes = new LinkedList<>();

        int col = information[0] - '0';
        int row = information[2] - '0';

        int[][] tomatoes = new int[row][col];
        int unripeTomatoNumber = 0;

        for (int i = 0; i < row; i++) {
            String[] tomatoRow = br.readLine().split(" ");
            for (int j = 0; j < col; j++) {
                tomatoes[i][j] = Integer.parseInt(tomatoRow[j]);

                if (tomatoes[i][j] == 1) {
                    ripenTomatoes.offer(new int[] { i, j });
                } else if (tomatoes[i][j] == 0) {
                    unripeTomatoNumber += 1;
                }
            }
        }

        int days = getAllTomatoRipenDay(unripeTomatoNumber, ripenTomatoes, tomatoes);

        bw.write(Integer.toString(days));

        bw.flush();
        bw.close();
    }

    public static int getAllTomatoRipenDay(int unripeTomatoNumber, Queue<int[]> ripenTomatoes, int[][] tomatoes) {
        if (unripeTomatoNumber == 0) {
            return 0;
        }

        int days = 0;
        int row = tomatoes.length;
        int col = tomatoes[0].length;
        int[] directionX = { 0, 0, -1, 1 };
        int[] directionY = { -1, 1, 0, 0 };

        while (!ripenTomatoes.isEmpty()) {
            int todayRipenTomatoNumber = ripenTomatoes.size();

            for (int i = 0; i < todayRipenTomatoNumber; i++) {
                int[] ripenTomato = ripenTomatoes.poll();

                for (int j = 0; j < 4; j++) {
                    int nextX = ripenTomato[1] + directionX[j];
                    int nextY = ripenTomato[0] + directionY[j];

                    if (nextX < 0 || nextX >= col || nextY < 0 || nextY >= row) {
                        continue;
                    }

                    if (tomatoes[nextY][nextX] == 0) {
                        tomatoes[nextY][nextX] = 1;
                        unripeTomatoNumber -= 1;
                        ripenTomatoes.offer(new int[] { nextY, nextX });
                    }
                }
            }

            if (ripenTomatoes.isEmpty()) {
                break;
            }

            days += 1;
        }

        return unripeTomatoNumber == 0 ? days : -1;
    }
}

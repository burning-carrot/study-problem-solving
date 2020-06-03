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

        String[] information = br.readLine().split(" ");
        int col = Integer.parseInt(information[0]);
        int row = Integer.parseInt(information[1]);

        TomatoBox tomatoes = new TomatoBox(row, col);

        for (int i = 0; i < row; i++) {
            tomatoes.putTomatoes(i, br.readLine().split(" "));
        }

        int days = tomatoes.getAllTomatoRipenDay();
        bw.write(Integer.toString(days));

        bw.flush();
        bw.close();
    }
}

class TomatoBox {
    private int[][] tomatoBox;
    private int boxWidth;
    private int boxHeight;
    Queue<Location> ripenTomatoes;
    private int unripeTomatoes = 0;

    public TomatoBox(int row, int col) {
        this.boxHeight = row;
        this.boxWidth = col;
        this.tomatoBox = new int[boxHeight][boxWidth];
        this.ripenTomatoes = new LinkedList<>();
    }

    public void putTomatoes(int row, String[] tomatoRow) {
        for (int i = 0; i < boxWidth; i++) {
            tomatoBox[row][i] = Integer.parseInt(tomatoRow[i]);

            if (tomatoBox[row][i] == 0) {
                unripeTomatoes += 1;
            } else if (tomatoBox[row][i] == 1) {
                ripenTomatoes.offer(new Location(row, i));
            }
        }
    }

    public int getAllTomatoRipenDay() {
        if (unripeTomatoes == 0) {
            return 0;
        }

        int days = 0;
        Location[] direction = { new Location(-1, 0), new Location(1, 0), new Location(0, -1), new Location(0, 1) };
        Queue<Location> newRipenTomatoes = new LinkedList<>();

        while (!ripenTomatoes.isEmpty()) {
            Location ripenTomato = ripenTomatoes.poll();

            for (int i = 0; i < 4; i++) {
                int nextCol = ripenTomato.col + direction[i].col;
                int nextRow = ripenTomato.row + direction[i].row;

                if (nextCol < 0 || nextCol >= boxWidth || nextRow < 0 || nextRow >= boxHeight) {
                    continue;
                }

                if (tomatoBox[nextRow][nextCol] == 0) {
                    tomatoBox[nextRow][nextCol] = 1;
                    unripeTomatoes -= 1;
                    newRipenTomatoes.offer(new Location(nextRow, nextCol));
                }
            }

            if (ripenTomatoes.isEmpty() && !newRipenTomatoes.isEmpty()) {
                days += 1;
                while (!newRipenTomatoes.isEmpty()) {
                    ripenTomatoes.offer(newRipenTomatoes.poll());
                }
            }
        }

        return unripeTomatoes == 0 ? days : -1;
    }
}

class Location {
    int col;
    int row;

    public Location(int row, int col) {
        this.row = row;
        this.col = col;
    }
}
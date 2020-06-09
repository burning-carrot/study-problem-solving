import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int length = Integer.parseInt(br.readLine());
        Paper colorPaper = new Paper(length);

        for (int i = 0; i < length; i++) {
            colorPaper.setPaperColor(i, br.readLine().split(" "));
        }

        colorPaper.devidePaper(new Location(0, 0), new Location(length - 1, length - 1));

        bw.write(Integer.toString(colorPaper.getWhitePaperCount()));
        bw.write("\n");
        bw.write(Integer.toString(colorPaper.getBluePaperCount()));
        bw.flush();
        bw.close();
    }
}

class Paper {
    private int[][] paper;
    private int length;
    private int[] paperCount;

    public Paper(int length) {
        this.length = length;
        this.paper = new int[length][length];
        this.paperCount = new int[2];
    }

    public void setPaperColor(int row, String[] paperRow) {
        for (int i = 0; i < length; i++) {
            paper[row][i] = Integer.parseInt(paperRow[i]);
        }
    }

    public void devidePaper(Location start, Location end) {
        if (checkAllColorSame(start, end)) {
            int color = paper[start.row][start.col];
            paperCount[color] += 1;
            return;
        }

        Location middle = new Location((start.row + end.row) / 2, (start.col + end.col) / 2);
        devidePaper(start, middle); // 좌상
        devidePaper(new Location(start.row, middle.col + 1), new Location(middle.row, end.col)); // 우상
        devidePaper(new Location(middle.row + 1, start.col), new Location(end.row, middle.col)); // 좌하
        devidePaper(new Location(middle.row + 1, middle.col + 1), end); // 우하
    }

    public int getWhitePaperCount() {
        return paperCount[0];
    }

    public int getBluePaperCount() {
        return paperCount[1];
    }

    public boolean checkAllColorSame(Location start, Location end) {
        int color = paper[start.row][start.col];

        for (int i = start.row; i <= end.row; i++) {
            for (int j = start.col; j <= end.col; j++) {
                if (color != paper[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
}

class Location {
    public int row;
    public int col;

    public Location(int row, int col) {
        this.row = row;
        this.col = col;
    }
}

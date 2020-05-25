import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int finalChannel = Integer.parseInt(br.readLine());
        int brokenButtonCount = Integer.parseInt(br.readLine());
        boolean[] brokenButtons = new boolean[10];

        if (brokenButtonCount > 0) {
            for (String button : br.readLine().split(" ")) {
                brokenButtons[Integer.parseInt(button)] = true;
            }
        }

        int minimalMoving = Math.abs(finalChannel - 100);

        for (int i = 0; i <= 888888; i++) {
            char[] currentChannel = String.valueOf(i).toCharArray();

            if (!canPressChannelButton(brokenButtons, currentChannel)) {
                continue;
            }

            if (minimalMoving > Math.abs(i - finalChannel) + currentChannel.length) {
                minimalMoving = Math.abs(i - finalChannel) + currentChannel.length;
            }
        }

        bw.write(Integer.toString(minimalMoving));

        bw.flush();
        bw.close();
    }

    public static boolean canPressChannelButton(boolean[] buttons, char[] channel) {
        for (char number : channel) {
            if (buttons[number - '0']) {
                return false;
            }
        }

        return true;
    }
}
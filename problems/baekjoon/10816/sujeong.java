import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int cardsNumber = Integer.parseInt(br.readLine());
        Map<Integer, Integer> cards = new HashMap<>();
        String[] cardSet = br.readLine().split(" ");

        for (int i = 0; i < cardsNumber; i++) {
            int currentCard = Integer.parseInt(cardSet[i]);

            if (cards.get(currentCard) == null) {
                cards.put(currentCard, 1);
            } else {
                cards.put(currentCard, cards.get(currentCard) + 1);
            }
        }

        int chooseCardsNumber = Integer.parseInt(br.readLine());
        String[] chooseCardSet = br.readLine().split(" ");

        for (int i = 0; i < chooseCardsNumber; i++) {
            int cardNumber = Integer.parseInt(chooseCardSet[i]);

            if (cards.get(cardNumber) == null) {
                bw.write("0 ");
            } else {
                bw.write(Integer.toString(cards.get(cardNumber)) + " ");
            }
        }

        bw.flush();
        bw.close();
    }
}
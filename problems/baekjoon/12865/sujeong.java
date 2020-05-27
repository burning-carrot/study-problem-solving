import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] information = br.readLine().split(" ");
        int productNumber = Integer.parseInt(information[0]);
        int maxWeight = Integer.parseInt(information[1]);

        Product[] products = new Product[101];
        int[] bags = new int[100001];

        for (int i = 0; i < productNumber; i++) {
            String[] product = br.readLine().split(" ");
            products[i] = new Product(product);
        }

        for (int i = 0; i < productNumber; i++) {
            for (int j = maxWeight; j >= products[i].weight; j--) {
                bags[j] = Math.max(bags[j], bags[j - products[i].weight] + products[i].value);
            }
        }

        bw.write(Integer.toString(bags[maxWeight]));

        bw.flush();
        bw.close();
    }
}

class Product {
    int weight;
    int value;

    public Product(String[] productInformation) {
        this.weight = Integer.parseInt(productInformation[0]);
        this.value = Integer.parseInt(productInformation[1]);
    }
}
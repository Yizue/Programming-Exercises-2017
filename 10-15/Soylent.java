import java.util.Scanner;

public class Soylent {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        for (int i = 0; i < N; i++) {
            int M = in.nextInt();
            if (M % 400 == 0) {
                System.out.println(M / 400);
            } else {
                System.out.println((M / 400) + 1);
            }
        }
    }

}

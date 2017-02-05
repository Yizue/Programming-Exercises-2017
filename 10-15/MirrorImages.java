import java.util.Scanner;

public class MirrorImages {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        
        for (int i = 1; i <= T; i++){
            int R = in.nextInt(), C = in.nextInt();
            char[][] Orig = new char[R][C]; 
            
            for (int j = 0; j < R; j++){
                String temp = in.next();
                for (int k = 0; k < C; k++){
                    Orig[j][k] = temp.charAt(k);
                }
            }
            System.out.println("Test " + i);
            for (int j = 0; j < R; j++){
                for (int k = 0; k < C; k++){
                    System.out.print(Orig[R - j - 1][C - k - 1]);
                }
                System.out.println("");
            }           
        }
    }   
}

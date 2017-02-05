
import java.util.Scanner;

public class Bits {

        public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        for (int i=0; i<t; i++)
        {
            int maxOne = 0;
            int num = sc.nextInt();
            String numS = (new Integer(num)).toString(); 
            
            for(int j=1; j<=numS.length(); j++)
            {
                //Get substring of numS
                String bin = Integer.toBinaryString( Integer.parseInt( numS.substring(0,j) ) );
                int c=0;
                for(int k=0; k<bin.length(); k++)
                    if(bin.charAt(k) == '1')
                        c++;
                
                if(c > maxOne)
                    maxOne = c;
            }
            System.out.println(maxOne);
        }
    }
    
}

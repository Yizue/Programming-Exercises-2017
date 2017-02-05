import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author shira002
 */
public class ThreePowers {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String num = sc.next();

	while (!num.equals("0"))
        {
            BigInteger sum = new BigInteger(num);
            sum = sum.subtract(new BigInteger("1"));
            String s = sum.toString(2);
            //System.out.println(s);
            BigInteger S = BigInteger.valueOf(1);
            int cnt=0, tot=0;
            for(int j=0; j<s.length(); j++)
                if(s.charAt(j) == '1')
                    cnt++;
            System.out.print("{ ");
            for(int i=s.length()-1; i>=0; i--)
            {
                //System.out.println("S: " + s.charAt(i));
                if(s.charAt(i) == '1')
                {
                    if(tot != cnt-1) 
                        System.out.print(S.toString() + ", ");
                    else 
                        System.out.print(S.toString() + " ");
                    tot++;
                }
                S = S.multiply(new BigInteger("3"));
            }
            System.out.println("}");
            //System.out.println(s);
            num = sc.next();
            sum = BigInteger.valueOf(0);
            sum.add(new BigInteger(num));
        }

    }
    
}

import java.math.*;
import java.util.*;
/**
 * Created by sunguoli on 3/9/17.
 */
public class BigIntegerTest {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);

        System.out.print("How many numbers do you need to draw");
        int k = in.nextInt();

        System.out.print("What is the highest number you can draw? ");
        int n = in.nextInt();

        /*
         * compute binomial coefficient n*(n-1)*(n-2)*...*(n-k+1)/(1*2*3*...*k)
         */

        BigInteger lotteryOdds = BigInteger.valueOf(1);

        for(int i = 1; i <= k; i++)
            lotteryOdds = lotteryOdds.multiply(BigInteger.valueOf(n - i + 1)).divide(BigInteger.valueOf(i));

        System.out.print("Your odds are 1 in " + lotteryOdds + ". Good luck!");
    }
}

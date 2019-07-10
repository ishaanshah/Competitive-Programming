/* Created by Ishaan Shah on 07-07-2019.
* Problem Name: Minimum and Maximum
* Problem Link: https://www.codechef.com/JULY19B/problems/MMAX
*/

import java.math.BigInteger;
import java.util.*;

class Main {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int n = sc.nextInt();
            BigInteger k = sc.nextBigInteger();
            int mod = k.mod(BigInteger.valueOf(n)).intValue();
            if (n == 2) {
                if (mod == 1) System.out.println("1");
                else System.out.println("0");
            } else {
                if (n%2 == 1) {
                    if (mod <= (n-1)/2) System.out.println(mod*2);
                    else System.out.println((n-mod)*2);
                } else {
                    if (mod < n/2) System.out.println(mod*2);
                    else if (mod > n/2) System.out.println((n-mod)*2);
                    else System.out.println(mod*2-1);
                }
            }
            t--;
        }
        sc.close();
    }
}
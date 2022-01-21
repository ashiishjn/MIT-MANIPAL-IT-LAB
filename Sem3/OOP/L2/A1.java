import java.util.Scanner;
public class TFirst{
    public static void main(String args[]){
        float val,a,b;
        System.out.println("Enter a and b for the following opeartions:\na. (a << 2) + (b >> 2) \nb. (b > 0) \nc. (a + b * 100) / 10 \nd. a & b ")
        Scanner scan=new Scanner(System.in);
        a=scan.nextInt();
        b=scan.nextInt();
        val=(a << 2) + (b >> 2);
        System.out.println("a. (a << 2) + (b >> 2) "+val);
        val= (b > 0);
        System.out.println("b. (b > 0) "+val);
        val=(a + b * 100) / 10;
        System.out.println("c. (a + b * 100) / 10 "+val);
        val=a & b;
        System.out.println("d. a & b"+val);
    }
}
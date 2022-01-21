import java.util.Scanner;
public class First{
    public static void main(String args[]){
        int val=0;
        int n;
        System.out.println("Enter the value of n:");
        Scanner scan = new Scanner(System.in);
        n=scan.nextInt();
        int dig=0;
        int temp=n;
        while(n>0){
            dig=n%10;
            val+=dig*dig*dig;
            n=n/10;
        }
        if(val==temp){
            System.out.println("Armstrong Number!");
        }
        else
            System.out.println("Not an Armstrong Number!");
    }
}
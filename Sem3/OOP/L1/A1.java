import java.util.Scanner;
public class Fourth{
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the number");
        int n = scan.nextInt();
        int temp = n, rem, rev=0;
        while(n!=0){
            rem=n%10;
            rev=rev*10+rem;
            n/=10;
        }
        if (temp==rev){
            System.out.println("Number is a palindrome");
        }
        else{
            System.out.println("Number is not a palindrome");
        }
    }
}
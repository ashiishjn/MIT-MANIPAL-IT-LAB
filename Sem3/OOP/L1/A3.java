import java.util.Scanner;
public class Sixth{
    public static void main(String args[]){
        Scanner scan= new Scanner(System.in);
        System.out.println("Enter the number to print the table of:");
        int n = scan.nextInt();
        for(int i=1;i<11;i++){
            System.out.println(n*i);
        }
    }
}
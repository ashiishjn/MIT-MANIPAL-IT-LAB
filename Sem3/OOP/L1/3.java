import java.util.Scanner;
public class Third{
    public static void main(String args[]){
        Scanner s= new Scanner(System.in);
        System.out.println("Enter the number of odd numbers required:");
        int n=s.nextInt();
        for(int i=0;i<n;i++){
            System.out.println(2*i+1);
        }

    }
}
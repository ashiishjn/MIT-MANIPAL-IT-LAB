import java.util.Scanner;
public class Fifth{
    public static void main(String args[]){
        Scanner scan=new Scanner(System.in);
        System.out.println("Enter the number to calculate the factorial of:");
        int a=scan.nextInt();
        scan.close();
        int val=1;
        for(int i=1;i<=a;i++){
            val*=i;
        }
        System.out.println(val);
    }
}
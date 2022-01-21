import java.util.Scanner;
public class Fifth{
    public static void main(String args[]){
        Scanner scan= new Scanner(System.in);
        int n=scan.nextInt();
        int arr[]=new int[n];
        System.out.println("Enter the elements:");
        for(int i=0;i<n;i++){
            arr[i]=scan.nextInt();
        }
        int key,flag=0;
        System.out.println("Enter the key:");
        key=scan.nextInt();
        System.out.print("The output is found at location:");
        for(int i=0;i<n;i++){
            if(arr[i]==key){
                System.out.print("a["+i+"] ");
            }
        }
        java.lang.System.exit(0);
        System.out.print("NULL");
    }
}
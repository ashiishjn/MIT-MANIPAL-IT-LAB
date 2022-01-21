import java.util.Scanner;
public class Third{
    public static void main(String args[]){
        int n;
        Scanner scan= new Scanner(System.in);
        n=scan.nextInt();
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                System.out.print(i+1+" ");
            }
            System.out.print('\n');
        }
        scan.close();
    }
}
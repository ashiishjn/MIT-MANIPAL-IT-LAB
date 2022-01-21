import java.util.Scanner;
public class Second{
    public static void main(String args[]){
        int m,n;
        Scanner scan=new Scanner(System.in);
        System.out.println("Enter the size of the matrix:");
        m=scan.nextInt();
        n=scan.nextInt();
        int a[][]=new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                System.out.println("Enter element ["+i+"]["+j+"]:");
                a[i][j]=scan.nextInt();
            }
        }
        int prin=0;
        for(int i=0;i<m;i++){
            if(i<n){
                System.out.println(a[i][i]);
                prin+=a[i][i];
            }
        }
        System.out.println(prin);
        scan.close();
    }
}
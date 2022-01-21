import java.util.Scanner;
public class First{
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
        int non=0;
        for(int i=0;i<m;i++){
            if((n-i-1)>=0){
                System.out.println(a[i][n-i-1]);
                non+=a[i][n-i-1];
            }
            }
        
        System.out.println(non);
        scan.close();
    }
}
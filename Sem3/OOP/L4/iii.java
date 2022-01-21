import java.util.Scanner;
public class Third{
    public static void main(String args[]){
        int n;
        Scanner scan=new Scanner(System.in);
        System.out.println("Enter the size of the matrix:");
        n=scan.nextInt();
        int a[][]=new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.println("Enter element ["+i+"]["+j+"]:");
                a[i][j]=scan.nextInt();
            }
        }
        boolean flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                flag=true;
                if(a[i][j]!=a[j][i]){
                    flag=false;
                    break;
                }
            }
            if(flag==false){
                break;
            }
        }
        if(flag==true){
            System.out.println("The matrix is symmetric");
        }
        else{
            System.out.println("The matrix is non-symmetric");
        }
        scan.close();
    }
}
import java.util.Scanner;
public class Fifth{
    public static void main(String args[]){
        int n;
        Scanner scan=new Scanner(System.in);
        System.out.println("Enter the size of matrix A:");
        n=scan.nextInt();
        int a[][]=new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.println("Enter element ["+i+"]["+j+"]:");
                a[i][j]=scan.nextInt();
            }
        }
        int row, column, flag=0, sum, sum1, sum2;
        //For diagonal elements
        sum = 0;
        for (row = 0; row < n; row++) {
            for (column = 0; column < n; column++) {
                if (row == column)
                    sum = sum + a[row][column];
            }
        }

        //For Rows
        for (row = 0; row < n; row++) {
            sum1 = 0;
            for (column = 0; column < n; column++) {
                sum1 = sum1 + a[row][column];
            }
            if (sum == sum1)
                flag = 1;
            else {
                flag = 0;
                break;
            }
        }

        //For Columns
        for (row = 0; row < n; row++) {
            sum2 = 0;
            for (column = 0; column < n; column++) {
                sum2 = sum2 + a[column][row];
            }
            if (sum == sum2)
                flag = 1;
            else {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
                System.out.println("Magic square");
        else
                System.out.println("Not a magic square");
        
        scan.close();
    }
}

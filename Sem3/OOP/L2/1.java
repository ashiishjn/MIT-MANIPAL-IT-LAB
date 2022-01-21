import java.util.Scanner;
public class First{
    public static void main(String args[]){
        Scanner scan=new Scanner(System.in);
        System.out.println("Enter the year");
        int year =scan.nextInt();
        boolean d1=year%4!=0, d2=year%100!=0, d3=year%400!=0;
        if(d1){
            System.out.println("It is a common year.");
        }
        else if(d2){
            System.out.println("It is a leap year.");
        }
        else if(d3){
            System.out.println("It is a common year.");
        }
        else{
            System.out.println("It is a leap year.");

        }
        scan.close();

    }
}
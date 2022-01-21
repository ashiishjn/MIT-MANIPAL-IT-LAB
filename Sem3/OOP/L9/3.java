import java.util.Scanner;
import java.util.Arrays;
public class Third{
    public static void main(String args[]){
        Scanner scan= new Scanner(System.in);
        System.out.print("Enter the string:");
        String strb= scan.nextLine();
        String strb2= ((new StringBuffer(strb)).reverse()).toString();
        System.out.println("1.Check for Palindrome");
        System.out.println("2.Arrange in alphabetical order");
        System.out.println("3.Reverse the string");
        System.out.println("4.Concatenate original and reversed");
        System.out.println("5.Exit");
        int choice;
        while(true){
            System.out.print(">");
            choice=scan.nextInt();
            switch (choice){
                case 1:
                    if(strb.equals(strb2))
                        System.out.println("String is a palindrome");
                    else
                        System.out.println("Not a palindrome");
                    break;
                case 2:
                    char[] c= strb.toCharArray();
                    Arrays.sort(c);
                    System.out.println(new String(c));
                    break;
                case 3:
                    System.out.println(strb2);
                    break;
                case 4:
                    System.out.println(strb.concat(strb2));
                    break;
                case 5:
                    scan.close();
                    return;
                default:
                    System.out.println("Invalid Choice");
            }   
        }
    }
}
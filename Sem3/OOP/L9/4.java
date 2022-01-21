import java.util.Scanner;
public class Fourth{
    static Scanner scan= new Scanner(System.in);
    static void compare(){
        System.out.print("Enter the first string:");
        String s1= scan.nextLine();
        System.out.print("Enter the second string:");
        String s2= scan.nextLine();
        int c = s1.compareTo(s2);
        if(c>0)
        System.out.println("String 1 is greater");
        else if(c<0)
        System.out.println("String 2 is greater");
        else
        System.out.println("Strings are same");
    }
    
    static void Swapcases(){
        System.out.print("Enter the string:");
        String s1= scan.nextLine();
        for(int i=0;i<s1.length();i++){
            char c=s1.charAt(i);
            if(c>='A'&& c<='Z'){
                c+=32;
            }
            else if(c>='a'&& c<='z'){
                c-=32;
            }
            else
                continue;
            System.out.print(c);
        }
        System.out.println();
    }
    
    static void substring(boolean r){
        System.out.print("Enter the string:");
        String s=scan.nextLine();
        System.out.print("Enter the sub-string:");
        String ss=scan.nextLine();
        boolean isFound = s.indexOf(ss) !=-1? true: false;
        if(isFound){
            if(r){
                System.out.println(s.replace(ss,"Hello"));
                return;
            }
            System.out.println("Substring found in the string");
        }
        else{
            System.out.println("Substring not found in the string");
        }        
        return;
    }
    public static void main(String args[]){
        System.out.println("1.Compare Two Strings");
        System.out.println("2.Swapcases");
        System.out.println("3.Check for substring");
        System.out.println("4.Replace substring with Hello");
        System.out.println("5.Exit");
        int choice;
        while(true){
            System.out.print(">");
            choice=scan.nextInt();
            scan.nextLine();
            switch (choice){
                case 1:
                    compare();
                    break;
                case 2:
                    Swapcases();;
                    break;
                case 3:
                    substring(false);
                    break;
                case 4:
                    substring(true);
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
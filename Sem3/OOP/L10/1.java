import java.util.Scanner;
import java.io.*;
public class First{
    public static void main(String args[]) throws IOException, EOFException{
        Scanner scan= new Scanner(System.in);
        File f1= new File("1.txt");
        File f2= new File("1C.txt");
        if(!f1.exists())
            f1.createNewFile();
        if(!f2.exists())
            f2.createNewFile();
        System.out.println("1.Write a line to a file");
        System.out.println("2.Read a line from a file");
        System.out.println("3.Copy the contents of one file to other file");
        System.out.println("4.Exit");
        System.out.println("Make a choice. JUST DECIDE!");
        int choice,ch;
        while(true){
            System.out.print(">");
            choice=scan.nextInt();
            scan.nextLine();
            switch(choice){
                case 1:
                FileOutputStream bor= new FileOutputStream(f1,true);
                System.out.println("Enter a line of string:");
                String s1=scan.nextLine();
                byte b[]=s1.getBytes();
                bor.write(b);
                bor.write('\n');
                bor.flush();
                System.out.println("Successfully written!");
                break;
            case 2:
                FileInputStream bir= new FileInputStream(f1);
                System.out.println("READING FILE:");
                while((ch=bir.read())!=-1){
                    System.out.print((char)ch);
                }
                break;
            case 3:
                FileInputStream bir2= new FileInputStream(f1);
                FileOutputStream bor2= new FileOutputStream(f2);
                while((ch=bir2.read())!=-1){
                    bor2.write(ch);
                }
                System.out.println("Files Copied");
                break;
            case 4:
                return;
            default:
                System.out.println("Invalid Choice!");          
            }  
        }
    }
}
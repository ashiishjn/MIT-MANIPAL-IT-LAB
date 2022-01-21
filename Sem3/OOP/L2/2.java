import java.util.Scanner;
public class Second{
    public static void main(String args[]){
        Scanner scan=new Scanner(System.in);
        int i= scan.nextInt();
        double d= scan.nextDouble();
        char c= scan.next().charAt(0);
        byte itb= (byte) i;
        int cti= (int) c;
        byte dtb=(byte) d;
        int dti =(int) d; 
        System.out.println("Entered integer:"+i);
        System.out.println("Entered double:"+d);
        System.out.println("Entered character:"+c);
        System.out.println("Int to Byte:"+itb);
        System.out.println("Char to Int:"+cti);
        System.out.println("Double to Byte:"+dtb);
        System.out.println("Double to Int:"+dti);
        scan.close();
    }
}
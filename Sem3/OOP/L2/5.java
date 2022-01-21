import java.util.Scanner;
public class Fifth{
    public static void main(String args[]){
        Scanner scan= new Scanner(System.in);
        char ch='y';
        while (ch=='y'){
            System.out.println("Enter first number, operator, second number");
            float n1=scan.nextFloat();
            char c=scan.next().charAt(0);
            int asc= (int) c;
            float n2=scan.nextFloat();
            // System.out.println(n1);
            // System.out.println(asc);
            // System.out.println(n2);
            switch(asc){
                case 43:
                    float np=n1+n2;
                    System.out.println(np);
                    break;
                case 45:
                    float nmi=n1-n2;
                    System.out.println(nmi);
                    break;
                case 42:
                    float nm=n1*n2;
                    System.out.println(nm);
                    break;
                case 47:
                    float nd=n1/n2;
                    System.out.println(nd);
                    break;
                case 37:
                    float nda=n1%n2;
                    System.out.println(nda);
                    break;
                case 94:
                    double ndd= java.lang.Math.pow(n1,n2);
                    System.out.println(ndd);
                    break;}
            System.out.println("Do another(y/n)?");
            ch= scan.next().charAt(0);
        }
        scan.close(); 
    }
}
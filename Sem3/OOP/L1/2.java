import java.util.Scanner;
public class Second{
    public static void main(String args[]){
        int ar[]= new int[10];
        int pos=0, neg=0, zero=0;
        Scanner s=new Scanner(System.in);
        for(int i=0;i<ar.length;i++){
            System.out.println("Enter number at position "+i);
            ar[i] = s.nextInt();
            if (ar[i]>0){
                pos+=1;
            }
            else if(ar[i]<0){
                neg+=1;
            }
            else{
                zero+=1;
            }
        }
        System.out.println("Number of postive numbers:"+pos);
        System.out.println("Number of negative numbers:"+neg);
        System.out.println("Number of zero numbers:"+zero);
    }
}
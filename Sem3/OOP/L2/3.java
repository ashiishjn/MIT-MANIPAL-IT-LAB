import java.util.Scanner;
public class Third{
    public static void main(String args[]){
        Scanner scan=new Scanner(System.in);
        int n = scan.nextInt();
        int mul=n<<1;
        int div=n>>1;
        System.out.println("Number multiplied by 2: "+mul);
        System.out.println("Number divided by 2: "+div);
        scan.close();
    }
}
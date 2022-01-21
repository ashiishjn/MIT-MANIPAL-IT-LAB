import java.util.Scanner;
public class Fourth{
    public static void main(String args[]){
        //Sieve of Eratosthenes
        Scanner scan= new Scanner(System.in);
        System.out.print("Enter starting number: ");
        int m=scan.nextInt();
        System.out.print("Enter ending number: ");
        int n =scan.nextInt();
        boolean prime[] = new boolean[n+1]; 
        for(int i=0;i<n;i++) 
            prime[i] = true; 
        for(int p = 2; p*p <=n; p++){ 
            if(prime[p] == true){ 
                for(int i = p*p; i <= n; i += p) 
                    prime[i] = false; 
            } 
        }
        for(int i = m; i <= n; i++) 
        { 
            if(prime[i] == true) 
                System.out.print(i + " "); 
        } 

    }
}
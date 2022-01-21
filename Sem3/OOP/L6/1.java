import java.util.Scanner;
class Account{
    static int count;
    Scanner scan= new Scanner(System.in);
    String name;
    int number;
    String type;
    double balance;
    Account(){
        System.out.println("Enter the name of the customer:");
        name=scan.nextLine();
        System.out.print("The account number alloted is ");
        number=computeAccount();
        System.out.println(this.number);
        count++;
    }    
    int computeAccount(){
        this.number=1234567;
        for(int i=0;i<this.name.length();i++){
            this.number=this.number+(int)(this.name).charAt(i);
        }
        return number;
    }
    void deposit(int value){
        balance+=value;
        System.out.println(value+" Deposited");
    }
    void withdraw(int value){
        if(balance<value){
            System.out.println("Insufficient Funds!");
            return;
        }
        balance-=value;
    }
    void display(){
        System.out.println("The balance in your account is:"+balance);
    }
    
};

class Savings extends Account{
    Savings(){
        super();
        System.out.println("The account type selected is Savings");
        this.type="Savings";
        System.out.println("Enter the amount to deposit:");
        deposit(scan.nextInt());
        Interest();
    }
    void Interest(){
        balance+=(0.06*balance);
    }
};

class Current extends Account{
    Current(){
        super();
        System.out.println("The account type selected is Current. MAB is Rs.10000");
        this.type="Current";
        System.out.println("Enter the amount to deposit:");
        deposit(scan.nextInt());
        Service();
    }
    void Service(){
        if(this.balance<10000){
            balance*=0.9;
        }
    }
};

public class First{
    public static void main(String args[]){
        Savings s1=new Savings();
        s1.deposit(1000);
        s1.withdraw(200);
        s1.Interest();
        s1.display();
        Current c1=new Current();
        c1.deposit(10);
        c1.withdraw(9000);
        c1.Service();
        c1.display();
    }
}
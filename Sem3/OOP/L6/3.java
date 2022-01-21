import java.util.Scanner;
class Bank{
    int interest=10;
    Scanner scan= new Scanner(System.in);
    int getRateOfInterest(){
        return interest;
    }
}
class SBI extends Bank{
    SBI(){
        interest=8;
    }
    int getRateOfInterest(){
        return interest;
    }
}
class ICICI extends Bank{
    ICICI(){
        interest=7;
    }
    int getRateOfInterest(){
        return interest;
    }
}
class AXIS extends Bank{
    AXIS(){
        interest=9;
    }
    int getRateOfInterest(){
        return interest;
    }
}

public class Third{
    public static void main(String args[]){
        Bank b= new Bank();
        SBI s= new SBI();
        ICICI i= new ICICI();
        AXIS a= new AXIS();
        System.out.println(b.getRateOfInterest());
        b=s;
        System.out.println(b.getRateOfInterest());
        b=a;
        System.out.println(b.getRateOfInterest());
        b=i;
        System.out.println(b.getRateOfInterest());
    }
}
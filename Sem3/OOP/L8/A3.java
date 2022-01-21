import java.util.Scanner;
interface sports{
    Scanner scan=new Scanner(System.in);
    void getNumberOfGoals();
    void disp();
}

class Hockey implements sports{
    int goals;
    String[] a =new String[3];
    Hockey(){
        System.out.println("Enter 3 players:");
        a[0]=scan.next();
        a[1]=scan.next();
        a[2]=scan.next();
    }
    public void getNumberOfGoals(){
        System.out.println("Enter number of goals:");
        goals= scan.nextInt();
    }
    public void disp(){
        for(String i:a){
            System.out.println(i);
        }
    }
}
class Football implements sports{
    int goals;
    String[] a =new String[3];
    Football(){
        System.out.println("Enter 3 players:");
        a[0]=scan.next();
        a[1]=scan.next();
        a[2]=scan.next();
    }
    public void getNumberOfGoals(){
        System.out.println("Enter number of goals:");
        goals= scan.nextInt();
    }
    public void disp(){
        for(String i:a){
            System.out.println(i);
        }
    }
}

public class Sixth{
    public static void main(String args[]){
        sports s= new Hockey();
        s.getNumberOfGoals();
        s.disp();
        s=new Football();
        s.getNumberOfGoals();
        s.disp();
    }
}
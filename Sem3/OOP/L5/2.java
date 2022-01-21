import java.util.Scanner;
class Employee{
    String name;
    String city;
    int salary;
    double allowance;
    double rent;
    double total;
    void getdata(){
        Scanner scan= new Scanner(System.in);
        System.out.println("Enter the name:");
        this.name=scan.nextLine();
        System.out.println("Enter the city:");
        this.city=scan.nextLine();
        System.out.println("Enter the salary:");
        this.salary=scan.nextInt();
        System.out.println("Enter the allowance:");
        this.allowance=scan.nextDouble();
        System.out.println("Enter the rent:");
        this.rent=scan.nextDouble();
        scan.close();
    }
    void calculate(){
        this.total= salary+(salary*allowance/100.0)+(salary*rent/100.0);
    }

    double display(){
        return this.total;
    }
}

public class Second{
    public static void main(String args[]){
        Employee e1=new Employee();
        e1.getdata();
        e1.calculate();
        System.out.println(e1.display());
    }
} 
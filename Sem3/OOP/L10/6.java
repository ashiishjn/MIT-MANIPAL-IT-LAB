import java.io.*;
class Employee implements Serializable{
    private static final long serialVersionUID= 1L;
    double salary, allowance, deductions;
    int empno;
    Employee(int e, double s){
        empno=e;
        salary=s;
    }
    void calculate(){
        deductions=0.2*salary;
        allowance=10000;
        salary=salary+allowance+deductions;
    }
    void display(){
        System.out.println(empno+" "+salary+" ");
    }
}

public class Sixth{
    public static void main(String args[])throws Exception{
        Employee e= new Employee(1234, 112213.40);
        ObjectOutputStream oos= new ObjectOutputStream(new FileOutputStream(new File("6.txt")));
        oos.writeObject(e);
        oos.close();
        ObjectInputStream ois= new ObjectInputStream(new FileInputStream(new File("6.txt")));
        Employee e1=(Employee)ois.readObject();
        e1.calculate();
        e1.display();
    }
}
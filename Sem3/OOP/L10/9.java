import java.io.*;
class Student{
    String name;
    int roll;
    int marks[]= new int[3];
    double percent;
    char grade;
    Student(String s[]){
        name=s[0];
        roll=Integer.parseInt(s[1]);
        marks[0]=Integer.parseInt(s[2]);
        marks[1]=Integer.parseInt(s[3]);
        marks[2]=Integer.parseInt(s[4]);
    }
    void calulate(){
        percent=(marks[0]+marks[1]+marks[2])/3;
        grade=percent>80?'A':'F';
    }
    void display(){
        System.out.println(name+" "+roll+" "+percent+" "+grade+" ");
    }
}

public class Ninth{
    public static void main(String args[]){
        try{
            Student s= new Student(args);
            s.calulate();
            s.display();
        }
        catch(NumberFormatException e){
            System.out.println("Invalid Number Provided");
        }
    }
}
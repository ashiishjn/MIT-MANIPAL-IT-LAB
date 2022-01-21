import java.util.Scanner;

class Box{
    double length, breadth, width;
    Box(double l,double b, double w){
        length=l;
        breadth=b;
        width=w;
    }    
    double volume(){
        double vol=this.length*this.breadth*this.width;
        return vol;
    }
}

public class First{
    public static void main(String args[]){
        Scanner scan=new Scanner(System.in);
        System.out.println("Enter the length:");
        double l=scan.nextDouble();
        System.out.println("Enter the breadth:");
        double b=scan.nextDouble();
        System.out.println("Enter the width:");
        double w=scan.nextDouble();
        Box b1=new Box(l,b,w);
        System.out.println(b1.volume());
        scan.close();
    }
} 
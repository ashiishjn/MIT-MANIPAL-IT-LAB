abstract class Calculator{
    double ar;
    abstract void area();
    void printer(){
        System.out.println(ar);
    }
}

class Rectangle extends Calculator{
    double length;
    double width;
    Rectangle(double l,double w){
        length=l;
        width=w;
    }
    void area(){
        ar = length*width;
    }
}

class Triangle extends Calculator{
    double base, height;
    Triangle(double b, double h){
        base=b;
        height=h;
    }
    void area(){
        ar= 0.5*base*height;
    }
}

public class Fourth{
    public static void main(String args[]){
        Rectangle r= new Rectangle(100,40);
        r.area();
        r.printer();
        Triangle c=new Triangle (100,50);
        c.area();    
        c.printer();
    }
}
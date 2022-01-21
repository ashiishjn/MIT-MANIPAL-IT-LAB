interface Calculator{
    double area();
}

class Rectangle implements Calculator{
    double length, breadth;
    Rectangle(double l, double b){
        length=l;
        breadth=b;
    }
    public double area(){
        return length*breadth;
    }
}

class Traingle implements Calculator{
    double base,height;
    Traingle(double r,double c){
        base=r;
        height=c;
    }
    public double area(){
        return 3.14*base*height;
    }
}

public class Fifth{
    public static void main(String args[]){
        Calculator r= new Rectangle(40,100);
        System.out.println(r.area());
        r= new Traingle(100,40);
        System.out.println(r.area());
    }
}
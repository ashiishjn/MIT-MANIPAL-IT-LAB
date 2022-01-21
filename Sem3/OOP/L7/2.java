import java.util.Scanner;
class Counter{
    static int count=0;
    Counter(){
        count+=1;
    }
    int add(int i1, int i2){
        return i1+i2;
    }
}

public class Second{
    public static void main(String args[]){
        Counter c1, c2, c3;
        c1=new Counter();
        c2=new Counter();
        c3=new Counter();
        System.out.println(c3.add(3,4));
        System.out.println("No. of objects created:"+Counter.count);
    }
}
import java.util.Scanner;
class Number{
    double d1;
    Number(double d){
        this.d1=d;
    }
    boolean isZero(){
        boolean b=true;
        if(d1== 0.0)
            return b;
        return !b;
    }
    boolean isPositive(){
        boolean b=true;
        if(d1>0)
            return b;
        return !b;
    }
    boolean isNegative(){
        return d1<0;
    }
    boolean isOdd(){
        return d1%2.0!=0;
    }
    boolean isEven(){
        return d1%2.0==0;
    }
    boolean isPrime(){
        boolean b=true;
        if(isPositive()&& d1%1==0){
            for(int i=2;i<d1;i++){
                if(d1%i==0){
                    b=false;
                    break;
                }
            }
        }
        else{
            b=false;
        }
        return b;
    }
    boolean isArmstrong(){
        boolean b=true;
        int temp=0, rem, numb=(int)d1;
        if(d1%1==0){
            
            while(numb>0){
                rem=numb%10;
                temp+=rem*rem*rem;
                numb=numb/10;
            }
            if(temp!=(int)d1)
                b=false;
        }
        else{
            b=false;
        }
        return b;
    }
}

public class Fifth{
    public static void main(String args[]){
        Number n1 =new Number(-153.0);
        System.out.println(n1.isEven());
        System.out.println(n1.isOdd());
        System.out.println(n1.isNegative());
        System.out.println(n1.isPositive());
        System.out.println(n1.isZero());
        System.out.println(n1.isPrime());
        System.out.println(n1.isArmstrong());
    }
}
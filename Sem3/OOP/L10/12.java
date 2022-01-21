import java.math.*;
class NegativeNumber extends Exception{
    public String toString(){
        return "Can't calculate for Negative Numbers";
    }
}

public class Twelfth{
    public static void main(String args[]){
        try{
            int n= Integer.parseInt(args[0]);
            if(n<0)
                throw new NegativeNumber();
            System.out.println(Math.sqrt(n));
        }
        catch(NegativeNumber e){
            System.out.println(e);
        }
    }
}
class EvilNumber extends Exception{
    public String toString(){
        return "Evil Number Entered";
    }
}

public class Tenth{
    public static void main(String args[]){
        try{
            int n= Integer.parseInt(args[0]);
            if(n==666)
                throw new EvilNumber();
            System.out.println(n);
        }
        catch(EvilNumber e){
            System.out.println(e);
        }
    }
}
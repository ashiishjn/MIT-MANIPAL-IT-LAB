import java.io.*;
class Seventh{
    public static void main(String args[]){
        try{
            int a= Integer.parseInt(args[0]);
            System.out.println(a);
        }
        catch(NumberFormatException e){
            System.out.println("Not a number");
        }
        finally{
            System.out.println("Exiting");
        }
    }
}
import java.io.*;
class Eighth{
    public static void main(String args[]){
        try{
            String s=args[0];
            System.out.println(s);
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Array Empty!");
        }
        finally{
            System.out.println("Exiting");
        }
    }
}
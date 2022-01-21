import java.util.Scanner;
import java.io.*;

public class Second{
    public static void main(String args[]) throws IOException, EOFException{
        Scanner scan= new Scanner(System.in);
        RandomAccessFile f1= new RandomAccessFile("2.txt","rw");
        f1.writeDouble(22.42);
        f1.writeByte(23);
        f1.seek(0);
        System.out.println(f1.readDouble());
        System.out.println(f1.readByte());
        long g= f1.getFilePointer();
        System.out.println("Enter an integer to append:");
        f1.writeInt(scan.nextInt());
        f1.seek(g);
        System.out.println(f1.readInt());
        f1.close();
        scan.close();
    }
}
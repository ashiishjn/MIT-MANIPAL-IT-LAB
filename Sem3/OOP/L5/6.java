import java.util.Scanner;
import java.io.FileWriter; 
import java.io.IOException;

class Book{
    public String title, author, edition;
    Book(String s1, String s2, String s3) {
        this.title = s1;
        this.author = s2;
        this.edition = s3;
    }
    void display() {
        System.out.println(this.title);
        System.out.println(this.author);
        System.out.println(this.edition);
    }
}

public class Sixth { 
    public static void main(String args[]) {
        Book[] arr = new Book[6];
        arr[0] = new Book("A", "Harry", "12");
        arr[1] = new Book("B", "Mary", "13");
        arr[2] = new Book("A", "Harry", "12");
        arr[3] = new Book("B", "Mary", "13");
        arr[4] = new Book("A", "Harry", "12");
        arr[5] = new Book("B", "Mary", "13");
        for(int i=0;i<n;i++){
            writeUsingFileWriter(arr[0].author);
            writeUsingFileWriter(arr[0].title);
            writeUsingFileWriter(arr[0].edition);
        }
    }
}
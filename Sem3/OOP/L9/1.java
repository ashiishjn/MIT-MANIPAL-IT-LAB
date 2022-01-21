import java.util.Scanner;
public class First{
    static void counter(String s){
        int words=0;
        int lines=0;
        int chars=s.length();
        int vowels=0;
        for(int i=0; i<chars;i++){
            char c=s.charAt(i);
            switch(c){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowels+=1;
                    break;
                case '\n':
                    lines+=1;
                case ' ':
                    words+=1;
                    break;
            }
        }
        System.out.println("Number of words:"+words);
        System.out.println("Number of lines:"+lines);
        System.out.println("Number of vowels:"+vowels);
        System.out.println("Number of characters:"+chars);
    }
    public static void main(String args[]){
        Scanner scan= new Scanner(System.in);
        String s= new String();
        System.out.println("Enter the String(Press Enter twice to escape):");
        String str= new String();
        while(true){
            str=scan.nextLine();
            if(str.length()==0)
                break;
            s=s.concat("\n");
            s=s.concat(str);
        }
        counter(s);
        scan.close();
    }
}
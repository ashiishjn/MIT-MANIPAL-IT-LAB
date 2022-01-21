import java.io.*;
class Third{
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


    public static void main(String args[]) throws Exception, EOFException{
	Scanner sc= new Scanner(System.in);
        File f1= new File("3.txt");
        if(!f1.exists()){
            System.out.println("File does not exist in the directory");
            return;
        }
        InputStream is= new FileInputStream(f1);
        int ch;
        StringBuffer s= new StringBuffer();
        while((ch=is.read())!=-1){
            System.out.print((char)ch);
            s.append(Character.toString((char)ch));
        }
        counter(s.toString());
        is.close();
    }
    
}
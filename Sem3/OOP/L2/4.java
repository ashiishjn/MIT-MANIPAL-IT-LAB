public class Fourth{
    public static void main(String args[]){
        int n=Integer.parseInt((args[0]));
        
        if (n==0){
            int x=10;
            double y=x;
            System.out.println("When x=10 and y=x then y="+y);
        }
        else if (n==1){
            double x=10.5;
            int y=x;
            System.out.println("When x=10.5 and y=x"+y);
        }
        else if (n==2){     
            double x=10.5;
            int y= (int)x;
            System.out.println("When x=10.5 and y=(int)x then y="+y);}

    }
}
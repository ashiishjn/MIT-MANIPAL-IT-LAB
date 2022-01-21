
class Mythread4 extends Thread
{
    int j;
    Mythread4(int j)
    {
        this.j=j;
    }
    public void run()
    {
        for(int i=1;i<=10;i++)
            System.out.println(j+"*"+i+"= "+(j*i));
    }
}
public class L11A2 
{
    public static void main(String[] args) 
    {
        Mythread4 t1=new Mythread4(5);
        Mythread4 t2=new Mythread4(7);
        Mythread4 t3=new Mythread4(13);
        t1.start();
        t2.start();
        t3.start();
    }
}

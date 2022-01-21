
class Mythread2 extends Thread
{
    public void run()
    {
        for(int i=0;i<4;i++)
            System.out.println(Thread.currentThread()+" "+i);
    }
}
public class L11Q3 
{
    public static void main(String[] args) 
    {
        Mythread2 t1=new Mythread2();
        Mythread2 t2=new Mythread2();
        t1.start();
        System.out.println(t1.isAlive());
        try
        {
        t1.join();
        }
        catch(InterruptedException e)
        {
            System.out.println("InterruptedException");
        }
        System.out.println(t2.isAlive());
        t2.start();
        System.out.println(t2.isAlive());
    }
}

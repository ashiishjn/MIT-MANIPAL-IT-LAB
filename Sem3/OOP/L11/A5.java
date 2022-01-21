
class Mythread7 extends Thread
{
    public void run()
    {
        System.out.println("Start");
        try
        {
        Thread.sleep(1000);
        }
        catch(InterruptedException e)
        {
            System.out.println("InterruptedException");
        }
        System.out.println("End");
    }
}
public class L11A5 
{   public static void main(String[] args) 
    {
        Mythread7 t1=new Mythread7();
        t1.start();
    }
    
}


class Mythread6 extends Thread
{
    public void run()
    {
        
        for(int i=0;i<5;i++)
        {
            System.out.println(Thread.currentThread()+" "+i);
        }
    }
}
public class L11A4 
{
    public static void main(String[] args) 
    {
        Mythread6 t1= new Mythread6();
        Mythread6 t2= new Mythread6();
        Mythread6 t3= new Mythread6();
        t1.setPriority(10);
        t2.setPriority(6);
        t3.setPriority(1);
        t1.start();
        t2.start();
        t3.start();
        System.out.println("Priority of T1 is"+t1.getPriority());
        System.out.println("Priority of T2 is"+t2.getPriority());
        System.out.println("Priority of T3 is"+t3.getPriority());
    }
}

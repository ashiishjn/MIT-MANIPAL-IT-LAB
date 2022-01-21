
package lab.pkg3;
class Mythread1 extends Thread
{
    public void run()
    {
        for(int i=0;i<10;i++)
            System.out.println(Thread.currentThread()+" "+i);
    }
}
public class L11Q2 
{
    public static void main(String[] args) 
    {
        Mythread1 t1=new Mythread1();
        Mythread1 t2=new Mythread1();
        t1.start();
        t2.start();
    }
}

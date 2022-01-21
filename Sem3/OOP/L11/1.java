
class runnableimplement implements Runnable
{
    public void run()
    {
        for(int i=0;i<5;i++)
            System.out.println("Runnable "+i);
    }
}
class Mythread extends Thread
{
    public void run()
        {
            System.out.println("Start");
            for(int i=0;i<5;i++)
            {
                System.out.println(i);}
            try
            {
                Thread.sleep(1000);
     
            }
            catch(Exception e)
            {
                System.out.println(e);
            }
            
            System.out.println("End");
        }
}
public class L11Q1 
{   
    public static void main(String[] args) 
    {
        Mythread t1=new Mythread();
        Mythread t3=new Mythread();
        runnableimplement obj = new runnableimplement();
       Mythread t2=new Mythread();
        Mythread t4=new Mythread();
        t3.start();
        
    }    
}

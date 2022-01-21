
class Mythread5 extends Thread
{
    public void run()
    {
        System.out.println(Thread.currentThread());
    }
}
public class L11A3 
{
    public static void main(String[] args) 
    {
        Mythread5 t1 = new Mythread5();
        System.out.println(t1.getName());
        t1.setName("New");
        System.out.println(t1.getName());
    }
}

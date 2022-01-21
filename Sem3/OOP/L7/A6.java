class Example6{
    static int i;
    static String s;
    //Static method
    static void display()
    {
        //Its a Static method
        Example6 obj1=new
        Example6();
        System.out.println("i:"+obj1.i);
        System.out.println("i:"+obj1.i);
    }
    void funcn(){
        //Static method called in non-static method
        display();
    }
    public static void main(String args[]) //Its a Static Method
    {
        //Static method called in another static method
        display();
    }
}
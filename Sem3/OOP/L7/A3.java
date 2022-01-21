class Example3 {
    static int num;
    static String mystr;
    static{
        num = 97;
        mystr = "Static keyword in Java";
    }

    public static void main(String args[]){
        System.out.println("Value of num="+num);
        System.out.println("Value of mystr="+mystr);
    }
}
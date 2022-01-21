public class First{
    public static void main(String args[]){
        int length=Integer.parseInt(args[0]), breadth=Integer.parseInt(args[1]);
        int area=length*breadth;
        int peri=2*(length+breadth);
        System.out.println("Area of the rectangle ="+area);
        System.out.println("Perimeter of the rectangle ="+peri);
    }
}
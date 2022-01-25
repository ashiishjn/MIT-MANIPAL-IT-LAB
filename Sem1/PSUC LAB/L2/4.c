#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float a,b,c;
    int x;
    float r1,r2,y,d;
    printf("Enter the coefficient of a,b and c\n");
    scanf("%f%f%f",&a,&b,&c);
    d=b*b-4*a*c;
    if(d>0)
        x=1;
    else if(d==0)
        x=2;
    else
        x=3;
    switch(x)
      {
          case 1:printf("Roots are real and distinct\n");
                 y=pow(d,0.5);
                 r1=(-b+y)/(2*a);
                 r2=(-b-y)/(2*a);
                 printf("The roots are %f and %f",r1,r2);
                 break;
          case 2:printf("Roots are real and equal\n");
                 r1=-b/(2*a);
                 printf("Root is %f",r1);
                 break;
          case 3:printf("Roots are imaginary\n");
                 d=-d;
                 y=pow(d,0.5)/(2*a);
                 r1=-b/(2*a);
                 printf("First root is %f +i%f \n",r1,y);
                 printf("Second root is %f -i%f",r1,y);
      }
    return 0;
}






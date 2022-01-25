#include <stdio.h>
#include <stdlib.h>

int main()
{
    float f,c;
    printf("Enter the temperature in Fahrenheit\n");
    scanf("%f",&f);
    c=(5.0/9)*(f-32);
    printf("\nThe temperature in centigrade is %f",c);
    return 0;
}

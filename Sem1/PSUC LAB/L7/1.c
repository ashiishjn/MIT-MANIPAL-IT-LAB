#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w=0,i;
    char a[1000];
    printf("Enter a sentence\n");
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if(i==0)
            continue;
        if(a[i]==' '&&a[i+1]!=' '&&a[i+1]!='\0')
            w++;

    }
    printf("The number of words are %d",++w);
    return 0;
}

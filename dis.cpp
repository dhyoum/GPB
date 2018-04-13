#include <stdio.h>

void dis_hexa(char* data, int len)
{
    for(int i=0; i<len; i++)
    {   
        printf("%#02x ", (unsigned int)(data[i] & 0xff));
        if (i && i%9==0) printf("\n");
    }

    printf("\n");
}

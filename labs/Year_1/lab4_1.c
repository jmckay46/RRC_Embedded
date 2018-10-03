#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char val;
    int count = 0;
    char str[20] = "hello there!";
    char *p_str2;
    char str2[20] = "zzzzzzzzzzzzzzzzz";
    char *p_str = str;
    p_str2 = str2;
            while(*p_str != 0x00)
            {
                val = *p_str++;
                count++;
                printf("value: %i\n", val);
            }
    return 0;
}
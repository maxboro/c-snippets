// Filter blanks from input and print again
#include <stdio.h>

int main()
{
    int prev_blank = 0;
    char c;
    
    while ((c = getchar()) != EOF){
        if (c == ' '){
           if (!prev_blank){
               putchar(c);
           }
           prev_blank = 1;
        } else {
            putchar(c);
            prev_blank = 0;
        }
    }
    return 0;
}

#include <stdio.h>
void main()
{
    char p[ 7 ] = "Mizzou";
    
    p[ 3 ] = 80; // 80 := ASCII for P
    
    // p[ 3 ] = (int)'P'; // Secondary Solution
    
    printf("%s",p);
}


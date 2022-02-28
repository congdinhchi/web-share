#include <stdio.h>

int main()
{
    printf("Hello World");
    unsigned long long x =2240258 ;
    unsigned long long n = 27887099;
    unsigned long long du = (x*x*26462723 ) / n;
    printf("%lld", x*x*26462723  - n*du);
    return 0;
}
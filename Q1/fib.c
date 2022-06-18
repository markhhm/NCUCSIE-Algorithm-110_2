#include <stdio.h>
#include <time.h>

int fib(unsigned long int n)
{
    if (n <= 1)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    clock_t start, end;
    float cpu_time_used;

    printf("Enter a number: ");
    scanf("%d", &n);

    start = clock();
    printf("fib(%lu) = %lu\n", n, fib(n));
    end = clock();

    cpu_time_used = difftime(end, start);
    printf("CPU time used: %f\n", cpu_time_used);

    return 0;
}
#include <stdio.h>
#include <time.h>

int fib_dp(int n)
{
    unsigned long int f[n + 1];
    int i;

    f[0] = 0;
    f[1] = 1;
    for (i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];

    return f[n];
}

int main(void)
{
    long long int n;
    clock_t start, end;
    float cpu_time_used;

    printf("Enter a number: ");
    scanf("%d", &n);

    start = clock();
    printf("fib(%lu) = %lu\n", n, fib_dp(n));
    end = clock();

    cpu_time_used = difftime(end, start);
    printf("CPU time used: %f\n", cpu_time_used);

    return 0;
}

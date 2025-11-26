#include <stdio.h>

#define NMAX 100

int max(int n, int *v)
{
    int m = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > m) {
            m = v[i];
        }
    }

    return m;
}

void count_sort(int *v, int n, int exp)
{
    int out[NMAX];
    int cnt[10] = {0};

    for (int i = 0; i < n; i++) {
        cnt[(v[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        cnt[i] += cnt[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        out[cnt[(v[i] / exp) % 10] - 1] = v[i];
        cnt[(v[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        v[i] = out[i];
    }
}

void radix_sort(int n, int *v)
{
    int max_el = max(n, v);

    for (int exp = 1; max_el / exp > 0; exp *= 10) {
        count_sort(v, n, exp);
    }
}

int main(void)
{
    int v[4] = {4, 3, 1, 2};

    radix_sort(4, v);

    for (int i = 0; i < 4; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}

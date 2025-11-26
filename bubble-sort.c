#include <stdio.h>

void bubble_sort(int n, int *v)
{
    int swapped;
    for (int i = 0; i < n - 1; i++) {

        swapped = 0;

        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swapped = 1;

                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main(void)
{
    int v[4] = {4, 1, 3, 2};

    bubble_sort(4, v);

    for (int i = 0; i < 4; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}

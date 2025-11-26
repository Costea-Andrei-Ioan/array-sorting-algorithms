#include <stdio.h>

#define NMAX 100

void merge(int *v, int l, int mid, int r)
{
    int nl = mid - l + 1;
    int nr = r - mid;

    int l_vect[NMAX], r_vect[NMAX];

    for (int i = 0; i < nl; i++) {
        l_vect[i] = v[l + i];
    }
    for (int i = 0; i < nr; i++) {
        r_vect[i] = v[mid + 1 + i];
    }

    int i = 0, j = 0;
    int k = l;

    while (i < nl && j < nr) {
        if (l_vect[i] <= r_vect[j]) {
            v[k] = l_vect[i];
            i++;
        } else {
            v[k] = r_vect[j];
            j++;
        }
        k++;
    }

    while (i < nl) {
        v[k] = l_vect[i];
        i++;
        k++;
    }

    while (j < nr) {
        v[k] = r_vect[j];
        j++;
        k++;
    }
}

void merge_sort(int *v, int l, int r)
{
    if (l >= r) {
        return;
    }

    int mid = l + (r - l) / 2;

    merge_sort(v, l, mid);
    merge_sort(v, mid + 1, r);
    merge(v, l, mid, r);
}

int main(void)
{
    int v[4] = {4, 2, 1, 3};

    merge_sort(v, 0, 4 - 1);

    for (int i = 0; i < 4; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}

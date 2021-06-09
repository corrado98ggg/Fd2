#include <stdio.h>
#include <stdlib.h>

void SubsetEqualRec(int v[], int si[], int k, int n, int s, int cnt) {
    
    int* tmp = calloc(n, sizeof(int));

    if (k == n - 1) {
        for (int i = 0; i < n; i++) {
            if (si[i] == 1) {

                cnt = cnt + v[i];
                tmp[i] = v[i];

                if(cnt == s){
                    printf("{");

                    for (int c = 0; c < n; c++) {
                        if (tmp[c] != 0) {
                            printf("%d ", tmp[c]);
                        }
                    }
                    printf("}, ");
                }
            }
        }
    }
    else
        for (int i = 0; i <= 1; i++) {
            si[k + 1] = i;
            SubsetEqualRec(v, si, k + 1, n, s, 0);
        }
}

void SubsetEqual(int n, int s) {

    if (n <= 0 || s <= 0) {
        return;
    }

    int* v = malloc(sizeof(int) * n);
    int* sol = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
        printf("%d ", v[i]);
    }

    SubsetEqualRec(v, sol, -1, n, s, 0);

    return;
}

/*
int main() {
    
    //FILE* file = fopen("insiemi.txt", "w");
    int v[] = { 1,2,3,4,5 };
    int si[] = { 0, 0, 0, 0, 0};
    //generaSosttoInsiemi va chiamata passandole il file, i vettorI
    //v e si, -1 e la dimensione n del vettore
    //generaSosttoInsiemi(v, si, -1, 5, 7, 0);

    SubsetEqual(5, 7);

 
    //fclose(file);
    return 0;
}
*/
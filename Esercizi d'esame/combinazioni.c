#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void combina(char* data, int n, int k, char* out_str, int index){

    for (int i = 0; i <= n - k; i++){
        out_str[index] = data[i];
        if (k > 1) {
            combina(&data[i + 1], n - 1 - i, k - 1, out_str, index + 1);
        }
        else
        {
            out_str[index + 1] = 0;
            
            printf("{");
            for (int i = 0; i < strlen(out_str); i++) {
                printf("%c", out_str[i]);
            }
            printf("}");
        }
    }
}

int main() {
    //possibili combinazioni di n elementi su k posizioni:

    //dato un array, l'algoritmo ci permette di stampare tutte
    //le possibili combinazioni di n caratteri di classe k

        char car[] = { 'A', 'B', 'C', 'D', 'E' };
        char* output = malloc(sizeof(char) * 6);

        combina(car, 5, 3, output, 0);
        return 0;
}
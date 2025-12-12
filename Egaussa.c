#include <stdio.h>

int main() {
    int n, i, j, k;

    printf("Podaj liczbe niewiadomych: ");
    scanf("%d", &n);

    float macierz[n][n+1];
    float wynik[n];

    printf("Podaj elementy macierzy rozszerzonej (wiersz po wierszu):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &macierz[i][j]);
        }
    }

    for (i = 0; i < n - 1; i++) {
        for (k = i + 1; k < n; k++) {
            float wspolczynnik = macierz[k][i] / macierz[i][i];
            for (j = 0; j <= n; j++) {
                macierz[k][j] = macierz[k][j] - wspolczynnik * macierz[i][j];
            }
        }
    }

    for (i = n - 1; i >= 0; i--) {
        float suma = 0;
        for (j = i + 1; j < n; j++) {
            suma = suma + macierz[i][j] * wynik[j];
        }
        wynik[i] = (macierz[i][n] - suma) / macierz[i][i];
    }

    printf("Wynik:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %f\n", i + 1, wynik[i]);
    }

    return 0;
}
#include <stdio.h>
#include <time.h>
#include <unistd.h>

void delay(int number_of_milisseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + number_of_milisseconds); 
} 

void imprimir_dois_sudokus(int sudoku[9][9], int sudoku_dois[9][9]) {
    for(int i = 0; i < 9; i++) {
        if(i % 3 == 0) printf("\n");
        for(int j = 0; j < 9; j++) {
            if(j % 3 == 0) printf(" ");
            if(sudoku[i][j] != -1) printf("%d ", sudoku[i][j]);
            else printf("_ ");
            // sleep(1);
        }
        printf("   ");
        for(int j = 0; j < 9; j++) {
            if(j % 3 == 0) printf(" ");
            if(sudoku_dois[i][j] != -1) printf("%d ", sudoku_dois[i][j]);
            else printf("_ ");
        }
        printf("\n");
    }
}

void imprimir_sudoku(int sudoku[9][9]) {
    for(int i = 0; i < 9; i++) {
        if(i % 3 == 0) printf("\n");
        for(int j = 0; j < 9; j++) {
            if(j % 3 == 0) printf(" ");
            // if(sudoku[i][j] != -1) printf("(%d, %d) ", i, j);
            if(sudoku[i][j] != -1) printf("%d ", sudoku[i][j]);
            else printf("_ ");
            // else printf("(%d, %d) ", i, j);
            // printf("%d,%d ", i, j);
        }
        printf("\n");
    }
}

void imprimir_regioes(int sudoku[9][9]) {
    for(int i = 0; i < 9; i+=3) {
        for(int j = 0; j < 9; j += 3) {
            for(int x = 0; x < 3; x++) {
                for(int y = 0; y < 3; y++) {
                    if(sudoku[i+x][j+y] != -1)
                        printf("%d ", sudoku[i+x][j+y]);
                    else
                        printf("_ ");
                } 
                printf("\n");
            }
            printf("\n");
        }
    }
}

int conferir_linha(int sudoku[9][9], int linha, int coluna) {
    for(int i = linha + 1; i < 9; i++) {
        if(sudoku[i][coluna] == sudoku[linha][coluna]) {
            return 1;
        }
    }
}

int conferir_coluna(int sudoku[9][9], int linha, int coluna) {
    for(int i = coluna + 1; i < 9; i++) {
        if(sudoku[linha][i] == sudoku[linha][coluna]) {
            return 1;
        }
    }
}

int conferir_regiao(int sudoku[9][9], int linha, int coluna) {
    // for(int i = 0; i < 9; i+=3) {
    //     for(int j = 0; j < 9; j += 3) {
    //         for(int x = 0; x < 3; x++) {
    //             for(int y = 0; y < 3; y++) {
    //                 if(sudoku[i+x][j+y] != -1) {
    //                     if(sudoku[i+x][j+y] == sudoku[linha][coluna] && linha != (i + x) && coluna != (j + y)) {
    //                         return 1;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
}

int conferir_sudoku(int sudoku[9][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(sudoku[i][j] != -1) {
                if(conferir_linha(sudoku, i, j) != 1) {
                    if(conferir_coluna(sudoku, i, j) != 1) {
                        if(conferir_regiao(sudoku, i, j) != 1) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            }
        }
    }

}

void main() {
    int quadro_inicio[9][9] = {
        {5, 3, -1, -1, 7, -1, -1, -1, -1},
        {6, -1, -1, 1, 9, 5, -1, -1, -1},
        {-1, 9, 8, -1, -1, -1, -1, 6, -1},
        {8, -1, -1, -1, 6, -1, -1, -1, 3},
        {4, -1, -1, 8, -1, 3, -1, -1, 1},
        {7, -1, -1, -1, 2, -1, -1, -1, 6},
        {-1, 6, -1, -1, -1, -1, 2, 8, -1},
        {-1, -1, -1, 4, 1, 9, -1, -1, 5},
        {-1, -1, -1, -1, 8, -1, -1, 7, 9},
    };
    int quadro[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9},
    };
    int aux[9][9];

    // for(int i = 0; i < 9; i++) {
    //     for(int j = 0; j < 9; j++) {
    //         quadro[i][j] = j;
    //     }
    // }

    printf("\n");
    // imprimir_sudoku(quadro);
    // for(int i = 0; i < 81 * 2 + 12; i++) {
    //     printf("\r");
    // }
    imprimir_sudoku(quadro_inicio);
    // imprimir_dois_sudokus(quadro_inicio, quadro);
    printf("\n");
    // printf("1 para erro, 0 para nao erro: %d \n", conferir_sudoku(quadro_inicio));
    // imprimir_regioes(quadro_inicio);
    printf("%d\n", (7 / 3));
    // for(int i = 0; i < 150; i++) printf("\b");
}
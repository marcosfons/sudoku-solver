#include <stdio.h>

typedef enum {
  false = 0,
  true = 1
} bool;

typedef struct quadrado {
  int value;
  int possibilidades[9];
} Quadrado;

void imprimirTabuleiro(int tabuleiro[9][9]) {
  for(int i = 0; i < 9; i++) {
    if(i != 0 && i % 3 == 0) printf("\n");
    for(int j = 0; j < 9; j++) {
      if(j % 3 == 0 && j != 0) printf(" ");
      if(tabuleiro[i][j] != 0) printf("%d ", tabuleiro[i][j]);
      else printf("_ ");
    }
    printf("\n");
  }
}

int maiorIndex(int vetor[9]) {
  int maior = 0;
  for(int i = 1; i < 9; i++) if(vetor[i] > vetor[maior]) maior = i;
  return maior;
}

bool erroLinha(int tabuleiro[9][9], int linha, int numero) {
  // true caso tenha erro
  // false nao tem erro
  for(int i = 0; i < 9; i++) {
    if(tabuleiro[linha][i] == numero) return true;
  }
  return false;
}

bool erroColuna(int tabuleiro[9][9], int coluna, int numero) {
  for(int i = 0; i < 9; i++) {
    if(tabuleiro[i][coluna] == numero) return true;
  }
  return false;
}

void imprimirRegiao(int tabuleiro[9][9], int lin, int col) {
  for(int i = lin / 3 * 3; i < lin / 3 * 3 + 3; i++) {
    for(int j = col / 3 * 3; i < col / 3 * 3 + 3; i++) {
      if(tabuleiro[i][j] == 0) printf("_ ");
      else printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
  }
}

bool erroRegiao(int tabuleiro[9][9], int lin, int col, int numero) {
  // printf("%d %d\n", lin / 3 * 3, col / 3 * 3);
  int linRegiao = lin / 3 * 3;
  int colRegiao = col / 3 * 3;
  for(int i = linRegiao; i < linRegiao + 3; i++) {
    for(int j = colRegiao; j < colRegiao + 3; j++) {
      if(tabuleiro[i][j] == numero) {
        return true;
      }
    }
  }
  return false;
}

bool temErro(int tabuleiro[9][9], int lin, int col, int numero) {
  if(erroLinha(tabuleiro, lin, numero)) return true;
  if(erroColuna(tabuleiro, col, numero)) return true;
  if(erroRegiao(tabuleiro, lin, col, numero)) return true;
  return false;
}

void solverSudoku(int tabuleiro[9][9]) {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      if(tabuleiro[i][j] == 0) {
        for(int x = 9; x > 1; x--) {
          if(temErro(tabuleiro, i, j, x) == false) {
            tabuleiro[i][j] = x;
            break;
          }
        }
      }
    }
  }

}


void pular() {
  printf("\n");
}

void pularlinha2() {
  printf("\n\n");
}

void main() {
  int tabuleiro[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9},
  };

  int tabuleiro2[9][9][9];

  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      for(int x = 0; x < 9; x++) {
          tabuleiro2[i][j][x] = 0;
      }
      if(tabuleiro[i][j] != 0) {
        tabuleiro2[i][j][ tabuleiro[i][j] - 1 ] = tabuleiro[i][j];
      }
    }
  }

  // for(int i = 0; i < 9; i++) {
  //   for(int j = 0; j < 9; j++) {
  //     printf("%d,%d  ", i,j);
  //   }
  //   printf("\n");
  // }
  imprimirTabuleiro(tabuleiro);
  pularlinha2();
  solverSudoku(tabuleiro);
  imprimirTabuleiro(tabuleiro);
  solverSudoku(tabuleiro);
  pularlinha2();
  // temErro(tabuleiro, 7, 7, 3) ? printf("tem erro\n") : printf("nao tem erro\n");
  imprimirTabuleiro(tabuleiro);
  printf("\n");

}

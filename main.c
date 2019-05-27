#include <stdio.h>
#include <windows.h>
#include <time.h>

typedef enum {
  false = 0,
  true = 1
} bool;

typedef struct quadrado {
  int value;
  int possibilidades[9];
} Quadrado;

void swap(int valores[], int i, int j) {
  int aux = valores[i];
  valores[i] = valores[j];
  valores[j] = aux;
}

void maisVezes(int tabuleiro[9][9], int vetor[9]) {
  int aux[9];
  int posMaior;
  for(int i = 0; i < 9; i++) {
    aux[i] = 0;
    vetor[i] = i+1;
  }
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      if(tabuleiro[i][j] != 0) {
        aux[tabuleiro[i][j] - 1] += 1;
      }
    }
  }

  for(int i = 0; i < 9; i++) {
    posMaior = i;
    for(int j = i+1; j < 9; j++) {
      if(aux[j] > aux[posMaior]) {
        posMaior = j;
      }
    }
    swap(vetor, i, posMaior);
    swap(aux, i, posMaior);
  }

}

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
    for(int j = col / 3 * 3; j < col / 3 * 3 + 3; j++) {
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

bool temErroOtimizado(int tabuleiro[9][9], int lin, int col, int numero) {
  for(int i = 0; i < 9; i++) {
    if(tabuleiro[i][col] == numero) return true;
    if(tabuleiro[lin][i] == numero) return true;
  }
  if(erroRegiao(tabuleiro, lin, col, numero)) return true;
  return false;
}

bool completado(int tabuleiro[9][9]) {
  // Retorna true caso o tabuleiro tenha terminado
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      if(tabuleiro[i][j] == 0) {
        return false;
      }
    }
  }
  return true;
}

void solverSudoku(int tabuleiro[9][9]) {
  int vetor[9];
  int i, j;
  for(int ri = 0; ri < 9; ri+=3){
    for(int rj = 0; rj < 9; rj+=3) {
      // Aqui faz um loop em todas as regiões
      // imprimirRegiao(tabuleiro, ri, rj);
      // printf("\n");
      for(int i = 0; i < 9; i++) vetor[i] = 0;

      for(int i = ri / 3 * 3; i < ri / 3 * 3 + 3; i++) {
        for(int j = rj / 3 * 3; j < rj / 3 * 3 + 3; j++) {

          if(tabuleiro[i][j] == 0) {
            for(int x = 0; x < 9; x++) {
              if(temErro(tabuleiro, i, j, x+1) == false) {
                vetor[x] += 1;
              }
            }
          }
        }
      }
      for(int x = 0; x < 9; x++) {
        if(vetor[x] == 1) {
          for(int i = ri / 3 * 3; i < ri / 3 * 3 + 3; i++) {
            for(int j = rj / 3 * 3; j < rj / 3 * 3 + 3; j++) {
              if(tabuleiro[i][j] == 0) {
                if(temErro(tabuleiro, i, j, x+1) == false) {
                  tabuleiro[i][j] = x+1;
                  return;
                } 
              }
            }
          }
        }
      }
    }
  }
  
  
}

void main() {

  // int tabuleiro[9][9] = {
  //   {0, 0, 0, 0, 0, 0, 0, 0, 0},
  //   {0, 0, 0, 0, 0, 0, 0, 0, 0},
  //   {0, 0, 0, 0, 0, 0, 0, 0, 0},
  //   {0, 0, 0, 0, 0, 0, 0, 0, 0},
  //   {0, 0, 0, 0, 0, 0, 0, 0, 0},
  //   {0, 0, 0, 0, 0, 0, 0, 0, 0},
  //   {0, 0, 0, 0, 0, 0, 0, 0, 0},
  //   {0, 0, 0, 0, 0, 0, 0, 0, 0},
  //   {0, 0, 0, 0, 0, 0, 0, 0, 0},
  // };

  // int tabuleiro[9][9] = {
  //   {5, 3, 0, 0, 7, 0, 0, 0, 0},
  //   {6, 0, 0, 1, 9, 5, 0, 0, 0},
  //   {0, 9, 8, 0, 0, 0, 0, 6, 0},
  //   {8, 0, 0, 0, 6, 0, 0, 0, 3},
  //   {4, 0, 0, 8, 0, 3, 0, 0, 1},
  //   {7, 0, 0, 0, 2, 0, 0, 0, 6},
  //   {0, 6, 0, 0, 0, 0, 2, 8, 0},
  //   {0, 0, 0, 4, 1, 9, 0, 0, 5},
  //   {0, 0, 0, 0, 8, 0, 0, 7, 9},
  // };

  // int tabuleiro[9][9] = {
  //   {0, 8, 0, 0, 6, 0, 0, 0, 1},
  //   {0, 0, 7, 0, 0, 1, 0, 0, 0},
  //   {6, 0, 0, 4, 0, 9, 0, 8, 7},
  //   {0, 0, 0, 0, 0, 0, 9, 4, 0},
  //   {0, 4, 5, 0, 0, 0, 0, 0, 8},
  //   {0, 0, 0, 0, 0, 0, 5, 0, 0},
  //   {3, 0, 0, 0, 0, 0, 0, 9, 0},
  //   {4, 2, 0, 0, 0, 0, 0, 0, 0},
  //   {0, 0, 1, 2, 0, 0, 7, 0, 0},
  // };

 int tabuleiro[9][9] = {
{2, 6, 0, 9, 0, 1, 0, 7, 3},
{0, 3, 7, 5, 6, 0, 0, 0, 0},
{0, 0, 1, 2, 0, 0, 4, 6, 9},
{0, 0, 2, 8, 4, 0, 7, 0, 0},
{5, 0, 8, 0, 9, 0, 2, 1, 4},
{6, 0, 0, 0, 2, 7, 0, 0, 8},
{0, 0, 9, 0, 0, 0, 6, 2, 7},
{7, 0, 0, 0, 3, 9, 8, 4, 0},
{0, 8, 0, 7, 0, 2, 0, 0, 0},
};

  // int tabuleiro[9][9] = {
  //   {1, 5, 0, 6, 0, 3, 0, 2, 0},
  //   {0, 0, 0, 0, 4, 0, 3, 7, 8},
  //   {3, 0, 0, 0, 0, 8, 0, 0, 0},
  //   {5, 1, 0, 0, 0, 0, 9, 0, 0},
  //   {0, 0, 2, 0, 0, 0, 6, 1, 0},
  //   {0, 0, 4, 3, 0, 0, 2, 0, 0},
  //   {7, 3, 5, 8, 0, 0, 0, 0, 6},
  //   {0, 8, 0, 0, 0, 0, 0, 4, 0},
  //   {0, 6, 9, 0, 0, 0, 8, 0, 0},
  // };

  int tabuleiro_medio[9][9] = {
    {0, 0, 4, 0, 1, 0, 6, 0, 7},
    {0, 7, 0, 0, 0, 0, 2, 5, 0},
    {5, 0, 0, 0, 0, 0, 9, 1, 0},
    {9, 6, 2, 0, 0, 1, 3, 0, 0},
    {0, 0, 0, 0, 4, 0, 0, 0, 0},
    {0, 0, 7, 2, 0, 6, 8, 0, 0},
    {6, 0, 0, 0, 0, 2, 0, 0, 0},
    {0, 4, 3, 0, 0, 8, 0, 0, 2},
    {0, 0, 1, 7, 0, 0, 5, 0, 8},
  };

  imprimirTabuleiro(tabuleiro);
  
  while(completado(tabuleiro) != true) {
    // Sleep(150);
    // imprimirTabuleiro(tabuleiro);
    solverSudoku(tabuleiro);
    // printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    // imprimirTabuleiro(tabuleiro);
    // imprimirTabuleiro(tabuleiro);
  }


  

  imprimirTabuleiro(tabuleiro);
  // imprimirTabuleiro(tabuleiro_medio);
  
  // temErro(tabuleiro, 7, 7, 3) ? printf("tem erro\n") : printf("nao tem erro\n");
  // imprimirTabuleiro(tabuleiro);
  // printf("\nTime elapsed: %f seconds\n", time_spent);
  printf("\n");

}

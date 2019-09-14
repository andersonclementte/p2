#include <stdio.h>
#include <stdlib.h>

char matriz[3][3]; //matriz global do jogo

void rodamatriz(void);
void jogadaplayer(void);
void jogadacpu(void);
void mapamatriz(void);
void graficomatriz(void);
char check(void);

int main()
{
  char ok = ' ';

  rodamatriz();
  mapamatriz();

  do{
    graficomatriz();
    jogadaplayer();
    ok = check(); //verificar jogada
    if (ok != ' ') break; //vencendor
    jogadacpu();
    ok = check();
  } while (ok == ' ');

  if (ok == 'X') printf("Voce ganhou!\n");
  else printf("Voce perdeu!\n");
  graficomatriz(); //exibe ultima rodada


  return 0;
}

void rodamatriz(void) //inicializa a matriz
{
  int i, j;

  for (i = 0; i < 3; i++){
    for (j = 0; j < 3; j++) matriz[i][j] = ' ';
  }

}

void jogadaplayer(void)
{
  int k, x, y;
  printf("Digite o valor de uma posição do tabuleiro: ");
  scanf("%d", &k);

  switch (k){
    case 1: x = 0; y = 0;
      break;
    case 2: x = 0; y = 1;
      break;
    case 3: x = 0; y = 2;
      break;
    case 4: x = 1; y = 0;
      break;
    case 5: x = 1; y = 1;
      break;
    case 6: x = 1; y = 2;
      break;
    case 7: x = 2; y = 0;
      break;
    case 8: x = 2; y = 1;
      break;
    case 9: x = 2; y = 2;
      break;
    default: printf("Posiao invalida.\n");
    jogadaplayer();

  }

  if (matriz[x][y] != ' '){
    printf("Movimento invalido, tente novamente.\n");
    jogadaplayer();
  }

  else matriz[x][y] = 'X';
}

void jogadacpu(void)
{
  int i, j;

  for (i = 0; i < 3; i++){
    for (j= 0; j< 3; j++){
      if (matriz[i][j] == ' ') break;
    }
    if (matriz[i][j] == ' ') break;
  }

  if (i*j == 9){
    printf("Empatou.\n");
    exit(0);
  }

  else matriz[i][j] = 'O';
}

void mapamatriz(void) //mapeia o jogo

{
  int i, j, var = 1;
  printf("Mapa de posições\n");
  for (i = 0; i < 3; i++){
    for (j = 0; j < 3; j++){
      printf(" %d ", var);
      var++;
      if (j != 2) printf("|");
    }
    if (i != 2) printf("\n---|---|---\n");
  }

  printf("\nAgora jogue\n");
}

void graficomatriz(void) //desenha a matriz
{
  int g;

  for (g = 0; g < 3; g++){
    printf(" %c | %c | %c ", matriz[g][0], matriz[g][1], matriz[g][2]);
    if (g != 2) printf("\n---|---|---\n");
  }
  printf("\n");
}

char check(void)//verifica a matriz
{
  int i;

  for(i=0; i<3; i++)  //verifica linhas
    if(matriz[i][0]==matriz[i][1] &&
       matriz[i][0]==matriz[i][2]) return matriz[i][0];

  for(i=0; i<3; i++)  //verifica colunas
    if(matriz[0][i]==matriz[1][i] &&
       matriz[0][i]==matriz[2][i]) return matriz[0][i];

  //verifica diagonais
  if(matriz[0][0]==matriz[1][1] &&
     matriz[1][1]==matriz[2][2])
       return matriz[0][0];

  if(matriz[0][2]==matriz[1][1] &&
     matriz[1][1]==matriz[2][0])
       return matriz[0][2];

  return ' ';

}
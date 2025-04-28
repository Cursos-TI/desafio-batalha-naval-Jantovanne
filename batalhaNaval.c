#include <stdio.h>

int main(){

    //Declaração de variáveis.
    char *linhas[] = {"A","B","C","D","F","G","H","I","J","K"};
    char *colunas[] = {"1","2","3","4","5","6","7","8","9","10"};
    int casas, i, j, linha, coluna, verticalhorizontal;
   
int tabuleiro[10][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};
//Inserindo os navios no tabuleiro.
printf("Bem vindo ao jogo de tabuleiro de batalha naval...\n");
do
{
printf("Selecione se deseja posicionar o navio para a vertical ou horizontal:\n");//Interação com o usuário.
printf("Digite 1 para vertical;\n");
printf("Digite 2 para horizontal.\n");
scanf("%d", &verticalhorizontal);
switch (verticalhorizontal)
{
case 1:
  printf("Digite o valor referente a coluna que deseja inserir o navio:\n");
  do
  {
  printf("0 - Coluna 1;\n");
  printf("1 - Coluna 2;\n");
  printf("2 - Coluna 3;\n");
  printf("3 - Coluna 4;\n");
  printf("4 - Coluna 5;\n");
  printf("5 - Coluna 6;\n");
  printf("6 - Coluna 7;\n");
  printf("7 - Coluna 8;\n");
  printf("8 - Coluna 9;\n");
  printf("9 - Coluna 10.\n");
  scanf("%d", &coluna);
  if ((coluna < 0) || (coluna > 9))
  {
printf("Opção inválida...\n");
  }
} while ((coluna < 0) | (coluna > 9));  
printf("Digite o valor referente a 1° linha(de cima para baixo) que deseja inserir o navio:\n");
printf("0 - Linha A;\n");
  printf("1 - Linha B;\n");
  printf("2 - Linha C;\n");
  printf("3 - Linha D;\n");
  printf("4 - Linha E;\n");
  printf("5 - Linha F;\n");
  printf("6 - Linha G;\n");
  printf("7 - Linha H;\n");
  printf("8 - Linha I;\n");
  printf("9 - Linha J.\n");
  scanf("%d", &linha);
if (tabuleiro[linha][coluna] == 0)
{
  printf("Agora digite quantas casas(em linhas) tem o navio(máximo 3):\n");
  scanf("%d", &casas);
  switch (casas)
  {
  case 1:
    tabuleiro[linha][coluna] = 3;
    break;
    case 2:
while (casas < 4)
{
  tabuleiro[linha][coluna] = 3;
casas++;
linha++;
}
    break;
    case 3:
    while (casas < 6)
    {
      tabuleiro[linha][coluna] = 3;
    casas++;
    linha++;
    }
        break;
  default: 
  printf("Opção inválida...\n");
    break;
  }
} else
{
  printf("Já existe um navio no local desejado.\n");
}


  break;
  case 2:
  printf("Digite o valor referente a linha que deseja inserir o navio:\n");
  do
  {
  printf("0 - Linha A;\n");
  printf("1 - Linha B;\n");
  printf("2 - Linha C;\n");
  printf("3 - Linha D;\n");
  printf("4 - Linha E;\n");
  printf("5 - Linha F;\n");
  printf("6 - Linha G;\n");
  printf("7 - Linha H;\n");
  printf("8 - Linha I;\n");
  printf("9 - Linha J.\n");
  scanf("%d", &linha);
  if ((linha < 0) || (linha > 9))
  {
printf("Opção inválida...\n");
  }
} while ((linha < 0) | (linha > 9));  
printf("Digite o valor referente a 1° coluna(da esquerda para a direita) que deseja inserir o navio:\n");
printf("0 - Coluna 1\n");
  printf("1 - Coluna 2;\n");
  printf("2 - Coluna 3;\n");
  printf("3 - Coluna 4;\n");
  printf("4 - Coluna 5;\n");
  printf("5 - Coluna 6;\n");
  printf("6 - Coluna 7;\n");
  printf("7 - Coluna 8;\n");
  printf("8 - Coluna 9;\n");
  printf("9 - Coluna 10.\n");
  scanf("%d", &coluna);
if (tabuleiro[linha][coluna] == 0)
{
  printf("Agora digite quantas casas(em colunas) tem o navio(máximo 3):\n");
  scanf("%d", &casas);
  switch (casas)
  {
  case 1:
    tabuleiro[linha][coluna] = 3;
    break;
    case 2:
while (casas < 4)
{
  tabuleiro[linha][coluna] = 3;
casas++;
coluna++;
}
    break;
    case 3:
    while (casas < 6)
    {
      tabuleiro[linha][coluna] = 3;
    casas++;
    coluna++;
    }
        break;
  default: 
  printf("Opção inválida...\n");
    break;
  } } else
  {
    printf("Já existe um navio no local desejado.\n");
  }


  break;
default:
printf("Oção inválida, digite novamente a coluna: \n");

  break;
}

} while ((verticalhorizontal < 1) || (verticalhorizontal > 2));



//Exibindo o tabuleiro.
for ( j = 0; j < 10; j++)
{
    printf("   %s", colunas[j]);
  
}
printf("\n");
for ( i = 0; i < 10; i++)
{
  printf("%s  ", linhas[i]);
  for ( j = 0; j < 10; j++)
  {
printf("%d   ", tabuleiro[i][j]);
 }
  printf("\n");
}




return 0;
}
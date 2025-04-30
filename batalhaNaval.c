#include <stdio.h>
//Definindo o tamanho do tabuleiro.
#define LINHAS 10
#define COLUNAS 10

//Inicializando um código dentro de uma variável que será uitilizada várias vezes dentro do jogo
int Casas() {int casas;
    do
    {
    printf("Qual o tamanho do seu navio em casas?\n");
    printf("1 - 1 casa\n");
    printf("2 - 2 casas\n");
    printf("3 - 3 casas\n");
scanf("%d", &casas);

if ((casas < 1) || (casas > 3))
{
printf("Opção inválida...\n");
}

} while ((casas < 1) || (casas > 3));
return casas;
}
int Linhas() {
    int linha;
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
} while ((linha < 0) || (linha > 9));  
return linha;
}
int Colunas() {
    int coluna;
    do{
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
  if ((coluna < 0) || (coluna > 9))
  {
    printf("Opção inválida...\n");
}
  
    } while ((coluna < 0) || (coluna > 9));
    return coluna;
}
int podeInserir(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna, int casas, int dirLinha, int dirColuna) {
    for (int i = 0; i < casas; i++) {
        int l = linha + i * dirLinha;
        int c = coluna + i * dirColuna;

        if (l < 0 || l >= LINHAS || c < 0 || c >= COLUNAS) {
            return 0; // fora dos limites
        }

        if (tabuleiro[l][c] != 0) {
            return 0; // já tem navio
        }
    }
    return 1;
}

int main() {
     //Declaração de variáveis.
     char *linhas[] = {"A","B","C","D","E","F","G","H","I","J"};
     char *colunas[] = {"1","2","3","4","5","6","7","8","9","10"};
int tabuleiro[LINHAS][COLUNAS];
int i, j, casas, linha, coluna, diagonal;

//Inicializando o tabuleiro.
for ( i = 0; i < LINHAS; i++)
{
    for ( j = 0; j < COLUNAS; j++)
    {
        tabuleiro[i][j] = 0;
    }
    
}

//Dando início ao jogo de batalha naval
printf("Bem vindo ao jogo de batalha naval!!\n");
printf("Esse é o seu tabuleiro atual: \n");

//Exibindo o tabuleiro atual ao usuário.
for ( j = 0; j < COLUNAS; j++)
{
    printf("   %s", colunas[j]);
  
}
printf("\n");
for ( i = 0; i < LINHAS; i++)
{
  printf("%s  ", linhas[i]);
  for ( j = 0; j < COLUNAS; j++)
  {
printf("%d   ", tabuleiro[i][j]);
 }
  printf("\n");
}

//Interação com o usuário, solicitando a inserção dos navios no tabuleiro.
printf("Agora é a hora de adicionar os navios ao tabuleiro...\n");
printf("Começando pelo navio na horizontal:\n");
casas = Casas();
printf("Agora digite a linha inicial(da esquerda para a direita), da posição do seu navio: \n");
linha = Linhas();
printf("Digite a coluna em que o seu navio está posicionado: \n");
coluna = Colunas();

//testando uma condição que detecta se já existe um navio ou se está dentro dos parâmetros do tabuleiro, no local inserido pelo usuário.
if (podeInserir(tabuleiro, linha, coluna, casas, 0, 1)) {
    for (i = 0; i < casas; i++) {
        tabuleiro[linha][coluna] = 3;
        coluna++;
    }
    printf("Navio 1 inserido!!\n");
} else {
    printf("Não é possível posicionar o navio nessa posição!\n");
}

//Inserindo o navio na posição vertical.
printf("Vamos para o navio na posição vertical:\n");
casas = Casas();
printf("Agora digite a linha em que seu navio está posicionado: \n");
linha = Linhas();
printf("Digite a coluna inicial(de cima para baixo) em que seu navio está posicionado: \n");
coluna = Colunas();

//testando uma condição que detecta se já existe um navio ou se está dentro dos parâmetros do tabuleiro, no local inserido pelo usuário.
if (podeInserir(tabuleiro, linha, coluna, casas, 1, 0)) {
    for (i = 0; i < casas; i++) {
        tabuleiro[linha][coluna] = 3;
        linha++;
    }
    printf("Navio 2 inserido!!\n");

} else {
    printf("Não é possível posicionar o navio nessa posição!\n");
}

//Interação com o usuário para inserção do navio na posição diagonal(2 navios).
for (int d = 0; d < 2; d++)
{

if (d == 0)
{
printf("Agora insira o primeiro navio na diagonal:\n"); }
else if (d == 1)
{
    printf("Agora insira o segundo navio na diagonal:\n");
}

casas = Casas();
printf("Começando de cima para baixo, escolha a linha inicial da posição do seu navio:\n");
linha = Linhas();
printf("Continuando de cima para baixo, escolha a coluna inicial da posição do seu navio:\n");
coluna = Colunas();
do
{
printf("Continuando de cima para baixo, o seu navio está direcionado para:\n");
printf("1 - diagonal esquerda;\n");
printf("2 - diagonal direita.\n");
scanf("%d", &diagonal);
switch (diagonal)
{
case 1:
if (podeInserir(tabuleiro, linha, coluna, casas, 1, -1)) {
    for (i = 0; i < casas; i++) {
        tabuleiro[linha][coluna] = 3;
        linha++;
        coluna--;
    }
    if (d == 0)
{
    printf("Navio 3 adicionado!!!\n");
} else
{
    printf("Navio 4 adicionado!!!\n");
}
} else {
    printf("Não é possível posicionar o navio nessa posição!\n");
}
    break;
case 2:
if (podeInserir(tabuleiro, linha, coluna, casas, 1, 1)) {
    for (i = 0; i < casas; i++) {
        tabuleiro[linha][coluna] = 3;
        linha++;
        coluna++;
    }
    if (d == 0)
{
    printf("Navio 3 adicionado!!!\n");
} else
{
    printf("Navio 4 adicionado!!!\n");
}
} else {
    printf("Não é possível posicionar o navio nessa posição!\n");
}
break;
default: printf("Opção inválida...\n");
    break;
}
} while ((diagonal < 1) || (diagonal > 2));


}






//Exibindo o tabuleiro com os navios inseridos.
for ( j = 0; j < COLUNAS; j++)
{
    printf("   %s", colunas[j]);
  
}
printf("\n");
for ( i = 0; i < LINHAS; i++)
{
  printf("%s  ", linhas[i]);
  for ( j = 0; j < COLUNAS; j++)
  {
printf("%d   ", tabuleiro[i][j]);
 }
  printf("\n");
}
return 0;
}
#include <stdio.h>
//Definindo o tamanho do tabuleiro.
#define LINHAS 10
#define COLUNAS 10

//Definindo as matrizes das habilidades de ataque.
#define LINHASCONE 2
#define COLUNASCONE 3
#define LINHASCRUZ 3
#define COLUNASCRUZ 5
#define LINHASOCTA 3
#define COLUNASOCTA 3

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
//Código que le a linha inicial a ser inserida no tabuleiro.

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
//Código que le a coluna inicial a ser inserida no tabuleiro.
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
//Código que verifica se tem navio ou se está fora dos limites do tabuleiro.
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

//Código que verifica se as habilidades estão dentro dos limites do tabuleiro e informa se algum navio foi atingido.
void aplicarocta(int tabuleiro[LINHAS][COLUNAS], int habilidade[3][3], int linhasH, int colunasH, int linha, int coluna) {
    for (int i = 0; i < linhasH; i++) {
        for (int j = 0; j < colunasH; j++) {
            int l = linha + i;
            int c = coluna + j;
            
            if (l >= 0 && l < LINHAS && c >= 0 && c < COLUNAS && habilidade[i][j] == 1) {
                if(tabuleiro[l][c] == 3){
                    printf("Navio atingido!!!\n");
              
                }   tabuleiro[l][c] = 1; // 1 = ataque
            } else
            {
                printf("O local escolhido ultrapassa os limites do tabuleiro...\n");
            }
        }
    }
}

void aplicarcone(int tabuleiro[LINHAS][COLUNAS], int habilidade[2][3], int linhasH, int colunasH, int linha, int coluna) {
    for (int i = 0; i < linhasH; i++) {
        for (int j = 0; j < colunasH; j++) {
            int l = linha + i;
            int c = coluna + j;
            
            if (l >= 0 && l < LINHAS && c >= 0 && c < COLUNAS && habilidade[i][j] == 1) {
                if(tabuleiro[l][c] == 3){
                    printf("Navio atingido!!!\n");
                }   tabuleiro[l][c] = 1; // 1 = ataque
            } else
            {
                printf("O local escolhido ultrapassa os limites do tabuleiro...\n");
            }
        }
    }
}

void aplicarcruz(int tabuleiro[LINHAS][COLUNAS], int habilidade[3][5], int linhasH, int colunasH, int linha, int coluna) {
    for (int i = 0; i < linhasH; i++) {
        for (int j = 0; j < colunasH; j++) {
            int l = linha + i;
            int c = coluna + j;
            
            if (l >= 0 && l < LINHAS && c >= 0 && c < COLUNAS && habilidade[i][j] == 1) {
                if(tabuleiro[l][c] == 3){
                    printf("Navio atingido!!!\n");
                }
                tabuleiro[l][c] = 1; // 1 = ataque
                
            } else
            {
                printf("O local escolhido ultrapassa os limites do tabuleiro...\n");
            }
            
        }
    }
}

int main() {
     //Declaração de variáveis.
     char *linhas[] = {"A","B","C","D","E","F","G","H","I","J"};
     char *colunas[] = {"1","2","3","4","5","6","7","8","9","10"};
int tabuleiro[LINHAS][COLUNAS];
int i, j, casas, linha, coluna, diagonal, tipo, sair;

//declarando as matrizes de habilidade.
int cone[LINHASCONE][COLUNASCONE] = {{0, 1, 0}, {1, 1, 1}};
int cruz[LINHASCRUZ][COLUNASCRUZ] = {{0, 0, 1, 0, 0}, {1, 1, 1, 1, 1}, {0, 0, 1, 0, 0}};
int octaedro[LINHASOCTA][COLUNASOCTA] = {{0, 1, 0},{1, 1, 1},{0, 1, 0}};


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
} else {
    printf("Não é possível posicionar o navio nessa posição!\n");
}
printf("Navio 1 inserido!!\n");

//Inserindo o navio na posição vertical.
printf("Vamos para o navio na posição vertical:\n");
casas = Casas();
printf("Agora digite a linha em que seu navio está posicionado: \n");
linha = Linhas();
printf("Digite a coluna inicial(de cima para baixo) em que seu navio está posicionado: \n");
coluna = Colunas();

//testando uma condição que detecta se já existe um navio ou se está dentro dos parâmetros do tabuleiro, no local inserido pelo usuário.
if (podeInserir(tabuleiro, linha, coluna, casas, 0, 1)) {
    for (i = 0; i < casas; i++) {
        tabuleiro[linha][coluna] = 3;
        linha++;
    }
} else {
    printf("Não é possível posicionar o navio nessa posição!\n");
}
printf("Navio 2 inserido!!\n");

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


//Interação com o usuário sobre a escolha das habilidades.
printf("Hora de lançar as habilidades de ataque.\n");
do{
do{
    printf("Escolha:\n1 - Cone\n");//Mostrando as opções e a forma das habilidades 
    for ( i = 0; i < LINHASCONE; i++)
    {
      for ( j = 0; j < COLUNASCONE; j++)
      {
    printf("%d   ", cone[i][j]);
     }
      printf("\n");
    }
    printf("2 - Cruz\n");
    for ( i = 0; i < LINHASCRUZ; i++)
    {
      for ( j = 0; j < COLUNASCRUZ; j++)
      {
    printf("%d   ", cruz[i][j]);
     }
      printf("\n");
    }
    printf("3 - Octaedro\n");
    for ( i = 0; i < LINHASOCTA; i++)
    {
      for ( j = 0; j < COLUNASOCTA; j++)
      {
    printf("%d   ", octaedro[i][j]);
     }
      printf("\n");
    }
    scanf("%d", &tipo);
    if (tipo < 1 || tipo > 3)
    {
printf("Opção inválida...\n");  
  }
    
} while (tipo < 1 || tipo > 3);

printf("Agora escolha a linha inicial em que a habilidade será inserida no tabuleiro(começando da linha 1 e coluna 1 da habilidade):\n");
linha = Linhas();
printf("Agora escolha a coluna inicial em que a habilidade será inserida no tabuleiro(começando da linha 1 e coluna 1 da habilidade):\n");
coluna = Colunas();

switch (tipo)
{
case 1:
    aplicarcone(tabuleiro, cone, LINHASCONE, COLUNASCONE, linha, coluna);
    break;
    case 2:
    aplicarcruz(tabuleiro, cruz, LINHASCRUZ, COLUNASCRUZ, linha, coluna);

    break;
    case 3:
    aplicarocta(tabuleiro, octaedro, LINHASOCTA, COLUNASOCTA, linha, coluna);

    break;

}

//Exibindo o tabuleiro com os navios e habilidades inseridos.
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

printf("1 - Lançar outro ataque \n2 - Sair do jogo\n");
scanf("%d", &sair);
} while (sair == 1);
if (sair == 2)
{
    printf("Saindo do jogo...\n");
}


return 0;
}

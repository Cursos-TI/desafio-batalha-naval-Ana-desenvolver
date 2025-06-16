#include <stdio.h>

// Desafio Batalha Naval - MateCheck

#define TAM_TABULEIRO 10 // Tamanho do tabuleiro(10x10)
#define TAM_NAVIO 3      // Tamanho fixo dos navios (3 posições)
#define NAVIO 3          // 3 Representa uma parte do navio
#define AGUA 0           // 0 Representa água

int main() {
    // Criação da matriz do tabuleiro 10x10, inicializada com 0 (água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

// Posições iniciais dos Navios
// Cada navio ocupará 3 posições conforme o TAM_NAVIO
// Será inserido um navio na horizontal, um na vertical e dois nas diagonais
int linha_horizontal = 2, coluna_horizontal = 4; // E3
int linha_vertical = 5, coluna_vertical = 7;     // H6
int linha_diagonal1 = 0, coluna_diagonal1 = 0;   // A1
int linha_diagonal2 = 7, coluna_diagonal2 =4;    // E8

// Verificação de limites: Para garantir que nenhum navio ultrapasse os limites do tabuleiro
if (coluna_horizontal + TAM_NAVIO > TAM_TABULEIRO ||
    linha_vertical + TAM_NAVIO > TAM_TABULEIRO ||
    linha_diagonal1 + TAM_NAVIO > TAM_TABULEIRO || coluna_diagonal1 + TAM_NAVIO > TAM_TABULEIRO ||
    linha_diagonal2 + TAM_NAVIO > TAM_TABULEIRO || coluna_diagonal2 - (TAM_NAVIO - 1) < 0) {     
    printf("Erro: um ou mais navios ultrapassaram os limites do tabuleiro.\n");
    return 1;
    }

 // Verificação de sobreposição: Para garantir que os navios não sejam colocados em posições já ocupadas
  for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] == NAVIO || 
            tabuleiro[linha_vertical + i][coluna_vertical] == NAVIO ||
            tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] == NAVIO ||
            tabuleiro[linha_diagonal2 + i][coluna_diagonal2 - i] == NAVIO) {
            printf("Erro: Sobreposição de navios detectada.\n");
            return 1; // Encerra o programa com erro
        }
    }

// Posicionando os navios no tabuleiro
// Preenche a matriz com o valor NAVIO (3) nas posições dos navios
for (int i = 0; i < TAM_NAVIO; i++) {
    tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;          
    tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;           
    tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] = NAVIO;                
    tabuleiro[linha_diagonal2 + i][coluna_diagonal2 - i] = NAVIO;             
}

// Imprime o cabeçalho 
printf("    "); 
for (char letra = 'A'; letra < 'A' + TAM_TABULEIRO; letra++) {
    printf("  %c", letra); // Imprime letras de A até J
}
printf("\n");

// Linha sepadora superior
printf("   +-");
for (int i = 0; i < TAM_TABULEIRO; i++) {
    printf("---"); // Separador entre as colunas
}
printf("+\n");

// Imprime o tabuleiro 
// Para cada linha(i), imprime número da linha e conteúdo das colunas (j)
for (int i = 0; i < TAM_TABULEIRO; i++) {
    if(i <= 8 ) {
        printf(" ");
    }
    printf("%d |", i + 1); // Numeração das linhas (1 a 10)

    for (int j = 0; j < TAM_TABULEIRO; j++){
        printf(" %2d", tabuleiro[i][j]); // Imprime o conteúdo da célula (0 = água, 3 = navio)
    }
    printf(" |\n"); // Fecha a linha com delimitador
}

// Linha inferior
printf("   +-");
for (int i = 0; i < TAM_TABULEIRO; i++){
    printf("---"); // Separação inferior 
}
printf("+\n");

return 0; // Finaliza o programa com sucesso
}


    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

   
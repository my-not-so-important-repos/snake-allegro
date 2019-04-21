#define MAX_COBRA 100

#define ESQUERDA 82
#define DIREITA 83
#define CIMA 84
#define BAIXO 85
#define ESC 27

#define DESENHAR_PEDACO_COBRA 1
#define APAGAR_PEDACO_COBRA 2
#define DESENHAR_CABECA 3
#define DESENHAR_COBRA_INTEIRA 4
#define APAGAR_COBRA_INTEIRA 5

#define VELOCIDADE_INICIAL 250

#define VAZIO                         1
#define CRUZ                          2
#define HORIZONTAL                    3
#define VERTICAL                      4
#define CANTO_SUPERIOR_ESQUERDO       5
#define CANTO_SUPERIOR_DIREITO        6
#define CANTO_INFERIOR_ESQUERDO       7
#define CANTO_INFERIOR_DIREITO        8
#define T_BAIXO                       9
#define T_CIMA                       10
#define T_DIREITA                    11
#define T_ESQUERDA                   12
#define CABECA_CIMA                  13
#define CABECA_BAIXO                 14
#define CABECA_ESQUERDA              15
#define CABECA_DIREITA               16
#define RABO_CIMA                    17
#define RABO_BAIXO                   18
#define RABO_ESQUERDA                19
#define RABO_DIREITA                 20
#define RABO_CANTO_SUPERIOR_ESQUERDO 21
#define RABO_CANTO_SUPERIOR_DIREITO  22
#define RABO_CANTO_INFERIOR_DIREITO  23
#define RABO_CANTO_INFERIOR_ESQUERDO 24
#define RABO_HORIZONTAL              25
#define RABO_VERTICAL                26
#define MACA                         27
#define RESERVADO                    28



typedef char board[28][25];
board tabuleiro;

bool tem_maca = false;

char tamanho_cobra, direcao, vidas,
     posicao_inicial_x, posicao_inicial_y, direcao_inicial;

// int x_maca, y_maca;

unsigned int pontos = 0;
unsigned int velocidade;

BITMAP *skin[27];
BITMAP *parede_cruz, *parede_horizontal, *parede_vertical,
       *parede_inferior_direita, *parede_inferior_esquerda, *parede_superior_direita, *parede_superior_esquerda,
       *parede_t_baixo, *parede_t_cima, *parede_t_direita, *parede_t_esquerda,
       *cabeca_cima, *cabeca_baixo, *cabeca_esquerda, *cabeca_direita,
       *cauda_cima, *cauda_baixo, *cauda_esquerda, *cauda_direita,
       *vertebra_inferior_direita, *vertebra_inferior_esquerda, *vertebra_superior_direita, *vertebra_superior_esquerda,
       *vertebra_horizontal, *vertebra_vertical;

struct vertebra{
  char x, y, bitmap;
} cobra[MAX_COBRA];


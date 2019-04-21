const int TAMANHO_MAXIMO_COBRA = 100;

const int ESQUERDA = 82;
const int DIREITA  = 83;
const int CIMA     = 84;
const int BAIXO    = 85;
const int ESC      = 27;

const int DESENHAR_PEDACO_COBRA  = 1;
const int APAGAR_PEDACO_COBRA    = 2;
const int DESENHAR_CABECA        = 3;
const int DESENHAR_COBRA_INTEIRA = 4;
const int APAGAR_COBRA_INTEIRA   = 5;

const int VELOCIDADE_INICIAL = 250;

const int VAZIO                        =  1;
const int CRUZ                         =  2;
const int HORIZONTAL                   =  3;
const int VERTICAL                     =  4;
const int CANTO_SUPERIOR_ESQUERDO      =  5;
const int CANTO_SUPERIOR_DIREITO       =  6;
const int CANTO_INFERIOR_ESQUERDO      =  7;
const int CANTO_INFERIOR_DIREITO       =  8;
const int T_BAIXO                      =  9;
const int T_CIMA                       = 10;
const int T_DIREITA                    = 11;
const int T_ESQUERDA                   = 12;
const int CABECA_CIMA                  = 13;
const int CABECA_BAIXO                 = 14;
const int CABECA_ESQUERDA              = 15;
const int CABECA_DIREITA               = 16;
const int RABO_CIMA                    = 17;
const int RABO_BAIXO                   = 18;
const int RABO_ESQUERDA                = 19;
const int RABO_DIREITA                 = 20;
const int RABO_CANTO_SUPERIOR_ESQUERDO = 21;
const int RABO_CANTO_SUPERIOR_DIREITO  = 22;
const int RABO_CANTO_INFERIOR_ESQUERDO = 23;
const int RABO_CANTO_INFERIOR_DIREITO  = 24;
const int RABO_HORIZONTAL              = 25;
const int RABO_VERTICAL                = 26;
const int MACA                         = 27;
const int RESERVADO                    = 28;



typedef char board[28][25];
board tabuleiro;

bool tem_maca = false;

char tamanho_cobra, direcao, vidas,
     posicao_inicial_x, posicao_inicial_y, direcao_inicial;

unsigned int pontos = 0, velocidade;

BITMAP *skin[27];

struct vertebra{
  char x, y, bitmap;
} cobra[TAMANHO_MAXIMO_COBRA];


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

const int VAZIO                        = 65;
const int CRUZ                         = 66;
const int HORIZONTAL                   = 67;
const int VERTICAL                     = 68;
const int CANTO_SUPERIOR_ESQUERDO      = 69;
const int CANTO_SUPERIOR_DIREITO       = 70;
const int CANTO_INFERIOR_ESQUERDO      = 71;
const int CANTO_INFERIOR_DIREITO       = 72;
const int T_BAIXO                      = 73;
const int T_CIMA                       = 74;
const int T_DIREITA                    = 75;
const int T_ESQUERDA                   = 76;
const int CABECA_CIMA                  = 77;
const int CABECA_BAIXO                 = 78;
const int CABECA_ESQUERDA              = 79;
const int CABECA_DIREITA               = 80;
const int RABO_CIMA                    = 81;
const int RABO_BAIXO                   = 82;
const int RABO_ESQUERDA                = 83;
const int RABO_DIREITA                 = 84;
const int RABO_CANTO_SUPERIOR_ESQUERDO = 85;
const int RABO_CANTO_SUPERIOR_DIREITO  = 86;
const int RABO_CANTO_INFERIOR_ESQUERDO = 87;
const int RABO_CANTO_INFERIOR_DIREITO  = 88;
const int RABO_HORIZONTAL              = 89;
const int RABO_VERTICAL                = 90;
const int MACA                         = 91;
const int RESERVADO                    = 92;



typedef char board[28][25];
board tabuleiro;

bool tem_maca = false;

char tamanho_cobra, direcao, vidas,
     posicao_inicial_x, posicao_inicial_y, direcao_inicial;

unsigned int pontos = 0, velocidade;

BITMAP *skin[27];
MIDI *fundo_musical;

struct vertebra{
  char x, y, bitmap;
} cobra[TAMANHO_MAXIMO_COBRA];


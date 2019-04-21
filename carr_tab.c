#include <stdio.h>

void carregar_tabuleiro(char *arquivo, board &tabuleiro){
  FILE *tabuleiro_arq;
  char temp[30], x, y;

  //Abrir o arquivo que contem as informacoes do tabuleiro
  tabuleiro_arq = fopen(arquivo, "r");

  y = 0;
  while(!feof(tabuleiro_arq))
  {
    y++;
    fgets(temp, 29, tabuleiro_arq);
    for(x = 0; x <= 27; x++)
    {
    	switch(temp[x])
      {
        case '�'://193
        case '�'://194
        case '�'://195
        case '�'://180
        case '�'://197
        case '�':
        case '�'://196
        case '�':
        case '�':
        case '�':
        case '�':
        case ' ':
        case '�'://219
          tabuleiro[x + 1][y] = temp[x];
          break;
        case ''://30
          posicao_inicial_x = x + 1;
          posicao_inicial_y = y;
          direcao_inicial = CIMA;
          break;
        case ''://31
          posicao_inicial_x = x + 1;
          posicao_inicial_y = y;
          direcao_inicial = BAIXO;
          break;
        case ''://17
          posicao_inicial_x = x + 1;
          posicao_inicial_y = y;
          direcao_inicial = ESQUERDA;
          break;
        case ''://16
          posicao_inicial_x = x + 1;
          posicao_inicial_y = y;
          direcao_inicial = DIREITA;
          break;
      } // switch(temp[x])
    } // for(x = 0; x <= 27; x++)
  } // while(!feof(tabuleiro_arq))
}


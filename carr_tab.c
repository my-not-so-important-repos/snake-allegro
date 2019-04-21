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
        case 'Á'://193
        case 'Â'://194
        case 'Ã'://195
        case '´'://180
        case 'Å'://197
        case '³':
        case 'Ä'://196
        case 'Ú':
        case 'À':
        case '¿':
        case 'Ù':
        case ' ':
        case 'Û'://219
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


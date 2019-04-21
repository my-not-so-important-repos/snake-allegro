inline void carregar_tabuleiro(char *arquivo, board &tabuleiro)
{
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
      if(((VAZIO <= temp[x]) && (temp[x] <= T_ESQUERDA)) || (temp[x] == RESERVADO))
      {
        tabuleiro[x + 1][y] = temp[x];
      }
      else
      {
        tabuleiro[x + 1][y] = temp[x];
      	switch(temp[x])
        {
          case CABECA_CIMA:
            posicao_inicial_x = x + 1;
            posicao_inicial_y = y;
            direcao_inicial = CIMA;
            break;
          case CABECA_BAIXO:
            posicao_inicial_x = x + 1;
            posicao_inicial_y = y;
            direcao_inicial = BAIXO;
            break;
          case CABECA_ESQUERDA:
            posicao_inicial_x = x + 1;
            posicao_inicial_y = y;
            direcao_inicial = ESQUERDA;
            break;
          case CABECA_DIREITA:
            posicao_inicial_x = x + 1;
            posicao_inicial_y = y;
            direcao_inicial = DIREITA;
            break;
        } // switch(temp[x])
      } // else
    } // for(x = 0; x <= 27; x++)
  } // while(!feof(tabuleiro_arq))
}


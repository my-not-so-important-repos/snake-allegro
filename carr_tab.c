void carregar_tabuleiro(){
  FILE *tabuleiro_arq;
  char temp[30], x, y;

  //Abrir o arquivo que cont�m as informa��es do tabuleiro
  tabuleiro_arq = fopen("board.map", "r");

  y = 0;
  while(!feof(tabuleiro_arq)){
    y++;
    fgets(temp, 29, tabuleiro_arq);
    for(x=0; x<=27; x++){
    	switch(temp[x]){
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
          tabuleiro[x+1][y] = temp[x];
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
      }
    }
  }
}


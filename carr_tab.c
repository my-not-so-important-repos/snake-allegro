void carregar_tabuleiro(){
  FILE *tabuleiro_arq;
  char temp[40], x, y;

  //Abrir o arquivo que cont‚m as informa‡äes do tabuleiro
  tabuleiro_arq = fopen("board.map", "r");

  y = 0;
  while(!feof(tabuleiro_arq)){
    y++;
    fgets(temp, 34, tabuleiro_arq);
    for(x=0; x<=32; x++){
    	switch(temp[x]){
        case '³':
        case 'Ä':
        case 'Ú':
        case 'À':
        case '¿':
        case 'Ù':
        case ' ':
          tabuleiro[x+1][y] = temp[x];
          break;
      }
    }
  }
}


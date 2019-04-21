void cobra_init(char posicao_inicial_x, char posicao_inicial_y){

  unsigned short i;

  for(i = 0; i <= tamanho_cobra - 1; i++){
    tabuleiro[cobra[i].x][cobra[i].y] = ' ';
  }

  /*
  tabuleiro[posicaoinicialx][posicaoinicialy] = 'c';
  tabuleiro[posicaoinicialx-1][posicaoinicialy] = 'c';
  tabuleiro[posicaoinicialx-2][posicaoinicialy] = 'c';
  */

  desenhar_cobra(APAGAR_COBRA_INTEIRA);
  
  tamanho_cobra = 3;

  cobra[0].x = posicao_inicial_x;
  cobra[0].y = posicao_inicial_y;
  cobra[0].bitmap = '';
  
  cobra[1].x = posicao_inicial_x - 1;
  cobra[1].y = posicao_inicial_y;
  cobra[1].bitmap = 'Í';
  
  cobra[2].x = posicao_inicial_x - 2;
  cobra[2].y = posicao_inicial_y;
  cobra[2].bitmap = '';

  //BUG:
  //Este comando s¢ funciona depois que a cobra morre pelo menos uma vez
  direcao = DIREITA;
  
  desenhar_cobra(DESENHAR_COBRA_INTEIRA);
  
}

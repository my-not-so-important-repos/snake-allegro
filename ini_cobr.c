void cobra_init(char posicao_inicial_x, char posicao_inicial_y){
  tamanho_cobra = 3;

  cobra[0].x = posicao_inicial_x;
  cobra[0].y = posicao_inicial_y;
  cobra[0].bitmap = '';
  
  cobra[1].x = posicao_inicial_x - 1;
  cobra[1].y = posicao_inicial_y;
  cobra[1].bitmap = '�';
  
  cobra[2].x = posicao_inicial_x - 2;
  cobra[2].y = posicao_inicial_y;
  cobra[2].bitmap = '';

  direcao = DIREITA;
}

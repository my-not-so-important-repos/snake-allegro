void cobra_init(char posicao_inicial_x, char posicao_inicial_y)
{
  tamanho_cobra = 3;
  switch(direcao_inicial){
    case DIREITA:
      cobra[0].x = posicao_inicial_x;
      cobra[0].y = posicao_inicial_y;
      cobra[0].bitmap = CABECA_DIREITA;

      cobra[1].x = posicao_inicial_x - 1;
      cobra[1].y = posicao_inicial_y;
      cobra[1].bitmap = RABO_HORIZONTAL;

      cobra[2].x = posicao_inicial_x - 2;
      cobra[2].y = posicao_inicial_y;
      cobra[2].bitmap = RABO_ESQUERDA;
      break;
    case ESQUERDA:
      cobra[0].x = posicao_inicial_x;
      cobra[0].y = posicao_inicial_y;
      cobra[0].bitmap = CABECA_ESQUERDA;

      cobra[1].x = posicao_inicial_x - 1;
      cobra[1].y = posicao_inicial_y;
      cobra[1].bitmap = RABO_HORIZONTAL;

      cobra[2].x = posicao_inicial_x - 2;
      cobra[2].y = posicao_inicial_y;
      cobra[2].bitmap = RABO_DIREITA;
      break;
    case CIMA:
      cobra[0].x = posicao_inicial_x;
      cobra[0].y = posicao_inicial_y;
      cobra[0].bitmap = CABECA_CIMA;

      cobra[1].x = posicao_inicial_x;
      cobra[1].y = posicao_inicial_y + 1;
      cobra[1].bitmap = RABO_VERTICAL;

      cobra[2].x = posicao_inicial_x;
      cobra[2].y = posicao_inicial_y + 2;
      cobra[2].bitmap = RABO_BAIXO;
      break;

    case BAIXO:
      cobra[0].x = posicao_inicial_x;
      cobra[0].y = posicao_inicial_y;
      cobra[0].bitmap = CABECA_BAIXO;

      cobra[1].x = posicao_inicial_x;
      cobra[1].y = posicao_inicial_y - 1;
      cobra[1].bitmap = RABO_VERTICAL;

      cobra[2].x = posicao_inicial_x;
      cobra[2].y = posicao_inicial_y - 2;
      cobra[2].bitmap = RABO_CIMA;
      break;
  }
}


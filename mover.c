void mover_cobra()
{
  char proximox, proximoy, proximo_bitmap_cabeca, proximo_bitmap_pescoco;

  switch(direcao)
  {
    case CIMA:
      proximox = cobra[0].x;
      proximoy = cobra[0].y - 1;
      proximo_bitmap_cabeca = CABECA_CIMA;
      //atualizar bitmap do pecoco
      if(cobra[1].x > cobra[0].x)
      {
        proximo_bitmap_pescoco = RABO_CANTO_INFERIOR_ESQUERDO;
      }
      else
        if(cobra[1].x < cobra[0].x)
        {
          proximo_bitmap_pescoco = RABO_CANTO_INFERIOR_DIREITO;
        }
        else
        {
          proximo_bitmap_pescoco = RABO_VERTICAL;
        }
      break;
    case BAIXO:
      proximox = cobra[0].x;
      proximoy = cobra[0].y + 1;
      proximo_bitmap_cabeca = CABECA_BAIXO;
      //atualizar bitmap do pesco‡o
      if(cobra[1].x < cobra[0].x){
        proximo_bitmap_pescoco = RABO_CANTO_SUPERIOR_DIREITO;
      }
      else
        if(cobra[1].x > cobra[0].x){
          proximo_bitmap_pescoco = RABO_CANTO_SUPERIOR_ESQUERDO;
        }
        else
          proximo_bitmap_pescoco = RABO_VERTICAL;
      break;
    case ESQUERDA:
      proximox = cobra[0].x - 1;
      proximoy = cobra[0].y;
      proximo_bitmap_cabeca = CABECA_ESQUERDA;
      //atualizar bitmap do pesco‡o
      if(cobra[1].y < cobra[0].y){
        proximo_bitmap_pescoco = RABO_CANTO_INFERIOR_DIREITO;
      }
      else
        if(cobra[1].y > cobra[0].y){
          proximo_bitmap_pescoco = RABO_CANTO_SUPERIOR_DIREITO;
        }
        else
          proximo_bitmap_pescoco = RABO_HORIZONTAL;
      break;
    case DIREITA:
      proximox = cobra[0].x + 1;
      proximoy = cobra[0].y;
      proximo_bitmap_cabeca = CABECA_DIREITA;
      //atualizar bitmap do pesco‡o
      if(cobra[1].y < cobra[0].y){
        proximo_bitmap_pescoco = RABO_CANTO_INFERIOR_ESQUERDO;
      }
      else
        if(cobra[1].y > cobra[0].y){
          proximo_bitmap_pescoco = RABO_CANTO_SUPERIOR_ESQUERDO;
        }
        else
          proximo_bitmap_pescoco = RABO_HORIZONTAL;
      break;
  }

  switch(tabuleiro[proximox][proximoy]){
    case MACA:
      tabuleiro[proximox][proximoy] = VAZIO;
      tem_maca = 0;
      pontos += 10;
      
      tamanho_cobra += 1;

      cobra[tamanho_cobra - 1] = cobra[tamanho_cobra - 2];
      for(int i = tamanho_cobra - 1; i >= 1; i--){
        cobra[i] = cobra[i - 1];
      }

      cobra[1].bitmap = proximo_bitmap_pescoco;

      cobra[0].x = proximox;
      cobra[0].y = proximoy;
      cobra[0].bitmap = proximo_bitmap_cabeca;

      desenhar_cobra(DESENHAR_CABECA);
      textprintf(screen, font, 900, 120, makecol(255, 255, 255), "%d", pontos);
      break;
    case VAZIO:
      desenhar_cobra(APAGAR_PEDACO_COBRA);

      // Atualizar os dados da cobra
      for(int i = tamanho_cobra - 1; i >= 2; i--){
        cobra[i] = cobra[i - 1];
      }

      cobra[1].x = cobra[0].x;
      cobra[1].y = cobra[0].y;
      cobra[1].bitmap = proximo_bitmap_pescoco;

      // Atualizar posicao da cabeca
      cobra[0].x = proximox;
      cobra[0].y = proximoy;
      cobra[0].bitmap = proximo_bitmap_cabeca;

      // Atualizar bitmap do rabo
      if(cobra[tamanho_cobra - 2].x < cobra[tamanho_cobra - 1].x){
        cobra[tamanho_cobra - 1].bitmap = RABO_DIREITA;
      }
      else
        if(cobra[tamanho_cobra - 2].x > cobra[tamanho_cobra - 1].x){
          cobra[tamanho_cobra - 1].bitmap = RABO_ESQUERDA;
        }
        else
          if(cobra[tamanho_cobra - 2].y > cobra[tamanho_cobra - 1].y){
            cobra[tamanho_cobra - 1].bitmap = RABO_CIMA;
          }
          else
            cobra[tamanho_cobra - 1].bitmap = RABO_BAIXO;

      desenhar_cobra(DESENHAR_COBRA_INTEIRA);
      break;
    case HORIZONTAL:
    case VERTICAL:
    case CANTO_INFERIOR_ESQUERDO:
    case CANTO_SUPERIOR_DIREITO:
    case CANTO_INFERIOR_DIREITO:
    case CANTO_SUPERIOR_ESQUERDO:
    case T_CIMA:
    case T_BAIXO:
    case T_DIREITA:
    case T_ESQUERDA:
    case CRUZ:
    case 'c':
      vidas--;
      desenhar_cobra(APAGAR_COBRA_INTEIRA);
      cobra_init(posicao_inicial_x, posicao_inicial_y);
      direcao = direcao_inicial;
      desenhar_cobra(DESENHAR_COBRA_INTEIRA);
      textprintf(screen, font, 900, 88, makecol(255, 255, 255), "%d", vidas);
      break;
  }
}


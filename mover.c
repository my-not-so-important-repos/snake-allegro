void mover_cobra(){
  char proximox, proximoy, proximo_bitmap_cabeca, proximo_bitmap_pescoco;

  switch(direcao){
    case CIMA:
      proximox = cobra[0].x;
      proximoy = cobra[0].y - 1;
      proximo_bitmap_cabeca = '';
      //atualizar bitmap do peco�o
      if(cobra[1].x > cobra[0].x){
        proximo_bitmap_pescoco = '�';//200
      }
      else
        if(cobra[1].x < cobra[0].x){
          proximo_bitmap_pescoco = '�';//188
        }
        else
          proximo_bitmap_pescoco = '�';//186
      break;
    case BAIXO:
      proximox = cobra[0].x;
      proximoy = cobra[0].y + 1;
      proximo_bitmap_cabeca = '';
      //atualizar bitmap do pesco�o
      if(cobra[1].x < cobra[0].x){
        proximo_bitmap_pescoco = '�';//187
      }
      else
        if(cobra[1].x > cobra[0].x){
          proximo_bitmap_pescoco = '�';//201
        }
        else
          proximo_bitmap_pescoco = '�';
      break;
    case ESQUERDA:
      proximox = cobra[0].x - 1;
      proximoy = cobra[0].y;
      proximo_bitmap_cabeca = '';
      //atualizar bitmap do pesco�o
      if(cobra[1].y < cobra[0].y){
        proximo_bitmap_pescoco = '�';//188
      }
      else
        if(cobra[1].y > cobra[0].y){
          proximo_bitmap_pescoco = '�';//187
        }
        else
          proximo_bitmap_pescoco = '�';
      break;
    case DIREITA:
      proximox = cobra[0].x + 1;
      proximoy = cobra[0].y;
      proximo_bitmap_cabeca = '';
      //atualizar bitmap do pesco�o
      if(cobra[1].y < cobra[0].y){
        proximo_bitmap_pescoco = '�';//200
      }
      else
        if(cobra[1].y > cobra[0].y){
          proximo_bitmap_pescoco = '�';//201
        }
        else
          proximo_bitmap_pescoco = '�';//205
      break;
  }

  switch(tabuleiro[proximox][proximoy]){
    char i;

    case 'm':
      tabuleiro[proximox][proximoy] = ' ';
      tem_maca = 0;
      pontos += 10;
      if(fmod(pontos / 10, 5) == 0){
        velocidade *= 0.80;
      }
      //Fazer a cobra crescer
      tamanho_cobra += 1;

      cobra[tamanho_cobra - 1] = cobra[tamanho_cobra - 2];
      for(i = tamanho_cobra - 1; i >= 1; i--){
        cobra[i] = cobra[i - 1];
      }

      // Atualizar o bitmap do pesco�o
      cobra[1].bitmap = proximo_bitmap_pescoco;

      // Atualizar posicao da cabeca
      cobra[0].x = proximox;
      cobra[0].y = proximoy;
      cobra[0].bitmap = proximo_bitmap_cabeca;

      desenhar_cobra(DESENHAR_CABECA);
      break;
    case ' ':
      desenhar_cobra(APAGAR_PEDACO_COBRA);

      // Atualizar os dados da cobra
      for(i = tamanho_cobra - 1; i >= 2; i--){
        cobra[i] = cobra[i - 1];
      }

      // Atualizar os dados do pesco�o
      cobra[1].x = cobra[0].x;
      cobra[1].y = cobra[0].y;
      cobra[1].bitmap = proximo_bitmap_pescoco;

      // Atualizar posicao da cabeca
      cobra[0].x = proximox;
      cobra[0].y = proximoy;
      cobra[0].bitmap = proximo_bitmap_cabeca;

      // Atualizar bitmap do rabo
      if(cobra[tamanho_cobra - 2].x < cobra[tamanho_cobra - 1].x){
        cobra[tamanho_cobra - 1].bitmap = 26;
      }
      else
        if(cobra[tamanho_cobra - 2].x > cobra[tamanho_cobra - 1].x){
          cobra[tamanho_cobra - 1].bitmap = '';
        }
        else
          if(cobra[tamanho_cobra - 2].y > cobra[tamanho_cobra - 1].y){
            cobra[tamanho_cobra - 1].bitmap = '';
          }
          else
            cobra[tamanho_cobra - 1].bitmap = '';

      desenhar_cobra(DESENHAR_COBRA_INTEIRA);
      break;
    case '�'://196
    case '�'://179
    case '�'://192
    case '�'://191
    case '�'://217
    case '�'://218
    case '�'://193
    case '�'://194
    case '�'://195
    case '�'://180
    case '�'://197
    case 'c':
      vidas--;
      velocidade = 500000;
      desenhar_cobra(APAGAR_COBRA_INTEIRA);
      cobra_init(posicao_inicial_x, posicao_inicial_y);
      direcao = direcao_inicial;
      desenhar_cobra(DESENHAR_COBRA_INTEIRA);
      break;
  }
}


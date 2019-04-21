void mover_cobra(){
  char i, proximox, proximoy, proximo_bitmap_cabeca, proximo_bitmap_pescoco;

  switch(direcao){
    case CIMA:
      proximox = cobra[0].x;
      proximoy = cobra[0].y - 1;
      proximo_bitmap_cabeca = '';
      //atualizar bitmap do peco‡o
      if(cobra[1].x > cobra[0].x){
        proximo_bitmap_pescoco = 'È';//200
      }
      else
        if(cobra[1].x < cobra[0].x){
          proximo_bitmap_pescoco = '¼';//188
        }
        else
          proximo_bitmap_pescoco = 'º';//186
      break;
    case BAIXO:
      proximox = cobra[0].x;
      proximoy = cobra[0].y + 1;
      proximo_bitmap_cabeca = '';
      //atualizar bitmap do pesco‡o
      if(cobra[1].x < cobra[0].x){
        proximo_bitmap_pescoco = '»';//187
      }
      else
        if(cobra[1].x > cobra[0].x){
          proximo_bitmap_pescoco = 'É';//201
        }
        else
          proximo_bitmap_pescoco = 'º';
      break;
    case ESQUERDA:
      proximox = cobra[0].x - 1;
      proximoy = cobra[0].y;
      proximo_bitmap_cabeca = '';
      //atualizar bitmap do pesco‡o
      if(cobra[1].y < cobra[0].y){
        proximo_bitmap_pescoco = '¼';//188
      }
      else
        if(cobra[1].y > cobra[0].y){
          proximo_bitmap_pescoco = '»';//187
        }
        else
          proximo_bitmap_pescoco = 'Í';
      break;
    case DIREITA:
      proximox = cobra[0].x + 1;
      proximoy = cobra[0].y;
      proximo_bitmap_cabeca = '';
      //atualizar bitmap do pesco‡o
      if(cobra[1].y < cobra[0].y){
        proximo_bitmap_pescoco = 'È';//200
      }
      else
        if(cobra[1].y > cobra[0].y){
          proximo_bitmap_pescoco = 'É';//201
        }
        else
          proximo_bitmap_pescoco = 'Í';//205
      break;
  }

  switch(tabuleiro[proximox][proximoy]){
    case ' ':
      desenhar_cobra(APAGAR_PEDACO_COBRA);
      
      /*******************************/
      /* atualizar os dados da cobra */
      /*******************************/
      for(i = tamanho_cobra - 1; i >= 2; i--){
        cobra[i] = cobra[i - 1];
      }

      // Atualizar os dados do pesco‡o
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
    case 'm':
      break;
    case 'Ä'://196
    case '³':
    case 'À'://192
    case '¿'://191
    case 'Ù'://217
    case 'Ú'://218
    case 'c':
      vidas--;
      cobra_init(12, 12);
      break;
  }
}

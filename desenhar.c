void desenhar_cobra(char operacao){
  switch(operacao){
    case DESENHAR_PEDACO_COBRA:
      //desenhar a cabe‡a
      switch(cobra[0].bitmap){
        case '': //30
          blit(cabeca_cima, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '': //31
          blit(cabeca_baixo, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '': //17
          blit(cabeca_esquerda, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '': //16
          blit(cabeca_direita, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
      }

      blit(cauda_cima, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32);

      //desenhar a cauda
      switch(cobra[tamanho_cobra - 1].bitmap){
	      case '': //24
  	    	blit(cauda_cima, screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, 32, 32);
    	    break;
      	case '': //25
      		blit(cauda_baixo, screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, 32, 32);
	        break;
  	    case 26: // eu nao posso colocar o caracter por que ele ‚ o EOF, o compilador vai entender que aqui ‚ o fim do c¢digo fonte
    	  	  blit(cauda_direita, screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, 32, 32);
      	  break;
	      case '': //27
  	    	blit(cauda_esquerda, screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, 32, 32);
    	    break;
      }
      break;
      
    case APAGAR_PEDACO_COBRA:
      tabuleiro[cobra[tamanho_cobra - 1].x][cobra[tamanho_cobra - 1].y] = ' ';
      
			blit(chao, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, chao->w, chao->h); //Apagar a cabe‡a
			blit(chao, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, chao->w, chao->h); //Apagar o pesco‡o
      blit(chao, screen, 0, 0, (cobra[tamanho_cobra - 1].x -1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, 32, 32); //apagar o rabo
      break;
      
    case DESENHAR_COBRA_INTEIRA:
    	{
        char i;
        for(i = 0; i <= (tamanho_cobra - 1); i++){
          switch(cobra[i].bitmap){
            case '':
              blit(cabeca_cima, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(cabeca_baixo, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(cabeca_esquerda, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(cabeca_direita, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;

            case '':
              blit(cauda_esquerda, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case 26: // eu nÆo coloquei o caracter aqui pelos motivos j  descritos acima.
              blit(cauda_direita, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(cauda_cima, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(cauda_baixo, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;

            case 'Í':
              blit(vertebra_horizontal, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case 'º':
              blit(vertebra_vertical, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
              
            case 'É':
              blit(vertebra_inferior_direita, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '»':
              blit(vertebra_inferior_esquerda, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case 'È':
              blit(vertebra_superior_direita, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '¼':
              blit(vertebra_superior_esquerda, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
          }
        };
      };
      break;
      
    case DESENHAR_CABECA:
      //cabeca
      switch(cobra[0].bitmap){
        case '':
          blit(cabeca_cima, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '':          
          blit(cabeca_baixo, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '':
          blit(cabeca_esquerda, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '':
          blit(cabeca_direita, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
      }
      switch(cobra[1].bitmap){
        case 'È':
          blit(vertebra_superior_direita, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32);
          break;
        case 'É':
          blit(vertebra_inferior_direita, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32);
          break;
        case '»':
          blit(vertebra_inferior_esquerda, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32);
          break;
        case '¼':
          blit(vertebra_superior_esquerda, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32);
          break;
        case 'º':
          blit(vertebra_vertical, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32);
          break;
        case 'Í':
          blit(vertebra_horizontal, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32);
          break;
      }
      break;

    case APAGAR_COBRA_INTEIRA:
      {
        char i;
        for(i = 0; i <= (tamanho_cobra - 1); i++){
          blit(chao, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
        }
      };
      break;
  }
}

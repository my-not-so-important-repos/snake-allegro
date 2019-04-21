void desenhar_cobra(char operacao){
  switch(operacao){
    case DESENHAR_PEDACO_COBRA:
      //desenhar a cabeca
      tabuleiro[cobra[0].x][cobra[0].y] = 'c';
      switch(cobra[0].bitmap){
        case '': //30
          blit(skin[CABECA_CIMA - 1], screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '': //31
          blit(skin[CABECA_BAIXO - 1], screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '': //17
          blit(skin[CABECA_ESQUERDA - 1], screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '': //16
          blit(skin[CABECA_DIREITA - 1], screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
      }

      //desenhar a cauda
      tabuleiro[cobra[tamanho_cobra - 1].x][cobra[tamanho_cobra - 1].y] = 'c';
      switch(cobra[tamanho_cobra - 1].bitmap){
	      case '': //24
  	    	blit(skin[RABO_CIMA - 1], screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, 32, 32);
    	    break;
      	case '': //25
      		blit(skin[RABO_BAIXO - 1], screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, 32, 32);
	        break;
  	    case 26: // nao posso colocar o caracter porque o compilador vai pensar que aqui eh o fim do codigo fonte
    	  	  blit(skin[RABO_DIREITA - 1], screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, 32, 32);
      	  break;
	      case '': //27
  	    	blit(skin[RABO_ESQUERDA - 1], screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, 32, 32);
    	    break;
      }
      break;
      
    case APAGAR_PEDACO_COBRA:
      tabuleiro[cobra[tamanho_cobra - 1].x][cobra[tamanho_cobra - 1].y] = ' ';
      
			blit(skin[VAZIO - 1], screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32); //Apagar a cabe‡a
			blit(skin[VAZIO - 1], screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32); //Apagar o pesco‡o
      blit(skin[VAZIO - 1], screen, 0, 0, (cobra[tamanho_cobra - 1].x -1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, 32, 32); //apagar o rabo
      break;
      
    case DESENHAR_COBRA_INTEIRA:
    	{
        char i;
        for(i = 0; i <= (tamanho_cobra - 1); i++)
        {
          tabuleiro[cobra[i].x][cobra[i].y] = 'c';
          switch(cobra[i].bitmap)
          {
            case '':
              blit(skin[CABECA_CIMA - 1], screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(skin[CABECA_BAIXO - 1], screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(skin[CABECA_ESQUERDA - 1], screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(skin[CABECA_DIREITA - 1], screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;

            case '':
              blit(skin[RABO_ESQUERDA - 1], screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case 26: // nao coloquei o caracter aqui pelos motivos ja citados acima.
              blit(skin[RABO_DIREITA - 1], screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(skin[RABO_CIMA - 1], screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(skin[RABO_BAIXO - 1], screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
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
          } // switch(cobra[i].bitmap)
        } // for(i = 0; i <= (tamanho_cobra - 1); i++)
      }
      break;
      
    case DESENHAR_CABECA:
      tabuleiro[cobra[0].x][cobra[0].y] = 'c';
      switch(cobra[0].bitmap){
        case '':
          blit(skin[CABECA_CIMA - 1], screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '':          
          blit(skin[CABECA_BAIXO - 1], screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '':
          blit(skin[CABECA_ESQUERDA - 1], screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '':
          blit(skin[CABECA_DIREITA - 1], screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
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
          tabuleiro[cobra[i].x][cobra[i].y] = ' ';
          blit(skin[VAZIO - 1], screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
        }
      };
      break;
  }
}


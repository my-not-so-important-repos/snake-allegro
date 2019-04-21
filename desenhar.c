void desenhar_cobra(char operacao){
  switch(operacao){
    case DESENHAR_PEDACO_COBRA:
      //desenhar a cabe‡a
      switch(cobra[0].bitmap){
        case '': //30
          blit(cabecacima, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '': //31
          blit(cabecabaixo, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '': //17
          blit(cabecaesquerda, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '': //16
          blit(cabecadireita, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
      }

      blit(caudacima, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32);

      //desenhar a cauda
      switch(cobra[tamanho_cobra - 1].bitmap){
	      case '': //24
  	    	blit(caudacima, screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, 32, 32);
    	    break;
      	case '': //25
      		blit(caudabaixo, screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, 32, 32);
	        break;
  	    case 26: // eu nao posso colocar o caracter por que ele ‚ o EOF, o compilador vai entender que aqui ‚ o fim do c¢digo fonte
    	  	  blit(caudadireita, screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, 32, 32);
      	  break;
	      case '': //27
  	    	blit(caudaesquerda, screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, 32, 32);
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
              blit(cabecacima, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(cabecabaixo, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(cabecaesquerda, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(cabecadireita, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;

            case '':
              blit(caudaesquerda, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case 26: // eu nÆo coloquei o caracter aqui pelos motivos j  descritos acima.
              blit(caudadireita, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(caudacima, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(caudabaixo, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;

            case 'Í':
              blit(vertebrahorizontal, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case 'º':
              blit(vertebravertical, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
              
            case 'É':
              blit(vertebrainferiordireita, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '»':
              blit(vertebrainferioresquerda, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case 'È':
              blit(vertebrasuperiordireita, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '¼':
              blit(vertebrasuperioresquerda, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
          }
        };
      };
      break;
      
    case DESENHAR_CABECA:
      //cabeca
      switch(cobra[0].bitmap){
        case '':
          blit(cabecacima, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '':          
          blit(cabecabaixo, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '':
          blit(cabecaesquerda, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
        case '':
          blit(cabecadireita, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
          break;
      }
      switch(cobra[1].bitmap){
        case 'È':
          blit(vertebrasuperiordireita, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32);
          break;
        case 'É':
          blit(vertebrainferiordireita, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32);
          break;
        case '»':
          blit(vertebrainferioresquerda, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32);
          break;
        case '¼':
          blit(vertebrasuperioresquerda, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32);
          break;
        case 'º':
          blit(vertebravertical, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32);
          break;
        case 'Í':
          blit(vertebrahorizontal, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32);
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

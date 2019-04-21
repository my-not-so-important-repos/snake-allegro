void desenhar_tabuleiro(){
  char x, y;
  
  for(y = 1; y <= 24; y++){
    for(x = 1; x <= 27; x++){
      switch(tabuleiro[x][y]){
        case '�'://197
          blit(parede_cruz, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
        case '�':
          blit(parede_vertical, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
        case '�':
          blit(parede_horizontal, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
          
        case '�'://194
          blit(parede_t_baixo, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
        case '�':
          blit(parede_t_cima, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
        case '�'://180
          blit(parede_t_esquerda, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
        case '�'://195
          blit(parede_t_direita, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;


        case '�':
          blit(parede_superior_direita, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
          
        case '�':
          blit(parede_inferior_direita, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
          
        case '�':
          blit(parede_inferior_esquerda, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
        case '�':
          blit(parede_superior_esquerda, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
        case ' ':
          blit(chao, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
      }

    }
  }
}

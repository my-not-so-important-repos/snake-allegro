void desenhar_tabuleiro(board &tabuleiro){
  acquire_screen();
  for(int y = 1; y <= 24; y++)
  {
    for(int x = 1; x <= 27; x++)
    {

      /*
      // #defeito# codigo semi-funcional
      if(tabuleiro[x][y] <= 12)
      {
        blit(skin[tabuleiro[x][y]], screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
      }
      */





      switch(tabuleiro[x][y])
      {
        case 'Å'://197
          blit(skin[CRUZ - 1], screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
        case '³':
          blit(skin[VERTICAL - 1], screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
        case 'Ä':
          blit(skin[HORIZONTAL - 1], screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
          
        case 'Â'://194
          blit(skin[T_BAIXO - 1], screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
        case 'Á':
          blit(skin[T_CIMA - 1], screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
        case '´'://180
          blit(skin[T_ESQUERDA - 1], screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
        case 'Ã'://195
          blit(skin[T_DIREITA - 1], screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;


        case 'À':
          blit(skin[CANTO_INFERIOR_ESQUERDO - 1], screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
          
        case 'Ú':
          blit(skin[CANTO_SUPERIOR_ESQUERDO - 1], screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
          
        case '¿':
          blit(skin[CANTO_SUPERIOR_DIREITO - 1], screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
        case 'Ù':
          blit(skin[CANTO_INFERIOR_DIREITO - 1], screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
        case ' ':
        case 'Û':
          blit(skin[VAZIO - 1], screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
      }

    }
  }
  release_screen();
}

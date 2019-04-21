void desenhar_cobra(char operacao)
{
  acquire_screen();
  switch(operacao){
    case DESENHAR_PEDACO_COBRA:
      //desenhar a cabeca
      tabuleiro[cobra[0].x][cobra[0].y] = 'c';
      blit(skin[cobra[0].bitmap - 65], screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);

      //desenhar a cauda
      tabuleiro[cobra[tamanho_cobra - 65].x][cobra[tamanho_cobra - 1].y] = 'c';
      blit(skin[cobra[tamanho_cobra - 1].bitmap - 65], screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, 32, 32);

    case APAGAR_PEDACO_COBRA:
      tabuleiro[cobra[tamanho_cobra - 1].x][cobra[tamanho_cobra - 1].y] = VAZIO;

			blit(skin[VAZIO - 65], screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32); //Apagar a cabe‡a
			blit(skin[VAZIO - 65], screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32); //Apagar o pesco‡o
      blit(skin[VAZIO - 65], screen, 0, 0, (cobra[tamanho_cobra - 1].x -1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, 32, 32); //apagar o rabo
      break;
      
    case DESENHAR_COBRA_INTEIRA:
      for(int i = 0; i <= (tamanho_cobra - 1); i++)
      {
        tabuleiro[cobra[i].x][cobra[i].y] = 'c';
        blit(skin[cobra[i].bitmap - 65], screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
      }
      break;
      
    case DESENHAR_CABECA:
      tabuleiro[cobra[0].x][cobra[0].y] = 'c';
      blit(skin[cobra[0].bitmap - 65], screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, 32, 32);
      blit(skin[cobra[1].bitmap - 65], screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, 32, 32);
      break;

    case APAGAR_COBRA_INTEIRA:
      for(int i = 0; i <= (tamanho_cobra - 1); i++)
      {
        tabuleiro[cobra[i].x][cobra[i].y] = VAZIO;
        blit(skin[VAZIO - 65], screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
      }
      break;
  }
  release_screen();
}

inline void menu_abertura()
{
  BITMAP *abertura;
  abertura = load_bitmap("abert3.bmp", NULL);
  blit(abertura, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
  readkey();
  destroy_bitmap(abertura);
}

inline void desenhar_painel()
{
  BITMAP *painel;
  painel = load_bmp("right.bmp", NULL);
  blit(painel, screen, 0, 0, 864, 0, painel->w, painel->h);
  destroy_bitmap(painel);
}

inline void desenhar_tabuleiro(board &tabuleiro)
{
  acquire_screen();
  for(int y = 1; y <= 24; y++)
  {
    for(int x = 1; x <= 27; x++)
    {
      if (tabuleiro[x][y] != RESERVADO)
      {
        blit(skin[tabuleiro[x][y] - 65], screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
      }
      else
      {
        blit(skin[VAZIO - 65], screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
      }
    } // for(int x = 1; x <= 27; x++)
  } // for(int y = 1; y <= 24; y++)
  release_screen();
}


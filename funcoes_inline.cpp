inline void sorteia_maca()
{
  int x_maca, y_maca;
  do
  {
    x_maca = (rand() % 25) + 2; //2 <= x <= 26
    y_maca = (rand() % 22) + 2; //2 <= y <= 23
  } while((tabuleiro[x_maca][y_maca] != VAZIO));
  tabuleiro[x_maca][y_maca] = MACA;
  blit(skin[MACA - 65], screen, 0, 0, (x_maca - 1) * 32, (y_maca - 1) * 32, 32, 32);
  tem_maca = true;
}

inline void processar_entrada_dados()
{
  if(keypressed())
  {
    int tecla;
    while(keypressed())
    {
      tecla = readkey();
    }

    switch(tecla >> 8)
    {
      case KEY_UP:
        if(direcao != BAIXO)
        {
          direcao = tecla >> 8;
        }
        break;
      case KEY_DOWN:
        if(direcao != CIMA)
        {
          direcao = tecla >> 8;
        }
        break;
      case KEY_RIGHT:
        if(direcao != ESQUERDA)
        {
          direcao = tecla >> 8;
        }
        break;
      case KEY_LEFT:
        if(direcao != DIREITA)
        {
          direcao = tecla >> 8;
        }
        break;
      case KEY_ESC:
        vidas = 0;
        break;
      case KEY_A:
        save_bmp("snapshot.bmp", screen, NULL);
        break;
    } // switch(tecla >> 8)
  } // if(keypressed())
}

inline void finalizar_tudo()
{
  for(int i = 0; i < 27; i++)
  {
    destroy_bitmap(skin[i]);
  }

  destroy_midi(fundo_musical);
}


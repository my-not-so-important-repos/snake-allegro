#include <allegro.h>

#include "global.c"
#include "ini_bitm.c"
#include "dese_tab.c"
#include "carr_tab.c"
#include "ini_cobr.c"
#include "desenhar.c"
#include "mover.c"

void menu_abertura()
{
  BITMAP *abertura;
  abertura = load_bitmap("abert2.bmp", NULL);
  stretch_blit(abertura, screen, 0, 0, abertura->w, abertura->h, 0, 0, SCREEN_W, SCREEN_H);
  readkey();
  destroy_bitmap(abertura);
}

void sorteia_maca()
{
  int x_maca, y_maca;
  do
  {
    x_maca = (rand() % 25) + 2; //2 <= x <= 26
    y_maca = (rand() % 22) + 2; //2 <= y <= 23
  } while((tabuleiro[x_maca][y_maca] != ' '));
  tabuleiro[x_maca][y_maca] = 'm';
  blit(skin[MACA - 1], screen, 0, 0, (x_maca - 1) * 32, (y_maca - 1) * 32, 32, 32);
  tem_maca = true;
}

int main()
{
  int tecla;
  MIDI *fundo_musical;

  allegro_init();
  install_keyboard();
  install_timer();
  install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);

  set_color_depth(16);
  set_gfx_mode(GFX_AUTODETECT, 1024, 768, 0, 0);

  menu_abertura();

  fundo_musical = load_midi("Anything_But_Tangerines.mid");
  play_midi(fundo_musical, true);

  bitmaps_init("chip2.bmp");

  carregar_tabuleiro("board.map", tabuleiro);

  desenhar_tabuleiro(tabuleiro);


  //Essa funcao inicializa o tamanho e a posicao da cobra
  cobra_init(posicao_inicial_x, posicao_inicial_y);
  direcao = direcao_inicial;
  vidas = 3;
  velocidade = VELOCIDADE_INICIAL;
  srand(time(NULL));






  while(vidas > 0)
  {


    if(keypressed())
    {
      while(keypressed())
      {
        tecla = readkey();
      };

      switch(tecla >> 8)
      {
        case KEY_UP:
          if(direcao != BAIXO){
            direcao = tecla >> 8;
          }
          break;
        case KEY_DOWN:
          if(direcao != CIMA){
            direcao = tecla >> 8;
          }
          break;
        case KEY_RIGHT:
          if(direcao != ESQUERDA){
            direcao = tecla >> 8;
          }
          break;
        case KEY_LEFT:
          if(direcao != DIREITA){
            direcao = tecla >> 8;
          }
          break;
        case KEY_ESC:
          vidas = 0;
          break;
        case KEY_A:
          save_pcx("snap.pcx", screen, NULL);
          break;
      } // switch(tecla >> 8)
    } // if(keypressed())





    mover_cobra();



    if(!tem_maca)
    {
      sorteia_maca();
    }


    rest(velocidade);



  } // while(vidas > 0)












  for(int i = 0; i < 27; i++)
  {
    destroy_bitmap(skin[i]);
  }

  destroy_bitmap(parede_t_direita);
  destroy_bitmap(parede_t_esquerda);
  destroy_bitmap(parede_t_cima);
  destroy_bitmap(parede_t_baixo);
  destroy_bitmap(cauda_esquerda);
  destroy_bitmap(cauda_direita);
  destroy_bitmap(cauda_baixo);
  destroy_bitmap(parede_horizontal);
  destroy_bitmap(parede_vertical);
  destroy_bitmap(parede_superior_direita);
  destroy_bitmap(parede_superior_esquerda);
  destroy_bitmap(parede_inferior_direita);
  destroy_bitmap(parede_inferior_esquerda);
  destroy_bitmap(vertebra_horizontal);
  destroy_bitmap(vertebra_vertical);

  destroy_midi(fundo_musical);

  allegro_exit();
  return 0;
}
END_OF_MAIN()

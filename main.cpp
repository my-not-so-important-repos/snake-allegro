#include <stdio.h>
#include <allegro.h>

#include "global.c"
#include "load_tab.cpp"
#include "init_bitmap.cpp"
#include "cobra_init.c"
#include "funcoes_desenho.c"
#include "mover.c"
#include "funcoes_inline.cpp"



int main()
{
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
  
  carregar_tabuleiro("teste.map", tabuleiro);

  desenhar_tabuleiro(tabuleiro);

  //Essa funcao inicializa o tamanho e a posicao da cobra
  cobra_init(posicao_inicial_x, posicao_inicial_y);

  direcao = direcao_inicial;
  vidas = 3;
  velocidade = VELOCIDADE_INICIAL;
  srand(time(NULL));
  desenhar_painel();
  textprintf(screen, font, 900, 88, makecol(255, 255, 255), "%d", vidas);
  textprintf(screen, font, 900, 120, makecol(255, 255, 255), "%d", pontos);
  textprintf(screen, font, 900, 152, makecol(255, 255, 255), "%d", velocidade);
  
  tem_maca = false;
  while(vidas > 0)
  {
    processar_entrada_dados();

    mover_cobra();

    if(!tem_maca)
    {
      sorteia_maca();
    }

    rest(velocidade);
  } // while(vidas > 0)

  finalizar_tudo();
  allegro_exit();
  return 0;
}
END_OF_MAIN() // nao tem ponto e virgula no final

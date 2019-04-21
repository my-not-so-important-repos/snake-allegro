//-----------------------------------------------------------
/*              Snake: Wings Of The Dreams                 */
/*                                  0.15.2                 */
/*  Codigo:                                                */
/*    Heitor Adao Junior                                   */
/*    Diego Venturi Dalpiaz                                */
/*  Imagens:                                               */
/*    Diego Venturi Dalpiaz (chipset)                      */
/*    Luiz Royo (abertura)                                 */
/*  Outras pessoas que ajudaram, mesmo que indiretamente:  */
/*    Andre A. Raabe (a logica)                            */
/*    Shawn Hargreaves (desenvolvedor da lib Allegro)      */
/*    Fernando Vicente de Oliveira - MaD (a ideia de       */
/*                             colocar em varios arquivos) */
/*                                                         */
/*  Data da ultima modificacao: 08/07/2004                 */
//-----------------------------------------------------------

#include <allegro.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Aqui est? definida as constantes usadas neste jogo
#include "const.c"

int main(void);
void carregar_tabuleiro(void);
void bitmaps_init(void);
void mover_cobra(void);
void desenhar_cobra(char);
void cobra_init(char, char);
void desenhar_tabuleiro(void);


char tabuleiro[28][25], tamanho_cobra, direcao, vidas,
     posicao_inicial_x, posicao_inicial_y, direcao_inicial,
     tem_maca, x_maca, y_maca;
unsigned int pontos, velocidade;
//long velocidade;
BITMAP *chao, *parede_cruz, *parede_horizontal, *parede_vertical,
       *parede_inferior_direita, *parede_inferior_esquerda, *parede_superior_direita, *parede_superior_esquerda,
       *parede_t_baixo, *parede_t_cima, *parede_t_direita, *parede_t_esquerda,
       *cabeca_cima, *cabeca_baixo, *cabeca_esquerda, *cabeca_direita,
       *cauda_cima, *cauda_baixo, *cauda_esquerda, *cauda_direita,
       *vertebra_inferior_direita, *vertebra_inferior_esquerda, *vertebra_superior_direita, *vertebra_superior_esquerda,
       *vertebra_horizontal, *vertebra_vertical, *maca;

struct vertebra{
  char x, y, bitmap;
} cobra[MAX_COBRA];


int main(){
  int tecla;

  /******************************/
  /* Inicializacao da variaveis */
  /******************************/
  allegro_init();
  install_keyboard();
  install_timer();

  set_gfx_mode(GFX_AUTODETECT, 1024, 768, 0, 0); //tamb?m podia ser GFX_SAFE

  //
  // Carregar a imagem de abertura
  //
  {
    BITMAP *abertura;
    PALETTE paleta;

    abertura = load_bitmap("abert.bmp", paleta);
    set_palette(paleta);

    blit(abertura, screen, 0, 0, (SCREEN_W-abertura->w)/2, (SCREEN_H-abertura->h)/2, abertura->w, abertura->h);
    readkey();
    destroy_bitmap(abertura);
  }



  //Carrega os tiles para cada bitmap
  bitmaps_init();

  rectfill(screen, 864, 0, 1023, 767, makecol(0,0,0));
  text_mode(-1);

  textprintf(screen, font, 864, 719, makecol(200,200,200), "Desevolvido por:");
  textprintf(screen, font, 864, 735, makecol(255,255,255), "Heitor Adao Junior e");
  textprintf(screen, font, 864, 751, makecol(255,255,255), "Diego Venturi");
  textprintf(screen, font, 864, 759, makecol(255,255,255), "Dalpiaz");

  //Esta funcao abre o arquivo ".map" e grava na matriz tabuleiro
  carregar_tabuleiro();


  desenhar_tabuleiro();


  //Essa funcao inicializa o tamanho e a posicao da cobra
  cobra_init(posicao_inicial_x, posicao_inicial_y);
  direcao = direcao_inicial;
  vidas = 3;
  tem_maca = 0;
  pontos = 0;
  velocidade = VELOCIDADE_INICIAL;
  srand(time(NULL));


  /****************************/
  /* Inicio do loop principal */
  /****************************/
  while(vidas){

    // Colocar as macas
    if(!tem_maca){
      do{
        x_maca = (int) fmod(rand(), 25) + 2; //2 <= x <= 26
        y_maca = (int) fmod(rand(), 22) + 2; //2 <= y <= 23
      } while((x_maca >= 27) || (x_maca <= 1) || (y_maca >= 24) || (y_maca <= 1) || (tabuleiro[x_maca][y_maca] != ' '));
      tabuleiro[x_maca][y_maca] = 'm';
      blit(maca, screen, 0, 0, (x_maca - 1) * 32, (y_maca - 1) * 32, 32, 32);
      tem_maca = 1;
    };
    mover_cobra();

    rectfill(screen, 864, 0, 1023, 40, makecol(0,0,0));
    textprintf(screen, font, 864,  0, makecol(255,255,255), "Vidas: %d", vidas);
    textprintf(screen, font, 864,  16, makecol(255,255,255), "Pontos: %d", pontos);
    textprintf(screen, font, 864, 32, makecol(255,255,255), "Delay: %d", velocidade);

   rest(velocidade);

    if(keypressed()){
      while(keypressed()){
        tecla = readkey();
      };

      switch(tecla>>8){
        case KEY_UP:
          if(direcao != BAIXO){
            direcao = tecla>>8;
          }
        break;
        case KEY_DOWN:
          if(direcao != CIMA){
            direcao = tecla>>8;
          }
        break;
        case KEY_RIGHT:
          if(direcao != ESQUERDA){
            direcao = tecla>>8;
          }
        break;
        case KEY_LEFT:
          if(direcao != DIREITA){
            direcao = tecla>>8;
          }
        break;
        case KEY_ESC:
          vidas = 0;
        break;

        case KEY_A:
          save_pcx("snap.pcx", screen, NULL);
        break;


      }
    }
  }

  destroy_bitmap(parede_t_direita);
  destroy_bitmap(parede_t_esquerda);
  destroy_bitmap(parede_t_cima);
  destroy_bitmap(parede_t_baixo);

  destroy_bitmap(cabeca_cima);
  destroy_bitmap(cabeca_baixo);
  destroy_bitmap(cabeca_esquerda);
  destroy_bitmap(cabeca_direita);

  destroy_bitmap(cauda_esquerda);
  destroy_bitmap(cauda_direita);
  destroy_bitmap(cauda_cima);
  destroy_bitmap(cauda_baixo);

  destroy_bitmap(parede_horizontal);
  destroy_bitmap(parede_vertical);
  destroy_bitmap(parede_superior_direita);
  destroy_bitmap(parede_superior_esquerda);
  destroy_bitmap(parede_inferior_direita);
  destroy_bitmap(parede_inferior_esquerda);

  destroy_bitmap(vertebra_horizontal);
  destroy_bitmap(vertebra_vertical);

  return(0);
}
END_OF_MAIN();

#include "dese_tab.c"
#include "carr_tab.c"
#include "ini_bitm.c"
#include "ini_cobr.c"
#include "mover.c"
#include "desenhar.c"

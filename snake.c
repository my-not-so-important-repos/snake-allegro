#include <allegro.h>
#include <stdio.h>
#include <unistd.h>
//#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

// Aqui est� definida as constantes usadas neste jogo
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
  /* Inicializa��o da variaveis */
  /******************************/
  allegro_init();
  install_keyboard();
  set_gfx_mode(GFX_AUTODETECT, 1024, 768, 0, 0); //tamb�m podia ser GFX_SAFE

  //Carrega os tiles para cada bitmap
  bitmaps_init();

  //Esta fun��o abre o arquivo ".map" e grava na matriz tabuleiro
  carregar_tabuleiro();


  desenhar_tabuleiro();


  //Essa fun��o inicializa o tamanho e a posi��o da cobra
  cobra_init(posicao_inicial_x, posicao_inicial_y);
  direcao = direcao_inicial;
  vidas = 3;
  tem_maca = 0;
  pontos = 0;
  velocidade = 500000;
  //velocidade = 100000;

  /****************************/
  /* In�cio do loop principal */
  /****************************/
  srand(time(NULL));
  while(vidas){

    /********************/
    /* Colocar as ma��s */
    /********************/
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
    textprintf(screen, font, 864,  0, makecol(255,255,255), "Vidas: %d   ", vidas);
    textprintf(screen, font, 864,  8, makecol(255,255,255), "Pontos: %d   ", pontos);
    textprintf(screen, font, 864, 16, makecol(255,255,255), "Delay: %d   ", velocidade);
    textprintf(screen, font, 864, 64, makecol(255,255,255), "Tecla SC: %d   ", tecla>>8);
    textprintf(screen, font, 864, 72, makecol(255,255,255), "Tecla Asc: %d   ", tecla & 0xFF);
    textprintf(screen, font, 864, 80, makecol(255,255,255), "direcao: %d   ", direcao);

    //sleep(1); //lento
    usleep(velocidade);

    if(keypressed()){
      while(keypressed()){
        tecla = readkey();
      };
      if((tecla>>8 == KEY_UP) || (tecla>>8 == KEY_DOWN) || (tecla>>8 == KEY_LEFT) || (tecla>>8 == KEY_RIGHT)){
        direcao = tecla>>8;
      }
      else
        if((tecla & 0xFF) == ESC){
          vidas = 0;
        };
    }
  }
  return(0);
}
END_OF_MAIN();

#include "dese_tab.c"
#include "carr_tab.c"
#include "ini_bitm.c"
#include "ini_cobr.c"
#include "mover.c"
#include "desenhar.c"

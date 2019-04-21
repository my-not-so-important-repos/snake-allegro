#include <allegro.h>
#include <stdio.h>
#include <unistd.h>
#include <conio.h>

// Aqui est† definida as constantes usadas neste jogo
#include "const.c"

int main(void);
void carregar_tabuleiro(void);
void bitmaps_init(void);
void mover_cobra(void);
void desenhar_cobra(char);
void cobra_init(char, char);
void desenhar_tabuleiro(void);

char tabuleiro[33][23], tamanho_cobra, direcao, vidas;
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
  char tecla;

  /******************************/
  /* Inicializaá∆o da variaveis */
  /******************************/
  allegro_init();
  //set_gfx_mode(GFX_SAFE, 1024, 768, 0, 0);
  set_gfx_mode(GFX_AUTODETECT, 1024, 768, 0, 0);

  //Carrega os tiles para cada bitmap
  bitmaps_init();

  //Esta funá∆o abre o arquivo ".map" e grava na matriz tabuleiro
  carregar_tabuleiro();


  desenhar_tabuleiro();


  //Essa funá∆o inicializa o tamanho e a posiá∆o da cobra
  cobra_init(12,12);
  vidas = 3;

  /****************************/
  /* In°cio do loop principal */
  /****************************/

  while(vidas){
    mover_cobra();

    sleep(1); //lento
    
    while(kbhit()){
      tecla = getch();
      if(tecla == 0) tecla = getch(); //se a tecla pressionada for extendida, ler o sengundo caracter no buffer do teclado
    }

    if(((tecla == CIMA) || (tecla == BAIXO) || (tecla == DIREITA) || (tecla == ESQUERDA)) && ((tecla + direcao) != 152)){
      direcao = tecla;
      tecla = 0;//este comando serve para que o programa n∆o fique passando por aqui toda hora
    }
    else
      if(tecla == ESC){
        vidas = 0;
      };
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

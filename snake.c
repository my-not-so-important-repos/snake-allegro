#include <allegro.h>
#include <stdio.h>
#include <unistd.h>
#include <conio.h>

// Aqui est  definida todas as constantes usadas neste jogo
#include "const.c"

int main(void);
void mover_cobra(void);
void desenhar_cobra(char);
void cobra_init(char, char);

char tabuleiro[33][23], tamanho_cobra, direcao, vidas;
BITMAP *chao, *parede, *maca,
       *cabecacima, *cabecabaixo, *cabecaesquerda, *cabecadireita,
       *caudacima, *caudabaixo, *caudaesquerda, *caudadireita,
       *vertebrahorizontal, *vertebravertical,
       *vertebrasuperiordireita, *vertebrasuperioresquerda,
       *vertebrainferiordireita, *vertebrainferioresquerda;
struct vertebra{
  char x, y, bitmap;
} cobra[MAX_COBRA];



int main(){
  char temp[40], x, y, tecla;
  int i;
  BITMAP *chipset;
  PALETTE paleta;
  FILE *tabuleiro_arq;

  /******************************/
  /* Inicializa‡Æo da variaveis */
  /******************************/
  allegro_init();
  //set_gfx_mode(GFX_SAFE, 1024, 768, 0, 0);
  set_gfx_mode(GFX_AUTODETECT, 1024, 768, 0, 0);
  chipset = load_bitmap("chip1.bmp", paleta);
  set_palette(paleta);

  /*****************/
  /* Criar bitmaps */
  /*****************/
  chao                     = create_bitmap(32, 32);
  parede                   = create_bitmap(32, 32);
  maca                     = create_bitmap(32, 32);

  cabecacima               = create_bitmap(32, 32);
  cabecadireita            = create_bitmap(32, 32);
  cabecabaixo              = create_bitmap(32, 32);
  cabecaesquerda           = create_bitmap(32, 32);

  caudacima                = create_bitmap(32, 32);
  caudadireita             = create_bitmap(32, 32);
  caudabaixo               = create_bitmap(32, 32);
  caudaesquerda            = create_bitmap(32, 32);

  vertebrasuperioresquerda = create_bitmap(32, 32);
  vertebrasuperiordireita  = create_bitmap(32, 32);
  vertebrainferiordireita  = create_bitmap(32, 32);
  vertebrainferioresquerda = create_bitmap(32, 32);
  vertebrahorizontal       = create_bitmap(32, 32);
  vertebravertical         = create_bitmap(32, 32);

  /************************/
  /* Preencher os bitmaps */
  /************************/
  blit(chipset, chao,  96,  0, 0, 0, 32, 32);
  blit(chipset, parede, 0,  0, 0, 0, 32, 32);
  blit(chipset, maca,  28, 32, 0, 0, 32, 32);

  blit(chipset, cabecacima,      0, 64, 0, 0, 32, 32);
  blit(chipset, cabecadireita,  32, 64, 0, 0, 32, 32);
  blit(chipset, cabecabaixo,    64, 64, 0, 0, 32, 32);
  blit(chipset, cabecaesquerda, 96, 64, 0, 0, 32, 32);

  blit(chipset, caudabaixo,     0, 96, 0, 0, 32, 32);
  blit(chipset, caudaesquerda, 32, 96, 0, 0, 32, 32);
  blit(chipset, caudacima,     64, 96, 0, 0, 32, 32);
  blit(chipset, caudadireita,  96, 96, 0, 0, 32, 32);

  blit(chipset, vertebrasuperioresquerda,  0, 32, 0, 0, 32, 32);
  blit(chipset, vertebrasuperiordireita,  32, 32, 0, 0, 32, 32);
  blit(chipset, vertebrainferiordireita,  64, 32, 0, 0, 32, 32);
  blit(chipset, vertebrainferioresquerda, 96, 32, 0, 0, 32, 32);
  blit(chipset, vertebrahorizontal,      128, 96, 0, 0, 32, 32);
  blit(chipset, vertebravertical,        128, 64, 0, 0, 32, 32);

  destroy_bitmap(chipset); // para liberar mem¢ria



  tamanho_cobra = 7;
  cobra[0].x = 12;
  cobra[0].y = 12;
  cobra[0].bitmap = '';

  cobra[1].x = 11;
  cobra[1].y = 12;
  cobra[1].bitmap = 'Í';

  cobra[2].x = 10;
  cobra[2].y = 12;
  cobra[2].bitmap = 'Í';

  cobra[3].x = 9;
  cobra[3].y = 12;
  cobra[3].bitmap = 'Í';

  cobra[4].x = 8;
  cobra[4].y = 12;
  cobra[4].bitmap = 'Í';

  cobra[5].x = 7;
  cobra[5].y = 12;
  cobra[5].bitmap = 'Í';

  cobra[6].x = 6;
  cobra[6].y = 12;
  cobra[6].bitmap = '';

  vidas = 3;
  direcao = DIREITA;

  /*************************/
  /* Inicializar Tabuleiro */
  /*************************/

  //Abrir o arquivo que cont‚m as informa‡äes do tabuleiro
  tabuleiro_arq = fopen("board.map", "r");

  y = 0;
  while(!feof(tabuleiro_arq)){
    y++;
    fgets(temp, 34, tabuleiro_arq);
    for(x=0; x<=32; x++){
    	switch(temp[x]){
        case '³':
        case 'Ä':
        case 'Ú':
        case 'À':
        case '¿':
        case 'Ù':
        case ' ':
          tabuleiro[x+1][y] = temp[x];
          break;
      }
    }
  }

  /******************************/
  /* Desenhar tabuleiro na tela */
  /******************************/
  for(y = 1; y <= 23; y++){
    for(x = 1; x <= 32; x++){
      switch(tabuleiro[x][y]){
        case 'Ú':
        case 'À':
        case '¿':
        case 'Ù':
        case '³':
        case 'Ä':
          blit(parede, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
        case ' ':
          blit(chao, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, 32, 32);
          break;
      }
    }
  }

  /****************************/
  /* In¡cio do loop principal */
  /****************************/

  while(vidas){
    mover_cobra();

    sleep(1); //lento

    while(kbhit()){
      tecla = getch();
      if(tecla == 0) tecla = getch(); //se a tecla pressionada for extendida, ler o sengundo caracter no buffer do teclado
    }

		switch(tecla){
      case CIMA:
      case BAIXO:
      case DIREITA:
      case ESQUERDA:
        if((direcao + tecla) != 152){ //a soma das setas opostas ‚ igual a 152
	      	direcao = tecla;
        }
        break;
      case ESC:
      case 'q':
        vidas = 0;
        break;
    }
  }
  return(0);
}
END_OF_MAIN();



//-------------------------------------------------
#include "ini_cobr.c"
//-------------------------------------------------

//-------------------------------------------------
#include "mover.c"
//-------------------------------------------------

//-------------------------------------------------
#include "desenhar.c"
//-------------------------------------------------

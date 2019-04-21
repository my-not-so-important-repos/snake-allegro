#include <allegro.h>
#include <stdio.h>
#include <conio.h>

#define MAX_COBRA 100

#define CIMA 72
#define BAIXO 80
#define ESQUERDA 75
#define DIREITA 77
#define ESC 27

#define DESENHAR_PEDACO_COBRA 1
#define APAGAR_PEDACO_COBRA 2


int main(void);
void mover_cobra(void);
void desenhar_cobra(char);

char tabuleiro[26][19], x, y, tamanho_cobra, direcao, game_over;
BITMAP *chao, *parede, *maca, *spider,
       *cabeca, *vertebrahorizontal, *vertebravertical, *cauda,
       *vertebrasuperiordireita, *vertebrasuperioresquerda,
       *vertebrainferiordireita, *vertebrainferioresquerda;
struct vertebra{
  char x, y, bitmap;
} cobra[MAX_COBRA];



int main(){
  char temp[80];
  char tecla;
  int i;
  BITMAP *chipset;
  PALETTE paleta;
  FILE *tabuleiro_arq;

  /******************************/
  /* Inicializa‡Æo da variaveis */
  /******************************/
  allegro_init();
  set_gfx_mode(GFX_SAFE, 1024, 768, 0, 0);
  chipset = load_bitmap("chip1.bmp", paleta);
  set_palette(paleta);
  
  chao   = create_bitmap(32, 32);
  parede = create_bitmap(32, 32);
  maca   = create_bitmap(32, 32);
  spider = create_bitmap(32, 32);

  blit(chipset, parede,   0, 0, 0, 0, 32, 32);
  blit(chipset,   chao,  96, 0, 0, 0, 32, 32);
  blit(chipset, spider, 128, 0, 0, 0, 32, 32);

  tamanho_cobra = 3;
  cobra[0].x = 12;
  cobra[0].y = 12;
  
  cobra[1].x = 11;
  cobra[1].y = 12;
  
  cobra[2].x = 10;
  cobra[2].y = 12;

  game_over = 0;
  direcao = DIREITA;
  
  /************************************************************************/
  /* fazer uma condi‡Æo que verifica se o usuario digitou um parƒmetro ao */
  /* executar esse jogo, se sim, entƒo carregar o arquivo com o nome      */
  /* do parƒmetro, caso contr rio, carregar o tabuleiro padrÆo.           */
  /************************************************************************/
  tabuleiro_arq = fopen("board.dat", "r");

  /*************************/
  /* Inicializar Tabuleiro */
  /*************************/
  y = 0;
  while(!feof(tabuleiro_arq)){
    y++;
    fgets(temp, 27, tabuleiro_arq);
    for(x=0; x<=25; x++){
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
  for(y = 1; y <= 18; y++){
    for(x = 1; x <= 25; x++){
      switch(tabuleiro[x][y]){
        case 'Ú':
        case 'À':
        case '¿':
        case 'Ù':
        case '³':
        case 'Ä':
          blit(parede, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, parede->w, parede->h);
          break;
        case ' ':
          blit(chao, screen, 0, 0, (x-1) * 32, (y - 1) * 32, parede->w, parede->h);
          break;
      }
    }
  }

  /****************************/
  /* In¡cio do loop principal */
  /****************************/
  while(!game_over){

    mover_cobra();
    sleep(1);
    //usleep(10000000); //muito r pido
    
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
        game_over = 1;
        break;
    }
  }
  return(0);
}
END_OF_MAIN();

void mover_cobra(){
  char i;

  desenhar_cobra(APAGAR_PEDACO_COBRA);

  /*******************************/
  /* atualizar os dados da cobra */
  /*******************************/
  for(i=1; i <= tamanho_cobra - 1; i++){
    cobra[i] = cobra[i - 1];
  }

  /*************************************************/
  /* Atualiza os bitmaps do rabo, pesco‡o e cabe‡a */
  /*************************************************/
	//cobra[tamanho_cobra-1].bitmap = ' ';
	//cobra[1].bitmap = ' ';

  /********************************/
  /* Calcular a posi‡Æo da cabe‡a */
  /********************************/
  switch(direcao){
    case CIMA:
			cobra[0].y = cobra[0].y - 1;
      break;
    case BAIXO:
      cobra[0].y = cobra[0].y + 1;
      break;
    case ESQUERDA:
    	cobra[0].x = cobra[0].x - 1;
      break;
    case DIREITA:
    	cobra[0].x = cobra[0].x + 1;
      break;
  }

  if(tabuleiro[cobra[0].x][cobra[0].y] == ' '){
    desenhar_cobra(DESENHAR_PEDACO_COBRA);
  }
  else game_over = 1;
}



void desenhar_cobra(char operacao){
  switch(operacao){
    case DESENHAR_PEDACO_COBRA:
      //desenhar a cabe‡a
      blit(spider, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, parede->w, parede->h);

      //desenhar o pesco‡o
      blit(spider, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, parede->w, parede->h);

      //desenhar o rabo
      blit(spider, screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, parede->w, parede->h);
      break;
    case APAGAR_PEDACO_COBRA:
			//Apagar a cabe‡a
			blit(chao, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, parede->w, parede->h);

			//Apagar o pesco‡o
			blit(chao, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, parede->w, parede->h);

			//apagar o rabo
      blit(chao, screen, 0, 0, (cobra[tamanho_cobra - 1].x -1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, parede->w, parede->h);

      break;
  }
}

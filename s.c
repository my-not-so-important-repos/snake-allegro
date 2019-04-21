#include <allegro.h>
#include <stdio.h>
#include <unistd.h>
#include <conio.h>
#include <pc.h>

#define MAX_COBRA 100

#define CIMA 72
#define BAIXO 80
#define ESQUERDA 75
#define DIREITA 77
#define ESC 27

#define DESENHAR_PEDACO_COBRA 1
#define APAGAR_PEDACO_COBRA 2
#define DESENHAR_CABECA 3
#define DESENHAR_COBRA_INTEIRA 4
#define APAGAR_COBRA_INTEIRA 5

int main(void);
void mover_cobra(void);
void desenhar_cobra(char);
void cobra_init(int, int);

char tabuleiro[33][23], x, y, tamanho_cobra, direcao, vidas;
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
  char temp[40];
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

  /*****************/
  /* Criar bitmaps */
  /*****************/
  chao										 = create_bitmap(32, 32);
  parede									 = create_bitmap(32, 32);
  maca										 = create_bitmap(32, 32);

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
  vertebrainferiordireita	 = create_bitmap(32, 32);
  vertebrainferioresquerda = create_bitmap(32, 32);
  vertebrahorizontal			 = create_bitmap(32, 32);
  vertebravertical				 = create_bitmap(32, 32);

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
  blit(chipset, vertebravertical,         96, 96, 0, 0, 32, 32);

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

  for(i = 0; i <= tamanho_cobra - 1; i++){
    tabuleiro[cobra[i].x][cobra[i].y] = 'c';
  }

  
  vidas = 3;
  direcao = DIREITA;

  destroy_bitmap(chipset); // para liberar mem¢ria
  
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

    usleep(500000); //lento
    
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








void mover_cobra(){
  char i;

  desenhar_cobra(APAGAR_PEDACO_COBRA);

  /*******************************/
  /* atualizar os dados da cobra */
  /*******************************/
  for(i=tamanho_cobra - 1; i > 0; i--){
    cobra[i] = cobra[i - 1];
  }


  /*****************************************/
  /* Atualiza os bitmaps do rabo e pesco‡o */
  /*****************************************/
	//cobra[tamanho_cobra-1].bitmap = ' ';
	//cobra[1].bitmap = ' ';

  /********************************/
  /* Calcular a posi‡Æo da cabe‡a */
  /********************************/
  switch(direcao){
    case CIMA:
			cobra[0].y--;
			cobra[0].bitmap = ''; //30
      break;
    case BAIXO:
      cobra[0].y++;
      cobra[0].bitmap = ''; //31
      break;
    case ESQUERDA:
			cobra[0].x--;
			cobra[0].bitmap = ''; //17
			break;
    case DIREITA:
			cobra[0].x++;
			cobra[0].bitmap = ''; //16
			break;
  }



  switch(tabuleiro[cobra[0].x][cobra[0].y]){
    case ' ':
      desenhar_cobra(DESENHAR_COBRA_INTEIRA);
      break;
    case 'Ä':
    case '³':
    case 'c':
      vidas--;
      cobra_init(12, 12);
      break;
  }

/*
  
  if(tabuleiro[cobra[0].x][cobra[0].y] == ' '){
    //desenhar_cobra(DESENHAR_PEDACO_COBRA);
    desenhar_cobra(DESENHAR_COBRA_INTEIRA);
  }
  else game_over = 1;
*/
}



void desenhar_cobra(char operacao){

  switch(operacao){
    case DESENHAR_PEDACO_COBRA:
      //desenhar a cabe‡a
      switch(cobra[0].bitmap){
        case '': //30
          blit(cabecacima, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, parede->w, parede->h);
          break;
        case '': //31
          blit(cabecabaixo, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, parede->w, parede->h);
          break;
        case '': //17
          blit(cabecaesquerda, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, parede->w, parede->h);
          break;
        case '': //16
          blit(cabecadireita, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, parede->w, parede->h);
          break;
      }

      blit(caudacima, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, parede->w, parede->h);

      //desenhar a cauda
      switch(cobra[tamanho_cobra - 1].bitmap){
	      case '': //24
  	    	blit(caudacima, screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, parede->w, parede->h);
    	    break;
      	case '': //25
      		blit(caudabaixo, screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, parede->w, parede->h);
	        break;
  	    case 26: // eu nao posso colocar o caracter por que ele ‚ o EOF, o compilador vai entender que aqui ‚ o fim do c¢digo fonte
    	  	  blit(caudadireita, screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, parede->w, parede->h);
      	  break;
	      case '': //27
  	    	blit(caudaesquerda, screen, 0, 0, (cobra[tamanho_cobra - 1].x - 1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, parede->w, parede->h);
    	    break;
      }
      break;
      
    case APAGAR_PEDACO_COBRA:
      tabuleiro[cobra[tamanho_cobra - 1].x][cobra[tamanho_cobra - 1].y] = ' ';
      
			blit(chao, screen, 0, 0, (cobra[0].x - 1) * 32, (cobra[0].y - 1) * 32, chao->w, chao->h); //Apagar a cabe‡a
			blit(chao, screen, 0, 0, (cobra[1].x - 1) * 32, (cobra[1].y - 1) * 32, chao->w, chao->h); //Apagar o pesco‡o
      blit(chao, screen, 0, 0, (cobra[tamanho_cobra - 1].x -1) * 32, (cobra[tamanho_cobra - 1].y - 1) * 32, chao->w, chao->h); //apagar o rabo
      break;
      
    case DESENHAR_CABECA:
      break;
    case DESENHAR_COBRA_INTEIRA:
    	{
        char i;
        for(i = 0; i <= (tamanho_cobra - 1) ;i++){
          switch(cobra[i].bitmap){
            case '':
              blit(cabecacima, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(cabecabaixo, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(cabecaesquerda, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(cabecadireita, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;

            case '':
              blit(caudaesquerda, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case 26: // eu nÆo coloquei o caracter aqui pelos motivos j  descritos acima.
              blit(caudadireita, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(caudacima, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '':
              blit(caudabaixo, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;

            case 'Í':
              blit(vertebrahorizontal, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case 'º':
              blit(vertebravertical, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
              
            case 'É':
              blit(vertebrasuperiordireita, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '»':
              blit(vertebrasuperioresquerda, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case 'È':
              blit(vertebrainferiordireita, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
            case '¼':
              blit(vertebrainferioresquerda, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
              break;
          }
        };
      };
      break;
    case APAGAR_COBRA_INTEIRA:
      {
        char i;
        for(i=0; i<= tamanho_cobra - 1 ; i++){
          blit(chao, screen, 0, 0, (cobra[i].x - 1) * 32, (cobra[i].y - 1) * 32, 32, 32);
        }
      };
      break;
  }
}






void cobra_init(int posicaoinicialx, int posicaoinicialy){

  unsigned short i;

  for(i = tamanho_cobra - 1; i <= 0; i--){
    tabuleiro[cobra[i].x][cobra[i].y] = ' ';
  }

  tabuleiro[posicaoinicialx][posicaoinicialy] = 'c';
  tabuleiro[posicaoinicialx-1][posicaoinicialy] = 'c';
  tabuleiro[posicaoinicialx-2][posicaoinicialy] = 'c';

  desenhar_cobra(APAGAR_COBRA_INTEIRA);
  
  tamanho_cobra = 3;
  
  cobra[0].x = 12;
  cobra[0].y = 12;
  cobra[0].bitmap = '';
  
  cobra[1].x = 11;
  cobra[1].y = 12;
  cobra[1].bitmap = 'Í';
  
  cobra[2].x = 10;
  cobra[2].y = 12;
  cobra[2].bitmap = '';


}

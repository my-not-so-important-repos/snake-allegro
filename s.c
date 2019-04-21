#include <allegro.h>

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX_COBRA		100

#define CIMA			72
#define BAIXO			80
#define ESQUERDA		75
#define DIREITA			77
#define ESC				27

#define APAGAR_COBRA	1
#define DESENHAR_COBRA	2

int		main(void);
int		mover_cobra(void);
int		desenhar_cobra(unsigned short);
char	tabuleiro[26][19], x, y, tamanho_cobra, direcao, game_over;
BITMAP	*chao, *parede, *maca, *spider;
struct vertebra
{
	char	x, y, bitmap;
} cobra[MAX_COBRA];


/* */

int main()
{
	/*~~~~~~~~~~~~~~~~~~~*/
	char	temp[80];
	char	tecla;
	int		i;
	BITMAP	*chipset;
	PALETTE paleta;
	FILE	*tabuleiro_arq;
	/*~~~~~~~~~~~~~~~~~~~*/

	/******************************/

	/* Inicializa‡Æo da variaveis */

	/******************************/
	allegro_init();
	set_gfx_mode(GFX_SAFE, 800, 600, 0, 0);
	chipset = load_bitmap("chip1.bmp", paleta);
	set_palette(paleta);

	chao = create_bitmap(32, 32);
	parede = create_bitmap(32, 32);
	maca = create_bitmap(32, 32);
	spider = create_bitmap(32, 32);

	blit(chipset, parede, 0, 0, 0, 0, 32, 32);
	blit(chipset, chao, 96, 0, 0, 0, 32, 32);
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
	tabuleiro_arq = fopen("board.dat", "r");

	/*************************/

	/* Inicializar Tabuleiro */

	/*************************/
	y = 0;
	while (!feof(tabuleiro_arq))
	{
		y++;
		fgets(temp, 27, tabuleiro_arq);
		for (x = 0; x <= 25; x++)
		{
			/***************************************************/

			/* poderia colocar if, no lugar de switch mas      */

			/* futuramente pretendo fazer alguma coisa c/ isso */

			/***************************************************/
			switch (temp[x])
			{
				case '³':
				case 'Ä':
				case 'Ú':
				case 'À':
				case '¿':
				case 'Ù':
				case ' ':
					tabuleiro[x + 1][y] = temp[x];
					break;
			}
		}
	}

	/******************************/
	/* Desenhar tabuleiro na tela */
	/******************************/
	for (y = 1; y <= 18; y++)
	{
		for (x = 1; x <= 25; x++)
		{
			switch (tabuleiro[x][y])
			{
				case 'Ú':
				case 'À':
				case '¿':
				case 'Ù':
				case '³':
				case 'Ä':
					blit(parede, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, parede->w, parede->h);
					break;

				case ' ':
					blit(chao, screen, 0, 0, (x - 1) * 32, (y - 1) * 32, parede->w, parede->h);
					break;
			}
		}
	}

	x = y = 2;

	while (!game_over)
	{
		mover_cobra();

		while (kbhit())
		{
			tecla = getch();
			if (tecla == 0)
				tecla = getch();	//se a tecla pressionada for extendida, ler o sengundo caracter no buffer do teclado
		}

		switch (tecla)
		{
			case CIMA:
			case BAIXO:
			case DIREITA:
			case ESQUERDA:
				game_over = 1;
				break;

			case ESC:
			case 'q':
				game_over = 1;
				break;
		}
	}

	getch();
	return (0);
}

END_OF_MAIN();


/* */

int mover_cobra()
{
	//  blit(spider, screen, )
	switch (direcao)
	{
		case CIMA:
			if (tabuleiro[x][y - 1] == ' ')
				//permitir o movimento
				y--;

			//blit
			break;

		case BAIXO:
			if (tabuleiro[x][y + 1] == ' ');
			break;

		case ESQUERDA:
			if (tabuleiro[x - 1][y] == ' ');
			break;

		case DIREITA:
			if (tabuleiro[x + 1][y] == ' ');
			break;
	}

	return (0);
}


/* */
int desenhar_cobra(unsigned short operacao)
{
	switch (operacao)
	{
		case APAGAR_COBRA:
			break;

		case DESENHAR_COBRA:
			break;
	}

	//fa‡a do rabo at‚ o pesco‡o
	//vertebra atual pega informa‡äes da pr¢xima vertebra
	//a posicao da cabe‡a ser  calculado baseado na dire‡Æo e
	//na posi‡Æo atual da cabe‡a
	return (0);
}

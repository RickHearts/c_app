#include<stdio.h>
#include<stdlib.h>

#define X 'X'
#define O 'O'
#define N ' '

#define INICIAR 1
#define JOGADA_VALIDA 2
#define JOGADA_INVALIDA 3
#define GANHA 4
#define SAIR 5

int proximo_jogador = 1;
int vitorias_jogador1 = 0;
int vitorias_jogador2 = 0;

void iniciar_jogo(char *a1, char *b1, char *c1, char *a2, char *b2, char *c2, char *a3, char *b3, char *c3)
{
	*a1 = N;
	*b1 = N;
	*c1 = N;
	*a2 = N;
	*b2 = N;
	*c2 = N;
	*a3 = N;
	*b3 = N;
	*c3 = N;
}

int fazer_jogada(char *a1, char *b1, char *c1, char *a2, char *b2, char *c2, char *a3, char *b3, char *c3)
{
	int casa;
	char jogada;
	if (proximo_jogador == 1)
	{
		jogada = X;
	}
	else
	{
		jogada = O;
	}

	printf("\n Jogador %d, escolha o numero da casa", proximo_jogador);
	printf("\n     7-a1,8-b1,9-c1");
	printf("\n     4-a2,5-b2,6-c2");
	printf("\n     1-a3,2-b3,3-c3");
	printf("\n0 - sair");
	printf("\n>> ");
	scanf("%d", &casa);

	switch (casa)
	{
	case 7:
		if (*a1 != N)
		{
			return JOGADA_INVALIDA;
		}
		else
		{
			*a1 = jogada;
		}
		break;

	case 8:
		if (*b1 != N)
		{
			return JOGADA_INVALIDA;
		}
		else
		{
			*b1 = jogada;
		}
		break;

	case 9:
		if (*c1 != N)
		{
			return JOGADA_INVALIDA;
		}
		else
		{
			*c1 = jogada;
		}
		break;

	case 4:
		if (*a2 != N)
		{
			return JOGADA_INVALIDA;
		}
		else
		{
			*a2 = jogada;
		}
		break;

	case 5:
		if (*b2 != N)
		{
			return JOGADA_INVALIDA;
		}
		else
		{
			*b2 = jogada;
		}
		break;

	case 6:
		if (*c2 != N)
		{
			return JOGADA_INVALIDA;
		}
		else
		{
			*c2 = jogada;
		}
		break;

	case 1:
		if (*a3 != N)
		{
			return JOGADA_INVALIDA;
		}
		else
		{
			*a3 = jogada;
		}
		break;

	case 2:
		if (*b3 != N)
		{
			return JOGADA_INVALIDA;
		}
		else
		{
			*b3 = jogada;
		}
		break;

	case 3:
		if (*c3 != N)
		{
			return JOGADA_INVALIDA;
		}
		else
		{
			*c3 = jogada;
		}
		break;

	case 0:
		return SAIR;
		break;

	default:
		return JOGADA_INVALIDA;
		break;
	}

	if (*a1 == jogada && *b1 == jogada && *c1 == jogada) {
		return GANHA;
	}
	if (*a2 == jogada && *b2 == jogada && *c2 == jogada) {
		return GANHA;
	}
	if (*a3 == jogada && *b3 == jogada && *c3 == jogada) {
		return GANHA;
	}


	if (*a1 == jogada && *a2 == jogada && *a3 == jogada) {
		return GANHA;
	}
	if (*b1 == jogada && *b2 == jogada && *b3 == jogada) {
		return GANHA;
	}
	if (*c1 == jogada && *c2 == jogada && *c3 == jogada) {
		return GANHA;
	}


	if (*a1 == jogada && *b2 == jogada && *c3 == jogada) {
		return GANHA;
	}
	if (*c1 == jogada && *b2 == jogada && *a3 == jogada) {
		return GANHA;
	}

	if (*a1 != N && *a2 != N && *a3 != N &&
		*b1 != N && *b2 != N && *b3 != N &&
		*c1 != N && *c2 != N && *c3 != N)
	{
		return INICIAR;
	}

	return JOGADA_VALIDA;
}

void mostrar_jogo(char a1, char b1, char c1, char a2, char b2, char c2, char a3, char b3, char c3)
{
	printf("+---------------------+\n");
	printf("Jogo do Galo\n");
	printf("+---------------------+\n\n");
	printf("Resultado X:%d - O:%d\n\n", vitorias_jogador1, vitorias_jogador2);
	printf("   (a) (b) (c) \n");
	printf("(1) %c | %c | %c \n", a1, b1, c1);
	printf("   ---+---+---\n");
	printf("(2) %c | %c | %c \n", a2, b2, c2);
	printf("   ---+---+---\n");
	printf("(3) %c | %c | %c \n", a3, b3, c3);
}

int main()
{
	int jogada = INICIAR;
	char a1, b1, c1,
		a2, b2, c2,
		a3, b3, c3;

	while (jogada != SAIR)
	{
		system("clear");

		if (jogada == INICIAR)
		{
			printf("Novo Jogo!\n");
			iniciar_jogo(&a1, &b1, &c1, &a2, &b2, &c2, &a3, &b3, &c3);
		}
		else if (jogada == GANHA)
		{
			printf("Jogador %d ganha!\n", proximo_jogador);
			if (proximo_jogador == 1) {
				vitorias_jogador1 = vitorias_jogador1 + 1;
				proximo_jogador = 2;
			}
			else
			{
				vitorias_jogador2 = vitorias_jogador2 + 1;
				proximo_jogador = 1;
			}

			iniciar_jogo(&a1, &b1, &c1, &a2, &b2, &c2, &a3, &b3, &c3);
		}
		else if (jogada == JOGADA_INVALIDA)
		{
			printf("Jogada Invalida!\n");
		}
		else if (jogada == JOGADA_VALIDA)
		{
			if (proximo_jogador == 1) {
				proximo_jogador = 2;
			}
			else
			{
				proximo_jogador = 1;
			}
		}

		mostrar_jogo(a1, b1, c1, a2, b2, c2, a3, b3, c3);
		jogada = fazer_jogada(&a1, &b1, &c1, &a2, &b2, &c2, &a3, &b3, &c3);
	}

	return 0;
}

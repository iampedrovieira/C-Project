#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef TEMPO_H
#define TEMPO_H

typedef struct tempo{
	int minutos;
	int hora;
	int dia;
	int mes;
	int ano;
}TEMPO;

void tempoAtual(TEMPO *temp);
#endif

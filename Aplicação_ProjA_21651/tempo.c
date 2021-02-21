#include "tempo.h"

//saber o tempo atual
void tempoAtual(TEMPO *temp){
	
	
	time_t currentTime;
	struct tm *tempo;
	currentTime=time(NULL);
	tempo=localtime(&currentTime);
	
	temp->minutos=tempo->tm_min;
	temp->hora=tempo->tm_hour;
	temp->dia=tempo->tm_mday;
	temp->mes=tempo->tm_mon+1;
	temp->ano=tempo->tm_year+1900;
	
}

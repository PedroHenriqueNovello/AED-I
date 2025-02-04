//Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620
#include <stdio.h>

int main(){
	int hora_ini, min_ini, hora_fim, min_fim;
	int total_ini, total_fim, horas, minutos;
	
	scanf ("%d %d %d %d", &hora_ini, &min_ini, &hora_fim, &min_fim);
	
	if(hora_ini==hora_fim && min_ini==min_fim){
		printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
	}
	else if(hora_ini==hora_fim && min_ini!=min_fim){
		if(min_fim > min_ini){
			minutos = min_fim - min_ini;
			printf("O JOGO DUROU 0 HORA(S) E %d MINUTO(S)\n", minutos);
		}
		else if(min_ini > min_fim){
			minutos = 60 - min_ini + min_fim;
			printf("O JOGO DUROU 23 HORA(S) E %d MINUTO(S)\n", minutos);
		}
	}
	else if(hora_fim > hora_ini){
		total_ini = hora_ini * 60 + min_ini;
		total_fim = hora_fim * 60 + min_fim;
		horas = (total_fim - total_ini) / 60;
		minutos = (total_fim - total_ini) - (horas * 60);
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", horas, minutos);
	}
	else if(hora_ini > hora_fim){
		total_ini = hora_ini * 60 + min_ini;
		total_fim = hora_fim * 60 + min_fim;
		horas = (1440 - total_ini + total_fim) / 60;
		minutos = (1440 - total_ini + total_fim) - (horas * 60);
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", horas, minutos);
	}
}

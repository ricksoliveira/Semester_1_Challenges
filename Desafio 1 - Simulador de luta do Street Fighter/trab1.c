/*
Trabalho solicitado pelo professor Alexandre Mello Ferreira, que visa simular uma partida entre Ryu vs Ken do jogo Street Fighter.

Nome: Henrique Servidoni de Oliveira
RA: 2760481821017

O programa abaixo funciona da seguinte maneira:

	Você deve colocar uma sequência de números inteiros positivos para os golpes que Ryu dá
	e uma sequência de números inteiros negativos para os golpes que Ryu recebe.
	Nenhum golpe poderá ter o valor 0.
	
	Cada sequência de numeros positivos e negativos representa um round, o programa irá somar cada sequência
	e ver se Ryu mais bateu ou apanhou para determinar quem ganhou tal round.
	
	Cada número positivo após um número negativo representa o início de um novo round.

	Ao digitar o número 0, o programa é encerrado e aparecerá na tela quem venceu a luta pelo maior número de rounds ganhos.
*/

#include <stdio.h>

int main(){
	
	int bateu_total, apanhou_total, golpe, anterior;
	int rounds_ryu, rounds_ken;
	bateu_total = 0;
	apanhou_total = 0;	//valores setados para 0 pois nenhum dos dois ainda bateu, recebeu golpes ou ganharam rounds.
	rounds_ryu = 0;
	rounds_ken = 0;
	
	scanf("%d", &golpe);
	bateu_total = bateu_total + golpe;
	anterior = golpe;		//atribuir golpe a anterior para comparação
	
	if(golpe>0){	//controle de erro para garantir que o primeiro golpe seja sempre de Ryu.
		
		while(golpe!=0){
			scanf("%d", &golpe);	//digitação dos golpes, comparando sempre o golpe atual com o anterior
			
			if(golpe > 0 && anterior > 0){
				bateu_total = bateu_total + golpe;
				anterior = golpe;
				
			}else if(golpe >= 0 && anterior < 0){	//se o golpe for positivo e o anterior for negativo, um novo round começou e esse bloco acrescenta na variável de quem ganhou o round anterior
				if(bateu_total + apanhou_total > 0){
					rounds_ryu++;
				}else if(bateu_total + apanhou_total < 0){
					rounds_ken++;
				}
				bateu_total = 0;	//também seta os danos até o momento para 0 novamente, uma vez que os danos de um round não influenciam em outro
				apanhou_total = 0;
				bateu_total = bateu_total + golpe;
				anterior = golpe;
				
			}else if(golpe < 0 && anterior < 0){
				apanhou_total = apanhou_total + golpe;
				anterior = golpe;
			
			}else if(golpe < 0 && anterior > 0){
				apanhou_total = apanhou_total + golpe;
				anterior = golpe;	
			}
		}
		
		if(rounds_ryu > rounds_ken)		//bloco de condicionais para calcular quem ganhou mais rounds e venceu a luta.
			printf("Ryu venceu");
		else if(rounds_ryu < rounds_ken)
			printf("Ken venceu");
		else if(rounds_ryu == rounds_ken)
			printf("empatou");
			
	}else
		printf("Comece com um valor positivo");
}

/*
	Nome: Henrique Servidoni de Oliveira
	RA: 2760481821017
	
	Trabalho solicitado pelo professor Alexandre Mello Ferreira, da disciplina de Algoritmos e Lógica de Programação, do primeiro
	semestre do curso de Análise e Desenvolvimento de Sistemas da FATEC - Campinas.
	
	Esse código visa simular um apocalipse zumbi em formato de matriz (simbolizando o planeta), onde 0 representa casas sem nada
	1 representa os humanos, e 2 representa casas com zumbis.
	
	A entrada consiste com as dimensões da matrizes, e em seguida o número de dias.
	
	O programa lerá cada casa da matriz, e comparará com seus vizinhos (uma "outra matriz" 3x3 cujo quem está sendo analisado é o centro),
	e então, contará quantos casas vazias, quantas casas com humanos e quantas casas com zumbi há em volta.
	
	Dependendo do numero de humanos e zumbis, o número será alterado para o dia seguinte.
	
	O programa termina quando o dia de iterações for o mesmo número de dias escolhidos (começando pelo dia 0).
*/

#include <stdio.h>

int main(){
	
	int p[50][50][50], m, n, i, j, k, a, b, lin_adj, lin_ant, col_ant, col_adj, iteracao, num_null, num_humano, num_zumbi;
	iteracao = 0;
	num_null = 0;
	num_humano = 0;
	num_zumbi = 0;
	
	scanf("%d %d", &m, &n);
	scanf("%d", &i);		// leitura do numero de dias
	
	for(j=0; j<m; j++){
		for(k=0; k<n; k++){				// leitura da matriz planeta p[m][n][i] onde a terceira dimensão [i] é o tempo em dias
			scanf("%d", &p[j][k][0]);
		}
	}
	
	while(iteracao<i){
		
		for(j=0; j<m; j++){
			for(k=0; k<n; k++){
				
				lin_ant = j-1;		// atribuindo os valores de linha e coluna anteriores e adjacentes para a definição da matriz 9x9
				col_ant = k-1;
				lin_adj = j+1;
				col_adj = k+1;
				
				if(j == 0) lin_ant = m-1;	// setando condições para as bordas das extremidades ser considerado as bordas opostas
				if(k == 0) col_ant = n-1;
				if(j == m-1) lin_adj = 0;
				if(k == n-1) col_adj = 0;
				
				for(a = lin_ant; a!=lin_adj+1; a++){
					if(a == m) a = 0;
					
					for(b = col_ant; b!=col_adj+1; b++){
						if(b == n) b = 0;
						
						if(p[a][b][iteracao] == 0){			// esse bloco confere a "mini" matriz 9x9 e conta quantos humanos, zumbis e espaços vazios há nela
							num_null++;
						}
						else if(p[a][b][iteracao] == 1){
							num_humano++;
						}
						else if(p[a][b][iteracao] == 2){
							num_zumbi++;
						}
					}
				}
				
				if(p[j][k][iteracao] == 1 && num_zumbi >= 1){		// bloco de condicionais para definir o que o número será no dia seguinte dependendo
					p[j][k][iteracao+1] = 2;						// de quanto de cada há em sua volta
					
				}else if(p[j][k][iteracao] == 2 && num_humano >= 2){	// o valor é salvo no terceiro indice+1 representando que o valor está no dia seguinte
					p[j][k][iteracao+1] = 0;							// para a mudança do dia não interferir na checagem atual
					
				}else if(p[j][k][iteracao] == 2 && num_humano == 0){
					p[j][k][iteracao+1] = 0;
					
				}else if(p[j][k][iteracao] == 0 && num_humano == 2){
					p[j][k][iteracao+1] = 1;
					
				}else{
					p[j][k][iteracao+1] = p[j][k][iteracao];
				}
				
				num_null = 0;		// seta a contagem para 0, recomençando para a próxima casa
				num_humano = 0;
				num_zumbi = 0;
				
			}
			
		}
		
		printf("iteracao %d\n", iteracao); 	// printa o próximo índice (dia seguinte) da terceira dimensão (que é o dia) da matriz planeta
		for(j=0; j<m; j++){
			for(k=0; k<n; k++){
				printf("%d", p[j][k][iteracao]);
			}
			printf("\n");
		}
		iteracao++;
	}

}

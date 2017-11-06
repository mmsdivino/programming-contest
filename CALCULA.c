#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Questao01
int main(){
	int i,o,n,resposta;
	char op;
	puts("Digite o numero de operandos:");
	scanf("%i",&o); i=1;
	while (o!=0){
		puts("Digite a operacao:");
		scanf("%i",&n); resposta=n;
		while (i<o){
			scanf("%c%i",&op,&n);
			switch(op){
				case '+': resposta=resposta+n; break;
				case '-': resposta=resposta-n; break;
				}
			i++;
		}
		printf("Resposta: %i.\n",resposta);
		puts("Digite o numero de operandos:");
		scanf("%i",&o); i=1;
	
	}
	return 0;
}

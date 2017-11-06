#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int N,D,i,cont,localmaior,maior;
	puts("Digite a quantidade de digitos do numero:");
	scanf("%i%*c",&N);
	puts("Quantos digitos serao apagados?");
	scanf("%i%*c",&D);
	while ((N!=0)&&(D!=0)){
		while ((N>100000)||(N<1)){
			puts("\aQuantidade de digitos invalida! Tente novamente!");
			puts("Digite a quantidade de digitos do numero:");
			scanf("%i*c",&N);
		}
		char numero[N];
		while ((D>100000)||(D<1)||(D>=N)){
			puts("\aQuantidade de numeros para apagar invalida! Tente novamente!");
			puts("Quantos digitos serao apagados?");
			scanf("%i*c",&D);
		}
		puts("Digite o numero que o apresentador escreveu:");
		gets(numero);
		if (numero[0]>numero[1]){
			localmaior=0; maior=numero[0]; numero[1]='-';
		}
		else {
			localmaior=1; maior=numero[1]; numero[0]='-';
		}
		cont=1; i=1;
		while (cont<D){
			if (numero[i]!='-'){
				if (maior>numero[i]) {numero[i]='-';cont++;}
				else if (maior<numero[i]){
					numero[localmaior]='-'; localmaior=i; maior=numero[i]; cont++;}
				
			}
			i++;
			printf("%i %i\n",i,cont);
		}
		for (i=0;i<N;i++){
			if (numero[i]!='-') printf("%c",numero[i]);
		}
		puts("\n");
		puts("Digite a quantidade de digitos do numero:");
		scanf("%i%*c",&N);
		puts("Quantos digitos serao apagados?");
		scanf("%i%*c",&D);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int X1,X2,Y1,Y2,m,i,cont=0;
	puts("Digite a coordenada do canto superior da sua fazenda:");
	scanf("%i %i",&X1,&Y1);
	puts("Digite a coordenada do canto inferior da sua fazenda:");
	scanf("%i %i",&X2,&Y2);
	//X3=X1; Y3=Y2; X4=X2; Y4=Y1;
	puts("Digite a quantidade de coordenadas dos meteoritos:");
	scanf("%i",&m);
	int v[(2*m)];
	for (i=0;i<m;i++){
		printf("Digite X e Y da coordenada do meteorito numero %i: \n",i+1);
		scanf("%i %i",&v[2*i],&v[(2*i)+1]);
	}
	for (i=0;i<(2*m);i=i+2){
		if ((v[i]>=X1)&&(v[i]<=X2)){
			if ((v[i+1]>=Y2)&&(v[i+1]<=Y1)){
				cont++;
			}
		}
	}
	printf("Na sua fazenda cairam %i meteoritos.",cont);
	return 0;
}

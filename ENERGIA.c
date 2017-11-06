#include <stdio.h>

#define LIMITE 100

void DFS (int matrizDFS[][LIMITE], int cor[], int estacoes, int estacao){
	int i;
	cor[estacao]=1; //CINZA == 1
	for (i=0; i<estacoes; i++){
		if (matrizDFS[estacao][i]==1 && cor[i]==0){ //BRANCO = 0
			DFS(matrizDFS,cor,estacoes,i);
		}
	}
	cor[estacao]=2; //PRETO ==2
}

int estaoConectadas(int cor[], int estacoes){
	int i;
	for (i=0; i<estacoes; i++)
		if (cor[i]==0) return 0;
	return 1;
}

int main(int argc, char **argv)
{
	int e, l, teste=1, i, j;
	int matriz[LIMITE][LIMITE];
	int cor[LIMITE];
	scanf("%d%d",&e, &l); //e = numero de vertices; l= numero de arestas.
	while (e!=0 || l!=0){
		for (i=0; i<e; i++){
			for (j=0; j<e; j++){
				matriz[i][j]=0;
			}
			cor[i]=0;
		}
		int x, y;	
		for (i=0; i<l; i++){
			scanf("%d%d",&x, &y);
			matriz[x-1][y-1]=1;
			matriz[y-1][x-1]=1;
		}
		DFS(matriz,cor,e,0);
		
		if (!estaoConectadas(cor,e)) printf("Teste %d\nfalha",teste);
		else printf("Teste %d\nnormal",teste);
		puts("\n");
		teste++;
		scanf("%d%d",&e, &l);
	}
	return 0;
}

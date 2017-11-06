#include <stdio.h>
#include <stdbool.h>


#define LIMITE 2001

void DFS (bool matrizDFS[][LIMITE], int cor[], int estacoes, int estacao){
	int i;
	cor[estacao]=1; //CINZA == 1
	/*for (i=0;i<estacoes; i++){
		printf("%d ",cor[i]);
	}
	puts("");*/
	for (i=0; i<estacoes; i++){
		if (matrizDFS[estacao][i] && cor[i]==0){ //BRANCO = 0
			//printf("%d %d %d %d\n",estacao, i, matrizDFS[estacao][i], cor[i]);
			DFS(matrizDFS,cor,estacoes,i);
		}
	}
	cor[estacao]=2; //PRETO ==2
	/*for (i=0;i<estacoes; i++){
		printf("%d ",cor[i]);
	}
	puts("");*/
}

void matriz_transposta (bool matrizDFS[][LIMITE], int estacoes) {
	int i, j;
	bool aux;
	for (i = 0; i < estacoes; i++) {
		for (j = i+1; j < estacoes; j++) {
			if (j != i) {
				aux = matrizDFS[i][j];
				matrizDFS[i][j] = matrizDFS[j][i];
				matrizDFS[j][i] = aux;
			}
		}
	}
	/*for (i = 0; i < l; i++) {
		for (j = 0; j < c; j++) {
			printf ("%d ",matriz[i][j]);
		}
		printf ("\n");
	}*/
}

int estaoConectadas(int cor[], int estacoes){
	int i;
	for (i=0; i<estacoes; i++)
		if (cor[i]==0) return 0;
	return 1;
}

int main(int argc, char **argv)
{
	int n, m, i, j;
	bool matriz[LIMITE][LIMITE];
	int cor[LIMITE], corT[LIMITE];
	scanf("%d%d",&n, &m); //n=numero de vertices; m=numero de arestas
	while (n!=0 || m!=0){
		for (i=0; i<n; i++){
			for (j=0; j<n; j++){
				matriz[i][j]=false;
			}
			cor[i]=0;
			corT[i]=0;
		}
		int v, w, p;	
		for (i=0; i<m; i++){
			scanf("%d%d%d",&v, &w, &p);
			matriz[v-1][w-1]=true;
			if (p==2) matriz[w-1][v-1]=true;
		}
		DFS(matriz,cor,n,0);
		matriz_transposta(matriz,n);
		//puts("");
		DFS(matriz,corT,n,0);
		
		if (!estaoConectadas(cor,n) || !estaoConectadas(corT,n)) puts("0");
		else puts("1");
		scanf("%d%d",&n, &m);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

#define LIMITE 50

void BFS(int matrizBFS[][LIMITE], int vetorVisitado[], int inicio, int vertices){
	int filaVisitados[vertices];
	memset(filaVisitados, -1, sizeof(filaVisitados));
	filaVisitados[0]=inicio;
	int verticeAtual = 0, inicioFila=0, tentar, indiceFila=0;
	while (vertices!=inicioFila){
		verticeAtual = filaVisitados[inicioFila];
		
		for (tentar = 0; tentar < vertices; tentar++){
			if (vetorVisitado[tentar]==0 && matrizBFS[verticeAtual][tentar]==1){
				vetorVisitado[tentar] = vetorVisitado[verticeAtual]+1;
				indiceFila++;
				filaVisitados[indiceFila]=(char)tentar;
			}
		}
		inicioFila++;
	}
}

int estaoConectadas(int cor[], int estacoes){
	int i;
	for (i=0; i<estacoes; i++)
		if (cor[i]==0) return 0;
	return 1;
}

int main(int argc, char **argv)
{
	int c, e, l, p, x, y, i, j, teste=1;
	int matriz[LIMITE][LIMITE];
	int cor[LIMITE];
	scanf("%d%d%d%d",&c, &e, &l, &p); //c=numero de vertices; e=numero de arestas
	while (c!=0 && e!=0 && l!=0 && p!=0){
		for (i=0; i<c; i++){
			for (j=0; j<c; j++){
				matriz[i][j]=0;
			}
			cor[i]=0;
		}
		for (i=0; i<e; i++){
			scanf("%d%d",&x, &y);
			matriz[x-1][y-1]=1;
			matriz[y-1][x-1]=1;
		}
		BFS(matriz,cor,l-1,c);
		
		printf("Teste %d\n",teste);
		int flag = 0;
		for (i=0; i<c; i++){
			if (cor[i]!=0 && i!=(l-1) && cor[i]<=p){
				if (flag) printf(" ");
				printf("%d",i+1);
				flag=1;
			}
		}
		puts("\n");
		
		scanf("%d%d%d%d",&c, &e, &l, &p);
		teste++;
	}
	return 0;
}

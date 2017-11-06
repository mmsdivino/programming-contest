#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  int i,j,n;
  float distancia,menor=10000000000.0;
  puts("Digite a quantidade de pontos:");
  scanf("%i",&n);
  float x[n], y[n];
  for (i=0;i<n;i++) {
    printf("Digite o valor de x%i:",i+1);
    scanf("%f",&x[i]);
    printf("Digite o valor de y%i:",i+1);
    scanf("%f",&y[i]);
  }
  for (i=0;i<n;i++) {
    j=i+1;
    while (j<n) {
      distancia=sqrt(pow((x[j]-x[i]),2.0)+pow((y[j]-y[i]),2.0));
      if (distancia<menor) menor=distancia;
      j++;      
    }
  }
  printf("A menor distancia entre os pontos e' igual a %.3f u.c.",menor);
  return 0;
}
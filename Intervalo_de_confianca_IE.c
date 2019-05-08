#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define turm 5

float idades[turm], u, s, e, p;
double zcrit,x =0;

float medidade(float a[turm]){
  float b = 0;
  float c = 0;
  for(int i = 0; i < turm; i++){
    b += a[i];
  }
  c = b / turm;
  return c;
}


float desvidade(float a[turm], float b){
  float c = 0;
  float d = 0;
  for(int i = 0; i < turm; i++){
    c += pow((a[i] - b), 2);
  }
  d = sqrt(c/(turm - 1));
  return d;
}


float erro(float a, float b){
  float c = 0;
  c = a * b;
  return c;
}

float confianca(float a){
  a = (a > 1) ? (a/100) : a;
  float ZCritico = (1 - a)/2;
  return ZCritico;
}

double Gaussian_Distribution( double x )
{
   return  0.5 * ( 1.0 + erf( (1/sqrt(2)) * x ) );
}

//Programa principal
int main(void){
  //solicitacao de input do usuario
  for(int i = 0; i < turm; i++){
    printf("Digite a idade do %do aluno: ", i + 1);
    scanf(" %f", &idades[i]);
  }
  printf("\nQual o nivel de confianca ? [ E.g = 95 ou 0.95 ] : ");
  scanf("%f",&p);
  //calculo de media, desvio e erro amostral
  u = medidade(idades);
  s = desvidade(idades, u);
  e = erro(1.96, s);
  zcrit = confianca(p);

  double j,h;
  j = round((1 - zcrit)*100000)/100000;

  while(j != (round(Gaussian_Distribution(x)*100000)/100000)){
    x += 0.0001;
  }

  h = (round(Gaussian_Distribution(x)*100000)/100000);

  /* Uncomment to debug
    printf("\n%lf",x);
    x = Gaussian_Distribution(1.9600);
    printf("\n%lf e %lf",j,h);
    if(j == h){
      printf("\nIgual");
    }
    else {
      printf("\nNao eh igual");
    }
  */

  //apresentacao dos resultados
  printf("\n\nA media amostral das idades da turma eh: %.4f", u);
  printf("\nO desvio padrao amostral das idades da turma eh: %.4f", s);
  printf("\nO erro amostral das idades da turma eh: %.4f", e);
  printf("\nZ's criticos : [0]%.4f e [1]%.4f",zcrit,(1 - zcrit));
  printf("\nValor Z Score : ±%.3lf",x);
  printf("\nMargem de confianca: %.0f%%",(p < 1) ? p*100 : p);
  printf("\n\nu - e < u < u + e");
  printf("\n%.4f < %.4f < %.4f", (u - e), u, (u + e));
}
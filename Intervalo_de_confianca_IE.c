#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define turm 37

float idades[turm], u, s, e;


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
  float a = (a > 1) ? (a/100) : a;
  float ZCritico = (1 - a)/2;
}

//Programa principal
int main(void){
  //solicitacao de input do usuario
  for(int i = 0; i < turm; i++){
    printf("Digite a idade do %do aluno: ", i + 1);
    scanf(" %f", &idades[i]);
  }
  //calculo de media, desvio e erro amostral
  u = medidade(idades);
  s = desvidade(idades, u);
  e = erro(1.96, s);
  //apresentacao dos resultados
  printf("\n\nA media amostral das idades da turma eh: %.4f", u);
  printf("\nO desvio padrao amostral das idades da turma eh: %.4f", s);
  printf("\nO erro amostral das idades da turma eh: %.4f", e);
  printf("\n\nMargem de confianca:");
  printf("\nu - e < u < u + e");
  printf("\n%.4f < %.4f < %.4f", (u - e), u, (u + e));
}
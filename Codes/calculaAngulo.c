// =======================================================================
//    Primiero programa:  colocando pivo na posicao certa de menor a maior
// =======================================================================

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592654

void translacaoOrigem(int n, int *vx, int *vy, int Cx, int Cy){
    int i;
    for(i=0; i<n; i++){
        vx[i] -= Cx;
        vy[i] -= Cx;
    }
}

int calculaCentro(int n, int *v){
    int ss = 0;
    int i;
    for(i=0; i<n; i++) {
        ss += v[i];
    }
    return(ss/n);
}

void geraElemVetor(int n, int *v){
    int i;
    for(i=0; i<n; i++){
        v[i]= rand()%101; 
    }
}

int* alocaVetor(int n) {
    int *v;
    v = (int*) malloc(n*sizeof(int));
    return(v);
}

float* alocaVetorFloat(int n) {
    float *v;
    v = (float*) malloc(n*sizeof(float));
    return(v);
}

void mostrarVetor(int n, int *v){
    int i;
    for(i=0; i<n; i++){
        printf(" %d", v[i]);
    }
    printf("\n");
}
void mostrarVetorFloat(int n, float *v){
    int i;
    for(i=0; i<n; i++){
        printf(" %5.2f", v[i]);
    }
    printf("\n");
}

float calculaAngulo(int vx, int vy) {
    int dot = vx*1 + vy*0;
    int det = vx*0 - vy*1;
    float angulo = atan2(det, dot) * 180/PI;
    if(angulo<0){
        angulo = angulo + 360;
    }
    return(angulo);
}

void calculaReta(int n, int *vx, int *vy, float *vAng){
    int i;
    printf("\n Os ângulos são:");
    for(i=0; i<n; i++){
        vAng[i] = calculaAngulo(vx[i], vy[i]);
    }
}

void calculaArea(int n, int *vx, int *vy){
  int i;
  double area = 0;
  for(i = 0; i < n-1; i++){
      area += ((vx[i] - vx[i+1]) * (vy[i] + vy[i+1]))/2;
  }
  area +=((vx[n-1] - vx[0]) * (vy[n-1] + vy[0]))/2;
  if (area < 0)
    area = area * -1;
  printf("\nÁrea: %.2f\n", area);
}

void main(void) {
    // ---- definir ----
    int n, *vx, *vy, Cx, Cy;
    float *va;
    printf("\n Digite valor de n: ");
    scanf("%d", &n);
    vx = alocaVetor(n);  // dinamica
    vy = alocaVetor(n);
    va = alocaVetorFloat(n);
    // inicializar srand
    srand(time(NULL)); 
    geraElemVetor(n, vx);
    geraElemVetor(n, vy);

        // mostrar vetores gerados
    printf("\n Vetores: \n");
    mostrarVetor(n, vx);
    mostrarVetor(n, vy);
    
        // calcular centroides
    Cx = calculaCentro(n, vx);
    Cy = calculaCentro(n, vy);
    
        // mostrando centro
    printf("\n Centro Calculado: (%d, %d) \n", Cx, Cy);
    translacaoOrigem(n, vx, vy, Cx, Cy);
    printf("\n Novos vetores: \n");
    mostrarVetor(n, vx);
    mostrarVetor(n, vy);
    calculaReta(n, vx, vy, va);
    mostrarVetorFloat(n, va);
    calculaArea(n, vx, vy);
    free(vx);
    free(vy);
    free(va);
}
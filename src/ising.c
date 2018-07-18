/*
#include "stdlib.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "metropolis.h"
#include "lattice.h"
#include "ejercicios.h"
*/
//float magnet(int *lattice, int n, float p,float T_max, float T_min, int T_pasos,float B,float J, int niter,int k);
/*
int main(int argc, char **argv) {
  int n = 32;
  int *lattice = malloc(n * n * sizeof(int));
  float prob = 0.5;
  float T =2.2;
  float J=1;
  float E;
  int M;
  int niter = 2000;
  float B = 0;
  //srand(1);
  srand(time(NULL));
  float* LUT =LookUpTable(J,B,T);
  M=fill_lattice(lattice, n, prob);
  E=energia_0(lattice,n,J,B);
  graf_bimodal(lattice,n,B,J/T,LUT,&E,&M,10000);
*/

  //ej_2a(lattice, n,  prob,3,  0.3, 4, 1,  0, 1000,10000 );
//  ej_2c(lattice,n,prob,1,0.1,0.6,100,0,10000,2200);

  //printf("%p\n", (void *) lattice);
  //magnet(lattice, n, prob, 3, 1.5, 251  , 1 , J, 1000,20000);

  //ej_2b(lattice, n, 0.48, 0.5, 2, 100*n*n, 500, n*n);
  /*int secs = time(NULL);
  int k = 100*n*n;
  int paso = calc_paso(lattice, n, 0, 0.48, LUT, &E, &M, &k, 100, n*n);
  secs = time(NULL)-secs;
  printf("%d en %d min, %d segs\n", paso, secs/60, secs%60);*/
  // ej_2d(lattice, n, 0.5,1, -0.6,-0.1, 26, 1, 10000,10*n*n);

/*
  int Programa;
  if(argc>1){
    sscanf(argv[1], "%x", &Programa);
  }else{
    Programa =0;
  }


  if(Programa == 42){
    float T_max, T_min;
    int T_pasos,k,*lattice2;
    sscanf(argv[2], "%d", &n);
    sscanf(argv[3], "%f", &prob);
    sscanf(argv[4], "%f", &T_min);
    sscanf(argv[5], "%f", &T_max);
    sscanf(argv[6], "%d", &T_pasos);
    sscanf(argv[7], "%f", &B);
    sscanf(argv[8], "%d", &niter);
    sscanf(argv[9], "%d", &k);
    lattice2 = (int *) malloc(n*n*sizeof(int));
    ej_2a(lattice2, n,  prob, T_max,  T_min,  T_pasos, B,  0, niter, k);
    free(lattice2);
  }

  if(Programa == 43){
    float J_max, J_min;
    int m,k,*lattice2, nsaltos;
    sscanf(argv[2], "%d", &n);
    sscanf(argv[3], "%f", &J_min);
    sscanf(argv[4], "%f", &J_max);
    sscanf(argv[5], "%d", &m);
    sscanf(argv[6], "%d", &k);
    sscanf(argv[7], "%d", &niter);
    sscanf(argv[8], "%d", &nsaltos);
    lattice2 = (int *) malloc(n*n*sizeof(int));
    ej_2b(lattice2, n, J_min, J_max, m, k, niter, nsaltos);
    free(lattice2);
  }

  if(Programa == 44){
    float T_max, T_min;
    int m,k,*lattice2;
    sscanf(argv[2], "%d", &n);
    sscanf(argv[3], "%f", &T_min);
    sscanf(argv[4], "%f", &T_max);
    sscanf(argv[5], "%d", &m);
    sscanf(argv[6], "%f", &J);
    sscanf(argv[7], "%f", &B);
    sscanf(argv[8], "%d", &niter);
    sscanf(argv[9], "%d", &k);
    lattice2 = (int *) malloc(n*n*sizeof(int));
    ej_2c(lattice2, n, 0.5,T_min, T_max, m, J,B,niter,k);
    free(lattice2);
  }
*/
  /* ---> ACLARACION: 2d) y 2e) <--- */
// La variable var=1,2,3 indica cual es la variable que será iterada
// El orden numerico de  las variables es JBT osea que 1->J, 2->B y 3->T
// Los valores X1 y X2 van, en orden, a las 2 variables restantes

// Lo ideal es fijar X1 o X2 en 1 para trabajar con solo 2 variables reducidas
// Las variables reducidas son J/T, B/T y J/B, pero no sirven de mucho (por ahora)
// Recomiendo fijar B (y solo B) y graficar en funcion de J o T
// Por ejemplo, se puede graficar en funcion de T para distintos valores de J/B
/*
  if(Programa == 45){
    float X_max, X_min, X1, X2;
    int var,m,k,*lattice2;
    sscanf(argv[2], "%d", &n);
    sscanf(argv[3], "%d", &var);
    sscanf(argv[4], "%f", &X_min);
    sscanf(argv[5], "%f", &X_max);
    sscanf(argv[6], "%d", &m);
    sscanf(argv[7], "%f", &X1);
    sscanf(argv[8], "%f", &X2);
    sscanf(argv[9], "%d", &niter);
    sscanf(argv[10], "%d", &k);
    lattice2 = (int *) malloc(n*n*sizeof(int));
    ej_2d(lattice2,n,var,X_min,X_max,m,X1,X2,niter,k);
    free(lattice2);
  }

  if(Programa == 46){
    float X_max, X_min, X1, X2;
    int var,m,k,*lattice2;
    sscanf(argv[2], "%d", &n);
    sscanf(argv[3], "%d", &var);
    sscanf(argv[4], "%f", &X_min);
    sscanf(argv[5], "%f", &X_max);
    sscanf(argv[6], "%d", &m);
    sscanf(argv[7], "%f", &X1);
    sscanf(argv[8], "%f", &X2);
    sscanf(argv[9], "%d", &niter);
    sscanf(argv[10], "%d", &k);
    lattice2 = (int *) malloc(n*n*sizeof(int));
    ej_2e(lattice2,n,var,X_min,X_max,m,X1,X2,niter,k);
    free(lattice2);
  }

  free(LUT);
  free (lattice);

  return 0;
}
*/
/*
float magnet(int *lattice, int n, float p,float T_max, float T_min, int T_pasos,float B,float J, int niter,int k){
  float Ti=T_min;
  int M = fill_lattice(lattice,n,p);
  float E = energia_0(lattice,n,J,B);
  float* LUT;
  FILE *fp = fopen("Magnetizacion.txt","a");
  float T_step = (T_max-T_min)/(T_pasos-1);
  fprintf(fp, "Magnetizacion para Temperaturas entre %g y %g con %d pasos con J=%f \n ", T_max,T_min,T_pasos,J);
  int secs = time(NULL);
  float *ener_t= malloc (T_pasos*sizeof(float));
  for(int k=0;k<T_pasos;k++){
    Ti=T_min+k*T_step;
    float m_T=0;
    float e_T=0;
    LUT = LookUpTable(J,B,Ti);
    for (int i=0;i<3000;i++){
      metropolis(lattice, n,B,J,LUT,&E,&M);
    }
    for (int j = 0; j < niter; j++){
      for(int l=0;l<k;l++){
        metropolis(lattice, n,B,J,LUT,&E,&M);
      }
      m_T = m_T+((float)M)/niter;
      e_T = e_T+((float)E)/niter;
    }
  ener_t[k]=e_T;
  fprintf(fp, "%g ,", m_T);
  printf("%g finalizado\n", Ti);
  free(LUT);
  }
  fprintf(fp, "\n Energia para Temperaturas entre %g y %g con %d pasos con J=%f \n ", T_max,T_min,T_pasos,J);
  for(int i=0;i<T_pasos;i++){
    fprintf(fp, "%g ,", ener_t[i]);
    printf("%d finalizado\n", i);
  }
  free(ener_t);
  secs = time(NULL)-secs;
  fprintf(fp, "\nEl calculo tomo %d hs, %d min, %d secs\n\n", secs/3600, (secs/60) % 60, secs % 60);
  fclose(fp);
}
*/

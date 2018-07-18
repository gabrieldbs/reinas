#include "lattice.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



/*
--- LLENAR PROBA---
*/

double llenar_proba(double *prob, int n){
	int i,r;
	for(i=0;i<n;i++){
	prob[i]=0.;
	}

	for(i=0;i<n;i++){
	prob[i]=0.014;	
	}
}
/*
---NUEVA RED ---
*/

int fill_new_lattice(int *lattice, int n, double *p) {
  int i,j,res=0, r,m=0;
	// ---LLENAR RED DE 0 ---
	for (i=0;i<n*n;i++){
	lattice[i]=0;
	res=res+lattice[i];	}

//	--- PONER 1 EN LA RED ---
  for (i=0;i<n;i++){
	m=0;
	for (j=0;j<n;j++){
		if (m<1){
			r= rand();
			//lattice[i*n+j]=((r<p[i]*RAND_MAX)*2-1);    // Cuando sea verdaddes el <  ==> 1*2-1 ==> 1  // Cuando sea falso el < ==> 0*2-1 ==> -1
			lattice[i*n+j]=((r<p[i]*RAND_MAX)); //  0 o 1 antes teniamos 1 o -1
			if (lattice[i*n+j]>0){
				m++;}
				//printf("%d \n", m);}		// --- SUMA 1 EN LA M,Y LO PRNTEA ---

			res=res+lattice[i*n+j]; // --- ARMA LA RED --
		}
	}
  }

  return res;                          
}

/*
---PRINTEAR---
*/
int print_lattice(int *lattice, int n) {
  int i,j;
	printf("\n");
  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      if (lattice[i*n+j]==1){
        printf("1 ");
      }else{
        printf("0 ");
      }
    }
    printf("\n");
  }
  return 0;
}


int print_proba_100(double *prob, int n) {
  int i;
	printf("\n");
  for (i=0;i<n;i++){
      printf("%g ",prob[i]);
      }
		printf("\n");
    
  return 0;
}

/*
---VIEJA MANERA DE HACER LA RED----
*/
int fill_lattice(int *lattice, int n, double p) {
  int i,res=0, r;
  for (i=0;i<n*n;i++){

    r= rand();
    lattice[i]=((r<p*RAND_MAX)*2-1);    
    res=res+lattice[i];
  }
  return res;                         
}
 

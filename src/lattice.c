#include "lattice.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



/*
--- LLENAR PROBA---
*/

double llenar_proba(double *prob, int n){
	int i;
	double proba;
	proba=0.18;
	for(i=0;i<n;i++){
	prob[i]=0.;
	}

	for(i=0;i<n;i++){
	prob[i]=proba;	
	}
	return (0);
}

int hist(double proba){
	//int l,max,min,paso;
	int a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0,a10=0,a11=0;
	//min =0.1;
	//max =0.3;
	//paso=0.02;
	printf("%g \n",proba);
	printf("a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11 \n");
	if (proba<0.18){a1=a1+1;}
	if (proba>0.18  && proba<=0.182){a2=a2+1;}
   if (proba>0.182 && proba<=0.184){a3=a3+1;}
	if (proba>0.184 && proba<=0.186){a4=a4+1;}
	if (proba>0.186 && proba<=0.188){a5=a5+1;}
	if (proba>0.188 && proba<=0.19){a6=a6+1;}
	//if (proba>0.2  && proba<=0.22){a7=a7+1;}
	//if (proba>0.22 && proba<=0.24){a8=a8+1;}
	//if (proba>0.24 && proba<=0.26){a9=a9+1;}
	//if (proba>0.26 && proba<=0.28){a10=a10+1;}
	if (proba>0.19){a11=a11+1;}
	printf("%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d ,%d  ,%d \n",a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11);
	return (0);
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
			//lattice[i*n+j]=((r<p[i]*RAND_MAX)*2-1);// Cuando sea verdaddes el <  ==> 1*2-1 ==> 1  // Cuando sea falso el < ==> 0*2-1 ==> -1
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
 

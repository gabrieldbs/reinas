#include "stdlib.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lattice.h"
#include "test.h"

int main(int argc, char **argv) {
	
	int a,c,d,it,n,m,cf,cd,CM, iterat;
	n=10;
	iterat=0;
	m=60000;
	int *lattice= malloc (n * n * sizeof(int));
	double *prob= malloc (n * sizeof(double));
	llenar_proba(prob,n);
	//print_proba_100(prob, n);
	srand(time(NULL));
	int M,o=0;
	//M=fill_new_lattice(lattice, n, prob);
	//print_lattice(lattice,n);
	// --- CHEQUEOS Y CAMBIOS---//
	//suma_linea(lattice, n, prob);
	int L=0;	
	int LMM=0,LLIN=0;
	int LMMMAS=0,LMMMENOS=0;
	d=0;
	for (it=0;it<m;it++){
		
		c=0;
		
		M=fill_new_lattice(lattice, n, prob);


//CHEQUEAR MITAD MITAD
			//print_proba_100(prob, n);
			CM=checkmitad(lattice,n);
			 if (CM==1){
					LMMMAS=LMMMAS+1;
						for(int icm=0;icm<n;icm++){
					prob[icm]=prob[icm]+1./(n*n*n);}}		
			 if (CM==2){
					LMMMENOS=LMMMENOS+1;
						 for(int icm=0;icm<n;icm++){
					prob[icm]=prob[icm]-1./(n*n*n);}}
				
  		 if (CM==0){		
			a=0;
			for(int q=0;q<n;q++){
				//printf("Test mitad  si \n");	
				a=a+suma_linea(lattice,n,q);}

			if (a<n){	
					LLIN=LLIN+1;
				for(int q;q<n;q++){
				
					prob[q]=prob[q]+1./(n*n);}
				}

			if (a==n){
					 //printf("Test suma linea si \n");					
					// CHEQUEO FILA
				cf=check_fila(lattice,n);
				if (cf != 0){
					LLIN=LLIN+1;}
				if (cf==0){
					//printf("Test suma fila si \n");
					//print_lattice(lattice,n);
					cd=0;
					for (int r=0;r<n-1;r++){
						cd=cd+checkdiagonal(lattice,n,r);}
					/*	if (cd==0){
							//print_lattice(lattice,n);
							printf("OK\n");}
						if (cd=!0){
							//print_lattice(lattice,n);
							printf("NO\n");}*/
						
						if (cd==0){
							print_lattice(lattice,n);
							printf("YES\n");
							d=d+1;}
					if (cd != 0){
						//	print_lattice(lattice,n);
							//printf("NOT \n");
 							 L=L+1;}
				}
				
			}
		 }
					/*
					for (int r=0;r<n;r++){
					cd=checkdiagonal(lattice,n,r);

					if (cd==0){
						printf("SIIi \n");
						d=d+1;
						print_lattice(lattice,n);
						printf("\n");
						//M=fill_new_lattice(lattice,n, prob);
						}
					else 
						printf("NOi \n");
						print_lattice(lattice,n);
						printf("\n");
					}*/	
			
	iterat=iterat+1;
	}// iteracion
	//print_proba_100(prob,n) ;
	double a1,a2,a3,a4,a5;
	a1=d*1.0/iterat;
	a2=L*1.0/iterat;
	a3=LMMMAS*1.0/iterat;
	a4=LMMMENOS*1.0/iterat;
	a5=LLIN*1.0/iterat;
	printf("d = %d, %g \n",d,a1);
	printf("L =%d, %g \n",L,a2);
	printf("LMMMAS =%d ,%g \n",LMMMAS ,a3);
	printf("LMMMENOS =%d, %g \n",LMMMENOS,a4);
	printf("LLIN =%d, %g \n",LLIN,a5);
	printf("iteraciones =%d \n",iterat);
	free (prob);
	free (lattice);
	return(0);
}



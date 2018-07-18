#include "stdlib.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lattice.h"
#include "test.h"

int main(int argc, char **argv) {
	
	int a,c,d,it,n,m,cf,cd,CM, iterat;
	n=100;
	iterat=0;
	m=100000;
	int *lattice= malloc (n * n * sizeof(int));
	double *prob= malloc (n * sizeof(double));
	llenar_proba(prob,n);
	print_proba_100(prob, n);
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
		for (int icm=0;i<n;i++){
			CM=checkmitad(lattice,n,i);
			 if (CM==1){
					LMMMAS=LMMMAS+1;
					prob[icm]=prob[icm]+1./(n*n*n);}		
			 if (CM==2){
					LMMMENOS=LMMMENOS+1;
					prob[icm]=prob[icm]-1./(n*n*n);}
				}
  		 if (CM==0){		
			a=0;
			for(int q=0;q<n;q++){
				//printf("Test mitad  si \n");	
				a=a+suma_linea(lattice,n,q);}

			if (a<n){	
					LLIN=LLIN+1;
				for(int q;q<n;q++){
				
					prob[q]=prob[q]+1./(n*n*n);}
				}

			if (a==n){
					 //printf("Test suma linea si \n");					
					// CHEQUEO FILA
				cf=check_fila(lattice,n);
				if (cf != 0){
					L=L+1;}
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
	print_proba_100(prob,n) ;
	printf("d = %d \n",d);
	printf("L =%d \n",L);
	printf("LMMMAS =%d \n",LMMMAS);
	printf("LMMMENOS =%d \n",LMMMENOS);
	printf("LLIN =%d \n",LLIN);
	printf("iteraciones =%d \n",iterat);
	free (prob);
	free (lattice);
	return(0);
}



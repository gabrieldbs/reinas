#include "stdlib.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lattice.h"
#include "test.h"

int main(int argc, char **argv) {
	//double l[16];
	int a,b,c,d,it,n,m,cf,cd,CM;
	n=8;
	m=50000;
	int *lattice= malloc (n * n * sizeof(int));
	double *prob= malloc (n * sizeof(double));
	llenar_proba(prob,n);
	srand(time(NULL));
	int M,o=0;
	//M=fill_new_lattice(lattice, n, prob);
	//print_lattice(lattice,n);
	// --- CHEQUEOS Y CAMBIOS---//
	//suma_linea(lattice, n, prob);
	
	for (it=0;it<m;it++){
		b=0;
		c=0;
		d=0;
		M=fill_new_lattice(lattice, n, prob);


//CHEQUEAR MITAD MITAD

		CM=checkmitad(lattice,n);

		 if (CM==1){
				for(int q=0;q<n;q++){
					prob[q]=prob[q]+1./(n*n);}
			}

		 if (CM==2)
				for(int q=0;q<n;q++){
					prob[q]=prob[q]-1./(n*n);}
		 if (CM==0){
			
			 a=0;
			for(int q=0;q<n;q++){
				//printf("Test mitad  si \n");	
				a=a+suma_linea(lattice,n,q);}

				if (a<n){	
					for(int q;q<n;q++){
						 prob[q]=prob[q]+1./(n*n);}
					}

				if (a==n){
					 //printf("Test suma linea si \n");					
					// CHEQUEO FILA
					cf=check_fila(lattice,n);

					if (cf==0){
						printf("Test suma fila si \n");
						print_lattice(lattice,n);
						for (int r;r<n;r++){
							cd=cheackdiagonal(lattice,n,r);
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
										

						}

				}
			}
		
			
			
	
	}
	
	printf("%d \n",d);
	free (prob);
	free(lattice);
	return(0);
}



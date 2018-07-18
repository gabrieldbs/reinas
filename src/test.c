#include "lattice.h"
#include "stdlib.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
double suma_tot(int *lattice,int n,int i){
	int MM=0;
	double res[n];
	for (int ii=0;ii<n;ii++){
		res[ii]=0;}

	for (int i=0;i<n;i++){
		MM=0;
		for(int j=0;j<n;j++){
				MM=MM+lattice[i*n+j];
				if (MM==0){
					res[i]=p[i]+1.0/(n*n);}
				if (MM==1){
					res[i]=p[i];}
		}
	}
	return res;
}
*/
int suma_linea(int *lattice, int n, int i){
	int MM;
		MM=0;
		for(int j=0;j<n;j++){
			MM=MM+lattice[i*n+j];
			}
		//printf(" MM %d \n",MM);
		return MM;			// 		MM == 0   NEG    MM== 1 POS
	} 

int check_fila(int *lattice, int n){
	int i, j, l,a=0;
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
			if (lattice[i*n+j]==1){
				
					for (l=i;l<n-1;l++){
						if (lattice[(l+1)*(n)+j]==1){
							a=a+1;}
						else{
							a=a+0;
						}
					}
				
			}
		}
	}
	/*
	if (a!=0){
		
		printf("Test por 1 fila NEG %d \n",a);
	}
	else {
		printf("Test por 1 fila POS %d \n",a);
	}*/
	return a;	//  A == 0 POS  A !=0 NEG
}

/*
Hay que hacer division entera
*/
int checkdiagonal(int *lattice, int n,int i){
	int a=0,b=0,c=0,d=0,e=0,l,oo;
	int jj=0,ii=0;
	int m=0;
	//print_lattice(lattice,n);
	for (int j=0;j<n;j++){
		a=lattice[i*n+j];
		//printf("a=%d \n",a);
	
		if (a==1){
			for(b=1;b<n;b++){
				d=b*(n+1)+(i*n+j);
				e=b*(n-1)+(i*n+j);
				//printf("d= %d, e= %d \n ",d,e);
				//print_lattice(lattice,n);
				l=(d)/(n);
				oo=(e)/(n);
				//printf("l+= %d, oo-= %d \n ",l,oo);
				if (l == i+b){
	
					ii=lattice[d];
						if (ii==1){m=m+1;}
						}
				if (oo == i+b){
					jj=lattice[e];
						if (jj==1){m=m+1;}
						}
			}
		}
	}/*
	if (m==0){
		printf("SI %d \n",m);	
		}
	if (m!=0){
		printf("NO %d \n",m);	
		}*/
	return m;
}
/*
int cheackdiagonal(int *lattice, int n,int w){
	int a,bb,cc;
	for(int i=0;i<n;i++){
		a=0,bb=0,cc=0;
		for(int j=0;j<n;j++){
			a=lattice[i*n+j];
			if (a==1){	
				b=i*n+j;
					if(i!=n){
					for (l=i;l<n;l++){
						if ((l*n+j+l)%n==l){
							bb=lattice[l*n+j+l];
							printf("%d\n",bb)
								}
						if ((l*n-j+l)%n==l){
							cc=lattice[l*n+j-l];
							printf("%d\n",bb)
							}
						}
					}
				}
			}
		}			
}
	
	
*/

int checkmitad(int * lattice, int n){
	int sum=0;
	int a=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n/2;j++){
			sum=sum+lattice[i*n+j];
		}
	}
	if (sum==n/2){
		a=0;}
		//print_lattice(lattice,n);		
		
	if(sum>n/2){
		a=2;}

	return a; // A ==0 POS A  !=0 NEG
}

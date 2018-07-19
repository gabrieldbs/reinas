#ifndef LATTICE_H
#define LATTICE_H
int fill_lattice(int *lattice, int n, double p);
int fill_new_lattice(int *lattice, int n, double *p);
int print_proba_100(double *prob, int n) ;
int print_lattice(int *lattice, int n);
int hist(double proba);
double llenar_proba(double *prob, int n);
#endif

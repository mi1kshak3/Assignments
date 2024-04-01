/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
#define C 3e+14
#define H 6.626e-34
#define K 1.38e-23
#define T1 3000
#define T2 4000
#define T3 5000
#define E 2.71828
#define PI 3.14159


int main()
{
    double lambda, R1, R2, R3;
    
    FILE *out1;
    out1 = fopen ("plottemp1.data", "w");
    
    fprintf (out1, "# lambda(um)   R values(W/m^3)\n");
    
    for (lambda = 0.1; lambda <= 3.0; lambda += 0.1) {
     R1 = (2 * PI * pow(C, 2) * H) / (pow(lambda, 5)) * (1) / (pow(E, ((H) * (C)) / (lambda * K * T1)) - 1);
    fprintf(out1, "%.2lf   %e\n", lambda, R1);
    }
    
    fclose(out1);
    
    FILE *out2;
    out2 = fopen ("plottemp2.data", "w");
    
    fprintf (out2, "# lambda(um)   R values(W/m^3)\n");
    
    for (lambda = 0.1; lambda <= 3.0; lambda += 0.1) {
        R2 = ((2 * PI * pow(C, 2) * H) / (pow(lambda, 5)) * (1) / ((pow(E, ((H) * (C)) / (lambda * K * T2))) -1));
        fprintf(out2, "%.2lf   %e\n", lambda, R2);
    }
    
    fclose(out2);
    
    FILE *out3;
    out3 = fopen ("plottemp3.data", "w");
    
    fprintf (out3, "# lambda(um)   R values(W/m^3)\n");
    
    for (lambda = 0.1; lambda <= 3.0; lambda += 0.1) {
        R3 = ((2 * PI * pow(C, 2) * H) / (pow(lambda, 5)) * (1) / ((pow(E, ((H) * (C)) / (lambda * K * T3))) -1));
        fprintf(out2, "%.2lf   %lg\n", lambda, R3);
    }
    
    fclose(out3);
    
    return 0;
}
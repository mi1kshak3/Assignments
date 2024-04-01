/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
 
int main()
{
    double L4_data; //data from another file
    double employee_number; //the number of employee
    double Shifts; //the total number of shifts worked
    double Wage; //base wage given to employee
    double Hours; //hours worked
    
    FILE *datafile;
    
    datafile = fopen("L4_data.txt", "r");
    
    while(fscanf(datafile, "%lf %lf %lf", &employee_number, &Shifts, &Wage) == 3)
    {
        
        double hoursworked = 0.0;
 
        for (double S = 1; S <= Shifts; S += 1) {
            fscanf(datafile, "%lf", &Hours);
             hoursworked += Hours;
        }
        double gross_pay = hoursworked * Wage;
    }
 
    printf("Employee Number       Total Hours            Gross Pay");
    printf("\n---------------       -----------            ----------");
 
    fseek(datafile, 0, SEEK_SET);
 
    while(fscanf(datafile, "%lf %lf %lf", &employee_number, &Shifts, &Wage) == 3){
        double hoursworked = 0.0;
        double gross_pay = 0.0;
 
        for (double S = 1; S <= Shifts; S += 1) {
            fscanf(datafile, "%lf", &Hours);
            hoursworked += Hours;
        }
            if (hoursworked < 0) {
            } 
            
            else if (hoursworked <= 15) {
            gross_pay = hoursworked * Wage;
            } 
            
            else if (hoursworked <= 25) {
            gross_pay = hoursworked * Wage * 1.05;
            } 
            
            else {
            gross_pay = hoursworked * Wage * 1.10;
            }
            
            printf("\n%.0lf                 %.2lf                  %.2lf", employee_number, hoursworked, gross_pay);
    }
 
    fclose(datafile);
    
    return 0;
}
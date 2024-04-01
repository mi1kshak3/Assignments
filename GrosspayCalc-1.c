/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
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
        
        printf("\n\nEmployee number: %.0lf", employee_number);
        printf("\nNumber of Shifts: %.0lf", Shifts);
        printf("\nBase Wage: %.2lf", Wage);
        
        double hoursworked = 0.0;  // Initialize total hours worked for each employee
 
        // Process the number of shifts and hours worked
        for (double S = 1; S <= Shifts; S += 1) {
            fscanf(datafile, "%lf", &Hours);
            
            hoursworked += Hours;  // Accumulate hours worked
            
            printf("\nShift %.0lf - Hours worked: %.2lf", S, Hours);
        }
        
        printf("\nhours worked %.2lf", hoursworked);
        
        double gross_pay = hoursworked * Wage;  // Calculate gross pay for each shift
 
        printf("\nTotal Pay for employee(%.0lf) is %.2lf", employee_number, gross_pay);
    }
 
    printf("\n\n\nEmployee Number       Total Hours            Gross Pay");
    printf("\n---------------       -----------            ----------");
 
    fseek(datafile, 0, SEEK_SET); // Necessary to re-use fscanf() below.
 
    while(fscanf(datafile, "%lf %lf %lf", &employee_number, &Shifts, &Wage) == 3){
        double hoursworked = 0.0;
        double gross_pay = 0.0;
 
        for (double S = 1; S <= Shifts; S += 1) {
            fscanf(datafile, "%lf", &Hours);
            
            hoursworked += Hours;  // Accumulate hours worked
        }
 
        if (hoursworked<=15){
            gross_pay=hoursworked*Wage;
            } else if (hoursworked>15){
            gross_pay=hoursworked*(Wage*1.05);
            } else if (hoursworked<=25){
            gross_pay=hoursworked*(Wage*1.05);
            } else if (hoursworked){
            gross_pay=hoursworked*(Wage*1.10);
            } else{
            printf("Invalid");
            }
            
            printf("\n%.0lf                 %.2lf                  %.2lf", employee_number, hoursworked, gross_pay);
    }
 
    fclose(datafile);
    
    return 0;
}
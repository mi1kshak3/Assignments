/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 99

void clean(char strng1[], char clnstrng1[]) {
    int i = 0;
    int j = 0;
    
    for (i; i < SIZE; i++)
    {
        clnstrng1[j] = tolower(strng1[i]);
        if (isalnum(strng1[i]))
        {
            j++; 
        }
    }
    clnstrng1[j] = '\0';
}

void reverse(char nonrvrs[], char rvrs[], int i, int j)
{
    if (nonrvrs[i] != '\0')
    {
        reverse(nonrvrs, rvrs, i + 1, j);
        rvrs[strlen(nonrvrs) - 1 - i] = nonrvrs[i];
    } 
    
    else
    {
        rvrs[j] = '\0';
    }
}


int main() 
{
    char strng1[SIZE];
    char clnstrng1[SIZE];
    
    char nonrvrs[SIZE];
    char rvrs[SIZE];
    
    printf("Enter your String: ");
    fgets(strng1, sizeof(strng1), stdin);

    clean(strng1, clnstrng1);
    printf("Cleaned String: %s\n", clnstrng1);
    
    strcpy(nonrvrs,clnstrng1);
    
    reverse(nonrvrs,rvrs, 0, 0);
    printf("Reversed String: %s\n", rvrs);
    
    //if the two strings are same = palindromes
    //if the two strings are NOT same = NOT palindromes
    
    int result;
    
    result = strcmp(rvrs, clnstrng1);
    
    if(result == 0)
    {
        printf("\nThe Sentence entered is a palindrome");
    }
    else
    {
        printf("\nThe Sentence entered is not a palindrome");
    }
    
    return 0;
}




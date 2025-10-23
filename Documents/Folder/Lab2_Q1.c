#include<stdio.h> 
#include <stdbool.h> 
#define SIZE 24
#define nRows 8
#define nCols 3
// PROTOTYPES
void print_array(int array[], int length);
void print_matrix(int mat[][nCols], int rows);
void set_array(int arr [], int length);
void rem_align(int arr[],int length, int pos);
void insert_align(int arr[],int length, int pos, int value);
void reshape(int arr[],int length,int arr2d[nRows][nCols]);
void print_trans_matrix(int arr2d[nRows][nCols],);
bool found_duplicate(int arr[],int length);
int flip_array(int arr[], int length);

int main()
{
int arr[SIZE];
int arr2d[nRows][nCols];
print_matrix(arr2d,nRows);
//Call to different functions
}

void print_array(int array[], int length){
   for(int i=0;i<length; i++)
      printf("array[%d]= %d\n", i, array[i]);
}

void print_matrix(int mat[][nCols], int rows){
   for(int i=0;i<rows; i++){
    for(int j=0;j<nCols; j++)
         printf("mat[%d][%d]= %d\n", i,j, mat[i][j]);
    puts("");     
   }     
}

//FUNCTION DEFINITIONS
void set_array(int arr [], int length){
   for(int i = 0; i < length; i++){
      
   }
}
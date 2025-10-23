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
void print_trans_matrix(int arr2d[nRows][nCols]);
bool found_duplicate(int arr[],int length);
void flip_array(int arr[], int length, int newArr[]);

int main()
{
int arr[SIZE];
int arr2d[nRows][nCols];


//Call to different functions
set_array(arr, SIZE);
print_array(arr, SIZE);
// reshape(arr, SIZE, arr2d);
// print_trans_matrix(arr2d);
int newArr[SIZE];
flip_array(arr, SIZE, newArr);
print_array(newArr, SIZE);
puts("");
print_array(arr, SIZE);
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
      arr[i] = i;
   }
}

void rem_align(int arr[],int length, int pos){
   if(pos < 0 || pos >= length){
       printf("invalid index");
   }else{
      for(int i = pos; i < length - 1; i++){
         arr[i] = arr[i+1];
      }
      arr[length - 1] = 0;
   }
   
}

void insert_align(int arr[],int length, int pos, int value){
   if(pos < 0 || pos >= length){
       printf("invalid index");
   }else{
      for(int i = length - 1; i > pos; i--){
         arr[i] = arr[i-1];
      }
      arr[pos] = value;
   }
}

void reshape(int arr[],int length,int arr2d[nRows][nCols]){
   if (length != nRows * nCols){
       printf("Invalid dimensions for reshape");
   }else{
       for(int i = 0; i < nRows; i++){
           for(int j = 0; j < nCols; j++){
               arr2d[i][j] = arr[i * nCols + j];
           }
       }
   }
}

void print_trans_matrix(int arr2d[nRows][nCols]){
   printf("C1\tC2\tC3\n");
   for(int i = 0; i < nRows; i++){
       for(int j = 0; j < nCols; j++){
           printf("%d\t", arr2d[i][j]);
       }
       printf("\n");
   }
}

bool found_duplicate(int arr[],int length){
   for(int i = 0; i < length; i++){
       for(int j = i + 1; j < length; j++){
           if(arr[i] == arr[j]){
               return true;
           }
       }
   }
   return false;
}

void flip_array(int arr[], int length, int newArr[]){
   for(int i = 0; i < length; i++){
       newArr[i] = arr[length - 1 - i];
   }
}

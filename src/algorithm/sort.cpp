#include "sort.h"

int ParticionFunc(int *array, int low, int high){

}


void quicksort(int *array, int low, int high){
   if(low<high)
   {
         int pivot =ParticionFunc(array, low,  high);
         quicksort( array, low, pivot );
         quicksort( array, pivot+1, high );
   }     

}
//
// Longest Increasing Subsequence
//
#include <stdio.h>
#include <string.h>

int main() {
	int arr[] = { 10,9,2,5,3,4,101,9,11};
	int length = 9;
	
	//
	// Using Dynamic Programming - Memoization
	// Initializing all the elements to 1 because arr[0] to arr[0] Longest incresing subsequence is 1
	//
	int lis[] = {1,1,1,1,1,1,1,1,1};
  
  	//
  	// For every element check the LIS like LIS for 0..1,0...2, 0..3 and so on
  	//
   	for ( int j = 1; j < length ; j++) {
   	   for ( int i = 0; i < j ; i++) {
   	   	   	 //
   	   	   	 //  If arr[i[ < arr[j] , increment lis[j] = lis [i] + 1 for eg. lis[0...4] = 2 , lis[0...5] =  lis[4] + 1
   	   	   	 //
  	   	   	 if ( arr[i] < arr[j] ) {
   	   	   	 	  lis [j] = lis [i] + 1;
  				}
   	   
		  }
   }
   
   //
   // Complexity is O(n^2)
   //
	
	printf ( " Length of Longest Increasing Subsequence = %d" , lis[length-1]);
	
	
	return 0;
}



//
// Count of strings that can be formed using a, b and c under given //   //constraints
//

#include <stdio.h>
#include <string.h>

//
// Passing multidimensional array - First element is undefined - Works !!
//
int countNoOfStrings ( int dp[][2][3],int n, int bCount, int cCount) {  

  //
  // Sequence of the first and second if condition matters, since the first
  // condition is mandatory 
  //
  if ( bCount < 0 || cCount < 0) {
    return 0;  
   }
  
  //
  // There can be a string which exists with b and c as 0
  //
  if ( bCount == 0 && cCount == 0) {
   return 1; 
  }
  
  //
  // For every single combination, we need to add 1 to result
  //
   if ( n == 0 ) {
    return 1;
   }
  
  if ( dp[n][bCount][cCount] != -1) {
    return dp[n][bCount][cCount]; 
  }

  int result;
  //
  // Three cases : Case a, Case b and Case c
  //
  result = countNoOfStrings ( dp,n-1,bCount, cCount);
  result = result + countNoOfStrings ( dp,n-1, bCount-1,cCount);
  result = result + countNoOfStrings ( dp,n-1, bCount, cCount - 1);
  // Yes, you can assign and return 
  return ( dp[n][bCount][cCount] = result);

}


int main() {
  
  int n = 3;
  int dp[n+1][1+1][2+1];
  //
  // Memset is defined in string.h
  //
  memset(dp, -1 , sizeof(dp));
  countNoOfStrings ( dp,n,1,2);
  
  //
  // dp[n][j][k] - Denotes how many strings can be formulated of size n
  // with max j "b" and k "c"
  // We add +1 to all the three indices because [0][][] makes no sense
  
  printf (" \n Number of strings = %d", dp[n][1][2]);
  return 0; 
}

//
// Recursion Program : Complexity - exponential
//
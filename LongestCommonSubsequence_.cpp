//
// Longest Common Subsequence
//
#include <stdio.h>
#include <string.h>

int max ( int a , int b) {
	if ( a > b) return a;
	else
		return b;
}

int main() {
	char str2[] = "payalsdesai";
	char str1[] = "dhavalsdesai";
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	int lcs[len1][len2];
	int flag = 0;
	int i,j,diff;
	diff = len1 - len2;
	
	//
	//  Initializing the first row and column to 0
	//
	for ( i = 0 ; i < len1 ; i++ ) {
		lcs[i][0] = 0;
    }
    for ( i = 0 ; i < len2 ; i++ ) {
		lcs[0][i] = 0;
    }
	for ( i = 1; i < len1; i++) {
 		flag = 0;
		for ( j = 1; j < len2; j++) {
				
			if ( (flag == 0) && ( str1[i] == str2[j])){
			   //
			   //	Add 1 to the diagonal element 
			   //
			   lcs[i][j] = lcs[i-1][j-1] + 1; 
			   flag = 1;
		    } else {
			   //
			   // Maximum of the left or upper element in the matrix
			   //
			   lcs[i][j] = max ( lcs[i-1][j], lcs[i][j-1]);
			   flag = 0;
			
			}
			
		}
	}
	
	char lcsString[lcs[len1-1][len2-1]];
	int count = lcs[len1-1][len2-1] - 1;
	//
	// Printing the  longest common subsequence
	//
	for ( i = len1-1 ; i > 0 ; i--) {
		for ( j = len2-1; j > 0; j--) {
			//
			// Print Diagonal elements
			//
			if ((i - diff) == j ) {
				if (( str1[i] == str2[j]) && (lcs[i][j] == (lcs[i-1][j-1] + 1 ))){
				   //
				   // Prints the LCS in reverse fashion
				   //
				   lcsString[count--] = str2[j];
 		    
				}
			}
		}
	}
	lcsString[lcs[len1-1][len2-1]] = '\0';
	
	printf ( "Length of Longest Common Subsequence = %d",lcs[len1-1][len2-1]);
	printf ( "\n %s", lcsString);
	return 0;
}

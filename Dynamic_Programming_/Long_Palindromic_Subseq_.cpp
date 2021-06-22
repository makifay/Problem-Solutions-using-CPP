// length of the Longest Palindromic Subsequence 

// n:string size 
// Time : O(n^2)
// Space: O(n^2)

#include<iostream> 
#include<string> 

// utiliy func to return the max 
int max (int x, int y) { return (x > y)? x : y; } 


int lps(std::string &str) 
{ 
    int n = str.size(); 
    int i, j, sl; 
    int L[n][n]; // memoization table to store results of subproblems (0 ... n-1)
    
    // palindrome lentgh 1 for string which has 1 item
    for (i = 0; i < n; i++) 
    	L[i][i] = 1; // diagonal of matrix 


	// Lower diagonal values are useless and not filled  
	// sl: length of substring 
	for (sl=2; sl<=n; sl++) { 
		for (i=0; i<n-sl+1; i++) { 
		    
			j = i+sl-1; 
			if ( sl == 2 &&  str[i] == str[j] ) // not required to look at the table
			    L[i][j] = 2; 
			else if (str[i] == str[j]) 
		    	L[i][j] = L[i+1][j-1] + 2; 
			else // if not equal, check the other items
		    	L[i][j] = max( L[i+1][j],     
		    	               L[i][j-1]  );
		} 
	} 

	return L[0][n-1]; // last item of the first row gives the max
} 


int main() 
{ 
	std::string s1 = "IT IS A RACECAR ALSO"; 
	std::cout << "1.The length of the LPS is " << lps(s1) << std::endl; 
	
	std::string s2 = "kagbdbaik"; 
	std::cout << "2.The length of the LPS is " << lps(s2) << std::endl;
	
	return 0; 
} 

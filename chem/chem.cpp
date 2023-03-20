#include <iostream>
#include <algorithm>
#include <fstream>

//#define cin fin 

using namespace std;

//ifstream fin("input14.txt"); 


int main(){

	int N, K, i, j, l;
	cin >> N >> K;
	
	int A[N][N];
	int DP[K][N];
	
	for (i=0; i<N; i++){
		for (j=0; j<N; j++){
			if (j<=i){
				A[i][j]=0;
			}
			else{			
				cin >> A[i][j];
			}		
		}	
	}

	
	for (i=0; i<N; i++){
		for (j=i+1; j<N; j++){
			A[i][j] = A[i][j]+A[i][j-1];
			for (l=i+1; l<j; l++)
				A[i][j] = A[i][j]+A[l][j];
			
		}	
	}
	


	for (i=0; i<K; i++){
		for (j=0; j<N; j++){
			DP[i][j] = 0;		
		}	
	}

	for (j=0; j<N; j++)
		DP[0][j] = A[0][j];

	

	for (i=1; i<K; i++){
		for (j=0; j<N; j++){
			int min = A[0][N-1];
			for (l = 0; l<j; l++){
				if ((DP[i-1][l]+A[l+1][j]) < min)
					min = DP[i-1][l]+A[l+1][j];		
			}
			DP[i][j] = min;
				
		}
	}

	cout << DP[K-1][N-1] << endl;

	return 0;
}





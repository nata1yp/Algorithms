#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <algorithm>
#include <time.h>
#include <stdint.h>
#include <fstream>

//#define cin fin 

using namespace std;

//ifstream fin("ex.txt"); 

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int main(){
	/*clock_t start, end;
    	start = clock();
	*/
	int N ,K, D,i, T, Ts, Cs, Tf, Cf;
	
	cin >> N >> K >> D >>T;
	
	int (*pc)[2] = new int[N][2], *d = new int[K+1] ;
	

	for (i=0; i<N; i++){
		cin >> pc[i][0] >> pc[i][1];
	}

	int max = 0;
	for (int i=0; i<K; i++){
		cin >> d[i];
		if (d[i] > max)
			max = d[i];
	}
	
	cin >> Ts >> Cs >> Tf >> Cf;


	qsort (pc, N , sizeof(*pc), [](const void *arg1, const void *arg2)->int
        {
            int const *lhs = static_cast<int const*>(arg1);
            int const *rhs = static_cast<int const*>(arg2);
            return (lhs[0] < rhs[0]) ? -1
                :  ((rhs[0] < lhs[0]) ? 1
                :  (lhs[1] < rhs[1] ? -1
                :  ((rhs[1] < lhs[1] ? 1 : 0))));
        });

	
	qsort (d, K , sizeof(int), compare);

	//ypologismos apostasewn metaksi tn stathmwn
	int sum = d[0];
	if (K > 1){
		for (int i=1;i<K;i++){
			d[i] = d[i] - sum;
			sum = sum + d[i];
			}
	}
	d[K]= D - max; //apostasi apo ton telefteo stathmo mexri ton proorismo


	long int time[N];
	int j, ans, l=0;
 	int L_eco, km_sport, km_eco;
	for (i=0; i < N; i++){
		time[i] = 0;
		int p = pc[i][0];
		int c = pc[i][1];
		//cout << i << " ";
		for (int j=0; j < K+1; j++){
				//cout << j << endl;
				//elegxos an iparxei i dinatotita na ftasw ston epomeno stathmo (i sto terma)
				L_eco = d[j]*Cs;

				if (L_eco > c){
					time[i]=T+1;
					break;
				}

				km_sport = c/Cf;

				//elegxos an mporw n xrisimopoiisw mono t sport				
				if (km_sport >= d[j]){
					km_sport=d[j];
					km_eco=0;
				}
				else{
				//an oxi, ipologismos posa km sport kai posa eco
					km_sport=(c-L_eco)/(Cf-Cs);
					km_eco = d[j]-km_sport;
				}
				

				time[i]= km_sport*Tf + km_eco*Ts + time[i];
				
		}
		//cout << time[i] << endl;

		if (time[i]<=T){
			ans = p;
			break;
			
		}
		else
			ans = -1;
			l++;
	}
	 
	cout << ans << endl;

	/*end = clock();
	double duration_sec = double(end-start)/CLOCKS_PER_SEC;
	cout << duration_sec; 
	*/
 return 0;
}





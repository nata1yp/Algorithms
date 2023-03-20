#include<iostream>
#include <fstream>
#include <algorithm>

//#define cin fin 

using namespace std;

//ifstream fin("input19.txt"); 

struct offer{
	string type;
	int amount;
	int cost;
};


void init(int A[], int B[], int C[], int N){
	int i;	
	A[0]=0; B[0]=0; C[0]=0;
	for (i=1; i<N+1; i++){
		A[i]=B[i]=C[i] = 1000000001;
	}	
}

void knapsack(offer X[], int K[], int N, int M, string item, int &pos){	
	int cur = 0;
	int i, j;	
	for (i=pos; i<M; i++)
	{
		if (X[i].type != item){
			pos=i;
			break;
		}
		int size = X[i].amount;
		int price = X[i].cost;
		cur = cur+size;
		for (j=min(cur, N); j>0; j--){
			int res=max(j-size,0);
			K[j] = min(K[j], K[res]+price);
		}
	}
	for (j=cur+1; j<N+1; j++)
			K[j] = 0;
}


void merge(int P[], int A[], int B[], int C[], int N, int &max){
	int i;
	for (i=0; i<N+1; i++){
		if (A[i]!=0 && B[i]!=0 && C[i]!=0){
			max = i;
			P[i]=A[i]+B[i]+C[i];
		}
		else P[i] = 0;
	}
}


bool offer_op(offer o1,offer o2){
    if((o1.type==o2.type) && (o1.cost==o2.cost))
        return o1.amount<o2.amount;
    if(o1.type==o2.type)
        return o1.cost<o2.cost;
    return o1.type<o2.type;
}

int main(){
	
	int N, M;	
	int i, j;
	char y;

	cin >> N >> M;
		

	struct offer O[M];

	for (i=0; i<M; i++){
		cin >> O[i].type;
		cin >> O[i].amount;
		cin >> O[i].cost;	
	}

	sort(O,O+M,offer_op);
		
	int A[N+1], B[N+1], C[N+1];
	int P1[N+1], P2[N+1], P3[N+1];
	int max1, max2, max3;
	max1=max2=max3=0;

	int pos = 0;
	string item;
	
	//politis 1
	init(A, B, C, N);
	
	item = "1A";
	knapsack(O, A, N, M, item, pos); 

	item = "1B";
	knapsack(O, B, N, M, item, pos); 

	item = "1C";
	knapsack(O, C, N, M, item, pos);

	merge(P1, A, B, C, N, max1);

	
	//politis 2
	init(A, B, C, N);

	item = "2A";
	knapsack(O, A, N, M, item, pos); 

	item = "2B";
	knapsack(O, B, N, M, item, pos); 

	item = "2C";
	knapsack(O, C, N, M, item, pos);

	merge(P2, A, B, C, N, max2);

 	
	//politis 3
	init(A, B, C, N);
	
	item = "3A";
	knapsack(O, A, N, M, item, pos); 

	item = "3B";
	knapsack(O, B, N, M, item, pos); 

	item = "3C";
	knapsack(O, C, N, M, item, pos);

	merge(P3, A, B, C, N, max3);



	
	if (max1+max2+max3<N){ 
		cout << "-1\n"; 
		return 0;
	}

	int res=1000000001;
	for (i=0; i<=min(N, max1); i++){
		for (j=0; j<=min(N-i,max2); j++){
			if (i+j+max3>=N){
				res = min(res, P1[i]+P2[j]+P3[N-i-j]);
			}		
		}
	}
	cout << res << endl; 

	return 0;
}



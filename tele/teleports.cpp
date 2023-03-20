#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//#define cin fin

using namespace std;

//ifstream fin("input28.txt"); 

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

struct subset {
	int parent;
	int rank;
	int morty;
};

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i) 
	subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}


void Union(struct subset subsets[], int xroot, int yroot)
{
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int main(){
	int N, M;
	int i, j; 
	int p_a, p_b, p_am, p_bm;
	cin >> N >> M;
	
	int c[N+1];
	int p[M+1][3];

	c[0]=100001;
	for (i=0; i<3; i++)
		p[0][i]=1000000001;

	for (i=1; i<=N; i++){
		cin >> c[i];
	}
	
	for (j=1; j<=M; j++){
		for (i=0; i<3; i++)
			cin >> p[j][i];
	}

	qsort (p, M+1 , sizeof(*p), [](const void *arg1, const void *arg2)->int
        {
            int const *lhs = static_cast<int const*>(arg1);
            int const *rhs = static_cast<int const*>(arg2);
            return (lhs[2] > rhs[2]) ? -1
                :  ((rhs[2] > lhs[2]) ? 1
                :  (lhs[1] > rhs[1] ? -1
                :  ((rhs[1] > lhs[1] ? 1 
			: 0))));
        });


 	struct subset* subsets = (struct subset*)malloc((N+1) * sizeof(struct subset));


   	for (int v = 1; v <= N; v++) {
        	subsets[v].parent = v;
        	subsets[v].rank = 0;
		subsets[v].morty = c[v];
    	}

	int min = p[0][2];

	
	for (j=1; j<=M; j++){
		int a = p[j][0];
		int b = p[j][1];
		p_a = find(subsets, a);
		p_b = find(subsets, b);
		p_am = find(subsets, subsets[a].morty);
		p_bm = find(subsets, subsets[b].morty);

		if ((p_a!=p_am) || (p_b!=p_bm)){
	        	Union(subsets, p_a, p_b);
			min = p[j][2];
		}
		else if ((p_a!=p_b) && ((p_a!=a) || (p_b!=b))){
	        	Union(subsets, p_a, p_b);
			min = p[j][2];
		}
	}

	cout << min << endl;

	return 0;
}







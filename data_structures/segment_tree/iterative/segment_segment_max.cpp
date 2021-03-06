/*																													   
 Templatka c++ Kacper Fis																							   																											   //
*/																													  
																								   
#include <bits/stdc++.h>																							   
																													   
using namespace std; 																								   
																													   
const int INF = 1000000001;																						   
const float PI = 3.14;																								   
typedef long long LL;																								   
																													   
typedef vector<int> vi;																								   
typedef list<int> li;																								   
typedef queue<int> qi; 																								   
typedef pair<int,int> ii; 																							   
typedef map<string,int> msi; //np msi['nazwa'] = 'liczba'															   
typedef vector<ii> vii; //vector par<int>, do tworzenia tablicy dla grafów wagowych #dijkstra #Bellman_Ford			   
typedef priority_queue< ii, vector<ii>, greater<ii> > pq; //kolejka priorytetowa vectorów par(top()=min) #dijkstra	   
																													   																				   
vector<ii>::iterator iter;																							   
																													   																				   
#define print_list(x) for(it = (x).begin(); it != (x).end(); it++) {cout << *it << " ";}							   
#define print_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++) {cout << *it2 << " ";}						   
#define search_list(x) for(it = (x).begin(); it != (x).end(); it++)													   
#define search_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++);											   
#define pb(x) push_back(x) 																							   
#define pf(x) push_front(x)																							   
#define mp(x, y) make_pair(x, y)                                                                                       
///////////////////////////////////////////////GLOBAL DEFINITIONS////////////////////////////////////////////////////////

const int p = 19;
int tree[10000005];
int leaf = 1 << (p - 1);
int lazy[10000005];

///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

void apply(int x, int v){
	tree[x] += v;
	if(x < leaf) lazy[x] += v;
}

void push(int x){
	for(int j = p; j > 0; j--){
		int i = x >> j;
		if(lazy[i]){
			apply(i * 2, lazy[i]);
			apply(i * 2 + 1, lazy[i]);
			lazy[i] = 0;
		}
	}
}

void build(int x){
	x /= 2;
	while(x){
		tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
		x /= 2;
	}
}

void insert(int l, int r, int v){
	int L = l += leaf, R = r += leaf;
	//faza 1
	push(L);
	push(R);
	
	//faza 2
	apply(L, v);
	if(L != R) apply(R, v);
	while(l / 2 != r / 2){
		if(l % 2 == 0) apply(l + 1, v);
		if(r % 2 == 1) apply(r - 1, v);
		l /= 2; r /= 2;
	}
	
	//faza 3
	build(L);
	build(R);
}

int Query(int l, int r){
	l += leaf; r += leaf;
	
	push(l);
	push(r);
	
	int ans = max(tree[l], tree[r]);
	while(l / 2 != r / 2){
		if(l % 2 == 0) ans = max(ans, tree[l + 1]);
		if(r % 2 == 1) ans = max(ans, tree[r - 1]);
		l /= 2; r /= 2;
	}
	return ans;
}
/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					 
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                  												       
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
     * Drzewo przedziałowe typu przedział-przedział (znajdujące maximum na przedziale)
     * */
    int q; //liczba zapytań
    cin >> q;
    for(int i = 0; i < q; i++){
		int x;
		cin >> x;
		if(x == 1){
			//add
			int a, b, v;
			cin >> a >> b >> v;
			insert(a, b, v);
		}
		else if(x == 2){
			//query
			int a, b;
			cin >> a >> b;
			cout << Query(a, b) << endl;
		}
	}
	




	
	return 0;
}

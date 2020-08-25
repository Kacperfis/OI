#include <bits/stdc++.h>																							   
																													   
using namespace std; 																								   
					
typedef long long LL;																									   
const int INF = 1000000001;																						   
const float PI = 3.14;																								   																							   
																													   
typedef vector<int> vi;																								   
typedef list<int> li;																								   
typedef queue<int> qi; 																								   
typedef pair<int,int> ii; 																							   
typedef map<string,int> msi; //np msi['nazwa'] = 'liczba'															   
typedef vector<ii> vii; //vector par<int>, do tworzenia tablicy dla grafów wagowych #dijkstra #Bellman_Ford			   
typedef priority_queue< ii, vector<ii>, greater<ii> > pq; //kolejka priorytetowa vectorów par(top()=min) #dijkstra	   
																													   																				   
																													   																				   
#define print_list(x) for(it = (x).begin(); it != (x).end(); it++) {cout << *it << " ";}							   
#define print_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++) {cout << *it2 << " ";}						   
#define search_list(x) for(it = (x).begin(); it != (x).end(); it++)													   
#define search_vector(x) for(it2 = (x).begin(); it2 != (x).end(); it2++);											   
#define pb(x) push_back(x) 																							   
#define pf(x) push_front(x)																							   
#define mp(x, y) make_pair(x, y)                                                                                       
///////////////////////////////////////////////GLOBAL DEFINITIONS////////////////////////////////////////////////////////

LL tab[1005][1005];
LL pref_sum[1005][1005];

///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					 
{ios_base::sync_with_stdio(false); cin.tie(NULL);    
	
	int n, m, q;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> tab[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			pref_sum[i][j] = pref_sum[i-1][j] + pref_sum[i][j-1] - pref_sum[i-1][j-1] + tab[i][j];
		}
	}
	
	cin >> q;
	for(int i = 1; i <= q; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << pref_sum[c][d] - pref_sum[a-1][d] - pref_sum[c][b-1] + pref_sum[a-1][b-1] << '\n';
	}
	
}              												       
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

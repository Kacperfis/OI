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

int P = 1e9 + 7;
int f[1000005];
int inv_f[1000005];

///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

int fastPow(int a, int b){
	int result = 1;
	while(b){
		if(b % 2) result = (1LL * result * a) % P;
		a = (1LL * a * a) % P;
		b /= 2;
	}
	return result;
}

int binomial(int n, int k){
	return 1LL * f[n] * inv_f[k] % P * inv_f[n - k] % P;
}

/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					 
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                  												       
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	 * Zauważmy, że we wzorze na współczynnik newtona(n! / k!(n - k)!)
	 * dzielenie możemy zapisać jako mnożenie przez odwrotność, a jeśli
	 * chcemy obliczyć jakąś odwrotność liczby: A^-1 mod P, to możemy 
	 * skorzystać z odwrotności modularnej, i najpierw wykonać preprocessing
	 * w O(n) w którym obliczmy wartości n!, (k!^-1 mod P)->jako odwrotność
	 * i (n - k)!^-1 mod P -> też jako odwrotność,a potem tylko wymnożymy 
	 * wszystkie wartości między sobą już według wzoru:
	 * 
	 * (n! mod P) * (k!^-1 mod P) * ((n - k)!^-1 mod P)
	 *
	 * */
	int n, k;
	cin >> n >> k;
	
	f[0] = inv_f[0] = 1;
	for(int i = 1; i <= 1000000; i++){
		f[i] = (f[i - 1] * 1LL * i) % P;
		inv_f[i] = fastPow(f[i], P - 2);
	}
	
	cout << binomial(n, k) << endl;
	
	
	return 0;
}

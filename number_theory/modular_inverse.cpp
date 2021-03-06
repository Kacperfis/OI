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

const int P = 1e9 + 7;

///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

int Fast_Pow_modular_inverse(int a, int b){
	int result = 1;
	
	while(b){
		if(b % 2) result = (1LL * result * a) % P;
		a = (1LL * a * a) % P;
		b /= 2;
	}
	return result;
}
/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					 
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                  												       
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/* 									 
	 *	 (1)	(A / B) mod P = (A * B^-1) mod P	
	 * 	 (2)	(A^-1) mod P = A^(p-2) mod P
	 * 
	 * 	 W owdrotności modularnej wykonujemy po prostu operację (1)
	 * 	 korzystając z zależności (2) -> obliczamy drugą część działania (1):
	 * 	 [ (B^-1) mod P ], by potem móc wykonać działanie (1)						
	 * 									 	
	 * */

	int a;
	cin >> a;
	cout << Fast_Pow_modular_inverse(a, P-2);
	
	
	return 0;
}

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

string s1, s2;
int dp[1000][1000];

///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

string LCS(string X, string Y, int n, int m){
	if(n == 0 || m == 0)
		return string("");
		
	else if(X[n-1] == Y[m-1])	
		return LCS(X, Y, n-1, m-1) + X[n-1];
		
	else if(dp[n-1][m] > dp[n][m-1])
		return LCS(X, Y, n-1, m);
		
	else return LCS(X, Y, n, m-1);
}

/////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])																					 
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                  												       
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cin >> s1 >> s2;
	
	int n = s1.size();
	int m = s2.size();
	
	for(int i = 0; i < n; i++){
		dp[0][i] = 0;
		dp[i][0] = 0;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s1[i - 1] != s2[j - 1]){
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
			else dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
		}
	}
	
	string ans = LCS(s1, s2, n, m);
	cout << "dlugosc lcs: " << dp[n][m] << endl;
	cout << "lcs: " << ans << endl;
	
	return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

// Maximum number of states, at least as large as the sum of all key word's length.
const int MAX = 505 * 505 * 4;

// Alphabet size, 26 for lower case English letters.
const int ALPHA_SIZE = 26 + 1;
const int FAIL = -1;

// Maximum length of the text.
const int MAX_LENGTH = 1200010;

int g[MAX][ALPHA_SIZE];
int f[MAX];
vector<int> output[MAX];
char text[MAX_LENGTH];
int new_state;

void enter(char *word, int index)
{
    int length = strlen(word);
    int j, state = 0;
    for (j = 0; j < length; j++) {
        int c = word[j] - 'a';
        if (g[state][c] == FAIL)
            break;
        state = g[state][c];
    }

    for ( ; j < length; j++) {
        int c = word[j] - 'a';
        new_state++;
        g[state][c] = new_state;
        state = new_state;
    }

    output[state].push_back(index);
}

int main(int argc, char *argv[])
{ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int  n;
    char word[1200005];
    int count[1200005];

    cin >> n;
	
    // Build goto function
    new_state = 0;
    memset(g, -1, sizeof g);
    memset(f, -1, sizeof f);
    for (int i = 0; i < MAX; i++)
        output[i].clear();

    // Read patterns and build the Trie
    for (int i = 0; i < n; i++) {
        cin >> word;
        count[i] = 0;
        enter(word, i);
    }
    
    //read main text
    cin >> text;

    for (char c = 'a'; c <= 'z'; c++) {
        int a = c - 'a';
        if (g[0][a] == FAIL)
            g[0][a] = 0;
    }

    // Build failure function
    queue<int> Q;
    for (char c = 'a'; c <= 'z'; c++) {
        int a = c - 'a';
        int s = g[0][a];
        if (s != 0) {
            Q.push(s);
            f[s] = 0;
        }
    }

    while (!Q.empty()) {
        int r = Q.front();
        Q.pop();
        for (char c = 'a'; c <= 'z'; c++) {
            int a = c - 'a';
            int s = g[r][a];
            if (s != FAIL) {
                Q.push(s);
                int state = f[r];
                while (g[state][a] == FAIL)
                    state = f[state];
                f[s] = g[state][a];
                for (unsigned k = 0; k < output[f[s]].size(); k++)
                    output[s].push_back(output[f[s]][k]);
            }
        }
    }

    // Count occurrences
    
    //int licznik_wszystkich_wystapien = 0;
    int state = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        int a = text[i] - 'a';
        while (g[state][a] == FAIL)
            state = f[state];
        state = g[state][a];
        for (unsigned k = 0; k < output[state].size(); k++){
            count[output[state][k]]++;
            //licznik_wszystkich_wystapien++;
		}
    }
    
    //printing the number of occurences for every pattern
    for(int i = 0; i < n; i++){
		cout << count[i] << '\n';
	}
  

    return 0;
}

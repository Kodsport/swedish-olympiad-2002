#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int wordCount;
char words[11][10];
bool nozero[256];
int mapping[256];
char order[21];
bool used[10];

void rec(int at, int col, int sum);


int main(){
	scanf("%d", &wordCount);
	for(int i = 0; i<=wordCount; i++){
		scanf("%s", words[i]);
		nozero[(int)words[i][0]] = true;
		int len = strlen(words[i]);
		reverse(words[i], words[i]+len);
	}
	int chars = 0;
	for(int i = 0; i<8; i++){
		bool keep = false;
		for(int j = 0; j<=wordCount; j++){
			char* word = words[j];
			if(strlen(word) <= (size_t)i) continue;
			keep = true;
			for(int l = 0; l<=chars; l++){
				if(order[l] == word[i]) break;
				if(order[l] == 0){
					order[l] = word[i];
					chars++;
					break;
				}
			}
		}
		if(!keep) break;
		order[chars++] = 1;
	}

	memset(mapping, -1, sizeof(mapping));
	rec(0, 0, 0);
}

void rec(int at, int col, int sum){
	if(order[at] == 1){
		int expected = mapping[words[wordCount][col]];
		if(sum%10 != expected){
			return;
		}
		sum /= 10;
		for(int i = 0; i<wordCount; i++){
			char* word = words[i];
			if(strlen(word) <= col+1) continue;
			if(mapping[word[col+1]] != -1){
				sum += mapping[word[col+1]];
			}
		}
		rec(at+1, col+1, sum);
	} else if(order[at] == 0){
		for(int i = 0; i<=wordCount; i++){
			for(int j = strlen(words[i])-1; j >= 0; j--){
				printf("%d", mapping[words[i][j]]);
			}
			printf("\n");
		}
		exit(0);
	} else {
		for(int i = 0; i<10; i++){
			if(!used[i] && (i != 0 || !nozero[order[at]])){
				mapping[order[at]] = i;
				used[i] = true;
				int nsum = sum;
				for(int j = 0; j<wordCount; j++){
					char* word = words[j];
					if(strlen(word) <= col) continue;
					if(word[col] == order[at]){
						nsum += mapping[word[col]];
					}
				}
				rec(at+1, col, nsum);
				mapping[order[at]]  = -1;
				used[i] = false;
			}
		}
	}
}

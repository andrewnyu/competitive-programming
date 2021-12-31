//CF 271D: Good Substrings
#include <iostream>
#include <vector>
using namespace std;
const int ALPHABET_SIZE = 26;

struct TrieNode{
	struct TrieNode *children[ALPHABET_SIZE+1];
	bool EOW; //end of word
};

struct TrieNode *getNode(){

	struct TrieNode *pNode = new TrieNode;
	pNode->EOW = false;

	for(int i=0; i<ALPHABET_SIZE; i++){
		pNode->children[i] = NULL;
	}

	return pNode;
}

void insert (struct TrieNode *root, string key){
	struct TrieNode *pCrawl = root;

	for(int i=0; i<key.length(); i++){
		int idx = key[i] - 'a';
		if(!pCrawl->children[idx]){
			pCrawl->children[idx] = getNode();
		}
		pCrawl = pCrawl->children[idx];
	}
}

bool search(struct TrieNode *root, string key){
	struct TrieNode *pCrawl = root;

	for(int i=0; i<key.length(); i++){
		int idx = key[i] - 'a';
		if(!pCrawl->children[idx]){
			return false;
		}
		pCrawl = pCrawl->children[idx];
	}
	return (pCrawl!=NULL && pCrawl->EOW);
}

int main(){
	string a;
	cin>>a;

	string alph;
	cin>>alph;


	int val[ALPHABET_SIZE+1];
	for(int i=0; i<ALPHABET_SIZE; i++){
		val[i] = 1-(alph[i]-'0');
	}

	int k;
	cin>>k;

	//solve
	int ck=0; //current count of k
	long long int res=0;
	TrieNode *root = getNode();
	//string current = "";
	for(int i=0; i<a.length(); i++){
		struct TrieNode *pCrawl = root;
		//current = "";
		int j=i;
		ck=0;
		while(j<a.length() && ck<=k){
			//current+=a[j];
			int cchar = a[j]-'a';
			ck+=val[cchar];

			if(ck>k){
				break;
			}

			if(!pCrawl->children[cchar]){
				pCrawl->children[cchar] = getNode();
				res+=1;
				//cout<<current<<endl;
				//cout<<ck<<endl;
			}
			pCrawl=pCrawl->children[cchar];
			
			j+=1;
		}
	}

	cout<<res<<endl;

}
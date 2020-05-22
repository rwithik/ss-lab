#include<bits/stdc++.h>

using namespace std;

vector<string> split(string line){
  vector<string> words;
  string word = "";
  for (auto ch: line){
    if (ch == '^'){
      words.push_back(word);
      word = "";
    }
    else {
      word.push_back(ch);
    }
  }
  words.push_back(word);
  return words;
}

int main(int argc, char const *argv[])
{
	fstream input("input.txt", ios::in);
	int pos = 1000;

	string line;
	vector<string> words;

	getline(input, line);
	getline(input, line);
	words = split(line);

	int j; 

	while(line[0] != 'E') {
		int pos = stoi(words[1]);
		for(int i = 3; i < words.size()-1; ++i) {
			int j = 0;
			// cout << words[i] << ":";
			cout << pos++ << " " << words[i][j] << words[i][j+1] << endl;
			j += 2;
			cout << pos++ << " " << words[i][j] << words[i][j+1] << endl;
			j += 2;
			cout << pos++ << " " << words[i][j] << words[i][j+1] << endl;
			j += 2;

		}
		cout << endl;

		getline(input, line);
		words = split(line);
	}
	return 0;
}
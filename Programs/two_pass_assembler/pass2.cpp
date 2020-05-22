#include<bits/stdc++.h>

using namespace std;

vector<string> split(string line){
  vector<string> words;
  string word = "";
  for (auto ch: line){
    if (ch == ' '){
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

string assemble(string opcode, string symcode){
  return opcode + symcode;
}

int main(int argc, char const *argv[])
{
  map<string, string> optab = {
    {"LDA", "03"},
    {"STA", "14"},
    // {"SUB", "05"},
    {"ADD", "16"}
  };

  map<string, string> symtab;
  vector<string> words;
  string line;
	fstream ifile("if.txt", ios::in);
  fstream objfile("obj.txt", ios::out);
  fstream symtabf("symtab.txt", ios::in);

  while(getline(symtabf, line)){
    words = split(line);
    symtab.insert(pair<string, string>(words[0], words[1]));
  }

  getline(ifile, line);
  words = split(line);

  string len = "0C";
  string start; 

  int pos = 0;
  if (words[2].compare("START") == 0){
    objfile << "H^" << words[1];
    cout << "H^" << words[1];
    pos += 1;
    pos += words[1].size();
    while(pos < 7){
      pos ++;
      objfile << "0";
      cout << "0";
    }
    objfile << "^" << "00";
    cout << "^" <<"00";
    objfile << words[3] << "^" << len << endl;
    cout << words[3] << "^"  << len << endl;
    start = words[3];
    getline(ifile, line);
    words = split(line);
  }

  string opcode, symcode;

  objfile << "T^";
  cout << "T^";

  objfile << "00";
  cout << "00";

  cout << start << "^" << len << "^";
  objfile << start << "^" << len << "^";

  while (words[words.size()-2].compare("END") != 0){
    if (optab.find(words[2]) != optab.end()){
      opcode = optab[words[2]];
      if (symtab.find(words[3]) != symtab.end()){
        symcode = symtab[words[3]];
      }
      else {
        symcode = "0000";
      }

    cout << assemble(opcode, symcode) << "^";
    objfile << assemble(opcode, symcode) << "^";
    }
    else if (words[2].compare("WORD") == 0) {
      opcode = "00";
      symcode = words[3];

    cout << assemble(opcode, symcode) << "^";
    objfile << assemble(opcode, symcode) << "^";
    }
    else {
      opcode = "00";
    }

    getline(ifile, line);
    words = split(line);
  }

  cout << endl << "E^" << start << endl;
  objfile << endl << "E^" << start << endl;

	return 0;
}

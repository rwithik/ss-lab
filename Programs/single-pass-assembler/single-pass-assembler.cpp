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

string obj;

int main(int argc, char const *argv[])
{
  fstream input("input.txt", ios::in);
  fstream output("objfile.txt", ios::out);

  const map<string, string> optab = {
    {"LDA", "00"},
    {"STA", "32"},
    {"SUB", "05"},
    {"ADD", "01"}
  };

  map <string, string> symtab = {};
  map <string, vector<int>> list = {};

  string line;
  vector<string> words;

  getline(input, line);
  words = split(line);

  string start;
  int locctr;

  string symcode, opcode;

  if (words[1].compare("START") == 0) {
    start = words[2];
    locctr = stoi(words[2]);
    getline(input, line);
    words = split(line);
    objfile << "H^" << words[0] << endl;
  }
  else {
    start = "0000";
    locctr = 0;
  }


  vector<string> objcode;
  obj << "T^" << start << "^";

  while (words[0].compare("END") != 0) {
    if (words[0][0] == '.'){
      getline(input, line);
      words = split(line);
      continue;
    }

    // cout << line << " " << words.size() << endl;

    if (words[0].compare("-") != 0){
      // if label
      cout << words[0] << symtab[words[0]].size() << endl;
      if (symtab.find(words[0]) != symtab.end()){
        if (symtab[words[0]].size() == 0 || symtab[words[0]][0] = '-'){
          for (auto i: list[words[1]]){
            objcode.replace(i, words[2]);
          }
        }
      }
      else {
        symtab.insert(pair<string, string>(words[0], to_string(locctr)));
      }

      if (optab.find(words[1]) != optab.end()) {
        // if optab
        obj.append(optab[words[1]]);
        if (symtab.find(words[1]) != symtab.end()) {
          if (symtab[words[2]].size() == 0) {
            list[words[2]].push_back();
          }
          else {
            symcode = symtab(words[1]);
            obj += symcode;
          }
        }
        else {
          symtab.insert(words[1], "");
        }
        locctr += 3;
      }
      else if (words[1].compare("WORD") == 0) {
        locctr += 3;
        obj.append(words[2]);
      }
      else if (words[1].compare("BYTE") == 0) {
        locctr += words[2].size() - 3;
      }
      else if (words[1].compare("RESW") == 0) {
        locctr += 3 * stoi(words[2]);
      }
      else if (words[1].compare("RESB") == 0) {
        locctr += stoi(words[2]);
      }
      
      objcode.push_back(obj);      
    }
  
    getline(input, line);
    words = split(line);
  }


  return 0;
}
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

int main(int argc, char const *argv[]) {

  const map<string, string> optab = {
    {"LDA", "00"},
    {"STA", "32"},
    // {"SUB", "05"},
    {"ADD", "01"}
  };

  fstream file("input.txt", ios::in);
  fstream ifile("if.txt", ios::out);
  map<string, string> symtab;
  int locctr = 0;
  int starting_address = 0;

  string line;

  bool duplicate = false;
  bool invalid_opcode = false;

  getline(file, line);
  vector<string> words = split(line);

  if (words[0].compare("START") == 0){
    locctr = stoi(words[1]);
    starting_address = locctr;
    // cout << "Start" << endl;
    ifile << locctr << "\t" << line << endl;
    locctr -= 3;
    getline(file, line);
    words = split(line);
  }

  while (words[1].compare("END") != 0){
    cout << "Current line: " << line << endl;
    if (words[0].compare("-") != 0) {
      if (symtab.find(words[0]) == symtab.end()){
        symtab.insert(pair<string, string>(words[0], to_string(locctr+3)));
      }
      else {
        duplicate = true;
        // cout << "Duplicate symbol " << words[0] << endl;
        ifile << "Duplicate symbol " << words[0] << endl;
      }
    }

    if (optab.find(words[1]) != optab.end()){
      locctr += 3;
    }
    else if (words[1].compare("WORD") == 0){
      locctr += 3;
    }
    else if (words[1].compare("RESW") == 0){
      locctr += 3 * stoi(words[2]);
    }
    else if (words[1].compare("WORD") == 0){
      locctr += stoi("RESB");
    }
    else {
      invalid_opcode = true;
      // cout << "Invalid opcode " << words[1] << endl;
      ifile << "Invalid opcode " << words[1] << endl;
    }

    // cout << "dup " << duplicate << ": " << "invop " << invalid_opcode << endl;

    if (!invalid_opcode && !duplicate) {
      ifile << locctr << "\t" << line << endl;
    }
    
    // cout << locctr << "\t" << line << endl;
    getline(file, line);
    words = split(line);
    invalid_opcode = false;
    duplicate = false;
  }

  locctr += 3;
  ifile << locctr << "\t" << line << endl;
  cout << "Program length: " << locctr - starting_address << endl << endl;

  cout << "SYMTAB" << endl << endl;

  for (auto i: symtab) {
    cout << i.first << ": " << i.second << endl;
  }

  return 0;
}

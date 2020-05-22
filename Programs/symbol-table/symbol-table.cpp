#include<bits/stdc++.h>

using namespace std;

map<string, int> symtab;

void insert(string s, int a) {
	if (symtab.find(s) != symtab.end()){
		cout << "Duplicate symbol" << endl;
	}
	else {
		symtab.insert(pair<string, int>(s, a));
	}
}

void remove(string s){
	if(symtab.erase(s))
		cout << s << " deleted." << endl;
	else 
		cout << "Not found" << endl;
}

void display(){
	for (auto i: symtab){
		cout << i.first << ": " << i.second << endl;
	}
	cout << endl;
}

void search(string name){
	if (symtab.find(name) != symtab.end()){
		cout << "Found at " << symtab.find(name) -> second << endl;
	}
	else {
		cout << "Not found" << endl;
	}
}

void modify(string s, int a) {
	if (symtab.find(s) != symtab.end()){
		cout << "Modified" << endl;
		symtab[s] = a;
	}
	else {
		cout << "Not found" << endl;
	}
}

int main(int argc, char const *argv[])
{
	int choice, address;
	string name;

	while (1){
	cout << "1. Insert" << endl;
	cout << "2. Delete" << endl;
	cout << "3. Display" << endl;
	cout << "4. Search" << endl;
	cout << "5. Modify" << endl;
	cout << "Enter choice: ";

	cin >> choice;

	switch(choice){
		case 1: 
			cout << "Enter the symbol name: ";
			cin >> name;
			cout << "Enter the address: ";
			cin >> address;
			insert(name, address);
			break;
		case 2:
			cout << "Enter the symbol name: ";
			cin >> name;
			remove(name);
			break;
		case 3:
			display();
			break;
		case 4:
			cout << "Enter the symbol name to be searched: ";
			cin >> name;
			search(name);
			break;
		case 5:
			cout << "Enter the symbol name to be modified: ";
			cin >> name;
			cout << "Enter the new address: ";
			cin >> address;
			modify(name, address);
			break;
		default:
			cout << "Invalid Entry" << endl;
	}
	}
	return 0;
}
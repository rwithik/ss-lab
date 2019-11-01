class Directory{
public:
  vector<Directory*> subdirs;
  vector<string> files;
  string path;
  Directory(string path){
    this -> path = path;
  }
};

void insert(Directory* root, string name, int choice);

void insert(Directory* root, string name, int choice){
  string subname;
  if (choice == 2){
    root -> files.push_back(name);
    cout << name << " created!" << endl;
  }
  else if (choice == 1){
    int n;
    Directory* subdir = new Directory(root -> path + "/" + name);
    root -> subdirs.push_back(subdir);
    cout << name << " created!" << endl;
    cout << "Enter the number of subdirectories and files of " << name << ": ";
    cin >> n;
    while(n--){
      cout << "Enter the name of file or directory to be created under " << name << ": ";
      cin >> subname;
      cout << "Enter 1 for directory, 2 for file: ";
      cin >> choice;
      insert(subdir, subname, choice);
    }
  }
}


void hierarchial(){
  string name;
  int choice;

  Directory* base = new Directory("/");

  cout << "Enter the name of file or directory to be created: ";
  cin >> name;
  cout << "Enter 1 for directory, 2 for file: ";
  cin >> choice;
  insert(base, name, choice);

}

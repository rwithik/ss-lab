void two(){
  string name, dirname;
  int choice;

  map<string, vector<string>> fs;
  map<string, vector<string>>::iterator search;

  while(true){
    cout << "=============================" << endl << endl;
    cout << "1. Create directory\n2. Create file\n3. Delete file\n4. Search file\n5. Display files\n6. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice){
      case 1: cout << "Name of the directory: ";
      cin >> name;
      fs.insert(pair<string, vector<string>>(name, vector<string>()));
      break;

      case 2: cout << "Directory name: ";
      cin >> dirname;
      cout << "Name of the file: ";
      cin >> name;
      search = fs.find(dirname);
      if (search == fs.end())
        cout << "Directory does not exist!" << endl;
      else{
        cout << "File created" << endl;
        search -> second.push_back(name);
      }
      break;

      case 3: cout << "Directory name: ";
      cin >> dirname;
      cout << "File name: ";
      cin >> name;
      search = fs.find(dirname);
      if (search != fs.end()){
        auto contents = search -> second;
        auto file = find(contents.begin(), contents.end(), name);
        if (file != contents.end()){
          cout << name << " deleted!" << endl;
          fs[dirname].erase(file);
        }
        else{
          cout << "File not found!" << endl;
        }
      }
      else{
        cout << "Directory not found!" << endl;
      }
      break;

      case 4: cout << "File name: ";
      cin >> name;
      for (auto i: fs){
        auto found = find(i.second.begin(), i.second.end(), name);
        if (found != i.second.end()){
          cout << "Found in directory: " << i.first << endl;
        }
      }
      break;

      case 5:
      for (auto i: fs){
        cout << i.first << "\t:";
        for (auto j: i.second){
          cout << j << ", ";
        }
        cout << "\b\b " << endl;
      }
      break;

      case 6:
      exit(0);

      default: cout << "Invalid choice!" << endl;
    }
  }
}

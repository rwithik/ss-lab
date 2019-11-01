void single(){
  string base, name;
  vector<string> files;
  vector<string>::iterator it;
  int choice;

  cout << "Enter the name of the base directory: ";
  cin >> base;

  while (true){
    cout << "=============================" << endl << endl;
    cout << "1. Create file\n2. Delete file\n3. Search file\n4. Display file\n5. Exit" << endl;
    cout << "Enter the choice: ";
    cin >> choice;
    switch (choice) {
      case 1: cout << "Name of the file: ";
      cin >> name;
      files.push_back(name);
      break;

      case 2: cout << "Name of the file: ";
      cin >> name;
      it = find(files.begin(), files.end(), name);
      files.erase(it);
      break;

      case 3: cout << "Name of the file: ";
      cin >> name;
      it = find(files.begin(), files.end(), name);
      if (it != files.end()) cout << name << " found!" << endl;
      else cout << "Not found!" << endl;
      break;

      case 4:
      for (auto file: files){
        cout << file << endl;
      }
      break;

      case 5: exit(0);
      break;

      default: cout << "Invalid choice!" << endl;
    }
  }
}

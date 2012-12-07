#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <map>

using std::map;
using std::pair;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;

int main (int argc, char** argv) {
    map <string, int> NoNList;
    string line;
    ifstream myfile(argv[1]);
    map<string, int>::iterator it;

    if (argc != 3) {
	  cout << "Usage list [filename] [threshold]" << endl;
    }
    
    else {
	  if (myfile.is_open()) {
		while (myfile.good()) {
		    getline (myfile, line);
		    if (NoNList.count(line) >= 1) {     //If there are > 1 names
			  NoNList[line]++;           	   //Increment
		    }
		    else {
			  NoNList.insert(pair<string, int>(line, 1));
		    }
		}
	  }
	  myfile.close();
    
	  //If the people who appear in the list >= threshold, they are NICE
	  cout << "NICE PEPS" << endl;
	  for (it = NoNList.begin(); it != NoNList.end(); it++) {
		if (it->second >= atoi(argv[2])) {
		    //cout << it->first << endl;
		    cout << it->first << " appeared: " << it->second << " times" << endl;
		}
	  }

	  //If the people who appear in the list < threshold, they are NAUGHTY
	  cout << endl;
	  cout << "NAUGHTY PEPS" << endl;
	  for (it = NoNList.begin(); it != NoNList.end(); it++) {
		if (it->second < atoi(argv[2])) {
		    cout << it->first << " appeared: " << it->second << " times" << endl;
		}
	  }
    }
    return 0;
}

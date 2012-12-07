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
    //ofstream myFile;
    map <string, int> dictionary;
    string line;
    ifstream myfile(argv[1]);
    
    if (argc != 3) {
	  cout << "Usage list [filename] [threshold]" << endl;
    }
    
    else {
	  cout << "filename: " << argv[1] << endl;
	  cout << "threshold: " << argv[2] << endl;
	  //cout << atoi(argv[1]) + atoi(argv[2]) << endl;
	  
	  if (myfile.is_open()) {
		while (myfile.good()) {
		    getline (myfile, line);
		    cout << line << endl;
		}
	  }
	  myfile.close();
	  
    }

    return 0;
}

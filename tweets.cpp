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
using std::ofstream;

//int main (int argc, char** argv) {
int main () {
    string line;
    ifstream myfile ("tweets");
    map <string, int> tweets;
    map<string, int>::iterator it;

    if (myfile.is_open()) {
	  while (myfile.good()) {
		getline (myfile, line, ' ');
		if (tweets.count(line) >= 1) {
		    tweets[line]++;
		}
		else {
		    tweets.insert(pair<string, int>(line, 1));
		    //cout << line << endl;
		}
	  }
    }
    myfile.close();

    ofstream myNewFile;
    myNewFile.open ("uniqueWords.txt");
    for (it = tweets.begin(); it != tweets.end(); it++) {
	  if (it->second <= 2500) {
		cout << it->first << "appeared " << it->second << " times" << endl;
	  }
    }
    myNewFile.close();

    return 0;
}

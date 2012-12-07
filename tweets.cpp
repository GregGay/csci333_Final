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

int main () {
    string line;
    ifstream myfile ("tweets");
    map <string, int> tweets;
    map<string, int>::iterator it;
    int total = 0;
    
    if (myfile.is_open()) {
	  while (myfile.good()) {
		getline (myfile, line, ' ');
		if (tweets.count(line) >= 1) {
		    tweets[line]++;
		}
		else {
		    tweets.insert(pair<string, int>(line, 1));
		}
	  }
    }
    myfile.close();

    ofstream myNewFile;
    myNewFile.open ("uniqueWords.txt");
    for (it = tweets.begin(); it != tweets.end(); it++) {
	  myNewFile << it->first << " appeared " << it->second << " times" << endl;
    }
    myNewFile.close();


    for (it = tweets.begin(); it != tweets.end(); it++) {
	  total+=it->second;
    }

    ofstream myNewerFile;
    myNewerFile.open ("lexFile.txt");
    myNewerFile << "Total words: " << total << endl;
    myNewerFile << "Unique Words: " << tweets.size() << endl;
    myNewerFile << "Lexical diversity: " << total/tweets.size() << endl;
    myNewerFile.close();

    return 0;
}

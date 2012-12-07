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

//int main (int argc, char** argv) {
int main () {
    string line;
    ifstream myfile ("tweets");
    map <int, string> dictionary;
    /*
    string str="ho t p";
    for (size_t n = 0; n < str.size(); n++) {
    size_t pos;
    pos = str.find(" ");
    string str3 = str.substr(pos);
    cout << str3 << endl;
    cout<<endl;
    }*/
    if (myfile.is_open()) {
	  while (myfile.good()) {
		getline (myfile, line, ' ');
		cout << line << endl;
	  }
	  myfile.close();
    }

    else cout << "Unable to open file." << endl;
    return 0;
}

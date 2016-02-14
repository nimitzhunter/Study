#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

string tail(const string & fname, int lines){

  auto filestream = ifstream {fname, ios_base::in };

  // set the pos at the end of the file
  filestream.seekg(0, ios_base::end);

  // counting the numbers of characters in the file.
  auto filesize = filestream.tellg();

  // return the tail of the file
  auto tail = string{};

  char ch;
  auto linecounter = 0;
  for (int i = 0; i < filesize; ++i){
    // counting backward.
    filestream.seekg(-1 -i, ios_base::end);

    // read the character at seekg pos
    filestream.get(ch);

    // count the lines
    if (ch == '\n'){
      ++linecounter;

      if (linecounter>lines)
        break;
    }
    // adding the read-in character
    tail.push_back(ch);
  }

  reverse(tail.begin(), tail.end());
  
  return tail;
}

int main(){
  cout << tail("myfile.txt",3);
}

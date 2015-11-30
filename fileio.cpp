#include <iostream>
#include <fstream>
#include <vector>

int main(){
  std::ofstream myfile;
  
  myfile.open("test.txt");
  myfile << "this is a test.\n";
  myfile << "end this misery already.";


  std::vector<int> myvec;
  myvec.push_back(10);
  myvec.push_back(11);
  myvec.push_back(12);
  myvec.push_back(13);
  myvec.push_back(14);

  for(const auto & x : myvec){
    myfile << x << "\n";
  }

  myfile.close();
}

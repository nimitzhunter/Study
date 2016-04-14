#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>

int main(){
  std::ifstream myfile("test.txt");
  std::vector<std::string> myvec;
  std::string word;
  
  while (myfile >> word){
    boost::algorithm::to_lower(word);
    myvec.push_back(word);
  }
  myfile.close();

  for(const auto & x : myvec){
    std::cout << x << std::endl;
  }
}

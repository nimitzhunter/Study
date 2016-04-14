#include <iostream>
#include <string>
#include <iterator>
#include <unordered_map>

using namespace std;

int RomanToInt(const string & Roms){
  if (Roms.size() == 0)
    return 0;

  static const auto Rom_Map = unordered_map<string,int>  {{"I",1},
                                                          {"V",5},
                                                          {"X",10},
                                                          {"L",50},
                                                          {"C",100},
                                                          {"D",500},
                                                          {"M",1000},
                                                          {"IV",4},
                                                          {"IX",9},
                                                          {"XL",40},
                                                          {"XC",90},
                                                          {"CD",400},
                                                          {"CM",900}};

  auto res = 0;
  auto first = Roms.begin();
  bool valid;
  while (first != Roms.end()){
    valid = false;

    auto second = next(first);
    if (second != Roms.end()){
      auto found = Rom_Map.find(string{*first} + *second);
      if (found != Rom_Map.end()){
        res += found->second;
        valid = true;
        first = next(second);
      }
    }

    if (!valid){
      auto found = Rom_Map.find(string{*first});
      if (found != Rom_Map.end()){
        res += found->second;
        valid = true;
        first = second;
      }
    }
    if (!valid){
      cerr << "Invalid character(s) found in Romans:" << Roms << endl;
      return res;
    }
  }

  cout << Roms << "=" << res << endl;

  return res;
}

int main(){
  RomanToInt("X"); 
  RomanToInt("IX"); 
  RomanToInt("CL"); 
  RomanToInt("XXXXIIII"); 
  RomanToInt("LIX"); 
  RomanToInt("CLXXXVII"); 
}

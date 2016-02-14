#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string trim(const std::string& str,
                 const std::string& whitespace = " \t")
{
  const auto strBegin = str.find_first_not_of(whitespace);
  if (strBegin == std::string::npos)
    return ""; // no content

  const auto strEnd = str.find_last_not_of(whitespace);
  const auto strRange = strEnd - strBegin + 1;

  return str.substr(strBegin, strRange);
}

void reverse_interval(std::string::iterator first,
                      std::string::iterator last){
  if (first == last)
    return;

  std::advance(last,-1);

  // swapping characters
  while ( std::distance(first,last) > 0){
    std::swap(*first, *last);
    std::advance(first,1);
    std::advance(last,-1);
  }
}

void reverse(std::string & str){
  std::cout << "input string:"<< str << std::endl;

  std::reverse(str.begin(),str.end());
  std::cout << "reversed str:"<< str << std::endl;

  str = trim(str);

  auto beg = str.begin();
  auto end = std::find(str.begin(),
                       str.end(),' ');

  int count = 0;
  while(std::distance(beg,end) > 0){
    std::reverse(beg, end);
    std::cout << "reversing substr " << ++count
              << ":"+str << std::endl;

    if (end != str.end()){
      beg = std::next(end,1);
      end = std::find(beg,str.end(),' ');
    }
    else
      beg=end;
  }
}

int main(){
  std::string mystr = "this is my string.";
  reverse(mystr);
  std::cout << mystr << std::endl;
}

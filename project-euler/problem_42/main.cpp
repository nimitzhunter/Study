#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <iomanip>

class TriangleFinder
{
private:
  int   TriangleCount;
public:
  TriangleFinder():TriangleCount(0) {}
  void  operator() (std::string);
  int print_result() const { return TriangleCount;};
};
    
void TriangleFinder::operator() (std::string sInput)
{
  int                   value=0;
  std::string::iterator it = sInput.begin();
  double                root;
  
  for ( ; it != sInput.end() ; ++it)
    {
      value+= (*it) -64;
    }
  // find out whether root is an interger.
  root  = sqrt(double(value)*8+1);
  if ( fabs(floor(root)-root) < 1e-6)
    {
      TriangleCount++;
    }
  /*  std::cout <<std::setw(10) << sInput
            <<std::setw(10) << root
            <<std::setw(10) << fabs(floor(root)-root)
            <<std::setw(10) << TriangleCount << std::endl;
  */
}

int main()
{
  using namespace       std;
  string                sTmp;
  vector<string>        vStr;
  ifstream              inFile("words.txt");
  TriangleFinder        Finder;
  
  while (getline(inFile,sTmp,','))
    {
      sTmp.erase(sTmp.begin());
      sTmp.erase(sTmp.end()-1);
      vStr.push_back(sTmp);
    }
  //  copy(vStr.begin(),vStr.end(),ostream_iterator<string>(cout,"\n"));
  Finder=for_each(vStr.begin(),vStr.end(),Finder);
  cout << Finder.print_result() << endl;
}

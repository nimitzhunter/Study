#include <string>
#include <vector>
#include <iostream>
#include <fstream>

int main()
{
	using namespace std;

	vector<string> vStr;
	string sTmp;
	ifstream inFile("data.txt");
	
	while ( getline(inFile,sTmp))
		vStr.push_back(sTmp);

	return 0;
}

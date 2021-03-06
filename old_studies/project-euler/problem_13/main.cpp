#include <string>
#include <vector>
#include <iostream>
#include <fstream>

/* Work out the first ten digits of the sum of the following
	 one-hundred 50-digit numbers
*/

int main()
{
	using namespace std;

	vector<int> array(50,0);
	string sTmp;
	ifstream inFile("data.txt");
	int index;

	string::reverse_iterator it;
	
	while ( getline(inFile,sTmp))
		{
			index=0;
			for (it=sTmp.rbegin() ; it != sTmp.rend() ; ++it)
				array[index++] += (int(*it))-48;
		}

	for ( int i = 0 ; i < 49 ; ++i)
		{
			array[i+1] += (array[i]/10);
			array[i] %= 10;
		}
	
	for ( int i = 49  ; i >0  ; --i)
		cout << array[i];
	cout << endl;
	return 0;
}

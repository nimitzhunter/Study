#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;
std::map<int,int> mymap;

std::pair<int,int> MaxSub(const std::vector<int> & A){
    pair<int,int> range{0,0};
    mymap.lower_bound(10);

    int min_idx = -1;
    int min_sum = 0;
    int max_sum = 0;
    int sum = 0;

    for (size_t i=0; i < A.size(); ++i){
        sum += A[i];
        if (sum < min_sum){
            min_sum = sum;
            min_idx = i;
        }
        if (sum - min_sum > max_sum){
        max_sum = sum - min_sum;
        range = {min_idx +1, i+1};
        }
        cout << sum     << " " 
            << min_sum << " " 
            << max_sum << " " 
            << min_idx << endl;
    }
    return range;
}

int main(){
    vector<int> A = {-100, 904, 40, 523, 12, -335, -385, -124, 481, -31};
    auto range = MaxSub(A);
    std::cout << range.first << " " << range.second << std::endl;
    for(const auto & elem:A)
        cout << elem << endl;
}

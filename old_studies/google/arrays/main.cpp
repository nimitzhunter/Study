#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T1, typename T2>
void Permute(vector<T1> & P, vector<T2> & A){
  // P[i] means swap(A[i], A[P[i]])
  for (size_t i = 0; i < P.size(); ++i){
    auto p_index = i;

    while(P[p_index] >= 0){
      std::swap(A[i], A[P[p_index]]);

      auto tmp = p_index;
      p_index = P[p_index];
      P[tmp] -= P.size(); // marking applied permutation
    }
  }
  // restoring the Permutation array;
  std::for_each(P.begin(), P.end(), [&](int & x) {x+=P.size();});
}

void nextPermute(vector<int> & P){
  if (P.begin() == P.end())
    return;

  // find the decreasing subsequence
  // Since using reverse iterator, search the increasing subsequence
  auto tmp = std::adjacent_find(P.rbegin(),
                                P.rend(),
                                std::greater<int>());

  auto k = std::prev(tmp.base());

  if (k == P.begin())
    return;// if the subarary == array

  auto s = std::prev(k);

  // In the subseq [k,end) find the element that is less than *s
  auto swap_target = std::find_if(k, P.end(),
                          [&](int x){return x < *s;});

  // no element in [k, end) lesser than *s
  if (swap_target == P.end())
    swap_target = std::prev(P.end());
  else
    std::advance(swap_target,-1);

  std::swap(*s, *swap_target);

  std::reverse(k, P.end());
}

void DutchFlag(vector<int> & A, int pivot_idx){
  // This is not a sorting algorithm
  // Everything before pivot is <= pivot
  // everything after pivot is > than pivot

  int pivot = A[pivot_idx];

  int smaller = 0;
  int larger = A.size();
  int equal = 0;

  while (equal < larger){
    if (A[equal] < pivot)
      swap(A[equal++],A[smaller++]);
    else if(A[equal] == pivot)
      ++equal;
    else{
      swap(A[equal],A[--larger]);
    }

    for(auto & elem : A)
      cout << elem << " ";
    cout << endl;
  }
}

void DutchFlag2(vector<int> & A, int pivot_idx){
  int pivot = A.at(pivot_idx);

  auto less = A.begin();
  auto equal = A.begin();
  auto greater = A.rbegin();

  // while(A.begin() != greater.base() &&
  //         equal != greater.base()-1){
  while(equal != greater.base()){
    auto & equal_val = *equal;

    if (equal_val == pivot)
      std::advance(equal,1);
    else if (equal_val < pivot){
      swap(equal_val, *less);
      std::advance(equal,1);
      std::advance(less,1);
    }
    else{
      swap(equal_val, *greater);
      std::advance(greater,1);
    }
  }
}

int main(){
  // vector<int> A{3,2,1,1,3,2};
  // // DutchFlag(A, 3);
  // DutchFlag2(A, 2);
  // for(auto & elem : A)
  //     cout << elem << " ";
  // cout << endl;

  // vector<char> B{'a','b','c','d'};
  // vector<int> P{2, 0, 1, 3};

  // Permute(P, B);

  // for(const auto & elem: B ){
  //   cout << elem << ",";
  // }
  // cout << endl;

  vector<int> P{6,2,1,5,4,3,0};
  nextPermute(P);
  std::copy(P.begin(),P.end(),
            std::ostream_iterator<int>(std::cout,","));
  nextPermute(P);
  cout << endl;
  std::copy(P.begin(),P.end(),
            std::ostream_iterator<int>(std::cout,","));
  nextPermute(P);
  cout << endl;
  std::copy(P.begin(),P.end(),
            std::ostream_iterator<int>(std::cout,","));
  cout << endl;
}

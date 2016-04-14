#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct IteratorCurrentAndEnd{
  bool operator < (const IteratorCurrentAndEnd & that) const {
    // to implement min-heap
    // switch sign to implement max-heap
    return *current > *that.current;
  }

  vector<int>::const_iterator current;
  vector<int>::const_iterator end;
};

vector<int> MergedSortedArrays(const vector<vector<int>> & Sorted_Arrays){
  auto min_heap = std::priority_queue <IteratorCurrentAndEnd, vector<IteratorCurrentAndEnd>>{};

  // min_heap of the first element of each sorted array
  for (const auto & sorted_array:Sorted_Arrays){
    if (!sorted_array.empty()){
      min_heap.emplace(
                       IteratorCurrentAndEnd{sorted_array.cbegin(),
                           sorted_array.cend()});
    }
  }

  vector<int> result;
  while(!min_heap.empty()){
    auto smallest_array = min_heap.top();

    min_heap.pop();

    if (smallest_array.current != smallest_array.end){
      result.emplace_back(*smallest_array.current);

      min_heap.emplace(IteratorCurrentAndEnd{
          next(smallest_array.current),
            smallest_array.end});
    }
  }

  return result;
}

int main(){
  std::vector<int>v1 {1,2,3};
  auto v2 = std::vector<int>{1,5,7,8,9};
  auto v3 = std::vector<int>{6,7,8,11,20,60};
  auto sorted_arrays = std::vector<std::vector<int>>{v1,v2,v3};
  auto res = MergedSortedArrays(sorted_arrays);
  copy(res.begin(), res.end(),std::ostream_iterator<int> (std::cout,","));
  auto min_heap = std::priority_queue <int, std::vector<int>>{};
  min_heap.emplace(1);
}

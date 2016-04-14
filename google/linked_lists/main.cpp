#include <iostream>
#include <vector>
#include <iterator>

template<class Container>
typename Container::const_iterator find_last_k(const Container & input,
                                     size_t k){
  if (k > input.size())
    return input.cend();

  auto head = std::begin(input);
  auto tail = std::next(head, k);

  while(tail != input.end()){
    std::advance(head,1);
    std::advance(tail,1);
  }

  return head;
}

int main(){
  std::vector<int> myvec {1,2,3,4,5,6,7,8,9,10};
  auto head = find_last_k(myvec, 10);
  while(head != myvec.end()){
    std::cout << *head << std::endl;
    std::advance(head,1);
  }
}


#include <string>
#include <bitset>
#include <boost/algorithm/string.hpp>

using alpha_size = 26;

int get_pos(const char c){
  return c-'a';
}

struct TrieNode{
  std::bitset<alpha_size> node_val;
  TrieNode * next_nodes [alpha_size];
};

class Trie{
private:
  TrieNode * Node;

public:
  Trie();
};

Trie::Trie(){
  Node = nullptr;
}

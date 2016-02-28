#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>

template<typename T>
struct tNode{
  T data;
  std::unique_ptr<tNode<T>> links[2];
};

struct Node{
  int data;
  Node * link[2];

  Node(int indata):data{indata}{
    link[0] = nullptr;
    link[1] = nullptr;
  }
};

void delete_node(Node * root){
  // recursively delete every node from root
  if (root != nullptr){
    delete_node(root->link[0]);
    delete_node(root->link[1]);
    delete root;
  }
}

struct Tree {
  Node * root;
  Tree(){root = nullptr;};
  ~Tree() {delete_node(root);};
};

void delete_tree(Tree * tree){
  delete_node(tree->root);
}

Node * create_node(int data){
  return new Node(data);
}

Node * insert_node(Node * root, int data){
  if (root == nullptr){
    root = create_node(data);
  }
  else {
    int dir = root->data < data;
    root->link[dir] = insert_node(root->link[dir], data);
  }

  return root;
}

void insert_tree(Tree & tree, int data){
  tree.root = insert_node(tree.root, data);
}

void remove_node(Tree * tree, int data){
// 1) locate the Node
// 2) travese to the inorder successor the switch the value and delete the
// inorder successor
  if (tree->root == nullptr)
    return;

  Node head{0};
  head.link[1] = tree->root;
  Node * it = & head;
  Node * p_node = nullptr;
  Node * saved = nullptr;
  int dir = 1;

  while(it->link[dir] != nullptr){
    p_node = it;
    it = it->link[dir];
    dir = it->data <= data;

    if (it->data == data){
      saved = it;
    }
  }

  if (saved != nullptr){
    saved->data = it->data;
    p_node->link[p_node->link[1] ==
                 it] = it->link[it->link[0] == nullptr];
    delete it;
  }

  tree->root = head.link[1];
}

void preorder_r(Node * root){
  if (root != nullptr){
    std::cout << root->data << std::endl;
    preorder_r(root->link[0]);
    preorder_r(root->link[1]);
  }
}

void structure_r(Node * root, int level){
  if (root == nullptr){
    for (int i=0; i < level; ++i){
      putchar('\t');
    }
    std::puts("~");
  }
  else{
    structure_r(root->link[1], level+1);
    for (int i=0; i < level; i++){
      putchar('\t');
    }
    std::cout << root->data << std::endl;
    structure_r(root->link[0], level+1);
  }
}

void tree_structure(Tree * tree){
  structure_r(tree->root,0);
}

void tree_preorder_r(Tree * tree){
  preorder_r(tree->root);
}

void postorder_stack(const Tree * tree){
  // Order of traversal: left, right, visit

  if (tree->root == nullptr)
    return;

  struct Mark_node {
    const Node * node;
    bool children_added;
    Mark_node(const Node * innode, bool state = false):
      node{innode},children_added(state){};
  };

  std::vector<Mark_node> trav_stack { Mark_node(tree->root) };

  while(!trav_stack.empty()){
    // looking at thetop of the stack
    // top has to be a reference because we will be changing its children_added
    // value

    Mark_node & top = *trav_stack.rbegin();

    /* don't need to add in the children anymore */
    if (top.children_added == true ||
        (top.node->link[0] == nullptr &&
         top.node->link[1] == nullptr)) {
      // if a node is already visited, we don't need to look at its children again
      // if a node doesnt have any children, we don't need to go left or right'
      std::cout << top.node->data << std::endl;
      trav_stack.pop_back();
    }
    else if (top.children_added == false){
      // pushing the children into the stack
      top.children_added = true;

      if (top.node->link[1] != nullptr)
        trav_stack.push_back(Mark_node(top.node->link[1]));

      if (top.node->link[0] != nullptr)
        trav_stack.push_back(Mark_node(top.node->link[0]));

    }
  }
  std::cout << std::endl;
}

void preorder_stack(const Tree * tree){
  // Order of traversal: visit, left, right,

  if (tree->root == nullptr)
    return;

  std::vector<Node *> trav_stack{tree->root};

  while(!trav_stack.empty()){
    // looking at thetop of the stack
    // top has to be a reference because we will be changing its children_added
    // value

    Node * top = *trav_stack.rbegin();

    std::cout << top->data << std::endl;
    Node * left = top->link[0];
    Node * right = top->link[1];

    trav_stack.pop_back();

    if (right != nullptr)
      trav_stack.push_back(right);

    if (left != nullptr)
      trav_stack.push_back(left);
  }

  std::cout << std::endl;
}

void inorder_stack(const Tree * tree){
  // Order of traversal: left, visit right

  if (tree->root == nullptr)
    return;

  struct Mark_node {
    const Node * node;
    bool children_added;

    Mark_node(const Node * innode, bool state = false):
      node{innode},children_added(state){};
  };

  std::vector<Mark_node> trav_stack;

  trav_stack.push_back(Mark_node(tree->root));

  while(!trav_stack.empty()){
    // looking at thetop of the stack
    // top has to be a reference because we will be changing its children_added value

    Mark_node & top = *(trav_stack.rbegin());

    if (top.children_added == true || /* don't need to add in the children anymore */
        (top.node->link[0] == nullptr &&
         top.node->link[1] == nullptr)) {
      // if a node is already visited, we don't need to look at its children again
      // if a node doesnt have any children, we don't need to go left or right'
      std::cout << "visiting:" << top.node->data<<std::endl;
      trav_stack.pop_back();
    }
    else if (top.children_added == false){
      // pushing the children into the stack
      const Node * tmpnode = top.node;
      trav_stack.pop_back();

      if (tmpnode->link[1] != nullptr){
        trav_stack.push_back(Mark_node(tmpnode->link[1]));
      }

      trav_stack.push_back(Mark_node(tmpnode,true));

      if (tmpnode->link[0] != nullptr){
        trav_stack.push_back(Mark_node(tmpnode->link[0]));
      }
    }
  }
  std::cout << std::endl;
}


Node * BuildTreePreorderHelper(const std::deque<int> & seq,
                               const std::deque<int>::const_iterator & beg,
                               const std::deque<int>::const_iterator & end){
  if (beg == end)
    return nullptr;

  auto next = std::next(beg);

  auto rootval = *beg;

  auto res = new Node(rootval);

  if (next != end){
    auto result = std::find_if(next, end,
                                [&rootval](int input)
                                {return input>rootval;});
    if (result != end){
        res->link[0] = BuildTreePreorderHelper(seq,next, result);
        res->link[1] = BuildTreePreorderHelper(seq,result, end);
    }
  }

  return res;
}

Node * BuildTreeRootPreorder(const std::deque<int> & seq){
  // The given array is a result of preorder-traversal.
  // Rebuild a binary tree from that array
  // Preorder : visit, left, right
  // the element is the root.
  // remove the first element from the array.
  // Find the first element A that is larger than the root node.
  // Everything left of element A is the left subtree; else right subtree.
  return BuildTreePreorderHelper(seq, seq.begin(), seq.end());
}


Node * BuildTreeFromSortedHelper(const std::vector<int> & sarray,
                                 std::vector<int>::const_iterator cbeg,
                                 std::vector<int>::const_iterator cend){
  /*
    the array is already sorted.
    pick the middle element to be the root <= guarantee a minimum heigh tree
   */
  if (cbeg == cend){
    return nullptr;
  }

  // Find the element in the middle of an sorted Array
  auto mid = std::distance(cbeg, cend)/2;

  // The middle value of the sorted array is used as the root node.
  Node * rootnode = new Node(*std::next(cbeg,mid));

  // Everything left of mid is less than mid.
  // Use everything left of mid to create a left subtree
  rootnode->link[0] = BuildTreeFromSortedHelper(sarray, cbeg, cbeg+mid);

  // Everything right of mid is less than mid.
  // Use everything right of mid to create a right subtree
  rootnode->link[1] = BuildTreeFromSortedHelper(sarray, cbeg+mid+1, cend);

  return rootnode;
}

Node * BuildTreeFromSorted(const std::vector<int> & sarray){
  return BuildTreeFromSortedHelper(sarray,
                                   sarray.cbegin(),
                                   sarray.cend());
}

void ReverseNode(Node * root){
  // reverse the node by switching left and right
  if (root == nullptr)
    return;

  auto tmp = root->link[0];
  root->link[0] = root->link[1];
  root->link[1] = tmp;

  ReverseNode(root->link[0]);

  ReverseNode(root->link[1]);
}

void ReverseTree(Tree * tree){
  ReverseNode(tree->root);
}

int main(){
  Tree mytree;
  // insert_tree(mytree,5);
  // insert_tree(mytree,3);
  // insert_tree(mytree,7);
  // insert_tree(mytree,2);
  // insert_tree(mytree,6);
  // insert_tree(mytree,8);
  // tree_structure(&mytree);

  // // postorder_stack(&mytree);
  // // preorder_stack(&mytree);
  // inorder_stack(&mytree);

  // delete_tree(&mytree);

  // std::deque<int> myseq{43,23,37,29,31,41,47,53};
  // mytree.root = BuildTreeRootPreorder(myseq);
  // tree_structure(&mytree);

  std::vector<int> myseq{1,2,3,4,5,6,7,8,9,10,11,12};
  mytree.root = BuildTreeFromSorted(myseq);
  tree_structure(&mytree);
  ReverseTree(&mytree);
  tree_structure(&mytree);
  std::vector <float> mv2;
}

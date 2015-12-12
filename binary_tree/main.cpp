#include <iostream>
#include <cstdio>
#include <vector>

template<typename T>
struct tNode{
  T data;
  std::unique_ptr<tNode<T>> links[2];
};

struct Node {
  int data;
  Node * link[2];

  Node(int indata):data{indata}{
    link[0] = nullptr;
    link[1] = nullptr;
  }
};

struct Tree {
  Node * root;
  Tree(){root = nullptr;};
};

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

void delete_node(Node * root){
  if (root != nullptr){
    delete_node(root->link[0]);
    delete_node(root->link[1]);
    delete root;
  }
}

void delete_tree(Tree * tree){
  delete_node(tree->root);
}

void remove_node(Tree * tree, int data){
  if (tree->root == nullptr)
    return;

// 1st locate the Node
// 2nd travese to the inorder successor the switch the value and delete the
// inorder successor                                                      

// what happen if we need to remove the root of the tree?
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
    p_node->link[p_node->link[1] == it] = it->link[it->link[0] == nullptr];
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
    // top has to be a reference because we will be changing its children_added value

    Mark_node & top = *trav_stack.rbegin(); 

    if (top.children_added == true || /* don't need to add in the children anymore */
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
    // top has to be a reference because we will be changing its children_added value
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

int main(){
  Tree mytree;
  insert_tree(mytree,5);
  insert_tree(mytree,3);
  insert_tree(mytree,7);
  insert_tree(mytree,2);
  insert_tree(mytree,6);
  insert_tree(mytree,8);
  tree_structure(&mytree);

  // postorder_stack(&mytree);
  // preorder_stack(&mytree);
  inorder_stack(&mytree);

  delete_tree(&mytree);
}

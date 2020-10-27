#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__UNIX__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
    void pushChild(Node *child){
      children.push_back(child);
    }
};

int heightTree(Node *current){
    if(current->children.size() == 0) return 1;
    int max_height = 0;
    for(int i = 0; i < current->children.size();i++){
      max_height = std::max(max_height,heightTree(current->children[i]));
    }
    return 1 + max_height;
}


int main_with_large_stack_space() {
  
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  Node root;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    
    int parent_index;
    std::cin >> parent_index;
    
    if (parent_index >= 0){
      nodes[child_index].setParent(&nodes[parent_index]);
      nodes[parent_index].pushChild(&nodes[child_index]);
    }
    else root = nodes[child_index];
    
    nodes[child_index].key = child_index;

  }
  
  for(Node x : nodes){
      std::cout<<x.children.size()<<std::endl;
  }
  int maxHeight = heightTree(&root) ;
  
  

    
  std::cout << maxHeight << std::endl;
  return 0;
}

int main (int argc, char **argv)
{
  return main_with_large_stack_space();
}

// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
public:
  struct Node {
    Node* leftNode;
    Node* rightNode;
    T value;
    int count;
  };
private:
  Node* root;
  Node* addNode(Node* root, T value_element) {
    if (root == nullptr) {
      root = new Node;
      root->value = value_element;
      root->count = 1;
      root->leftNode = nullptr;
      root->rightNode = nullptr;
    } else {
      if (value_element > root->value) root->rightNode = addNode(root->rightNode, value_element);
      else if (value_element < root->value) root->leftNode = addNode(root->leftNode, value_element);
      else root->count++;
    }
    return root;
  }
  int searchNode(Node* root, T value_element) {
    if (root == nullptr) return 0; 
    else {
      Node* current = root;
      if (current->value == value_element) return current->count;
      else if (current->value < value_element) return searchNode(current->rightNode, value_element);
      else if (current->value > value_element) return searchNode(current->leftNode, value_element);
    }
  }
public:
  BST() {
    root = nullptr;
  }
  void addNode_(T value_element) {
    root = addNode(root, value_element);
  }
  int searchNode_(T value_element) {
    return searchNode(root, value_element);
  }
};
#endif  // INCLUDE_BST_H_

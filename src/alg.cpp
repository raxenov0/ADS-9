// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <string>
#include <algorithm>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::string temp;
  std::string str;
  std::ifstream in(filename);
  if (!in) {
    std::cout << "File error!" << std::endl;
  }
  while (getline(in, str,' ')) {
    transform(str.begin(), str.end(), str.begin(), tolower);
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == '\0') break;
      else if(str[i] != '\n' && str[i] != ' ') temp += str[i];
    }
    tree.addNode_(temp);
    temp = "";
  }
  return tree;
}
}

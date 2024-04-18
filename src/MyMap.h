#ifndef MYMAP_H
#define MYMAP_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include "TreeNode.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

template <typename K, typename V>
class MyMap
{
private:
  TreeNode<K, V> *root = nullptr;

  // Returns reference to the value of a node with key `access_key`
  // If no such node exists, throws std::out_of_range exception
  V &at_helper(TreeNode<K, V> *&rt, const K &access_key);

  // Counts the number of nodes in the tree
  int size_helper(TreeNode<K, V> *rt) const;

  // De-allocates all nodes in the tree
  void clear_helper(TreeNode<K, V> *&rt);

  // Inserts node with key `new_key` and value `new_value`
  // Does nothing if a node with `new_key` already exists in tree
  // Search property should be maintained
  void insert_helper(TreeNode<K, V> *&rt, const K &new_key, const V &new_value);

  // Returns pointer to node with the minimum key
  TreeNode<K, V> *get_min(TreeNode<K, V> *rt);

  // Removes node with key `erase_key` if it exists
  // Does nothing otherwise
  // Search property should be maintained
  void erase_helper(TreeNode<K, V> *&rt, const K &erase_key);

  // Returns pointer to node with key `search_key` if it exists
  // Returns nullptr otherwise
  TreeNode<K, V> *find_helper(TreeNode<K, V> *rt, const K &search_key) const;

  // Prints the elements of the tree with tree-like formatting
  void print_helper(TreeNode<K, V> *rt, std::string indent) const;

  // Helper Function for operator[], similar to at() except:
  // If access_key is not found, create new node with that key and return ref to its value
  // You can assume type V has default constructor available (i.e. V() is valid)
  V &bracket_helper(TreeNode<K, V> *&rt, const K &access_key);

  // This is a helper function for the copy constructor and operator=
  // It should recursively clone the whole tree, by using new to make a new tree
  // node, whose left and right children are clones of the left and right
  // children
  TreeNode<K, V> *clone(const TreeNode<K, V> *rt);

public:
  MyMap();

  ~MyMap();

  MyMap(const MyMap<K, V> &source);

  MyMap<K, V> &operator=(const MyMap<K, V> &source);

  TreeNode<K, V> *&begin();

  V &at(const K &access_key);

  V &operator[](const K &access_key);

  // Returns true if the tree has no nodes
  // Returns false otherwise
  bool empty() const;

  int size() const;

  void clear();

  void insert(const K &new_key, const V &new_value);

  void erase(const K &erase_key);

  TreeNode<K, V> *find(const K &search_key) const;

  void print() const;

  void convert_to_sorted_list(TreeNode<K, V> *&rt, std::vector<V> &sorted);
};

#include "MyMap.hpp"
#endif

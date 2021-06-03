

/* 

 *
 * TEST FOR BinaryTree.CPP
 *
 * AUTHOR: Shavit Luzon
 *
 * Date: 2021-05
 *

*/

#include "BinaryTree.hpp"
#include "doctest.h"
using namespace ariel;

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
using namespace std;

using namespace std;
using namespace ariel;

/* 
  Functions to check: all operations.
 */

TEST_CASE("Checking the demo works as expected")
{

  std::ostringstream stream;
  std::string str;
  BinaryTree<int> tree_of_ints;
  tree_of_ints.add_root(1)
      .add_left(1, 9)  // Now 9 is the left child of 1
      .add_left(9, 4)  // Now 4 is the left child of 9
      .add_right(9, 5) // Now 5 is the right child of 9
      .add_right(1, 3) // Now 3 is the right child of 1
      .add_left(1, 2); // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)

  std::cout << tree_of_ints << std::endl; /* Prints the tree in a reasonable format. For example:
        1
        |--------|
        2        3
        |---|
        4   5
  */

  stream.str("");
  stream.clear();
  for (auto it = tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 1 2 4 5 3
  str = stream.str();
  CHECK_EQ(str, std::string("1 2 4 5 3 "));

  stream.str("");
  stream.clear();
  for (auto it = tree_of_ints.begin_inorder(); it != tree_of_ints.end_inorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 4 2 5 1 3
  str = stream.str();
  CHECK_EQ(str, std::string("4 2 5 1 3 "));

  stream.str("");
  stream.clear();
  for (auto it = tree_of_ints.begin_postorder(); it != tree_of_ints.end_postorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 4 5 2 3 1
  str = stream.str();
  CHECK_EQ(str, std::string("4 5 2 3 1 "));

  stream.str("");
  stream.clear();
  for (int element : tree_of_ints)
  { // this should work like inorder
    stream << element << " ";
  } // prints: 4 2 5 1 3
  str = stream.str();

  CHECK_EQ(str, std::string("4 2 5 1 3 "));

  // The same should work with other types, e.g. with strings:

  BinaryTree<std::string> tree_of_strings;
  tree_of_strings.add_root("1")
      .add_left("1", "9")  // Now 9 is the left child of 1
      .add_left("9", "4")  // Now 4 is the left child of 9
      .add_right("9", "5") // Now 5 is the right child of 9
      .add_right("1", "3") // Now 3 is the right child of 1
      .add_left("1", "2"); // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
  std::cout << tree_of_strings << std::endl;

  stream.str("");
  stream.clear();
  for (auto it = tree_of_strings.begin_preorder(); it != tree_of_strings.end_preorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 1 2 4 5 3
  str = stream.str();

  CHECK_EQ(str, std::string("1 2 4 5 3 "));

  stream.str("");
  stream.clear();
  for (auto it = tree_of_strings.begin_inorder(); it != tree_of_strings.end_inorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 4 2 5 1 3
  str = stream.str();

  CHECK_EQ(str, std::string("4 2 5 1 3 "));

  stream.str("");
  stream.clear();
  for (auto it = tree_of_strings.begin_postorder(); it != tree_of_strings.end_postorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 4 5 2 3 1
  str = stream.str();

  CHECK_EQ(str, std::string("4 5 2 3 1 "));

  //demonstrate the arrow operator:

  stream.str("");
  stream.clear();
  for (auto it = tree_of_strings.begin_postorder(); it != tree_of_strings.end_postorder(); ++it)
  {
    stream << it->size() << " ";
  } // prints: 1 1 1 1 1
  str = stream.str();

  CHECK_EQ(str, std::string("1 1 1 1 1 "));
} //ENDED test case

TEST_CASE("Checking pre_order traversal works good on a tree: ")
{

  BinaryTree<int> tree_of_ints;
  tree_of_ints.add_root(1)
      .add_left(1, 9)  // Now 9 is the left child of 1
      .add_left(9, 4)  // Now 4 is the left child of 9
      .add_right(9, 5) // Now 5 is the right child of 9
      .add_right(1, 3) // Now 3 is the right child of 1
      .add_left(1, 2); // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
}

BinaryTree<int> create_tree_plus_random(int randomAdd)
{
  BinaryTree<int> tree;

  // create the following tree
  //                    17*
  //              2*          3*
  //         4*        5*         7*
  //      8*        10*   11*        13
  //    9*        20*       23*
  //
  tree.add_root(17 + randomAdd);
  tree.add_left(17 + randomAdd, 2 + randomAdd);
  tree.add_right(17 + randomAdd, 3 + randomAdd);
  tree.add_right(3 + randomAdd, 7 + randomAdd);
  tree.add_right(3 + randomAdd, 7 + randomAdd);
  tree.add_left(7 + randomAdd, 13 + randomAdd);
  tree.add_left(4 + randomAdd, 8 + randomAdd);
  tree.add_left(8 + randomAdd, 9 + randomAdd);
  tree.add_right(2 + randomAdd, 5 + randomAdd);
  tree.add_left(5 + randomAdd, 10 + randomAdd);
  tree.add_right(5 + randomAdd, 11 + randomAdd);
  tree.add_left(10 + randomAdd, 20 + randomAdd);
  tree.add_right(11 + randomAdd, 23 + randomAdd);
  return tree;
}

vector<int> pre_order_tree_plus_random(int randomAdd)
{
  return vector<int>{17 + randomAdd, 2 + randomAdd, 5 + randomAdd, 10 + randomAdd, 20 + randomAdd, 11 + randomAdd, 23 + randomAdd, 3 + randomAdd, 7 + randomAdd, 13 + randomAdd};
}

vector<int> in_order_tree_plus_random(int randomAdd)
{
  return vector<int>{2 + randomAdd, 20 + randomAdd, 10 + randomAdd, 5 + randomAdd, 11 + randomAdd, 23 + randomAdd, 17 + randomAdd, 3 + randomAdd, 7 + randomAdd, 13 + randomAdd};
}

vector<int> post_order_tree_plus_random(int randomAdd)
{
  return vector<int>{20 + randomAdd, 10 + randomAdd, 23 + randomAdd, 11 + randomAdd, 5 + randomAdd, 2 + randomAdd, 13 + randomAdd, 7 + randomAdd, 3 + randomAdd, 17 + randomAdd};
}

BinaryTree<int> create_tree_multiply_random(int randomMultiply = 1)
{
  BinaryTree<int> tree;

  // create the following tree
  //                    99
  //              2          3
  //         4        5         14
  //                    11          86
  //                  88   23
  //                     72
  tree.add_root(99 * randomMultiply);
  tree.add_left(99 * randomMultiply, 2 * randomMultiply);
  tree.add_right(99 * randomMultiply, 3 * randomMultiply);
  tree.add_right(3 * randomMultiply, 14 * randomMultiply);
  tree.add_left(2 * randomMultiply, 4 * randomMultiply);
  tree.add_right(2 * randomMultiply, 5 * randomMultiply);
  tree.add_right(5 * randomMultiply, 11 * randomMultiply);
  tree.add_right(11 * randomMultiply, 23 * randomMultiply);
  tree.add_left(11 * randomMultiply, 88 * randomMultiply);
  tree.add_right(88 * randomMultiply, 72 * randomMultiply);
  tree.add_right(14 * randomMultiply, 86 * randomMultiply);
  return tree;
}

vector<int> pre_order_tree_multiply_random(int randomMultiply)
{
  return vector<int>{99 * randomMultiply, 2 * randomMultiply, 4 * randomMultiply, 5 * randomMultiply, 11 * randomMultiply, 88 * randomMultiply, 72 * randomMultiply, 23 * randomMultiply, 3 * randomMultiply, 14 * randomMultiply, 86};
}

vector<int> in_order_tree_multiply_random(int randomMultiply)
{
  return vector<int>{4 * randomMultiply, 2 * randomMultiply, 5 * randomMultiply, 88 * randomMultiply, 72 * randomMultiply, 11 * randomMultiply, 23 * randomMultiply, 99 * randomMultiply, 3 * randomMultiply, 14 * randomMultiply, 86 * randomMultiply};
}

vector<int> post_order_tree_multiply_random(int randomMultiply)
{
  return vector<int>{4 * randomMultiply, 72 * randomMultiply, 88 * randomMultiply, 23 * randomMultiply, 11 * randomMultiply, 5 * randomMultiply, 2 * randomMultiply, 86 * randomMultiply, 14 * randomMultiply, 3 * randomMultiply, 99 * randomMultiply};
}

BinaryTree<int> create_only_right_multiply_random(int randomMultiply = 1)
{
  BinaryTree<int> tree;

  // create the following tree
  //                    99
  //                        3
  //                           14
  //                               86
  //                                  77
  //                                     92
  //                                         95
  //                                             98
  //                                                 94
  tree.add_root(99 * randomMultiply);
  tree.add_right(99 * randomMultiply, 3 * randomMultiply);
  tree.add_right(3 * randomMultiply, 14 * randomMultiply);
  tree.add_right(14 * randomMultiply, 86 * randomMultiply);
  tree.add_right(86 * randomMultiply, 77 * randomMultiply);
  tree.add_right(77 * randomMultiply, 92 * randomMultiply);
  tree.add_right(92 * randomMultiply, 95 * randomMultiply);
  tree.add_right(95 * randomMultiply, 98 * randomMultiply);
  tree.add_right(98 * randomMultiply, 94 * randomMultiply);
  return tree;
}

vector<int> pre_order_tree_only_left_multiply_random(int randomMultiply)
{
  return vector<int>{99 * randomMultiply, 3 * randomMultiply, 14 * randomMultiply, 86 * randomMultiply, 77 * randomMultiply, 92 * randomMultiply, 95 * randomMultiply, 98 * randomMultiply, 94 * randomMultiply};
}

vector<int> in_order_tree_only_left_multiply_random(int randomMultiply)
{
  return vector<int>{99 * randomMultiply, 3 * randomMultiply, 14 * randomMultiply, 86 * randomMultiply, 77 * randomMultiply, 92 * randomMultiply, 95 * randomMultiply, 98 * randomMultiply, 94 * randomMultiply};
}

vector<int> post_order_tree_only_left_multiply_random(int randomMultiply)
{
  return vector<int>{94 * randomMultiply, 98 * randomMultiply, 95 * randomMultiply, 92 * randomMultiply, 77 * randomMultiply, 86 * randomMultiply, 14 * randomMultiply, 3 * randomMultiply, 99 * randomMultiply};
}

BinaryTree<int> create_only_left_multiply_random(int randomMultiply = 1)
{
  BinaryTree<int> tree;

  // create the following tree
  //                                     99
  //                                  3
  //                              14
  //                           86
  //                        77
  //                      92
  //                    95
  //                 98
  //              94
  tree.add_root(99 * randomMultiply);
  tree.add_left(99 * randomMultiply, 3 * randomMultiply);
  tree.add_left(3 * randomMultiply, 14 * randomMultiply);
  tree.add_left(14 * randomMultiply, 86 * randomMultiply);
  tree.add_left(86 * randomMultiply, 77 * randomMultiply);
  tree.add_left(77 * randomMultiply, 92 * randomMultiply);
  tree.add_left(92 * randomMultiply, 95 * randomMultiply);
  tree.add_left(95 * randomMultiply, 98 * randomMultiply);
  tree.add_left(98 * randomMultiply, 94 * randomMultiply);
  return tree;
}

void check_adds_right_create_only_right_multiply_random(int randomMultiply = 1)
{
  BinaryTree<int> tree;

  // create the following tree
  //                                     7
  //                                        3
  //                                          14
  //                                             86
  //                                                77
  //                                                   92
  //                                                      95
  //                                                         98
  //                                                            94
  CHECK_NOTHROW(tree.add_root(99 * randomMultiply));
  CHECK_THROWS(tree.add_right(13 * randomMultiply, 3 * randomMultiply)); //there's no 13 exists
  CHECK_NOTHROW(tree.add_right(99 * randomMultiply, 3 * randomMultiply));
  CHECK_NOTHROW(tree.add_right(3 * randomMultiply, 14 * randomMultiply));
  CHECK_NOTHROW(tree.add_right(14 * randomMultiply, 86 * randomMultiply));
  CHECK_NOTHROW(tree.add_right(99 * randomMultiply, 65 * randomMultiply)); //change 3 to 65
  CHECK_NOTHROW(tree.add_right(86 * randomMultiply, 77 * randomMultiply));
  CHECK_NOTHROW(tree.add_right(77 * randomMultiply, 92 * randomMultiply));
  CHECK_NOTHROW(tree.add_right(92 * randomMultiply, 95 * randomMultiply));
  CHECK_THROWS(tree.add_right(144 * randomMultiply, 3 * randomMultiply)); //there's no 144 exists
  CHECK_NOTHROW(tree.add_right(95 * randomMultiply, 98 * randomMultiply));
  CHECK_NOTHROW(tree.add_right(95 * randomMultiply, 98 * randomMultiply)); //same line as before- switching to same- does nothing
  CHECK_NOTHROW(tree.add_root(1 * randomMultiply));                        //changes the root
  CHECK_NOTHROW(tree.add_root(1 * randomMultiply));                        //changes the root (same line does nothing)
  CHECK_NOTHROW(tree.add_right(98 * randomMultiply, 94 * randomMultiply));
  CHECK_THROWS(tree.add_right(185 * randomMultiply, 94 * randomMultiply));  //there's no 185
  CHECK_NOTHROW(tree.add_right(92 * randomMultiply, 135 * randomMultiply)); //change 95 to 134
  CHECK_NOTHROW(tree.add_right(92 * randomMultiply, 200 * randomMultiply)); //change 134 to 200
  CHECK_NOTHROW(tree.add_right(98 * randomMultiply, 111 * randomMultiply)); //change 94 to 111
  CHECK_NOTHROW(tree.add_root(7 * randomMultiply));                         //changes the root
  CHECK_THROWS(tree.add_right(765 * randomMultiply, 94 * randomMultiply));  //there's no 765

  //pre_order check (to see if the nodes of the tree were really changed):
  vector<int> preOrder = {7 * randomMultiply, 65 * randomMultiply, 14 * randomMultiply, 86 * randomMultiply, 77 * randomMultiply, 92 * randomMultiply, 200 * randomMultiply, 98 * randomMultiply, 111};
  unsigned int i = 0;
  for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it, i++)
  {
    CHECK_EQ(preOrder.at(i), *it);
  }
  //in_order check (to see if the nodes of the tree were really changed):

  vector<int> InOrder = {7, 65 * randomMultiply, 14 * randomMultiply, 86 * randomMultiply, 77 * randomMultiply, 92 * randomMultiply, 200 * randomMultiply, 98 * randomMultiply, 111};
  i = 0;
  for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it, i++)
  {
    CHECK_EQ(preOrder.at(i), *it);
  }
  //post_order check (to see if the nodes of the tree were really changed):
  vector<int> postOrder = {111 * randomMultiply, 98 * randomMultiply, 200 * randomMultiply, 92 * randomMultiply, 77 * randomMultiply, 86 * randomMultiply, 14 * randomMultiply, 65 * randomMultiply, 7};
  i = 0;
  for (auto it = tree.begin_postorder(); it != tree.end_postorder(); ++it, i++)
  {
    CHECK_EQ(preOrder.at(i), *it);
  }
}

void check_adds_only_left_multiply_random(int randomMultiply = 1)
{
  BinaryTree<int> tree;
  // create the following tree
  //                                     7
  //                                   3
  //                                 14
  //                               86
  //                             77
  //                           92
  //                         95
  //                      98
  //                    94
  CHECK_NOTHROW(tree.add_root(99 * randomMultiply));
  CHECK_THROWS(tree.add_left(13 * randomMultiply, 3 * randomMultiply)); //there's no 13 exists
  CHECK_NOTHROW(tree.add_left(99 * randomMultiply, 3 * randomMultiply));
  CHECK_NOTHROW(tree.add_left(3 * randomMultiply, 14 * randomMultiply));
  CHECK_NOTHROW(tree.add_left(14 * randomMultiply, 86 * randomMultiply));
  CHECK_NOTHROW(tree.add_left(99 * randomMultiply, 65 * randomMultiply)); //change 3 to 65
  CHECK_NOTHROW(tree.add_left(86 * randomMultiply, 77 * randomMultiply));
  CHECK_NOTHROW(tree.add_left(77 * randomMultiply, 92 * randomMultiply));
  CHECK_NOTHROW(tree.add_left(92 * randomMultiply, 95 * randomMultiply));
  CHECK_THROWS(tree.add_left(144 * randomMultiply, 3 * randomMultiply)); //there's no 144 exists
  CHECK_NOTHROW(tree.add_left(95 * randomMultiply, 98 * randomMultiply));
  CHECK_NOTHROW(tree.add_left(95 * randomMultiply, 98 * randomMultiply)); //same line as before- switching to same- does nothing
  CHECK_NOTHROW(tree.add_root(1 * randomMultiply));                       //changes the root
  CHECK_NOTHROW(tree.add_root(1 * randomMultiply));                       //changes the root (same line does nothing)
  CHECK_NOTHROW(tree.add_left(98 * randomMultiply, 94 * randomMultiply));
  CHECK_THROWS(tree.add_left(185 * randomMultiply, 94 * randomMultiply));  //there's no 185
  CHECK_NOTHROW(tree.add_left(92 * randomMultiply, 135 * randomMultiply)); //change 95 to 134
  CHECK_NOTHROW(tree.add_left(92 * randomMultiply, 200 * randomMultiply)); //change 134 to 200
  CHECK_NOTHROW(tree.add_left(98 * randomMultiply, 111 * randomMultiply)); //change 94 to 111
  CHECK_NOTHROW(tree.add_root(7 * randomMultiply));                        //changes the root
  CHECK_THROWS(tree.add_left(765 * randomMultiply, 94 * randomMultiply));  //there's no 765

  //should be from up to bottom:
  vector<int> theTree = {7 * randomMultiply, 3 * randomMultiply, 14 * randomMultiply, 86 * randomMultiply, 77 * randomMultiply, 82 * randomMultiply, 95 * randomMultiply, 98 * randomMultiply, 94 * randomMultiply};

  //pre_order check (to see if the nodes of the tree were really changed):

  vector<int> preOrder = {7 * randomMultiply, 65 * randomMultiply, 14 * randomMultiply, 86 * randomMultiply, 77 * randomMultiply, 92 * randomMultiply, 200 * randomMultiply, 98 * randomMultiply, 111};
  unsigned int i = 0;
  for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it, i++)
  {
    CHECK_EQ(preOrder.at(i), *it);
  }
  //in_order check (to see if the nodes of the tree were really changed):

  vector<int> InOrder = {111 * randomMultiply, 98 * randomMultiply, 200 * randomMultiply, 92 * randomMultiply, 77 * randomMultiply, 86 * randomMultiply, 14 * randomMultiply, 65 * randomMultiply, 7};
  i = 0;
  for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it, i++)
  {
    CHECK_EQ(preOrder.at(i), *it);
  }
  //post_order check (to see if the nodes of the tree were really changed):
  vector<int> postOrder = {111 * randomMultiply, 98 * randomMultiply, 200 * randomMultiply, 92 * randomMultiply, 77 * randomMultiply, 86 * randomMultiply, 14 * randomMultiply, 65 * randomMultiply, 7};
  i = 0;
  for (auto it = tree.begin_postorder(); it != tree.end_postorder(); ++it, i++)
  {
    CHECK_EQ(preOrder.at(i), *it);
  }
}

vector<int> vector_pre_order_tree_only_left_multiply_random(int randomMultiply)
{
  return vector<int>{99 * randomMultiply, 3 * randomMultiply, 14 * randomMultiply, 86 * randomMultiply, 77 * randomMultiply, 92 * randomMultiply, 95 * randomMultiply, 98 * randomMultiply, 94 * randomMultiply};
}

vector<int> vector_in_order_tree_only_left_multiply_random(int randomMultiply)
{
  return vector<int>{94 * randomMultiply, 98 * randomMultiply, 95 * randomMultiply, 92 * randomMultiply, 77 * randomMultiply, 86 * randomMultiply, 14 * randomMultiply, 3 * randomMultiply, 99 * randomMultiply};
}

vector<int> vector_post_order_tree_only_left_multiply_random(int randomMultiply)
{
  return vector<int>{94 * randomMultiply, 98 * randomMultiply, 95 * randomMultiply, 92 * randomMultiply, 77 * randomMultiply, 86 * randomMultiply, 14 * randomMultiply, 3 * randomMultiply, 99 * randomMultiply};
}

TEST_CASE("Checking basic tree operations")
{

  SUBCASE("Add_right&& change root: Check tree only_left_multiply_random throws exceptions when needed. checks pre, post and inorder too")
  {
    for (int i = 0; i < 20; i++)
    {
      check_adds_right_create_only_right_multiply_random(i);
    }
  }

  SUBCASE("Add_left && change root :Check tree only_right_multiply_random throws exceptions when needed. checks pre, post and inorder too")
  {
    for (int i = 0; i < 20; i++)
    {
      check_adds_only_left_multiply_random(i);
    }
  }
}

TEST_CASE("Checking random trees iterators")
{

  SUBCASE("Check tree_plus_random PRE ORDER ITERATOR")
  {
    vector<int> pre;
    unsigned int j;
    for (int i = 0; i < 20; i++)
    {
      BinaryTree<int> tree = create_tree_plus_random(i);
      pre = pre_order_tree_plus_random(i);
      j = 0;
      for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it, j++)
      {
        CHECK_EQ(pre.at(j), *it);
      }
    }
  }

  SUBCASE("Check tree_plus_random INORDER ITERATOR")
  {
    vector<int> in;
    unsigned int j;
    for (int i = 25; i < 40; i++)
    {
      in = in_order_tree_plus_random(i);
      unsigned int j = 0;
      BinaryTree<int> tree = create_tree_plus_random(i);
      for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it, j++)
      {
        CHECK_EQ(in.at(j), *it);
      }
    }
  }

  SUBCASE("Check tree_plus_random POSTORDER ITERATOR")
  {
    vector<int> post;
    unsigned int j;
    for (int i = 25; i < 40; i++)
    {
      post = post_order_tree_plus_random(i);
      unsigned int j = 0;
      BinaryTree<int> tree = create_tree_plus_random(i);
      for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it, j++)
      {
        CHECK_EQ(post.at(j), *it);
      }
    }
  }

  SUBCASE("Check tree_multiply_random PRE ORDER ITERATOR")
  {
    vector<int> pre;
    unsigned int j;
    for (int i = 0; i < 20; i++)
    {
      BinaryTree<int> tree = create_tree_multiply_random(i);
      pre = pre_order_tree_multiply_random(i);
      j = 0;
      for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it, j++)
      {
        CHECK_EQ(pre.at(j), *it);
      }
    }
  }

  SUBCASE("Check tree_multiply_random INORDER ITERATOR")
  {
    vector<int> in;
    unsigned int j;
    for (int i = 25; i < 40; i++)
    {
      in = in_order_tree_multiply_random(i);
      unsigned int j = 0;
      BinaryTree<int> tree = create_tree_multiply_random(i);
      for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it, j++)
      {
        CHECK_EQ(in.at(j), *it);
      }
    }
  }

  SUBCASE("Check tree_multiply_random POSTORDER ITERATOR")
  {
    vector<int> post;
    unsigned int j;
    for (int i = 25; i < 40; i++)
    {
      post = post_order_tree_multiply_random(i);
      unsigned int j = 0;
      BinaryTree<int> tree = create_tree_multiply_random(i);
      for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it, j++)
      {
        CHECK_EQ(post.at(j), *it);
      }
    }
  }
}

//Reference:
//https://stackoverflow.com/questions/3513173/converting-ostream-into-standard-string
//https://stackoverflow.com/questions/5781597/incomplete-type-is-not-allowed-stringstream/5781612
//https://stackoverflow.com/questions/5288036/how-to-clear-ostringstream
// Test 1 that was published (Michael Trushkin's)
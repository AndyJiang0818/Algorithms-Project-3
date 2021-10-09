// Xihao Jiang
// CSCI 335 Homework 3
// Main file for Part 2.1 of Homework 3.

#include "avl_tree.h"
#include "sequence_map.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

namespace {

// @dbx_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &dbx_filename, TreeType &a_tree) {
  ifstream infile(dbx_filename);
  string line, temp;
  while (getline(infile, line)) {
    vector<string> field;
    istringstream iss(line);
    while (getline(iss, temp, '/')) {
      field.push_back(temp);
    }
    if (field.size() >= 3) {
      unsigned int i = 1;
      while (i < field.size()) {
        if (field[i].size() > 0 && field[0][0] != ' ') {
          SequenceMap map(field[i], field[0]);
          if (a_tree.contains(map)) {
            SequenceMap temp = a_tree.search(map);
            temp.Merge(map);
            a_tree.insert(temp);
          } else {
            a_tree.insert(map);
          }
        }
        i++;
      }
    }
  }
  //a_tree.printTree();
}

}  // namespace

int
main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
    return 0;
  }
  const string dbx_filename(argv[1]);
  cout << "Input filename is " << dbx_filename << endl;
  // Note that you will replace the type AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<SequenceMap> a_tree;
  QueryTree(dbx_filename, a_tree);
  string input;
  for (int i = 0; i < 3; i++) {
    cin >> input;
    SequenceMap seq(input, "");
    if (a_tree.contains(seq)) {
      SequenceMap result = a_tree.search(seq);
      cout << result << endl;
    } else {
      cout << "Not Found" << endl;
    }
  }
  return 0;
}

// Xihao Jiang
// CSCI 335 Homework 3
// Main file for Part 2.2 of Homework 3.

#include "avl_tree.h"
#include "sequence_map.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

namespace
{

  // @dbx_filename: an input database filename.
  // @seq_filename: an input sequences filename.
  // @a_tree: an input tree of the type TreeType. It is assumed to be
  //  empty.
  template <typename TreeType>
  void TestTree(const string &dbx_filename, const string &seq_filename, TreeType &a_tree)
  {
    ifstream infile(dbx_filename);
    string line, temp;
    while (getline(infile, line))
    {
      vector<string> field;
      istringstream iss(line);
      while (getline(iss, temp, '/'))
      {
        field.push_back(temp);
      }
      if (field.size() >= 3)
      {
        unsigned int i = 1;
        while (i < field.size())
        {
          if (field[i].size() > 0 && field[0][0] != ' ')
          {
            SequenceMap map(field[i], field[0]);
            if (a_tree.contains(map))
            {
              SequenceMap temp = a_tree.search(map);
              temp.Merge(map);
              a_tree.insert(temp);
            }
            else
            {
              a_tree.insert(map);
            }
          }
          i++;
        }
      }
    }
  }

} // namespace

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
    return 0;
  }
  const string dbx_filename(argv[1]);
  const string seq_filename(argv[2]);
  cout << "Input file is " << dbx_filename << ", and sequences file is " << seq_filename << endl;
  // Note that you will replace the type AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<SequenceMap> a_tree;
  TestTree(dbx_filename, seq_filename, a_tree);
  cout << "2: " << a_tree.getSize() << endl;
  double average = (double)a_tree.totalDepth() / a_tree.getSize();
  cout << "3a: " << average << endl;
  cout << "3b: " << log10(average) / log10(a_tree.getSize()) << endl;
  ifstream infile(seq_filename);
  string line;
  while (getline(infile, line))
  {
    SequenceMap seq(line, "");
    a_tree.search(seq);
  }
  cout << "4a: " << a_tree.querySucc << endl;
  cout << "4b: " << (double)a_tree.totalRec / a_tree.querySucc << endl;
  ifstream infile2(seq_filename);
  while (getline(infile2, line))
  {
    SequenceMap seq(line, "");
    a_tree.remove(seq);
  }
  cout << "5a: " << a_tree.removeSucc << endl;
  cout << "5b: " << (double)a_tree.totalRemoveRec / a_tree.removeSucc << endl;
  cout << "6a: " << a_tree.getSize() << endl;
  average = (double)a_tree.totalDepth() / a_tree.getSize();
  cout << "6b: " << average << endl;
  cout << "6c: " << log10(average) / log10(a_tree.getSize()) << endl;
  return 0;
}

# AVL Trees

## Overview
Create a class object named SequenceMap that has as private data members the following two: string recognition_sequence_ ; vector<string> enzyme_acronyms_;

1. Add a constructor SequenceMap(const string &a_rec_seq, const string &an_enz_acro),that
constructs a SequenceMap from two strings (note that after the constructor is called the vector
enzyme_acronyms_ will contain just one element, the an_enz_acro).

2. bool operator<(const SequenceMap &rhs) const, that operates based on the regular string
comparison between the recognition_sequence_ strings (this will be a one line function).

3. Overload the << operator in order to print out the enzyme_acronyms vector, for a given
recognition sequence. Refer to assignment 1 for example of overloading the operator signature.

4. void Merge(const SequenceMap &other_sequence). This function assumes that the object’s
recognition_sequence_ and other_sequence.recognition_sequence_ are equal to each other. The
function Merge() merges the other_sequence.enzyme_acronym_ with the object’s
enzyme_acronym_. The other_sequence object will not be affected.

## Thoughts
1. Set up a constructor sequence_map. 
2. Created public operations "bool operator", "friend ostream& operator", "void Merge"; 
and private "string recognition_sequence_", "vector<string> enzyme_acronyms_". 
3. Threw an "UnderflowException" when there is an error. 
4. Completed the method where removing x from the tree, and nothing happens when x is not found. 
Print out the tree properly. 

## Run
- To compile on terminal type:
1. make clean
2. make all

- To delete executables and object file type:
1. make clean

- To run with a given file that is redirected to standard input:
1. ./query_tree rebase210.txt
2. ./query_tree rebase210.txt < input_part2.1.txt
3. ./test_tree rebase210.txt sequences.txt
4. ./test_tree_mod rebase210.txt sequences.txt

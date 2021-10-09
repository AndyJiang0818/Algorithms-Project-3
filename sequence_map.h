// Xihao Jiang
// CSCI 335 Homework 3

#ifndef SEQUENCE_MAP_H
#define SEQUENCE_MAP_H

#include <iostream>
#include <vector>

using namespace std;

class SequenceMap
{
public:
    SequenceMap(const string &a_rec_seq, const string &an_enz_acro)
    {
        recognition_sequence_ = a_rec_seq;
        enzyme_acronyms_ = vector<string>();
        enzyme_acronyms_.push_back(an_enz_acro);
    }

    bool operator<(const SequenceMap &rhs) const
    {
        return recognition_sequence_ < rhs.recognition_sequence_;
    }

    friend ostream& operator<<(ostream &ostr, const SequenceMap &map)
    {
        for (unsigned int i = 0; i < map.enzyme_acronyms_.size(); i++)
        {
            ostr << map.enzyme_acronyms_[i] << " ";
        }
        return ostr;
    }

    void Merge(const SequenceMap &other_sequqnce)
    {
        for (unsigned int i = 0; i < other_sequqnce.enzyme_acronyms_.size(); i++)
        {
            enzyme_acronyms_.push_back(other_sequqnce.enzyme_acronyms_[i]);
        }
    }

private:
    string recognition_sequence_;
    vector<string> enzyme_acronyms_;
};

#endif

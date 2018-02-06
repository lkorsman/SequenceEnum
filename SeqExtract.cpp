// AUTHOR: Luke Korsman
// FILENAME: SeqExtract.cpp
// DATE: 03Nov2017
// VERSION: 1

// ASSUMPTIONS / INVARIANTS:
// 1. The extractSubsequence function should only be called if object is active
// 2. No string should be returned if user accidentally calls
//    returnWordVariation when the object is inactive
// 3. The returnWordVariation function only checks if the subsequence passed 
//    into the constructor is the beginning or end of the encapsulated word.

#include "SeqExtract.h"
#include <iostream>
using namespace std;

SeqExtract::SeqExtract(string encapWord, string subsequenceOfEncapWord) : 
    SequenceEnum(encapWord)
{
    subsequence = subsequenceOfEncapWord;
}

string SeqExtract::returnWordVariation()
{
    if (isActive())
    {
        string word = getEncapsulatedWord();
        string beginEncapWord =
            word.substr(0, subsequence.length());
        string beginOtherHalf = 
            word.substr(subsequence.length());
        string endEncapWord =
        word.substr((word.length() -
                    subsequence.length()));
        string endOtherHalf;
        if (subsequence.length() == 1)
        {
            endOtherHalf =
                word.substr(0, (word.length() - 1));
        }
        else
        {
            endOtherHalf =
                word.substr(0, (word.length() -
                            subsequence.length()));
        }
        
        active = false;
        if (subsequence.length() >= word.length() || 
            subsequence.length() == 0)
            return "This is not a subsequence of the encapsulated word!";
        else if (subsequence == beginEncapWord)
            return beginOtherHalf;
        else if (subsequence == beginOtherHalf)
            return beginEncapWord;
        else if (subsequence == endEncapWord)
            return endOtherHalf;
        else if (subsequence == endOtherHalf)
            return endEncapWord;
        else
            return "This is not a subsequence of the encapsulated word!";
    }
    return "";
}

void SeqExtract::setEncapsulatedWord(string encapWord, 
        string subsequenceOfEncapWord)
{
    SequenceEnum::setEncapsulatedWord(encapWord);
    subsequence = subsequenceOfEncapWord;
    active = true;
}

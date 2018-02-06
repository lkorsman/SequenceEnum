// AUTHOR: Luke Korsman
// FILENAME: SpasEnum.h
// DATE: 05Nov2017
// VERSION: 1

// ASSUMPTIONS / INVARIANTS:
// 1. The returnWordVariation should check object state to determine what 
//    variation of the encapsulated word should be returned.
// 2. If the object is active, a concatenated version of the encapsulated word
//    should be returned from the returnWordVariation function.
// 3. If the object is inactive, a truncated version of the encapsulated word
//    should be returned from the returnAlternateWordVariation function.
// 4. The concatenated and truncated versions of the encapsulated word should
//    seemingly be random.

#include "SpasEnum.h"
#include <iostream>
using namespace std;

SpasEnum::SpasEnum(string encapsulatedWord) : SequenceEnum(encapsulatedWord)
    {
        srand(time(0));
    }

string SpasEnum::returnWordVariation()
{
    int randomVariationPicker = rand() % 2;
    string word = getEncapsulatedWord();
    
    if (isActive())
    {
        active = false;
        if (randomVariationPicker == 1)
        {
            return word.substr(0, 2) + word;
        }
        else
        {
            return word + word.substr(0, 2);
        }
    }
    return "";
}

string SpasEnum::returnAlternateWordVariation()
{
    int randomVariationPicker = rand() % 2;
    string word = getEncapsulatedWord();
    
    if (!isActive())
    {
        if (randomVariationPicker == 1)
        {
            return word.substr(0, 1);
        }
        else
        {
            return word.substr(0, 2);
        } 
    }
    return "";
}
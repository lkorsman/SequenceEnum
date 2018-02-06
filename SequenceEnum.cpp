// AUTHOR: Luke Korsman
// FILENAME: SequenceEnum.cpp
// DATE: 03Nov2017
// VERSION: 1

// ASSUMPTIONS:
// 1. returnWordVariation should not be called if inactive. The function should
//    return no string if called while object is inactive
// 2. returnWordVariation should randomly repeat a character of the encapsulated
//    word
// 3. Calling the returnWordVariation should set the object to inactive
// 4. The user should not have direct access to the encapsulatedWord variable
// 5. The setEncapsulatedWord function should set the object to active

#include "SequenceEnum.h"
#include <iostream>
using namespace std;

SequenceEnum::SequenceEnum(string word)
{
    srand(time(0));
    encapsulatedWord = word;
    active = true;
}

string SequenceEnum::returnWordVariation()
{
    if (active)
    {
        long encapWordLen = encapsulatedWord.length();
        string lastLetter =
            encapsulatedWord.substr((encapWordLen-1),(encapWordLen-1));
        string firstLetter = encapsulatedWord.substr(0,1);
        int randomNumber = rand() % 3;
        
        active = false;
        if (randomNumber == 1)
        {
            return encapsulatedWord + lastLetter;
        }
        else
            return firstLetter + encapsulatedWord;
    }
    return "";
}

bool SequenceEnum::guessEncapsulatedWord(string guess) const
{
    if (!active)
    {
        if (guess == encapsulatedWord)
            return true;
        else
            return false;
    }
    return false;
}

bool SequenceEnum::isActive() const
{
    return active;
}

string SequenceEnum::getEncapsulatedWord()
{
    return encapsulatedWord;
}

void SequenceEnum::setEncapsulatedWord(string word)
{
    encapsulatedWord = word;
    active = true;
}


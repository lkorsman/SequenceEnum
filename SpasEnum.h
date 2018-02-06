// AUTHOR: Luke Korsman
// FILENAME: SpasEnum.h
// DATE: 05Nov2017
// VERSION: 1

// DESCRIPTION: If active, a SpasEnum concatenates an internal subsequence,
// seemingly arbitrarily piece of the word encapsulated by the SequenceEnum
// class. If inactive, it truncates the word encapsulated by the SequenceEnum
// class.
// FUNCTIONALITY:
// - Calling the returnWordVariation function while active returns a sequence 
//   of the encapsulated word, seemingly arbitrarily.
// - Calling the returnAlternateWordVariation function while inactive returns a 
//   truncated version of the encapsulated word.
// - The user has the ability to guess the encapsulated word by calling the
//   guessEncapsulatedWord from the parent class and passing in a string.
// - The user can check if the object is active by calling isActive function
//   contained in the parent class
// LEGAL STATES:
// - The object can be active meaning the a word has been encapsulated and the
//   returnWordVariation has not been called.
// - The object can be inactive, meaning the returnWordVariation function has
//   been called.
// DEPENDENCIES: SequenceEnum.h
// ANTICIPATED USE: This class is intended to be a guessing game where a user
// can submit a word to be encapsulated and then get a hint of what the
// encapsulated word is by calling the returnWordVariation & 
// returnAlternateWordVariation functions
// DATA PROCESSED: Strings
// LEGAL INPUT:
// - For the constructor, lowercase, alphabetical strings of length 3 or longer
// ILLEGAL INPUT:
// - For the constructor, uppercase letters, non-alphabetical characters,
//   strings less than length 3.
// ASSUMPTIONS:
// 1. The SpasEnum object is initially active when the constructor is called.
// 2. Calling the returnWordVariation function when the object is active will
//    return a concatenated version of the encapsulated word.
// 3. Calling the returnAlteranteWordVariation function when the object is 
//    inactive will return a truncated version of the encapsulated word.

#ifndef SPASENUM_H
#define SPASENUM_H
#include "SequenceEnum.h"
#include <iostream>
using namespace std;

class SpasEnum: public SequenceEnum
{
public:
    SpasEnum(string);
    // Description: Constructor of the object. Encapsulates the word passed in
    // as a parameter and sets the object to active. The word passed in must be
    // alphabetical characters only, lowercase and of length 3 or longer.
    // Preconditions: None
    // Postconditions: Object is active
    
    string returnWordVariation();
    // Description: If active, returns a concatenated version of the 
    // encapsulated word and sets the object to inactive. 
    // Preconditions: Object must be active
    // Postconditions: Object is inactive
    
    string returnAlternateWordVariation();
    // Description: If inactive, returns a truncated version of the 
    // encapsulated word.
    // Preconditions: Object must be inactive
    // Postconditions: Object is inactive
};
#endif
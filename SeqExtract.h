// AUTHOR: Luke Korsman
// FILENAME: SeqExtract.h
// DATE: 03Nov2017
// VERSION: 1

// DESCRIPTION: If active, the SeqExtract class extracts a subsequence of the
// encapsulated word from the SequenceEnum class if the subsequence is found
// within the encapsulated word. For example, if the word ‘believe’ is
// encapsulated, and the subsequence ‘beli’ proffered, ‘eve’ would be emitted.
// FUNCTIONALITY:
// - Calling the returnWordVariation function while active will return the rest
//   of the subsequence of the encapsulated word if that subsequence is found
// - The user has the ability to guess the encapsulated word by calling the
//   guessEncapsulatedWord from the parent class and passing in a string.
// - The user can check if the object is active by calling isActive function
//   contained in the parent class
// - The setEncapsulatedWord function allows the user to set the object again
//   using a new encapsulated word and subsequence guess. It also sets the 
//   object to active
// LEGAL STATES:
// - The object can be active meaning the returnWordVariation function has not 
//   been called.
// - The object can be inactive, meaning the returnWordVariation has been 
//   called.
// DEPENDENCIES: SequenceEnum.h
// ANTICIPATED USE: This class is intended to be a guessing game where a user
// can submit a word to be encapsulated and then get a hint of what the
// encapsulated word is by guessing either the start or ending of the
// encapsulated word.
// DATA PROCESSED: Strings
// LEGAL INPUT:
// - For the constructor, lowercase, alphabetical strings of 
// length 3 or longer are accepted as the first parameter.
// - For the constructor's second parameter, lowercase, alphabetical characters
//   of length less than the length of the encapsulated word and longer than 0
//   are accepted.
// - For the setEncapsualtedWord function's the first parameter, lowercase, 
//   alphabetical strings of length 3 or longer are accepted as the parameter.
// - For the setEncapsulatedWord's second parameter, lowercase, alphabetical 
//   characters of length less than the length of the encapsulated word and 
//   longer than 0 are accepted.
// ILLEGAL INPUT:
// - For the constructor's first parameter, uppercase letters, non-alphabetical
// characters, strings less than length 3.
// - For the constructor's second parameter, uppercase, non-alphabetical
//   characters.
// - For the setEncapsulatedWord function's first parameter, uppercase letters,
//   non-alphabetical characters, strings less than length 3.
// - For the setEncapulsatedWord function's second parameter, uppercase, 
//   non-alphabetical characters.
// ASSUMPTIONS:
// 1. The SequenceEnum object is initially 'active'.
// 2. The user will either proffer the start or end of the encapsulated word
//    as their subsequence for the constructor and setEncapsulaltedWord.
// 3. The user can only call the returnWordVariation once to receive a hint at 
//    the encapsulated word. If the user wishes to proffer another subsequence
//    of the encapsulated word, they will need to use the setEncapsulateWord 
//    function using the same encapsulated word and their new subsequence
//    guess.

#ifndef SEQEXTRACT_H
#define SEQEXTRACT_H
#include "SequenceEnum.h"
#include <iostream>
using namespace std;

class SeqExtract: public SequenceEnum
{    
private:
    string subsequence;
    
public:
    SeqExtract(string encapWord, string subsequenceOfEncapWord);
    // Description: Constructor of the SeqExtract object. Encapsulates the
    // first string taken in a parameter. The second string taken in as a 
    // parameter is a user's guess at a subsequence of the encapsulated first
    // word. The first word passed in must be alphabetical characters only, 
    // lowercase and of length 3 or longer. The second word should be 
    // alphabetical characters only, lowercase and a guess at the beginning or
    // end of the encapsulated word.
    // Preconditions: None
    // Postconditions: The object is active
    
    string returnWordVariation();
    // Description: Returns the other half of the encapsulated word if the 
    // subsequenceOfEncapWord taken in as a parameter to the constructor is
    // a subsequence of the beginning or end of the encapsulated word
    // Preconditions: The object must be active
    // Postconditions: The object is inactive  
    
    void setEncapsulatedWord(string encapWord, string subsequenceOfEncapWord);
    // Description: Resets the SeqExtract object to active and encapsulates 
    // the first string passed in as a parameter. The second string should be 
    // a guess at a subsequence of the encapsulated first word. The first word
    // passed in must be alphabetical characters only, lowercase and of length 
    // 3 or longer. The second word should be alphabetical characters only, 
    // lowercase and a guess at the beginning or end of the encapsulated word.
    // Preconditions: The object must be inactive
    // Postconditions: The object is active
};
#endif
// AUTHOR: Luke Korsman
// FILENAME: SequenceEnum.h
// DATE: 03Nov2017
// VERSION: 1

// DESCRIPTION: The SequenceEnum class contains an encapsulated word. It emits
// a variation of that word repeating one of the characters if the SequenceEnum
// class is active. The class also supports guessing of the encapsulated word.
// FUNCTIONALITY:
// - When active, the user can call the returnWordVariation function to receive
//   a variation of the encapsulated word with one of the letters repeating.
// - The user has the ability to guess the encapsulated word by calling the
//   guessEncapsulatedWord and passing in a string.
// - The user can check the state of the object by calling the isActive
//   function
// - The setEncapsulatedWord function allows the user to set the object again
//   using a new encapsulated word. It also sets the object to active
// LEGAL STATES:
// - The object can be active meaning a word has been encapsulated and the 
//   returnWordVariation has not been called
// - The object can be inactive, meaning the returnWordVariation has been 
//   called.
// DEPENDENCIES: None
// ANTICIPATED USE: This class is intended to be a guessing game where a user
// can submit a word to be encapsulated and then get a hint of what the
// encapsulated word is by returning a variation of the encapsulated
// word.
// DATA PROCESSED: Strings
// LEGAL INPUT:
// - For the constructor, lowercase, alphabetical strings of length 3 or longer
//   are accepted as the parameter
// - For the guessEncapsulatedWord function, lowercase, alphabetical strings of
//   length 3 or longer are accepted as the parameter
// - For setEncapsulatedWord, lowercase, alphabetical strings of length 3 or 
//   longer are accepted as the parameter
// ILLEGAL INPUT:
// - For the constructor, uppercase letters, non-alphabetical characters,
//   strings less than length 3.
// - For the guessEncapsulatedWord function, uppercase letters,
//   non-alphabetical characters are not allowed for the parameter.
// - For setEncapsulatedWord, uppercase letters, non-alphabetical characters,
//   strings less than length 3.
// ASSUMPTIONS:
// 1. The SequenceEnum object is initially 'active' when using the constructor
//    that takes a string as a parameter.
// 2. The SequenceEnum object is 'inactive' once the returnWordVariation 
//    function is called
// 3. The user will check state using the isActive function before calling
//    returnWordVariation, guessEncapsulatedWordfunction, & setEncapsulatedWord.

#ifndef SEQUENCEENUM_H
#define SEQUENCEENUM_H
#include <iostream>
using namespace std;

class SequenceEnum
{
private:
    string encapsulatedWord;    // Encapsulated word that can be guessed
    
protected:
    bool active;                    // Determines state of the object
    string getEncapsulatedWord();   // Getter for encapsulatedWord
    
public:
    SequenceEnum(string);
    // Description: Constructor of the object. The string passed in as a
    // parameter must be a word (of alphabetical characters), lowercase and of
    // length 3 or longer.
    // Preconditions: None
    // Postconditions: Object is active
    
    string returnWordVariation();
    // Description: Returns a variation of the encapsulated word with one of
    // the encapsulated word's letters repeating. Sets the object to inactive.
    // Preconditions: The object must be active
    // Postconditions: The object is inactive
    
    bool guessEncapsulatedWord(string) const;
    // Description: Allows user to guess the encapsulated word. Returns true if
    // the string passed in is the encapsulated word, false if not. The string
    // passed in must be lowercase.
    // Preconditions: The object must be inactive
    // Postconditions: None
    
    bool isActive() const;
    // Description: Returns true if the object is active, false if it is
    // inactive
    // Preconditions: None
    // Postconditions: None
    
    void setEncapsulatedWord(string);
    // Description: Sets the SequenceEnum object to active and encapsulates 
    // the string passed in as a parameter. The string passed in as a parameter
    // must be a word (of alphabetical characters), lowercase and of length 3 
    // or longer.
    // Preconditions: The object must be inactive
    // Postconditions: The object is active
};
#endif

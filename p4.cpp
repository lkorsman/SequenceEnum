// AUTHOR: Luke Korsman
// FILENAME: p4.cpp
// DATE: 03Nov2017
// VERSION: 1

// DESCRIPTION OF MAIN PROCESS(ES): This will test all the functions of the 
// SequenceEnum, SeqExtract and SpasEnum classes. Each function in this class 
// will test one of the classes. First, each function will initialize an object
// of that class. Next, it will print a description of the test to the console.
// Then run its tests. Last, it will print the results of the tests to the 
// console.
// DATA STRUCTURES USED: SequenceEnum, SeqExtract and SpasEnum objects, strings
// FUNCTIONALITY EXERCISED: Tests inheritance, making sure the derived classes
// (SeqExtract and SpasEnum) inherit functionality of SequenceEnum correctly. 
// Also, this class tests the behavior of each function in each class, making 
// sure they return the correct variations of the encapsulated word.
// SOURCE OF INPUT: None
// FORMAT OF OUTPUT: Printing to the console
// DESIGN: Functions have been created with pre-defined test parameters and the
// results are printed to the console
// INTENT: The intent is to demonstrate inheritance between a base class and
// two derived classes.
//
// ASSUMPTIONS:
// 1. No input is needed from the user or file.
// 2. Libraries used: <iostream>
// 3. Classes used: SequenceEnum, SeqExtract, SpasEnum

#include "SequenceEnum.h"
#include "SeqExtract.h"
#include "SpasEnum.h"
#include <iostream>
using namespace std;

void welcome();
// Description: Describes the program to the user. Lets the user know this 
// program will run tests to test the functions and constructors of the 
// the three classes (SequenceEnum, SeqExtract, SpasEnum).
// Input: None
// Processing: Nothing
// Output: Printing to console

void testSequenceEnumClass();
// Description: This function tests the SequenceEnum class. It will ensure the 
// constructor works properly as well as all the functions of the class. It 
// will also ensure a valid state is maintained.
// Input: None
// Processing: None
// Output: Printing to console

void testSequenceEnumSetEncapsulatedWord();
// Description: This will test the setEncapsulatedWord function of the 
// SequenceEnum class. It will ensure a new word is encapsulated and set to 
// active.
// Input: None
// Processing: None
// Output: Printing to console

void testSeqExtractClass();
// Description: This function tests the SeqExtract class. It will ensure the 
// constructor works properly as well as all the functions of the class. It 
// will also ensure a valid state is maintained.
// Input: None
// Processing: None
// Output: Printing to console

void testSeqExSetEncapsulatedWord();
// Description: This will test the setEncapsulatedWord function of the 
// SeqExtract class. It will ensure a new word is encapsulated and set to 
// active.
// Input: None
// Processing: None
// Output: Printing to console

void testSeqExtractReturnWordVariations();
// Description: This will test all the variations that could be returned from
// the returnWordVariation function of the SeqExtract class. This is to ensure
// the strings returned from the function return the correct piece of the 
// encapsulated word.
// Input: None
// Processing: None
// Output: Printing to console

void testSpasEnumClass();
// Description: This function tests the SpasEnum class. It will ensure the 
// constructor works properly as well as all the functions of the class. It 
// will also ensure a valid state is maintained.
// Input: None
// Processing: None
// Output: Printing to console

void testSpasEnumSetEncapsulatedWord();
// Description: This will test the setEncapsulatedWord function of the 
// SpasEnum class. It will ensure a new word is encapsulated and set to 
// active.
// Input: None
// Processing: None
// Output: Printing to console

void goodbye();
// Description: Prints a message to the console letting the user know the 
// program finished.
// Input: None
// Processing: Nothing
// Output: Printing to console

int main() {
    welcome();
    testSequenceEnumClass();
    testSequenceEnumSetEncapsulatedWord();
    testSeqExtractClass();
    testSeqExSetEncapsulatedWord();
    testSeqExtractReturnWordVariations();
    testSpasEnumClass();
    testSpasEnumSetEncapsulatedWord();
    goodbye();
    return 0;
}

void welcome()
{
    cout << "\nThis program tests the functionality of the three classes: "
            "SequenceEnum, SeqExtract \nand SpasEnum. It will test the "
            "different state changes and as well SeqExtract and \nSpasEnum "
            "inheriting from the SequenceEnum base class.\n" << endl;
}

void testSequenceEnumClass()
{
    SequenceEnum seqE("hello");
    
    cout << "This function will test the functions of the SequenceEnum class." 
            " First it will \ncreate a SequenceEnum object, then call the "
            "functions of the class while testing \nthe state throughout.\n"; 
    cout << "seqE object initial state: " << (seqE.isActive() ?
                                              "Active" : "Inactive") << endl;
    cout << "Calling the returnWordVariation function, result: "
            << seqE.returnWordVariation() << endl;
    cout << "seqE object state: " << (seqE.isActive() ?
                                      "Active" : "Inactive") << endl;
    cout << "Trying to call returnWordVariation while object is inactive: "
            << seqE.returnWordVariation() << endl;
    cout << "Guessing encapsulated word as 'goodbye': "
            << (seqE.guessEncapsulatedWord("goodbye") ?
                "Correct" : "Incorrect") << endl;
    cout << "Guessing encapsulated word as 'hello': "
            << (seqE.guessEncapsulatedWord("hello") ? "Correct" : "Incorrect")
            << endl << endl;
}

void testSequenceEnumSetEncapsulatedWord()
{
    SequenceEnum seqESet("abc");
    
    cout << "This function tests the setEncapsulatedWord function of the "
            "SequenceEnum class. \nIt will ensure a new encapsulated word is "
            "stored and the object is set back \nto active." << endl;
    cout << "Object created with word 'abc', state: " << (seqESet.isActive() ?
                                      "Active" : "Inactive") << endl;
    cout << "Calling returnWordVariation function: " 
            << seqESet.returnWordVariation() << endl;
    cout << "State: " << (seqESet.isActive() ?
                                      "Active" : "Inactive") << endl;
    cout << "Calling setEncapsulatedWord using word 'xyz'." << endl;
    seqESet.setEncapsulatedWord("xyz");
    cout << "State: " << (seqESet.isActive() ?
                                      "Active" : "Inactive") << endl;
    cout << "Calling returnWordVariation function: " 
            << seqESet.returnWordVariation() << endl << endl;
    
}

void testSeqExtractClass()
{
    SeqExtract seqEx("fido", "fud");
    
    cout << "This function will test the functions of the SeqExtract class. "
            "First it will create \na SeqExtract object, then call the "
            "functions of the class and its base class \n(SequenceEnum) while "
            "testing the state throughout." << endl;
    cout << "Created a SeqExtract object with an encapsulated word 'fido' "
            "and a subsequence of \n'fud'." << endl;
    cout << "seqEx object initial state: " << (seqEx.isActive() ?
                                               "Active" : "Inactive") << endl;
    cout << "Calling the returnWordVariation function\n";
    cout << "Result: " << seqEx.returnWordVariation() << endl;
    cout << "SeqEx object state: " << (seqEx.isActive() ?
                                       "Active" : "Inactive") << endl;
    cout << "Guessing encapsulated word as 'fidO': "
            << (seqEx.guessEncapsulatedWord("fidO") ? "Correct" : "Incorrect")
            << endl;
    cout << "Guessing encapsulated word as 'fido': "
            << (seqEx.guessEncapsulatedWord("fido") ? "Correct" : "Incorrect")
            << endl << endl;
}

void testSeqExSetEncapsulatedWord()
{
    SeqExtract seqExSet("abc", "a");
    
    cout << "This function tests the setEncapsulatedWord function of the "
            "SeqExtract class. \nIt will ensure a new encapsulated word is "
            "stored and the object is set back \nto active." << endl;
    cout << "Created a SeqExtract object with an encapsulated word 'abc' "
            "and a subsequence \nof 'a'." << endl;
    cout << "seqExSet object initial state: " << (seqExSet.isActive() ?
                                      "Active" : "Inactive") << endl;
    cout << "Calling returnWordVariation function: " 
            << seqExSet.returnWordVariation() << endl;
    cout << "State: " << (seqExSet.isActive() ?
                                      "Active" : "Inactive") << endl;
    cout << "Calling setEncapsulatedWord using word 'xyz' and subsequence "
            "'xy'." << endl;
    seqExSet.setEncapsulatedWord("xyz", "xy");
    cout << "State: " << (seqExSet.isActive() ?
                                      "Active" : "Inactive") << endl;
    cout << "Calling returnWordVariation function: " 
            << seqExSet.returnWordVariation() << endl;
    cout << "State: " << (seqExSet.isActive() ?
                                      "Active" : "Inactive") << endl << endl;
}

void testSeqExtractReturnWordVariations()
{
    SeqExtract seqExReturns("abc", "a");
    
    cout << "This function will test all the variations of the "
            "returnWordVariation function \nof the SeqExtract class to ensure "
            "all returned variations of the function are \nworking properly."
            << endl;
    cout << "Encapsulated 'abc' and proffered 'a', results: " 
            << seqExReturns.returnWordVariation() << endl;
    seqExReturns.setEncapsulatedWord("abc", "ab");
    cout << "Encapsulated 'abc' and proffered 'ab', results: " 
            << seqExReturns.returnWordVariation() << endl;
    seqExReturns.setEncapsulatedWord("abc", "c");
    cout << "Encapsulated 'abc' and proffered 'c', results: " 
            << seqExReturns.returnWordVariation() << endl;
    seqExReturns.setEncapsulatedWord("abc", "bc");
    cout << "Encapsulated 'abc' and proffered 'bc', results: " 
            << seqExReturns.returnWordVariation() << endl;
    seqExReturns.setEncapsulatedWord("abc", "abc");
    cout << "Encapsulated 'abc' and proffered 'abc' \nResults: " 
            << seqExReturns.returnWordVariation() << endl;
    seqExReturns.setEncapsulatedWord("abc", "");
    cout << "Encapsulated 'abc' and proffered ''(zero characters) \nResults: " 
            << seqExReturns.returnWordVariation() << endl << endl;
}

void testSpasEnumClass()
{
    SpasEnum spasE("mississippi");
    
    cout << "This will test the functions of the SpasEnum class. First it "
            "will create a \nSpasEnum object, then call the functions of the "
            "class and its base class \n(SequenceEnum) while testing the state"
            " throughout." << endl;
    cout << "spasE object initial state: " << (spasE.isActive() ?
                                               "Active" : "Inactive") << endl;
    cout << "Calling the returnWordVariation function\n";
    cout << "Result: " << spasE.returnWordVariation() << endl;
    cout << "spasE object state: " << (spasE.isActive() ?
                                       "Active" : "Inactive") << endl;
    cout << "Calling the returnAlternateWordVariation function\n";
    cout << "Result: " << spasE.returnAlternateWordVariation() << endl;
    cout << "spasE object state: " << (spasE.isActive() ?
                                       "Active" : "Inactive") << endl << endl;
}

void testSpasEnumSetEncapsulatedWord()
{
    SpasEnum spasESet("spasenum");
    
    cout << "This function tests the setEncapsulatedWord function of the "
            "SpasEnum class. \nIt will ensure a new encapsulated word is "
            "stored and the object is set back \nto active." << endl;
    cout << "Object created with word 'spasenum', state: " << 
            (spasESet.isActive() ? "Active" : "Inactive") << endl;
    cout << "Calling returnWordVariation function: " 
            << spasESet.returnWordVariation() << endl;
    cout << "State: " << (spasESet.isActive() ?
                                      "Active" : "Inactive") << endl;
    cout << "Calling setEncapsulatedWord using word 'abcdefg'." << endl;
    spasESet.setEncapsulatedWord("abcdefg");
    cout << "State: " << (spasESet.isActive() ?
                                      "Active" : "Inactive") << endl;
    cout << "Calling returnWordVariation function: " 
            << spasESet.returnWordVariation() << endl;
    cout << "State: " << (spasESet.isActive() ?
                                      "Active" : "Inactive") << endl;
    cout << "Calling returnAlternateWordVariation function: " 
            << spasESet.returnAlternateWordVariation() << endl;
    cout << "State: " << (spasESet.isActive() ?
                                      "Active" : "Inactive") << endl << endl;
}

void goodbye()
{
    cout << "Program has ended.\n" << endl;
}

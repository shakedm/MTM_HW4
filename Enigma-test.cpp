#include "Enigma.h"
#include "mtmtest.h"
#include <functional>
#include <string>
#include <iostream>

using namespace mtm::escaperoom;

void EnigmaEqual(){
    std::set<string> test = {"first", "second", "third"};
    Enigma first("1", EASY_ENIGMA, 3, test);
    Enigma second("2", MEDIUM_ENIGMA);
    Enigma third("3", HARD_ENIGMA);

    Enigma first_copy(first);
    Enigma second_copy(second);

    Enigma assigned_enigma = third;

    ASSERT_EQUALS(first , first_copy); //checks both copy_c'tor & == operator
    ASSERT_EQUALS(second , second_copy); //checks both copy_c'tor & == operator
    ASSERT_EQUALS(third , assigned_enigma); //checks assignment & operator
    ASSERT_EQUALS(first, first);
}

void EnigmaNotEqual() {
    std::set<string> test = {"first", "second", "third"};
    Enigma first("1", EASY_ENIGMA, 3, test);
    Enigma second("2", MEDIUM_ENIGMA);
    Enigma third("3", HARD_ENIGMA);

    Enigma first_copy(first);
    Enigma second_copy(second);

    Enigma assigned_enigma = third;

    ASSERT_NOT_EQUAL(first , third);
    ASSERT_NOT_EQUAL(second , assigned_enigma);
    ASSERT_NOT_EQUAL(assigned_enigma, first_copy);
    ASSERT_NOT_EQUAL(second_copy, first);
}

void EnigmaLessThan(){
    std::set<string> test = {"first", "second", "third"};
    Enigma first("1", EASY_ENIGMA, 3, test);
    Enigma second("2", MEDIUM_ENIGMA);
    Enigma third("3", HARD_ENIGMA);

    Enigma first_copy(first);

    Enigma assigned_enigma = third;

    ASSERT_TRUE(first < second);
    ASSERT_FALSE(third < second);
    ASSERT_FALSE(assigned_enigma < first_copy);
}

void EnigmaGreaterThan(){
    std::set<string> test = {"first", "second", "third"};
    Enigma first("1", EASY_ENIGMA, 3, test);
    Enigma second("2", MEDIUM_ENIGMA);
    Enigma third("3", HARD_ENIGMA);

    Enigma first_copy(first);
    Enigma second_copy(second);

    Enigma assigned_enigma = third;

    ASSERT_FALSE(first > first_copy);
    ASSERT_TRUE(assigned_enigma > second_copy);
    ASSERT_TRUE(third > second);
}

void EnigmaPrint(){
    std::set<string> test = {"first", "second", "third"};
    Enigma first("1", EASY_ENIGMA, 3, test);
    Enigma second("2", MEDIUM_ENIGMA);
    Enigma third("3", HARD_ENIGMA);

    Enigma first_copy(first);
    Enigma second_copy(second);

    Enigma assigned_enigma = third;

    ASSERT_PRINT("1 (0) 3", first);
    ASSERT_PRINT("2 (1) 0", second_copy);
    ASSERT_PRINT("3 (2) 0", assigned_enigma);
}

void EnigmaAreEqualyComplex(){
    std::set<string> test = {"first", "second", "third"};
    Enigma first("1", EASY_ENIGMA, 3, test);
    Enigma second("2", MEDIUM_ENIGMA);
    Enigma third("3", HARD_ENIGMA);

    Enigma first_copy(first);
    Enigma second_copy(second);

    Enigma assigned_enigma = third;

    ASSERT_TRUE(first.areEqualyComplex(first_copy));
    ASSERT_TRUE(second.areEqualyComplex(second_copy));
    ASSERT_TRUE(third.areEqualyComplex(assigned_enigma));
    ASSERT_FALSE(first.areEqualyComplex(second));
}

void EnigmaGetName(){
    std::set<string> test = {"first", "second", "third"};
    Enigma first("1", EASY_ENIGMA, 3, test);
    Enigma second("2", MEDIUM_ENIGMA);
    Enigma third("3", HARD_ENIGMA);

    Enigma first_copy(first);
    Enigma second_copy(second);

    Enigma assigned_enigma = third;

    ASSERT_EQUALS("1", first.getName());
    ASSERT_EQUALS("2", second_copy.getName());
    ASSERT_EQUALS("3", assigned_enigma.getName());
    ASSERT_NOT_EQUAL("bla", first_copy.getName());
    ASSERT_NOT_EQUAL("room52", second.getName());
    ASSERT_NOT_EQUAL("room2", third.getName());
}

void EnigmaGetDifficulty(){
    std::set<string> test = {"first", "second", "third"};
    Enigma first("1", EASY_ENIGMA, 3, test);
    Enigma second("2", MEDIUM_ENIGMA);
    Enigma third("3", HARD_ENIGMA);

    Enigma first_copy(first);
    Enigma second_copy(second);

    Enigma assigned_enigma = third;

    ASSERT_EQUALS(EASY_ENIGMA, first.getDifficulty());
    ASSERT_EQUALS(MEDIUM_ENIGMA, second_copy.getDifficulty());
    ASSERT_EQUALS(HARD_ENIGMA, assigned_enigma.getDifficulty());
    ASSERT_NOT_EQUAL(HARD_ENIGMA, first_copy.getDifficulty());
    ASSERT_NOT_EQUAL(HARD_ENIGMA, second.getDifficulty());
    ASSERT_NOT_EQUAL(EASY_ENIGMA, third.getDifficulty());
}

void EnigmaAddRemoveElement(){
    std::set<string> test = {"first", "second", "third"};
    Enigma first("1", EASY_ENIGMA, 3, test);
    Enigma second("2", MEDIUM_ENIGMA);

    Enigma first_copy(first);

    ASSERT_TRUE(first.areEqualyComplex(first_copy));

    first.addElement("forth");

    ASSERT_THROWS(EnigmaNoElementsException, second.removeElement("first"));
    ASSERT_FALSE(first.areEqualyComplex(first_copy));
    ASSERT_THROWS(EnigmaElementNotFundException,
                  first_copy.removeElement("forth"));
    ASSERT_NO_THROW(first.removeElement("forth"));
    ASSERT_THROWS(EnigmaElementNotFundException,
                  first.removeElement("forth"));
}


void EnigmaBuilders(){
    //create various enigmas in good strat values range (checking both builders):
    std::set<std::string> test = {"first", "second", "third"};
    ASSERT_NO_THROW(Enigma("1", EASY_ENIGMA, 3, test));
    ASSERT_NO_THROW(Enigma("2", MEDIUM_ENIGMA));

    Enigma first("1", EASY_ENIGMA, 3, test);
    Enigma second("2", MEDIUM_ENIGMA);
    Enigma third("3", HARD_ENIGMA);
    //wrong set size
    ASSERT_THROWS(EnigmaIllegalSizeParamException, Enigma("3", HARD_ENIGMA, 5,
                                                           test));

    //check copy builder:
    Enigma first_copy(first);
    Enigma second_copy(second);

    //check assignment:
    Enigma assigned_enigma = third;
}



int main() {
    RUN_TEST(EnigmaBuilders);
    RUN_TEST(EnigmaEqual);
    RUN_TEST(EnigmaNotEqual);
    RUN_TEST(EnigmaLessThan);
    RUN_TEST(EnigmaGreaterThan);
    RUN_TEST(EnigmaPrint);
    RUN_TEST(EnigmaAreEqualyComplex);
    RUN_TEST(EnigmaGetName);
    RUN_TEST(EnigmaGetDifficulty);
    RUN_TEST(EnigmaAddRemoveElement);
    std::cout << "All Done!" << std::endl;
}

#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <vector>


bool ValidUserInput_for_Factorize(std::string &userInput);

bool Program_Run();


class Factorize {
private:
    int myBaseNum;
    int myScope;
    std::vector<int> myFactors;

public:
    explicit Factorize(int &number);
    bool wasOriginalPrime();
    void find_factors();
};

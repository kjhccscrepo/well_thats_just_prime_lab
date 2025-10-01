#pragma once

#include <string>
#include <vector>


bool ValidUserInput_for_Factorize(const std::string &userInput);

void Program_Run();


class Factorize {
private:
    int myBaseNum;
    int myScope;
    std::vector<int> myFactors;

public:
    explicit Factorize(const int &number);
    bool wasOriginalPrime(const std::vector<int> &check) const;
    std::vector<int> find_factors();
    std::string prettyPrint_myFactors(const std::vector<int> &factorList) const;
    void setFactors();
};


#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "prime.hpp"


bool ValidUserInput_for_Factorize(const std::string &userInput) {
    for (int i = 0; i < userInput.length(); i++) {
        if (!std::isdigit(userInput[i])) {
            return false;
        }
    }
    try {
        const int test = std::stoi(userInput);
    } catch (...) {
        return false;
    }
    const int potentialInput = std::stoi(userInput);
    return true;
}
void Program_Run() {
    bool continueProgram = true;
    while (continueProgram) {
        std::string input;
        bool validatedInput = false;
        while (!validatedInput) {
            std::cout << "Please enter in a positive integer:\t";
            getline(std::cin, input);
            if (!ValidUserInput_for_Factorize(input)) {
                std::cout << "\nPlease enter a valid positive Integer Value...\n";
            } else {
                validatedInput = true;
            }
        }
        int userInputInt = std::stoi(input);
        Factorize userFactor(userInputInt);





        continueProgram = false;
    }

}

Factorize::Factorize(const int &number) {
    this->myBaseNum = number;
    this->myScope = number;
}


bool Factorize::wasOriginalPrime(const std::vector<int> &check) const {
    if (check.at(0) == myBaseNum) {
        return true;
    } else
        return false;
}


std::vector<int> Factorize::find_factors() {
    std::vector<int> factors;
    if (myBaseNum <= 1) {
        return factors;
    }
    bool isMyScopePrime = false;
    int timeTillConfirmedPrime;
    while (!isMyScopePrime) {
        timeTillConfirmedPrime = myScope;
        for (int i = 2; i <= (myScope - 1); i++) {
            if (myScope % i == 0) {
                factors.push_back(i);
                myScope = myScope / i;
                break;
            } else {
                timeTillConfirmedPrime--;
            }
            if (timeTillConfirmedPrime == 0 && i == (myScope - 1)) {
                isMyScopePrime = true;
                factors.push_back(myScope);
            }
        }
    }
    // check if the inserted number was prime
    if (wasOriginalPrime(factors)) {
        factors.push_back(1);
    }
    return factors;
}

std::string Factorize::prettyPrint_myFactors(const std::vector<int> &factorList) const {
    std::stringstream factorStringstream;
    if (factorList.empty()) {
        factorStringstream << "The number inputted was less than or equal to 1,\nenter a different number and try again...";
    } else {
        factorStringstream << "The factors of " << this->myFactors.size() << " are:\t";
        for (int i = 0; i < this->myFactors.size(); i++) {
            factorStringstream << this->myFactors.at(i);
            if (i != this->myFactors.size() - 1) {
                factorStringstream << " X ";
            }
        }
    }
    return factorStringstream.str();
}

void Factorize::setFactors() {
    myFactors == find_factors();
}



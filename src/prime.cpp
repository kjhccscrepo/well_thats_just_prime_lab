
#include <string>
#include "prime.hpp"


bool ValidUserInput_for_Factorize(std::string &userInput) {
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
    if (potentialInput <= 1) {
        return false;
    }
    return true;
}
bool Program_Run() {
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



        continueProgram = false;
    }


    return false;
}

Factorize::Factorize(int &number) {
    this->myBaseNum = number;
    this->myScope = number;
}


bool Factorize::wasOriginalPrime() {
    if (myFactors.size() == 1 && myFactors.at(0) == this->myBaseNum) {
        return true;
    } else
        return false;
}


void Factorize::find_factors() {
    bool isMyScopePrime = false;
    int timeTillConfirmedPrime;
    while (!isMyScopePrime) {
        timeTillConfirmedPrime = this->myScope;
        for (int i = 2; i <= (this->myScope - 1); i++) {
            if (myScope % i == 0) {
                this->myFactors.push_back(i);
                this->myScope = this->myScope / i;
                break;
            } else {
                timeTillConfirmedPrime--;
            }
            if (timeTillConfirmedPrime == 0 && i == (this->myScope - 1)) {
                isMyScopePrime = true;
                this->myFactors.push_back(this->myScope);
            }
        }
    }
    // check if the inserted number was prime
    if (wasOriginalPrime()) {
        myFactors.push_back(1);
    }
}

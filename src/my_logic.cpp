#include <iostream>
#include <sstream>
#include "my_logic.hpp"
#include "prime.hpp"

std::string lowercaseString(const std::string &inputString) {
    std::string tempString;
    for (int i = 0; i < inputString.length(); i++) {
        tempString.push_back(inputString[i]);
    }
    return tempString;
}
bool frogValidStringInput(const std::string &inputString) {
    for (int i = 0; i <= inputString.length(); i++) {
        if (!std::isalpha(inputString[i])) {
            return false;
        }
    }
    return true;
}
bool compareStrings(const std::string &desiredString, const std::string &inputString) {
    if (desiredString == lowercaseString(inputString)) {
        return true;
    }
    return false;
}
bool frogValidate(const std::string &validConfirmString, const std::string &userMessage) {
    std::string userInput;
    bool validatingInput(true);
    while (validatingInput) {
        std::cout << userMessage;
        std::getline(std::cin, userInput);
        if (frogValidStringInput(userInput)) {
            validatingInput = false;
        }
    }
    return compareStrings(validConfirmString, userInput);
}
bool ValidUserInput_for_Factorize(const std::string &userInput) {
    for (int i = 0; i < userInput.length(); i++) {
        if (!std::isdigit(userInput[i])) {
            return false;
        }
    }
    return true;
}
void Program_Run() {
    std::stringstream validMessage;
    validMessage << "\nPlease enter \"yes\" to continue using the program.";
    validMessage << "\nOther input will be treated as an indication to stop.\n";
    validMessage << "\tYour input:\t";
    std::string validContinueInput = "yes";
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
        userFactor.setFactors();
        std::cout << userFactor.prettyPrint_myFactors();
        if (!frogValidate(validContinueInput, validMessage.str())) {
            continueProgram = false;
        }
    }
}

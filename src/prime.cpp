#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "prime.hpp"



Factorize::Factorize(const int &number) {
    this->myBaseNum = number;
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
    int myScope = myBaseNum;
    int fixScope = myScope;
    bool isMyScopePrime = false;
    int timeTillConfirmedPrime;
    while (!isMyScopePrime) {
        // program is stuck in here
        timeTillConfirmedPrime = myScope;
        for (int i = 2; i <= (myScope - 1); i++) {
            if (myScope % i == 0) {
                fixScope = myScope;
                factors.push_back(i);
                myScope = (fixScope / i);
                i = myBaseNum;
            } else {
                timeTillConfirmedPrime--;
            }
            if (timeTillConfirmedPrime == 1 && i == (myScope - 1)) {
                isMyScopePrime = true;
                factors.push_back(myScope);
            }
        }
    }
    // check if the inserted number was prime
    if (wasOriginalPrime(factors)) {
        factors.push_back(1);
    }
    std::ranges::sort (factors);
    return factors;
}
std::string Factorize::wasCompositeOrPrime() const {
    if (wasOriginalPrime(myFactors)) {
        return "Prime";
    }
    return "Composite";
}

std::string Factorize::factorListString() const {
    std::stringstream fs;
    for (int i = 0; i < this->myFactors.size(); i++) {
        fs << myFactors.at(i);
        if (i != myFactors.size() - 1) {
            fs << " X ";
        }
    }
    return fs.str();
}
std::string Factorize::prettyPrint_myFactors() const {
    std::stringstream stringStreamFactorPrettyPrint;
    if (myFactors.empty()) {
        stringStreamFactorPrettyPrint << "The number inputted was less than or equal to 1.\nEnter a different number and try again...\n";
    } else {
        stringStreamFactorPrettyPrint << "The factors of the " << wasCompositeOrPrime() << ", " << myBaseNum << ", are:\t";
        stringStreamFactorPrettyPrint << factorListString() << "\n";
    }
    return stringStreamFactorPrettyPrint.str();
}
void Factorize::setFactors() {
    myFactors = find_factors();
}
#pragma once
#include <string>
#include <vector>

class Factorize {
private:
    int myBaseNum;
    std::vector<int> myFactors;
public:
    explicit Factorize(const int &number);
    bool wasOriginalPrime(const std::vector<int> &check) const;
    std::vector<int> find_factors();
    std::string wasCompositeOrPrime() const;
    std::string factorListString() const;
    std::string prettyPrint_myFactors() const;
    void setFactors();
};

#include "Pattern.h"
// the class is only setters/getters + a constructor sooo not much inside
void Pattern::setPattern(const std::string& p)
{
    pattern = p;
}
void Pattern::setCount(int c)
{
    count = c;
}
void Pattern::setProbability(double prob)
{
    probability = prob;
}

std::string Pattern::getPattern() const
{
    return pattern;
}
int Pattern::getCount() const
{
    return count;
}
double Pattern::getProbability() const
{
    return probability;
}
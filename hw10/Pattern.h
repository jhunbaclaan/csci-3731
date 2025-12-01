#ifndef PATTERN_H
#define PATTERN_H

#include <string>

class Pattern
{
    private:
        std::string pattern;
        int count;
        double probability; // from 0.0-1.0

    public:
        Pattern(const std::string& p = "", int c = 0)
            :  pattern(p), count(c)
            {
                
            }
        // setters, getters
        void setPattern(const std::string& p);
        void setCount(int c);
        void setProbability(double prob);

        std::string getPattern() const;
        int getCount() const;
        double getProbability() const;
};

#endif
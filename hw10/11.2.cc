#include <iostream>
#include <cstdlib>
#include <ctime>
#include "TextReader.h"
#include "Pattern.h"

int main()
{
    // random number generator initialization
    srand((unsigned int)time(NULL));

    // settings
    std::string filename = "redchamber.txt";
    std::size_t length = 3;
    int outputLength = 500;

    // read the training text
    std::string text = TextReader::fromFile(filename);

    // count patterns
    auto counts = TextReader::counting(text, length);

    // build lookup
    auto lookup = TextReader::buildLookup(counts, length);

    // pick a prefix
    std::string generated = "dr"; // it's really up to you (just keep it as length-1)
    if(generated.size() != length - 1)
    {
        std::cerr << "prefix length must be length - 1!\n";
        return 1;
    }

    // generate
    while(generated.size() < (std::size_t)outputLength)
    {
        std::string prefix = generated.substr(generated.size() - (length - 1));

        // if doesn't exist, stop
        if(lookup.count(prefix) == 0)
        {
            break;
        }
        const std::vector<Pattern>& vec = lookup[prefix];
        // generate rand
        double r = (double)rand()/(double)RAND_MAX;
        // find first pattern with >= r cumulative prob.
        char nextChar = '?';
        for(const Pattern&p : vec)
        {
            if(r <= p.getProbability())
            {
                // last char of full pattern
                const std::string& full = p.getPattern();
                nextChar = full.back();
                break;
            }
        }
        // append
        generated.push_back(nextChar);
    }

    // print
    std::cout << "text generated:\n";
    std::cout << generated << "\n";

    return 0;
}
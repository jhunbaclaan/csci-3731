#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include "TextReader.h"

std::string TextReader::fromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if(!file.is_open())
    {
        throw std::runtime_error("could not open file! please check that " + filename + " is valid.");
    }
    std::ostringstream ss;
    ss << file.rdbuf(); // concatenate into one string
    return ss.str(); // string should be concatenated here
}

// turning the concatenized strings into words to be used by the program
std::vector<std::string> TextReader::tokenize(const std::string& text)
{
    std::vector<std::string> words; // words to tokenize
    std::string current;
    for (char c : text)
    {
        if (std::isalpha(c)) // if c.isChar()...
        {
            current += std::tolower(c);
        }
        else
        {
            if (!current.empty())
            {
                words.push_back(current);
                current.clear();
            }
        }
    }
    if (!current.empty())
    {
        words.push_back(current);
    }
    return words;
}

std::vector<std::string> TextReader::reading(const std::string& filename)
{
    return tokenize(fromFile(filename));
}

// counting patterns
std::unordered_map<std::string, int> TextReader::counting(const std::string& text, std::size_t length)
{
    std::unordered_map<std::string, int> count; // counter for patterns 
    // invalid case
    if (length < 2 || text.size() < length)
    {
        return count;
    }
    // go through entire text
    for (std::size_t i = 0; i + length <= text.size(); i++)
    {
        std::string pattern = text.substr(i, length); // substring for pattern
        count[pattern]++;
    }
    return count;
}

// lookup function
std::unordered_map<std::string, std::vector<Pattern>>
    TextReader::buildLookup(const std::unordered_map<std::string, int>& counts, std::size_t length)
    {
        std::unordered_map<std::string, std::vector<Pattern>> lookup;

        // base case
        if(length < 2)
        {
            return lookup;
        }

        // build the lookup
        for(const auto& entry : counts)
        {
            const std::string& fullPattern = entry.first;
            int count = entry.second;

            // prefix = length-1
            std::string prefix = fullPattern.substr(0, length-1);

            // create pattern
            Pattern p(fullPattern, count);
            lookup[prefix].push_back(p);
        }

        // compute probabilities per prefix
        for(auto& pair : lookup)
        {
            std::vector<Pattern>& patterns = pair.second;

            int total = 0;
            for(const Pattern& p : patterns)
            {
                total += p.getCount();
            }

            // cumulative prob
            double cumulative = 0.0;
            for(auto& p : patterns)
            {
                cumulative += static_cast<double>(p.getCount()) / total;
                p.setProbability(cumulative);
            }
        }

        return lookup;
    }
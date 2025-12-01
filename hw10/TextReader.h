#ifndef TEXTREADER_H
#define TEXTREADER_H
#include <string>
#include <vector>
#include <unordered_map>
#include "Pattern.h"

class TextReader
{
    public:
        static std::string fromFile(const std::string& filename);
        static std::vector<std::string> reading(const std::string& filename); // tokenization for discerning what are words from strings
        static std::unordered_map<std::string, int> counting(const std::string& text, std::size_t length);
        // lookup struct
        static std::unordered_map<std::string, std::vector<Pattern> >
            buildLookup(const std::unordered_map<std::string, int>& counts, std::size_t length);

    private:
        static std::vector<std::string> tokenize(const std::string& filename); // returns tokenized words w/o punctuation
};

#endif

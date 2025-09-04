#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP


#include <list>
#include <string>
#include "token.hpp"


class tokenizer
{
    public: std::list<token> tokenize(const std::list<std::string>& lines_of_code) const;
};


#endif // TOKENIZER_HPP

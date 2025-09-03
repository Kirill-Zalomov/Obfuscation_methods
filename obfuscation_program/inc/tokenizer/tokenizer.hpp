#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP


#include <list>
#include <string>
#include "token.hpp"


class tokenizer
{
    std::list<token> tokenize(const std::list<std::string>& lines_of_code);
};


#endif // TOKENIZER_HPP

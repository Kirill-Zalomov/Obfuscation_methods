#ifndef OBFUSCATOR_HPP
#define OBFUSCATOR_HPP


#include "../tokenizer/token.hpp"


#include <list>


class obfuscator
{
    public: virtual ~obfuscator() = default;
    public: virtual void obfuscate(std::list<token>& tokens) const;
};


#endif // OBFUSCATOR_HPP

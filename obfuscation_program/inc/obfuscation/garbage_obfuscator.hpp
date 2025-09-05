#ifndef GARBAGE_OBFUSCATOR_HPP
#define GARBAGE_OBFUSCATOR_HPP


#include "obfuscator.hpp"
#include "tokenizer/token_type.hpp"


#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>


class garbage_obfuscator : public obfuscator
{
    private: static const std::vector<std::string> garbage_strings;

    public: virtual void obfuscate(std::list<token>& tokens) const override;
};


#endif // GARBAGE_OBFUSCATOR_HPP

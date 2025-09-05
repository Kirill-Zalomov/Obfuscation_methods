#ifndef VARIABLES_OBFUSCATOR_HPP
#define VARIABLES_OBFUSCATOR_HPP


#include "obfuscator.hpp"
#include "../tokenizer/token.hpp"


#include <list>
#include <string>
#include <unordered_map>
#include <random>


class variables_obfuscator : public obfuscator
{
    private: static std::string generate_random_name();

    public: virtual void obfuscate(std::list<token>& tokens) const override;
};


#endif // VARIABLES_OBFUSCATOR_HPP

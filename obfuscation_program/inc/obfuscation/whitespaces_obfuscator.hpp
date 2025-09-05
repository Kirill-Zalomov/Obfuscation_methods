#ifndef WHITESPACES_OBFUSCATOR_HPP
#define WHITESPACES_OBFUSCATOR_HPP


#include "obfuscator.hpp"


#include <cstdlib>
#include <ctime>
#include <string>


class whitespaces_obfuscator : public obfuscator
{
    public: virtual void obfuscate(std::list<token>& tokens) const override;
};


#endif // WHITESPACES_OBFUSCATOR_HPP

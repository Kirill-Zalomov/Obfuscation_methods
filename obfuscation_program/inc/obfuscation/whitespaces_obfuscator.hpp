#ifndef WHITESPACES_OBFUSCATOR_HPP
#define WHITESPACES_OBFUSCATOR_HPP


#include "obfuscator.hpp"


class whitespaces_obfuscator : public obfuscator
{
    public: virtual void obfuscate(std::list<token>& tokens) const override;
};


#endif // WHITESPACES_OBFUSCATOR_HPP

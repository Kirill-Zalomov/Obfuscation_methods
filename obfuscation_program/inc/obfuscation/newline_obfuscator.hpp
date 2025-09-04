#ifndef NEWLINES_OBFUSCATOR_HPP
#define NEWLINES_OBFUSCATOR_HPP


#include "obfuscator.hpp"


class newlines_obfuscator : public obfuscator
{
    public: virtual void obfuscate(std::list<token>& tokens) const override;
};


#endif // NEWLINES_OBFUSCATOR_HPP

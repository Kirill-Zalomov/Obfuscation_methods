#ifndef VARIABLES_OBFUSCATOR_HPP
#define VARIABLES_OBFUSCATOR_HPP


#include "obfuscator.hpp"


class variables_obfuscator : public obfuscator
{
    public: virtual void obfuscate(std::list<token>& tokens) const override;
};


#endif // VARIABLES_OBFUSCATOR_HPP

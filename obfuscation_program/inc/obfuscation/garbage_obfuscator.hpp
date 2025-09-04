#ifndef GARBAGE_OBFUSCATOR_HPP
#define GARBAGE_OBFUSCATOR_HPP


#include "obfuscator.hpp"


class garbage_obfuscator : public obfuscator
{
    public: virtual void obfuscate(std::list<token>& tokens) const override;
};


#endif // GARBAGE_OBFUSCATOR_HPP

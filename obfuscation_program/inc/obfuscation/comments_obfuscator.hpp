#ifndef COMMENTS_OBFUSCATOR_HPP
#define COMMENTS_OBFUSCATOR_HPP


#include "obfuscator.hpp"


class comments_obfuscator : public obfuscator
{
    public: virtual void obfuscate(std::list<token>& tokens) const override;
};


#endif // COMMENTS_OBFUSCATOR_HPP

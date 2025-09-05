#ifndef COMMENTS_OBFUSCATOR_HPP
#define COMMENTS_OBFUSCATOR_HPP


#include "obfuscator.hpp"


#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>


class comments_obfuscator : public obfuscator
{
    private: static const std::vector<std::string> random_words;

    public: virtual void obfuscate(std::list<token>& tokens) const override;
};


#endif // COMMENTS_OBFUSCATOR_HPP

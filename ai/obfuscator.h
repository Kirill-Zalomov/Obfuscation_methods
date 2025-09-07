#ifndef OBFUSCATOR_H
#define OBFUSCATOR_H

#include <string>
#include <vector>
#include <random>

class Obfuscator {
private:
    std::mt19937 rng;

    // Генерация случайных данных
    std::string generateRandomIdentifier();
    std::string generateRandomComment();
    std::string generateRandomStatement();
    std::string generateRandomSpaces();

    // Вспомогательные функции
    bool isKeyword(const std::string& word);
    bool isInStringOrComment(const std::string& code, size_t pos);
    bool isValidVariableChar(char c);
    bool isPreprocessorDirective(const std::string&, size_t);
    bool isProtectedIdentifier(const std::string&);

public:
    Obfuscator();
    std::string obfuscate(const std::string& code);
};

#endif

#include "obfuscator.h"
#include <random>
#include <algorithm>
#include <cctype>
#include <map>
#include <iostream>
#include <set>

Obfuscator::Obfuscator() : rng(std::random_device()()) {}

std::string Obfuscator::generateRandomIdentifier() {
    static const char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
    static const int charCount = sizeof(chars) - 1;

    std::uniform_int_distribution<int> lengthDist(4, 12);
    std::uniform_int_distribution<int> charDist(0, charCount - 1);

    int length = lengthDist(rng);
    std::string result;

    // Первый символ должен быть буквой или _
    std::uniform_int_distribution<int> firstCharDist(0, 51);
    result += chars[firstCharDist(rng)];

    // Остальные символы
    for (int i = 1; i < length; ++i) {
        result += chars[charDist(rng)];
    }

    return result;
}

std::string Obfuscator::generateRandomComment() {
    static const std::vector<std::string> commentWords = {
        "TODO", "FIXME", "NOTE", "OPTIMIZE", "DEBUG", "TEST", "WORKAROUND",
        "temporary", "solution", "implementation", "algorithm", "function",
        "variable", "constant", "parameter", "return", "value", "object"
    };

    std::uniform_int_distribution<int> typeDist(0, 2);
    std::uniform_int_distribution<int> wordDist(0, commentWords.size() - 1);
    std::uniform_int_distribution<int> countDist(2, 8);

    int type = typeDist(rng);
    std::string comment;

    if (type == 0) {
        // Однострочный комментарий
        comment = "// ";
        int wordCount = countDist(rng);
        for (int i = 0; i < wordCount; ++i) {
            comment += commentWords[wordDist(rng)] + " ";
        }
    } else if (type == 1) {
        // Многострочный комментарий
        comment = "/* ";
        int wordCount = countDist(rng);
        for (int i = 0; i < wordCount; ++i) {
            comment += commentWords[wordDist(rng)] + " ";
        }
        comment += "*/";
    }

    return comment;
}

std::string Obfuscator::generateRandomStatement() {
    static const std::vector<std::string> statements = {
        "int _temp_" + generateRandomIdentifier() + " = 0;",
        "double _var_" + generateRandomIdentifier() + " = 1.0;",
        "if(false){}",
        "while(false){}",
        "for(int i=0;i<0;i++){}",
        "bool _flag_" + generateRandomIdentifier() + " = true;",
        "char _ch_" + generateRandomIdentifier() + " = 'a';",
        "unsigned long _ul_" + generateRandomIdentifier() + " = 0UL;",
        "float _f_" + generateRandomIdentifier() + " = 0.0f;",
        "short _s_" + generateRandomIdentifier() + " = 0;",
        "long _l_" + generateRandomIdentifier() + " = 0L;"
    };

    std::uniform_int_distribution<int> dist(0, statements.size() - 1);
    return statements[dist(rng)];
}

bool Obfuscator::isKeyword(const std::string& word) {
    static const std::vector<std::string> keywords = {
        "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor",
        "bool", "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t",
        "class", "compl", "concept", "const", "constexpr", "const_cast", "continue",
        "co_await", "co_return", "co_yield", "decltype", "default", "delete", "do",
        "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern",
        "false", "float", "for", "friend", "goto", "if", "inline", "int", "long",
        "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr",
        "operator", "or", "or_eq", "private", "protected", "public", "register",
        "reinterpret_cast", "requires", "return", "short", "signed", "sizeof",
        "static", "static_assert", "static_cast", "struct", "switch", "template",
        "this", "thread_local", "throw", "true", "try", "typedef", "typeid",
        "typename", "union", "unsigned", "using", "virtual", "void", "volatile",
        "wchar_t", "while", "xor", "xor_eq"
    };

    return std::find(keywords.begin(), keywords.end(), word) != keywords.end();
}

bool Obfuscator::isProtectedIdentifier(const std::string& identifier) {
    static const std::set<std::string> protectedIdentifiers = {
        // Стандартные пространства имен
        "std", "boost", "qt", "android", "ios", "windows",

        // Стандартные типы и классы
        "string", "wstring", "cout", "wcout", "cin", "wcin", "endl", "cerr", "clog",
        "vector", "map", "set", "list", "array", "deque", "queue", "stack", "pair",
        "tuple", "function", "atomic", "thread", "mutex", "condition_variable",
        "future", "promise", "shared_ptr", "unique_ptr", "weak_ptr", "optional",
        "variant", "any", "chrono", "filesystem", "regex", "random", "ratio",

        // Макросы и директивы препроцессора
        "include", "define", "ifdef", "ifndef", "endif", "pragma", "error", "warning",
        "line", "undef",

        // Основные функции
        "main", "printf", "scanf", "malloc", "free", "new", "delete", "sizeof",
        "alignof", "typeid", "dynamic_cast", "static_cast", "reinterpret_cast",
        "const_cast", "noexcept", "throw", "try", "catch",

        // Системные идентификаторы
        "NULL", "nullptr", "true", "false", "bool", "char", "int", "float", "double",
        "void", "short", "long", "signed", "unsigned", "const", "volatile", "static",
        "extern", "register", "auto", "inline", "virtual", "explicit", "friend",
        "operator", "template", "typename", "class", "struct", "union", "enum",
        "namespace", "using", "typedef", "public", "protected", "private",
        "this", "return", "if", "else", "switch", "case", "default", "for", "while",
        "do", "break", "continue", "goto", "asm",

        // Системные заголовки
        "iostream", "vector", "string", "map", "set", "algorithm", "functional",
        "memory", "thread", "chrono", "atomic", "mutex", "condition_variable",
        "future", "type_traits", "utility", "tuple", "optional", "variant", "any",
        "filesystem", "regex", "random", "numeric", "cmath", "cstdlib", "cstdio",
        "cstring", "ctime", "cassert", "cerrno", "climits", "cfloat", "cstdint",
        "cstddef", "cstdarg", "csetjmp", "csignal", "cctype", "cwctype", "clocale",
        "codecvt", "iosfwd", "ios", "istream", "ostream", "iostream", "fstream",
        "sstream", "streambuf", "iomanip", "exception", "stdexcept", "system_error",
        "initializer_list", "new", "typeinfo", "bitset", "functional", "iterator",
        "ratio", "cfenv", "cinttypes", "cuchar", "array", "deque", "forward_list",
        "list", "queue", "stack", "vector", "map", "set", "unordered_map",
        "unordered_set", "iterator", "algorithm", "numeric", "memory", "scoped_allocator",
        "complex", "valarray", "random", "limits", "cstdbool", "cstdalign"
    };

    return protectedIdentifiers.find(identifier) != protectedIdentifiers.end();
}

bool Obfuscator::isPreprocessorDirective(const std::string& code, size_t pos) {
    // Ищем начало строки
    size_t lineStart = pos;
    while (lineStart > 0 && code[lineStart - 1] != '\n') {
        lineStart--;
    }

    // Проверяем, есть ли '#' в начале строки
    for (size_t i = lineStart; i < pos; i++) {
        if (code[i] == '#') {
            return true;
        }
        if (!std::isspace(code[i])) {
            break;
        }
    }

    return false;
}

bool Obfuscator::isInStringOrComment(const std::string& code, size_t pos) {
    bool inSingleLineComment = false;
    bool inMultiLineComment = false;
    bool inString = false;
    bool inChar = false;
    char quoteChar = '\0';

    for (size_t i = 0; i < pos && i < code.size(); ++i) {
        if (inSingleLineComment) {
            if (code[i] == '\n') {
                inSingleLineComment = false;
            }
            continue;
        }

        if (inMultiLineComment) {
            if (code[i] == '*' && i + 1 < code.size() && code[i + 1] == '/') {
                inMultiLineComment = false;
                ++i;
            }
            continue;
        }

        if (inString) {
            if (code[i] == '\\') {
                ++i; // Skip escaped character
            } else if (code[i] == quoteChar) {
                inString = false;
            }
            continue;
        }

        if (inChar) {
            if (code[i] == '\\') {
                ++i;
            } else if (code[i] == '\'') {
                inChar = false;
            }
            continue;
        }

        if (code[i] == '/' && i + 1 < code.size()) {
            if (code[i + 1] == '/') {
                inSingleLineComment = true;
                ++i;
            } else if (code[i + 1] == '*') {
                inMultiLineComment = true;
                ++i;
            }
        } else if (code[i] == '"' || code[i] == '\'') {
            inString = (code[i] == '"');
            inChar = (code[i] == '\'');
            quoteChar = code[i];
        }
    }

    return inSingleLineComment || inMultiLineComment || inString || inChar;
}

bool Obfuscator::isValidVariableChar(char c) {
    return std::isalnum(c) || c == '_';
}

std::string Obfuscator::obfuscate(const std::string& code) {
    std::string result;
    std::map<std::string, std::string> variableMap;

    // Первый проход: сбор переменных (только локальных)
    size_t i = 0;
    while (i < code.size()) {
        if (!isInStringOrComment(code, i)) {
            // Поиск потенциальных идентификаторов
            if (std::isalpha(code[i]) || code[i] == '_') {
                size_t start = i;
                while (i < code.size() && isValidVariableChar(code[i])) {
                    ++i;
                }

                std::string identifier = code.substr(start, i - start);

                // Пропускаем защищенные идентификаторы и ключевые слова
                if (!isKeyword(identifier) && !isProtectedIdentifier(identifier) && identifier.size() > 1) {
                    // Проверяем контекст - если перед идентификатором есть тип, это может быть объявление
                    size_t beforeStart = start;
                    while (beforeStart > 0 && std::isspace(code[beforeStart - 1])) {
                        --beforeStart;
                    }

                    // Ищем тип перед идентификатором
                    if (beforeStart > 0) {
                        size_t typeEnd = beforeStart;
                        while (typeEnd > 0 && isValidVariableChar(code[typeEnd - 1])) {
                            --typeEnd;
                        }

                        std::string potentialType = code.substr(typeEnd, beforeStart - typeEnd);
                        if (isKeyword(potentialType) &&
                            (potentialType == "int" || potentialType == "double" || potentialType == "float" ||
                             potentialType == "char" || potentialType == "bool" || potentialType == "void" ||
                             potentialType == "short" || potentialType == "long" || potentialType == "unsigned" ||
                             potentialType == "signed" || potentialType == "const" || potentialType == "static" ||
                             potentialType == "auto" || potentialType == "volatile" || potentialType == "register")) {

                            // Это объявление переменной - добавляем в карту
                            if (variableMap.find(identifier) == variableMap.end()) {
                                variableMap[identifier] = generateRandomIdentifier();
                            }
                        }
                    }
                }
            } else {
                ++i;
            }
        } else {
            ++i;
        }
    }

    // Второй проход: применение обфускации
    i = 0;
    bool lastWasComment = false;
    std::uniform_real_distribution<double> probDist(0.0, 1.0);

    while (i < code.size()) {
        char current = code[i];

        // Проверяем, находимся ли мы в строке/комментарии
        if (isInStringOrComment(code, i)) {
            // В комментарии - удаляем или оставляем
            if (current == '/' && i + 1 < code.size() && code[i + 1] == '/') {
                // Однострочный комментарий - удаляем с вероятностью 70%
                if (probDist(rng) < 0.7) {
                    // Пропускаем до конца строки
                    while (i < code.size() && code[i] != '\n') {
                        ++i;
                    }
                    continue;
                } else {
                    // Оставляем комментарий
                    result += "//";
                    i += 2;
                    lastWasComment = true;
                }
            } else if (current == '/' && i + 1 < code.size() && code[i + 1] == '*') {
                // Многострочный комментарий - удаляем с вероятностью 80%
                if (probDist(rng) < 0.8) {
                    // Пропускаем до конца комментария
                    i += 2;
                    while (i < code.size() - 1 && !(code[i] == '*' && code[i + 1] == '/')) {
                        ++i;
                    }
                    if (i < code.size() - 1) i += 2;
                    continue;
                } else {
                    result += "/*";
                    i += 2;
                    lastWasComment = true;
                }
            } else {
                result += current;
                ++i;
            }
        } else {
            // Не в строке/комментарии - применяем обфускацию

            // Проверяем, не директива ли препроцессора
            bool isPreprocessor = isPreprocessorDirective(code, i);

            // Обработка идентификаторов
            if (std::isalpha(current) || current == '_') {
                size_t start = i;
                while (i < code.size() && isValidVariableChar(code[i])) {
                    ++i;
                }

                std::string identifier = code.substr(start, i - start);

                // Переименовываем только если это не защищенный идентификатор
                if (!isKeyword(identifier) && !isProtectedIdentifier(identifier) &&
                    variableMap.find(identifier) != variableMap.end()) {
                    result += variableMap[identifier];
                } else {
                    result += identifier;
                }
                continue;
            }

            // Вставка случайных операторов (2% вероятность после ; { })
            if ((current == ';' || current == '}' || current == '{') && probDist(rng) < 0.02) {
                result += current;
                result += generateRandomStatement();
                ++i;
                continue;
            }

            // Удаление переводов строк (кроме случаев после комментариев и директив препроцессора)
            if (current == '\n') {
                if (lastWasComment || isPreprocessorDirective(code, i)) {
                    result += current;
                    lastWasComment = false;
                } else if (probDist(rng) < 0.8) { // 80% вероятность удаления перевода строк
                    result += ' ';
                } else {
                    result += current;
                }
                ++i;
                continue;
            }

            result += current;
            ++i;
        }
    }

    return result;
}

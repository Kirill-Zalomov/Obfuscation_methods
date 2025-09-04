#include "tokenizer/token_classifier.hpp"


const std::unordered_set<std::string> token_classifier::key_words = {
    "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor",
    "break", "case", "catch", "class", "compl", "concept", "const", "consteval",
    "constexpr", "constinit", "const_cast", "continue", "co_await", "co_return",
    "co_yield", "decltype", "default", "delete", "do", "dynamic_cast", "else",
    "enum", "explicit", "export", "extern", "false", "for", "friend", "goto",
    "if", "inline", "mutable", "namespace", "new", "noexcept", "not", "not_eq",
    "nullptr", "operator", "or", "or_eq", "private", "protected", "public",
    "register", "reinterpret_cast", "requires", "return", "sizeof", "static",
    "static_assert", "static_cast", "struct", "switch", "template", "this",
    "thread_local", "throw", "true", "try", "typedef", "typeid", "typename",
    "union", "using", "virtual", "void", "volatile", "while", "xor", "xor_eq"
};


const std::unordered_set<std::string> token_classifier::data_types = {
    "bool", "char", "char8_t", "char16_t", "char32_t", "double", "float",
    "int", "long", "short", "signed", "unsigned", "void", "wchar_t",

    "int8_t", "int16_t", "int32_t", "int64_t",
    "uint8_t", "uint16_t", "uint32_t", "uint64_t",

    "long double", "float_t", "double_t",

    "size_t", "ssize_t", "ptrdiff_t", "time_t", "clock_t",

    "auto",

    "array", "vector", "deque", "forward_list", "list",
    "set", "map", "multiset", "multimap",
    "unordered_set", "unordered_map", "unordered_multiset", "unordered_multimap",
    "stack", "queue", "priority_queue",

    "string", "wstring", "u8string", "u16string", "u32string",
    "basic_string", "string_view", "wstring_view", "u8string_view",
    "u16string_view", "u32string_view",

    "pair", "tuple",

    "optional", "variant", "any",

    "unique_ptr", "shared_ptr", "weak_ptr", "auto_ptr",
};


const std::unordered_set<std::string> token_classifier::operators = {
    "+", "-", "*", "/", "%", "++", "--", "==", "!=", "<", ">", "<=", ">=",
    "&&", "||", "!", "&", "|", "^", "~", "<<", ">>", "=", "+=", "-=", "*=",
    "/=", "%=", "&=", "|=", "^=", "<<=", ">>=", "->", ".", "->*", ".*", "?",
    ":", "::"
};


const std::regex token_classifier::
identifier_pattern("^[a-zA-Z_][a-zA-Z0-9_]*$");

const std::regex token_classifier::
literal_pattern("^(\\d+(\\.\\d+)?([eE][+-]?\\d+)?)|('.')|(\".*\")|(true|false|nullptr)$");

const std::regex token_classifier::
comment_pattern("^//.*$");

const std::regex token_classifier::
multi_line_comment_pattern("^/\\*.*\\*/$");

const std::regex token_classifier::
preprocessor_pattern("^#.*$");


bool token_classifier::is_key_word ( const std::string& token ) const
{
    return key_words.find(token) != key_words.end();
}


bool token_classifier::is_literal(const std::string& token) const
{
    // Проверяем числовые литералы
    if (!token.empty())
    {
        // Целые числа и числа с плавающей точкой
        if (std::isdigit(token[0]) ||
        (token.size() > 1 && token[0] == '.' && std::isdigit(token[1])))
        {
            try
            {
                std::size_t pos;
                std::stod(token, &pos);
                return pos == token.size();
            }
            catch (...)
            {
                // Не число
            }
        }

        // Строковые литералы
        if (token.size() >= 2 && token.front() == '"' && token.back() == '"')
        {
            return true;
        }

        // Символьные литералы
        if (token.size() >= 3 && token.front() == '\'' && token.back() == '\'')
        {
            return true;
        }

        // Булевы литералы и nullptr
        if (token == "true" || token == "false" || token == "nullptr")
        {
            return true;
        }
    }
    return false;
}


bool token_classifier::is_data_type(const std::string& token) const
{
    return data_types.find(token) != data_types.end();
}


bool token_classifier::is_identifier(const std::string& token) const
{
    if (token.empty()) return false;

    // Проверяем, что это не ключевое слово и не тип данных
    if (is_key_word(token) || is_data_type(token))
    {
        return false;
    }

    // Проверяем паттерн идентификатора
    return std::regex_match(token, identifier_pattern);
}


bool token_classifier::is_operator(const std::string& token) const
{
    return operators.find(token) != operators.end();
}


bool token_classifier::is_semicolon(const std::string& token) const
{
    return token == ";";
}


bool token_classifier::is_comment(const std::string& token) const
{
    return std::regex_match(token, comment_pattern);
}


bool token_classifier::is_multi_line_comment(const std::string& token) const
{
    return std::regex_match(token, multi_line_comment_pattern) ||
           (token.size() >= 4 && token.substr(0, 2) == "/*" &&
            token.substr(token.size() - 2) == "*/");
}


bool token_classifier::is_preprocessor_directive(const std::string& token) const
{
    return !token.empty() && token[0] == '#' &&
           (token.find("include") != std::string::npos ||
            token.find("define") != std::string::npos ||
            token.find("ifdef") != std::string::npos ||
            token.find("ifndef") != std::string::npos ||
            token.find("endif") != std::string::npos ||
            token.find("pragma") != std::string::npos);
}


bool token_classifier::is_openning_round_bracket(const std::string& token) const
{
    return token == "(";
}


bool token_classifier::is_closing_round_bracket(const std::string& token) const
{
    return token == ")";
}


bool token_classifier::is_openning_square_bracket(const std::string& token) const
{
    return token == "[";
}


bool token_classifier::is_closing_square_bracket(const std::string& token) const
{
    return token == "]";
}


bool token_classifier::is_openning_curly_bracket(const std::string& token) const
{
    return token == "{";
}


bool token_classifier::is_closing_curly_bracket(const std::string& token) const
{
    return token == "}";
}


bool token_classifier::is_openning_triangle_bracket(const std::string& token) const
{
    return token == "<";
}


bool token_classifier::is_closing_triangle_bracket(const std::string& token) const
{
    return token == ">";
}


bool token_classifier::is_new_line_symbol(const std::string& token) const
{
    return token == "\n";
}


#ifndef TOKEN_TYPE_HPP
#define TOKEN_TYPE_HPP


enum token_type
{
    unknown_,
    literal_,
    key_word_,
    data_type,
    identifier_,
    operator_,
    semicolon_,
    comment_,
    multi_line_comment_,
    preprocessor_directive_,
    openning_parenthesis_,
    closing_parenthesis_,
    openning_curly_brace_,
    closing_curly_brace_,
};


#endif // TOKEN_TYPE_HPP

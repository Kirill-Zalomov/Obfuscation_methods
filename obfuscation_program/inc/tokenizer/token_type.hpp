#ifndef TOKEN_TYPE_HPP
#define TOKEN_TYPE_HPP


enum token_type
{
    unknown_,
    literal_,
    space_,
    key_word_,
    data_type_,
    identifier_,
    operator_,
    semicolon_,
    comment_,
    multi_line_comment_,
    preprocessor_directive_,
    openning_square_bracket_,
    closing_square_bracket_,
    openning_curly_bracket_,
    closing_curly_bracket_,
    openning_round_bracket_,
    closing_round_bracket_,
    openning_triangle_bracket_,
    closing_triangle_bracket_,
};


#endif // TOKEN_TYPE_HPP

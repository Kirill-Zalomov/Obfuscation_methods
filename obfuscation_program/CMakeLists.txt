cmake_minimum_required(VERSION 3.10)
project(obfuscation_program VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(tokenizator_test_programm
    "src/tokenizator_test_programm.cpp"
    "src/tokenizer/token.cpp"
    "src/tokenizer/token_classifier.cpp"
    "src/tokenizer/token_printer.cpp"
    "src/tokenizer/tokenizer.cpp"
    "src/io/file_reader.cpp"
)
target_include_directories(tokenizator_test_programm PUBLIC
    "inc/"
)


add_executable(args_parser_test_programm
    "src/args_parser_test_programm.cpp"
    "src/args/args_parser.cpp"
    "src/args/arg_checker.cpp"
)
target_include_directories(args_parser_test_programm PUBLIC
    "inc/"
)

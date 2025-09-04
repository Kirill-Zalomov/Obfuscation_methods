cmake_minimum_required(VERSION 3.10)
project(obfuscation_program VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(obfuscation_program
    "src/main.cpp"
    "src/tokenizer/token.cpp"
    "src/tokenizer/token_classifier.cpp"
    "src/tokenizer/token_printer.cpp"
    "src/tokenizer/tokenizer.cpp"
    "src/io/file_reader.cpp"
)
target_include_directories(obfuscation_program PUBLIC
    "inc/"
    "inc/args/"
    "inc/gui/"
    "inc/io/"
    "inc/obfuscation/"
    "inc/tokenizer/"
)

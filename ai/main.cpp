#include <iostream>
#include <fstream>
#include <string>
#include "obfuscator.h"

std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
    return content;
}

void writeFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot create file: " + filename);
    }

    file << content;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
        return 1;
    }

    try {
        std::string inputFile = argv[1];
        std::string outputFile = argv[2];

        std::cout << "Reading input file: " << inputFile << std::endl;
        std::string code = readFile(inputFile);

        std::cout << "Obfuscating code..." << std::endl;
        Obfuscator obfuscator;
        std::string obfuscatedCode = obfuscator.obfuscate(code);

        std::cout << "Writing output file: " << outputFile << std::endl;
        writeFile(outputFile, obfuscatedCode);

        std::cout << "Obfuscation completed successfully!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

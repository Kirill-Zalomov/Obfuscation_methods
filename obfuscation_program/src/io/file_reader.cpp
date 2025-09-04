#include "io/file_reader.hpp"


std::list<std::string> file_reader::read_lines(const std::string& filename)
{
    std::list<std::string> lines;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Не удалось открыть файл: " + filename);
    }

    std::string line;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    return lines;
}

#ifndef FILE_READER_HPP
#define FILE_READER_HPP


#include <fstream>
#include <string>
#include <list>


class file_reader
{
    public: std::list<std::string> read_file_lines(const std::string& filename);
};


#endif // FILE_READER_HPP

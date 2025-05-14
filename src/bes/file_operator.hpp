#ifndef __BES_FILE_OPERATOR_HPP__
#define __BES_FILE_OPERATOR_HPP__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <cstring>
#include <iomanip>

#include "types.hpp"

namespace bes {
    class FileBase {
        public:
        FileBase() = default;
        FileBase(std::string file_name);
        virtual ~FileBase();
        virtual bool FileLoad2Memory();
        virtual void Print2Bin();
        virtual void Print2Oct();
        virtual void Print2Dec();
        virtual void Print2Hex();

        public:
        std::string file_name_;
        std::ifstream file_;
        std::streamsize file_size_;
        std::vector<char> buffer_;
    };

    // TODO: 操作读取出的文件数据
    // class FileOperator: public FileBase {
    // };
}


#endif

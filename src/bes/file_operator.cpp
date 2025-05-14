#include "file_operator.hpp"

namespace bes
{
    /* FileBase
    * @brief: 加载文件同时初始化参数
    * @param file_name:     文件路径
    * @return:  null
    */
    FileBase::FileBase(std::string file_name): file_name_(file_name)
    {
    file_.open(file_name_, std::ios::binary | std::ios::ate);
    if (!file_.is_open())
    {
        throw std::runtime_error("ERROR: open file error.");
    }

    // 获取文件大小
    file_size_ = file_.tellg();
    // 文件指针回置
    file_.seekg(0, std::ios::beg);
    }

    /* FileLoad2Memory
    * @brief: 将文件加载至内存，后续可以通过不同的重写来优化加载至内存的方法
    * @param: null
    * @return bool: 是否加载成功
    */
    bool FileBase::FileLoad2Memory()
    {
    // 使用 vector 加载数据
    if (!file_.is_open())
    {
        std::cerr << "ERROR: load failed, file not open." << std::endl;
        return false;
    }

    if (file_size_ > MB_100)
    {
        std::cerr << "WARNING: file size exceeds 100 MB." << std::endl;
    }

    buffer_.reserve(file_size_);
    if (!file_.read(buffer_.data(), file_size_))
    {
        throw std::runtime_error("ERROR: load file error.");
        return false;
    }

    return true;
    }
    
    /* Print2Bin
    * @brief: 将二进制文件以二进制形式输出
    * @param: null
    * @return: null
    */
    void FileBase::Print2Bin()
    {
        // TODO: 将数据以二进制形式输出
        
    }

    /* Print2Oct
    * @brief: 将二进制文件以八进制形式输出
    * @param: null
    * @return: null
    */
    void FileBase::Print2Oct()
    {
        // TODO: 将数据以八进制形式输出

    }

    /* Print2Dec
    * @brief: 将二进制文件以十进制输出
    * @param: null
    * @return: null
    */
    void FileBase::Print2Dec()
    {
        // 以十进制输出需要将数据进行转化
        int32_t *data = nullptr;
        data = reinterpret_cast<int32_t*>(buffer_.data());
        for (int i = 0; i < file_size_ / 4; i++)
        {
            std::cout << std::dec << std::setw(10) << *data << " ";
            if ((i + 1) % 16 == 0)
            {
                std::cout << std::endl;
            }
        }

    }

    /* Print2Hex
    * @brief: 将二进制文件以十六进制输出
    */
    void FileBase::Print2Hex()
    {
        for (int i = 0; i < file_size_; i++)
        {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned char>(buffer_[i]) << " ";
            if ((i + 1) % 16 == 0)
            {
                std::cout << std::endl;
            }
        } 
    }
    
} // namespace bes

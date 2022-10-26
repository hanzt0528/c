#include<iostream>
#include <fstream>



#include<algorithm>
std::string find_file_ext(std::string str_full_path)
{
    std::string str_full_path_temp = str_full_path;
    std::transform(str_full_path_temp.begin(), str_full_path_temp.end(), str_full_path_temp.begin(), ::tolower);

    std::string::size_type pos = str_full_path_temp.rfind(".");
    std::string ext = str_full_path_temp.substr(pos == std::string::npos ? str_full_path_temp.length() : pos + 1);
    return ext;
}

int main(int argc, char* argv[])
{
    std::cout << "main:"<<std::endl;
    std::ofstream out;
	out.open("./1.txt",std::ios::app);
	out << "test"<<std::endl;
    out.close();
    
    std::cout << " test.test.onnx ext is :\n"<<find_file_ext("test.test.onnx")<<std::endl;
}
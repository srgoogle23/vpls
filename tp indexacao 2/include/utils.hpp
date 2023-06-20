#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <string>
#include <algorithm>
#include <vector>
#include <dirent.h>
#include <regex>
#include <locale>

class Utils
{
public:
    Utils();
    static std::vector<std::string> pegarArquivosPasta(const std::string &pasta);
    static std::string removerDetalhesPalavras(std::string str);
};

#endif

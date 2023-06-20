#include "utils.hpp"

Utils::Utils()
{
}

std::vector<std::string> Utils::pegarArquivosPasta(const std::string &pasta)
{
    std::vector<std::string> arquivos;
    DIR *diretorio;
    struct dirent *arquivo;
    if ((diretorio = opendir(pasta.c_str())) != nullptr)
    {
        while ((arquivo = readdir(diretorio)) != nullptr)
        {
            if (arquivo->d_type == DT_REG) // Somente arquivos regulares
            {
                arquivos.push_back(arquivo->d_name);
            }
        }
        closedir(diretorio);
    }
    return arquivos;
}

std::string Utils::removerDetalhesPalavras(std::string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    std::regex regex = std::regex("[,.;:?!]");
    str = std::regex_replace(str, regex, "");
    regex = std::regex("[-_]");
    str = std::regex_replace(str, regex, "");

    for (unsigned int i = 0; i < str.size(); i++)
    {
        str = (str.find("á") != std::string::npos) ? str.replace(str.find("á"), 2, "a") : str;
        str = (str.find("à") != std::string::npos) ? str.replace(str.find("à"), 2, "a") : str;
        str = (str.find("ã") != std::string::npos) ? str.replace(str.find("ã"), 2, "a") : str;
        str = (str.find("â") != std::string::npos) ? str.replace(str.find("â"), 2, "a") : str;
        str = (str.find("ä") != std::string::npos) ? str.replace(str.find("ä"), 2, "a") : str;
        str = (str.find("é") != std::string::npos) ? str.replace(str.find("é"), 2, "e") : str;
        str = (str.find("è") != std::string::npos) ? str.replace(str.find("è"), 2, "e") : str;
        str = (str.find("ê") != std::string::npos) ? str.replace(str.find("ê"), 2, "e") : str;
        str = (str.find("ë") != std::string::npos) ? str.replace(str.find("ë"), 2, "e") : str;
        str = (str.find("í") != std::string::npos) ? str.replace(str.find("í"), 2, "i") : str;
        str = (str.find("ì") != std::string::npos) ? str.replace(str.find("ì"), 2, "i") : str;
        str = (str.find("î") != std::string::npos) ? str.replace(str.find("î"), 2, "i") : str;
        str = (str.find("ï") != std::string::npos) ? str.replace(str.find("ï"), 2, "i") : str;
        str = (str.find("ó") != std::string::npos) ? str.replace(str.find("ó"), 2, "o") : str;
        str = (str.find("ò") != std::string::npos) ? str.replace(str.find("ò"), 2, "o") : str;
        str = (str.find("õ") != std::string::npos) ? str.replace(str.find("õ"), 2, "o") : str;
        str = (str.find("ô") != std::string::npos) ? str.replace(str.find("ô"), 2, "o") : str;
        str = (str.find("ö") != std::string::npos) ? str.replace(str.find("ö"), 2, "o") : str;
        str = (str.find("ú") != std::string::npos) ? str.replace(str.find("ú"), 2, "u") : str;
        str = (str.find("ù") != std::string::npos) ? str.replace(str.find("ù"), 2, "u") : str;
        str = (str.find("û") != std::string::npos) ? str.replace(str.find("û"), 2, "u") : str;
        str = (str.find("ü") != std::string::npos) ? str.replace(str.find("ü"), 2, "u") : str;
        str = (str.find("ç") != std::string::npos) ? str.replace(str.find("ç"), 2, "c") : str;
        str = (str.find("ý") != std::string::npos) ? str.replace(str.find("ý"), 2, "y") : str;
        str = (str.find("ÿ") != std::string::npos) ? str.replace(str.find("ÿ"), 2, "y") : str;
        str = (str.find("ñ") != std::string::npos) ? str.replace(str.find("ñ"), 2, "n") : str;
    }
    return str;
}
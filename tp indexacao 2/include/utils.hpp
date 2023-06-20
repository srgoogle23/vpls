#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <string>
#include <algorithm>
#include <vector>
#include <dirent.h>

using namespace std;

class Utils
{
	public:
		Utils();
		static vector<string> obterArquivosDaPasta(const string &pasta);
		static string removerAcentos(string str);
};

#endif
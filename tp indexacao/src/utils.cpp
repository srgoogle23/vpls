#include "utils.hpp"

Utils::Utils()
{
}

string Utils::removerAcentos( string str )
{
	if (str.find("á") != string::npos)
	{
		str =  str.replace(str.find("á"), 2, "a");
	}
	if (str.find("à") != string::npos)
	{
		str =  str.replace(str.find("à"), 2, "a");
	}
	if (str.find("ã") != string::npos)
	{
		str =  str.replace(str.find("ã"), 2, "a");
	}
	if (str.find("â") != string::npos)
	{
		str =  str.replace(str.find("â"), 2, "a");
	}
	if (str.find("ä") != string::npos)
	{
		str =  str.replace(str.find("ä"), 2, "a");
	}

	// if finds Á|À|Ã|Â|Ä replace to A
	if (str.find("Á") != string::npos)
	{
		str =  str.replace(str.find("Á"), 2, "A");
	}
	if (str.find("À") != string::npos)
	{
		str =  str.replace(str.find("À"), 2, "A");
	}
	if (str.find("Ã") != string::npos)
	{
		str =  str.replace(str.find("Ã"), 2, "A");
	}
	if (str.find("Â") != string::npos)
	{
		str =  str.replace(str.find("Â"), 2, "A");
	}
	if (str.find("Ä") != string::npos)
	{
		str =  str.replace(str.find("Ä"), 2, "A");
	}

	// if finds é|è|ê|ë replace to e
	if (str.find("é") != string::npos)
	{
		str =  str.replace(str.find("é"), 2, "e");
	}
	if (str.find("è") != string::npos)
	{
		str =  str.replace(str.find("è"), 2, "e");
	}
	if (str.find("ê") != string::npos)
	{
		str =  str.replace(str.find("ê"), 2, "e");
	}
	if (str.find("ë") != string::npos)
	{
		str =  str.replace(str.find("ë"), 2, "e");
	}

	// if finds É|È|Ê|Ë replace to E
	if (str.find("É") != string::npos)
	{
		str =  str.replace(str.find("É"), 2, "E");
	}
	if (str.find("È") != string::npos)
	{
		str =  str.replace(str.find("È"), 2, "E");
	}
	if (str.find("Ê") != string::npos)
	{
		str =  str.replace(str.find("Ê"), 2, "E");
	}
	if (str.find("Ë") != string::npos)
	{
		str =  str.replace(str.find("Ë"), 2, "E");
	}

	// if finds í|ì|î|ï replace to i
	if (str.find("í") != string::npos)
	{
		str =  str.replace(str.find("í"), 2, "i");
	}
	if (str.find("ì") != string::npos)
	{
		str =  str.replace(str.find("ì"), 2, "i");
	}
	if (str.find("î") != string::npos)
	{
		str =  str.replace(str.find("î"), 2, "i");
	}
	if (str.find("ï") != string::npos)
	{
		str =  str.replace(str.find("ï"), 2, "i");
	}

	// if finds Í|Ì|Î|Ï replace it to I
	if (str.find("Í") != string::npos)
	{
		str =  str.replace(str.find("Í"), 2, "I");
	}
	if (str.find("Ì") != string::npos)
	{
		str =  str.replace(str.find("Ì"), 2, "I");
	}
	if (str.find("Î") != string::npos)
	{
		str =  str.replace(str.find("Î"), 2, "I");
	}
	if (str.find("Ï") != string::npos)
	{
		str =  str.replace(str.find("Ï"), 2, "I");
	}

	// ó|ò|õ|ô|ö replace to o
	if (str.find("ó") != string::npos)
	{
		str =  str.replace(str.find("ó"), 2, "o");
	}
	if (str.find("ò") != string::npos)
	{
		str =  str.replace(str.find("ò"), 2, "o");
	}
	if (str.find("õ") != string::npos)
	{
		str =  str.replace(str.find("õ"), 2, "o");
	}
	if (str.find("ô") != string::npos)
	{
		str =  str.replace(str.find("ô"), 2, "o");
	}
	if (str.find("ö") != string::npos)
	{
		str =  str.replace(str.find("ö"), 2, "o");
	}

	// Ó|Ò|Õ|Ô|Ö to O
	if (str.find("Ó") != string::npos)
	{
		str =  str.replace(str.find("Ó"), 2, "O");
	}
	if (str.find("Ò") != string::npos)
	{
		str =  str.replace(str.find("Ò"), 2, "O");
	}
	if (str.find("Õ") != string::npos)
	{
		str =  str.replace(str.find("Õ"), 2, "O");
	}
	if (str.find("Ô") != string::npos)
	{
		str =  str.replace(str.find("Ô"), 2, "O");
	}
	if (str.find("Ö") != string::npos)
	{
		str =  str.replace(str.find("Ö"), 2, "O");
	}

	// ú|ù|û|ü to u and Ú|Ù|Û|Ü to U
	if (str.find("ú") != string::npos)
	{
		str =  str.replace(str.find("ú"), 2, "u");
	}
	if (str.find("ù") != string::npos)
	{
		str =  str.replace(str.find("ù"), 2, "u");
	}
	if (str.find("û") != string::npos)
	{
		str =  str.replace(str.find("û"), 2, "u");
	}
	if (str.find("ü") != string::npos)
	{
		str =  str.replace(str.find("ü"), 2, "u");
	}
	if (str.find("Ú") != string::npos)
	{
		str =  str.replace(str.find("Ú"), 2, "U");
	}
	if (str.find("Ù") != string::npos)
	{
		str =  str.replace(str.find("Ù"), 2, "U");
	}
	if (str.find("Û") != string::npos)
	{
		str =  str.replace(str.find("Û"), 2, "U");
	}
	if (str.find("Ü") != string::npos)
	{
		str =  str.replace(str.find("Ü"), 2, "U");
	}

	// ñ to n and Ñ to N
	if (str.find("ñ") != string::npos)
	{
		str =  str.replace(str.find("ñ"), 2, "n");
	}
	if (str.find("Ñ") != string::npos)
	{
		str =  str.replace(str.find("Ñ"), 2, "N");
	}

	// ç to c and Ç to C
	if (str.find("ç") != string::npos)
	{
		str =  str.replace(str.find("ç"), 2, "c");
	}
	if (str.find("Ç") != string::npos)
	{
		str =  str.replace(str.find("Ç"), 2, "C");
	}

	// ý|ÿ to y and Ý to Y
	if (str.find("ý") != string::npos)
	{
		str =  str.replace(str.find("ý"), 2, "y");
	}
	if (str.find("ÿ") != string::npos)
	{
		str =  str.replace(str.find("ÿ"), 2, "y");
	}
	if (str.find("Ý") != string::npos)
	{
		str =  str.replace(str.find("Ý"), 2, "Y");
	}

	// replace , . ; : ? ! to ''
	if (str.find(",") != string::npos)
	{
		str =  str.replace(str.find(","), 1, "");
	}
	if (str.find(".") != string::npos)
	{
		str =  str.replace(str.find("."), 1, "");
	}
	if (str.find(";") != string::npos)
	{
		str =  str.replace(str.find(";"), 1, "");
	}
	if (str.find(":") != string::npos)
	{
		str =  str.replace(str.find(":"), 1, "");
	}
	if (str.find("?") != string::npos)
	{
		str =  str.replace(str.find("?"), 1, "");
	}
	if (str.find("!") != string::npos)
	{
		str =  str.replace(str.find("!"), 1, "");
	}

	// - _ to ""
	if (str.find("-") != string::npos)
	{
		str =  str.replace(str.find("-"), 1, "");
	}
	if (str.find("_") != string::npos)
	{
		str =  str.replace(str.find("_"), 1, "");
	}

	// str to lower case
	transform(str.begin(), str.end(), str.begin(), ::tolower);

	return str;
}
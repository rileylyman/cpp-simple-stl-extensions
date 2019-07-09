#pragma once

#include "pch.h"
#include "framework.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

namespace StringUtils {
	int cstr_len(char* str);

	std::string replace_char(std::string str, char val, char replacement);

	//string methods for calculating csv
	std::string sub_string(char* str, int start, int end);
	std::vector<std::string>* str_tok(std::string str, std::string delimiter);

	//file methods
	std::string read_file(std::string file_name);

	void msg_warning(std::string msg);
	void msg_error(std::string msg);
	void msg_info(std::string msg);

}
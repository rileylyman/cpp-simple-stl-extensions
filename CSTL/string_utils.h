#pragma once

#include "pch.h"
#include "framework.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

namespace str_utils {
	int cstr_len(const char* str);

	std::string replace_char(std::string str, char val, char replacement);

	//string methods for calculating csv
	std::string sub_string(const char* str, int start, int end);
	std::vector<std::string> str_tok(const std::string& str, const std::string& delimiter);

	//file methods
	std::string read_file(const std::string& file_name);

	void msg_warning(std::string msg);
	void msg_error(std::string msg);
	void msg_info(std::string msg);

}

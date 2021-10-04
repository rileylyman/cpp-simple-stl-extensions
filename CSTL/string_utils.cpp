// XiCSV.cpp : Defines the functions for the static library.
#include "pch.h"
#include "string_utils.h"

namespace str_utils {

	int cstr_len(const char* str) {
		int count = 0;
		while (str[count] != '\0') {
			count += 1;
		}
		return count;
	}

	std::string replace_char(std::string str, char val, char replacement) {
		for (unsigned int ch = 0; ch < str.length(); ch++) {
			if (str[ch] == val) {
				str[ch] = replacement;
			}
		}
		return str;
	}

	std::string sub_string(char* str, int start, int end) {
		std::string out;

		int str_len = cstr_len(str);

		if (end > str_len) {
			end = str_len;
		}
		if (start >= end) {
			return out;
		}

		out.reserve(end - start);

		for (int i = start; i < end; i++) {
			out += str[i];
		}

		return out;
	}

	std::vector<std::string> str_tok(const std::string& str, const std::string& delimiter) {
		int str_len = str.length();
		int del_len = delimiter.length();

		std::vector<std::string> strings;
		if (del_len > str_len) {
			return strings;
		}


		const char* char_arr = str.c_str();
		std::string temp_str;

		for (int i = 0; i < str_len; i++) {
			if (sub_string(char_arr, i, i + del_len) == delimiter) {
				if (!temp_str.empty()) {
				  strings.push_back(temp_str);
				}
				temp_str.clear();
			}
			else {
				temp_str += char_arr[i];
			}
		}

		if (!temp_str.empty()) {
			strings.push_back(temp_str);
		}

		return strings;
	}

	std::string read_file(const std::string& file_name) {
		std::ifstream file(file_name, std::ios::binary);

		std::string data;

		if (!file.is_open()) {
			msg_error("Failed at opening file: " + file_name);
			return data;
		}

		// Make the string the exact size of the file.
		file.seekg(0, std::ios::end);
		data.reserve(file.tellg());
		file.seekg(0, std::ios::beg);

		std::string line;

		while (std::getline(file, line)) {
			data += line;
			data += '\n';
		}

		return data;
	}

	void msg_warning(std::string msg) {
		std::cout << "[Warning] " << msg << std::endl;
	}
	
	void msg_error(std::string msg) {
		std::cout << "[Error] " << msg << std::endl;
	}
	
	void msg_info(std::string msg) {
		std::cout << "[Info] " << msg << std::endl;
	}

}

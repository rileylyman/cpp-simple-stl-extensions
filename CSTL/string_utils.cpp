// XiCSV.cpp : Defines the functions for the static library.
#include "pch.h"
#include "string_utils.h"

namespace StringUtils {

	int cstr_len(char* str) {
		int count = 0;
		while (str[count] != '\0') {
			count += 1;
		}
		return count;
	}

	std::string replace_char(std::string str, char val, char replacement) {
		for (int ch = 0; ch < str.length(); ch++) {
			if (str[ch] == val) {
				str[ch] = replacement;
			}
		}
		return str;
	}

	std::string sub_string(char* str, int start, int end) {
		int str_len = cstr_len(str);

		if ((end - start) > str_len) {
			return "";
		}

		std::string out;

		for (int i = start; i < end; i++) {
			out += str[i];
		}

		return out;
	}

	std::vector<std::string>* str_tok(std::string str, std::string delimiter) {
		int str_len = str.length();
		int del_len = delimiter.length();

		if (del_len > str_len) {
			return nullptr;
		}

		std::vector<std::string>* strings = new std::vector<std::string>();

		char* char_arr = new char[str_len];
		char_arr = (char*)str.c_str();

		std::string temp_str = "";

		for (int i = 0; i < str_len; i++) {
			if (sub_string(char_arr, i, i + del_len) == delimiter) {
				strings->push_back(temp_str);
				temp_str = "";
			}
			else {
				temp_str += char_arr[i];
			}
		}

		if (temp_str != "") {
			strings->push_back(temp_str);
		}

		return strings;
	}

	std::string StringUtils::read_file(std::string file_name) {
		std::ifstream file;
		file.open(file_name);

		if (!file.is_open()) {
			StringUtils::msg_error("Failed at opening file: " + file_name);
			return "";
		}

		std::string data;
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
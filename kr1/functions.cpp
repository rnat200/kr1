#include "functions.h"
void InputStingsNumber(int32_t& num) {
	do {
		std::cout << "Enter Strings count \n";
		std::cin >> num;
	} while (num < 1);
	
}

void InputStrings(String *strings, int32_t num) {
	std::cout << "Enter " << num << " strings\n";
	for (int32_t i{};i<num;++i) {
		std::cin.getline(strings[i].str, MAX_WORD_LEN);
	}
}


int32_t ExtractKeys(const char* str) {
	int32_t pos = -1;
	for (int32_t i{static_cast<int32_t>( strlen(str) - 1) }; i >= 0; i--) {
		if (str[i] == ' ') {
			pos = i;
			break;
		}
	}
	char num_str[MAX_WORD_LEN];
	strcpy(num_str, str + pos + 1);
	return atoi(num_str);
}


int CompareByKeys(const void* x1, const void* x2) {
		const String* a = static_cast<const String*>(x1);
		const String* b = static_cast<const String*>(x2);
		return (a->key > b->key) - (a->key < b->key);
}

void QsortByKeys(String* str,int32_t num) {
	qsort(str, num, sizeof(String),CompareByKeys);
}

void Task() {
	int32_t num{};
	InputStingsNumber(num);
	std::cin.ignore();
	String strings[MAX_STRINGS];
	InputStrings(strings, num);
	for (int32_t i{}; i < num; ++i) {
		strings[i].key = ExtractKeys(strings[i].str);
	}
	QsortByKeys(strings, num);
	for (int32_t i{}; i < num; ++i) {
		std::cout << strings[i].str << std::endl;
	}

	
	int32_t sum{};
	int32_t min_val{-999999999};
	int32_t max_val{ 999999999};

	if (num > 0) {
		min_val = max_val = strings[0].key;
		for (int32_t i = 0; i < num; ++i) {
			sum += strings[i].key;
			if (strings[i].key < min_val) min_val = strings[i].key;
			if (strings[i].key > max_val) max_val = strings[i].key;
		}
	}

	std::cout << "Sum: " << sum << " Min: " << min_val << " Max: " << max_val << std::endl;

	
}
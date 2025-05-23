#include "functions.h"

int main() {

	try {
		Task();
	}
	catch (std::system_error& e) {
		std::cout << "System error! : " << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}

	return 0;
}
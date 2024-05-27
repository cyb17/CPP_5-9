#include <string>
#include <sstream>
#include <limits>
#include <iostream>

bool isValidPrice(const std::string& price) {
    // Check if the string contains only digits and at most one dot
    if (price.find_first_not_of("0123456789.") != std::string::npos)
        return false;

    // Find the position of the dot
    int pointPosition = price.find_first_of('.');
        double val;
    if (pointPosition == std::string::npos) {
        // No dot found, check if the value is within the double range
        std::istringstream iss(price);
        if (!(iss >> val) || !(iss.eof()) || val < 0.0 || val > std::numeric_limits<double>::max())
		{
			std::cerr << "error flux\n";
		  	return false;
		}
    } else {
        // Dot found, ensure it's the only one and not at the start or end
        if (pointPosition != price.find_last_of('.') || pointPosition == 0 || pointPosition == price.length() - 1)
            return false;

        // Convert to double and check range
        std::istringstream iss(price);
        if (!(iss >> val) || !(iss.eof()) || val < 0.0 || val > std::numeric_limits<double>::max())
        {
			std::cerr << "error flux\n";
		  	return false;
		}
    }
	std::cout << val << '\n';
    return true;
}

int main() {
    std::string price1 = "DBL_MAX";
    std::string price2 = "1234.56.78";
    std::string price3 = "12a34.56";
    std::string price4 = "1234.56.";

    std::cout << "Is valid price (1234.56): " << isValidPrice(price1) << std::endl;
    std::cout << "Is valid price (1234.56.78): " << isValidPrice(price2) << std::endl;
    std::cout << "Is valid price (12a34.56): " << isValidPrice(price3) << std::endl;
    std::cout << "Is valid price (1234.56.): " << isValidPrice(price4) << std::endl;

    return 0;
}

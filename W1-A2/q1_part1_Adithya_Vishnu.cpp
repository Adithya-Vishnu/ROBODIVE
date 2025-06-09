#include <iostream>
#include <string>
#include <vector>

int extractCalibrationValue(const std::string& line) {
    char fDigit = '0', lDigit = '0';
    for (char c : line) {
        if (isdigit(c)) {
            if (fDigit == '0') fDigit = c;
            lDigit = c;
        }
    }
    return (fDigit - '0') * 10 + (lDigit - '0');
}

int main() {
    std::vector<std::string> lines = {
        "1abc2", "pqr3stu8vwx", "a1b2c3d4e5f", "treb7uchet"
    };

    std::cout << "Individual Calibration Values:\n";
    for (const auto& line : lines) {
        int value = extractCalibrationValue(line);
        std::cout << value << "\n";
    }

    return 0;
}

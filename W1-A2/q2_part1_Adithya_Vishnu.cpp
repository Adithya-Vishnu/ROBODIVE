#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int extractCalibrationValueWithWords(const std::string& line) {
    std::unordered_map<std::string, int> wordToDigit = {
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
        {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };

    int fDigit = -1, lDigit = -1;
    std::string word = "";

    for (size_t i = 0; i < line.size(); ++i) {
        if (isalpha(line[i])) {
            word += line[i];
            if (wordToDigit.count(word)) {
                if (fDigit == -1) fDigit = wordToDigit[word];
                lDigit = wordToDigit[word];
                word = "";
            }
        } else if (isdigit(line[i])) {
            if (fDigit == -1) fDigit = line[i] - '0';
            lDigit = line[i] - '0';
        } else {
            word = "";
        }
    }

    return fDigit * 10 + lDigit;
}

int main() {
    std::vector<std::string> lines = {
        "two1nine", "eightwothree", "abcone2threexyz", "xtwone3four", 
        "4nineeightseven2", "zoneight234", "7pqrstsixteen"
    };

    std::cout << "Individual Calibration Values (with Words):\n";
    for (const auto& line : lines) {
        int value = extractCalibrationValueWithWords(line);
        std::cout << value << "\n";
    }

    return 0;
}

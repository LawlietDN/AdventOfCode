#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

bool isSafeReport(std::vector<int> const& data) {
    bool isIncreasing = true;
    bool isDecreasing = true;

    for (size_t i = 1; i < data.size(); ++i) {
        int diff = data[i] - data[i - 1];

        if (std::abs(diff) < 1 || std::abs(diff) > 3) {
            return false; 
        }

        if (diff > 0) {
            isDecreasing = false;
        } else if (diff < 0) {
            isIncreasing = false;
        }
    }

    return isIncreasing || isDecreasing;
}

int main() {
    std::ifstream file("puzzleInput.txt");
    std::string line;
    int safeCount = 0;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<int> data;
        int number;

        while (iss >> number) {
            data.push_back(number);
        }

        if (isSafeReport(data)) {
            ++safeCount;
        }
    }

    file.close();

    std::cout << "Safe reports: " << safeCount << '\n';
    return 0;
}

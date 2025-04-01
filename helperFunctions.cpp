// helperFunctions.cpp
#include "helperFunctions.h"
#include <ctime>
#include <regex>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <stdio.h>

std::string maskCardNumber(const std::string& cardNumber) {
    // Use regex to match the format of the card number and mask the middle digits
    std::regex maskPattern(R"((\d{4})(\d{4})(\d{4})(\d{4}))");
    return std::regex_replace(cardNumber, maskPattern, R"($1-XXXX-XXXX-$4)");
}

std::string getUserCountry() {
    char buffer[128];
    std::string result = "";

    // Run curl command to get country from ipinfo.io
    FILE* pipe = popen("curl -s ipinfo.io/country", "r");
    if (!pipe) return "Unknown";

    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        result += buffer;
    }
    pclose(pipe);

    // Remove trailing newline character
    result.erase(result.find_last_not_of("\n") + 1);

    return result;
}

std::string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    // Format date and time as YYYY-MM-DD HH:MM:SS
    char buffer[20];  // Buffer size increased to accommodate time
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    return std::string(buffer);
}

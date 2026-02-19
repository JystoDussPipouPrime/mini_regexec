#include "miniregex.h"
#include <iostream>
#include <vector>

#define RED   "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[33m"
#define RESET "\033[0m"

int main() {

    std::vector<std::string> text;

    text.push_back("0.235\0");
    text.push_back("-0.235\0");
    text.push_back("-0.23513423423\0");
    text.push_back("-0.\0");
    text.push_back("-0.\0");



    text.push_back("-.\0");
    text.push_back(".\0");
    text.push_back("-0..\0");
    text.push_back("235\0");
    text.push_back("--.235\0");
    text.push_back("-1.235\0");
    for (std::vector<std::string>::iterator t = text.begin(); t != text.end(); ++t) {


        if (mini_regex((*t).c_str(), "[0.X]\0")) {
            std::cout << GREEN << "OK " << RESET;
            std::cout << BLUE << *t << RESET << std::endl;
        } else {
            std::cout << RED << "KO " << RESET;
            std::cout << BLUE << *t << RESET << std::endl;
        }
        // std::cout << "\t" << *t;

    // std::cout << std::endl;
    }


    return 1;
}
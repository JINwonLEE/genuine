#include <iostream>
#include <string>

int main() {
    std::string tmp;
    while(std::getline(std::cin, tmp)) {
        std::cout << tmp << std::endl;
    }
    
    return 0;
}

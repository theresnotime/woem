#include <iostream>
#include <cstdarg>
#include <string>
#include <fstream>
#include <memory>
#include <cstdio>
#include <algorithm>

std::string exec(const char* cmd) {
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while (!feof(pipe.get())) {
        if (fgets(buffer, 128, pipe.get()) != NULL)
            result += buffer;
    }
    return result;
}


int main(int argc, char const *argv[]) {
    if (argc < 2) {
        std::cout << "You can't woem nothing mate\n";
        return 1;
    }
    std::string cmd = "cat ";
    cmd += argv[1];
    std::string str = exec(cmd.c_str());
    std::ofstream output;

    reverse(str.begin(), str.end()); 
	std::cout << "\n" << str << "\n"; 
    return 0;
}
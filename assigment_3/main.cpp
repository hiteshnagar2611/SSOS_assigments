#include <iostream>
#include <fstream>
#include <string>
#include <map>

// Function to build the symbol table
std::map<std::string, int> buildSymbolTable(const std::string& fileName) {
    // Define a symbol table (label to address mapping
    std::map<std::string, int> symbolTable;
    std::ifstream inputFile(fileName);
    std::string line;
    int currentAddress = 0;

    // Read the file line by line
    while (std::getline(inputFile, line)) {
        // Trim leading and trailing spaces
        line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);
        line.erase(0, line.find_first_not_of(" \t\n\r\f\v"));

        // Skip empty lines and comments
        if (line.empty() || line.find("//") == 0) {
            continue;
        }

        // Split the line into parts
        size_t colonPos = line.find(':');
        if (colonPos != std::string::npos) {
            // Line defines a label (user-defined symbol)
            std::string label = line.substr(0, colonPos);
            symbolTable[label] = currentAddress;
        }

        // Increment the current address
        currentAddress++;
    }

    return symbolTable;
}
// Function to convert an assembly instruction to object code.
int main() {
    // Define the opcode table (you can extend this with more opcodes).
    std::string fileName = "file.txt"; // Replace with your assembly code file
    std::map<std::string, int> symbolTable = buildSymbolTable(fileName);
    // Print the symbol table
    std::cout << "Symbol Table:" << std::endl;
    for (const auto& entry : symbolTable) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }

    return 0;
}

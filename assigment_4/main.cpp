
// Converting to object code 
// WAP to convert an assembly program to object code using an opcode table and symbol table. 

#include <iostream>
#include <string>
#include <map>

using namespace std;

// Define the opcode table (you can extend this with more opcodes).
map<string, string> opcodeTable = {
    {"ADD", "0000"},
    {"SUB", "0001"},
    {"LD", "0010"},
    // Add more opcodes here
};

// Define a symbol table (label to address mapping).
map<string, int> symbolTable = {
    {"LOOP", 1000},
    {"DATA", 2000},
    // Add more symbols here
};

// Function to convert an assembly instruction to object code.
string assembleInstruction(string instruction) {
    string opcode, operand;
    int spaceIndex = instruction.find(" ");

    if (spaceIndex != string::npos) {
        opcode = instruction.substr(0, spaceIndex);
        operand = instruction.substr(spaceIndex + 1);
    } else {
        opcode = instruction;
    }

    // Look up the opcode in the opcode table.
    if (opcodeTable.find(opcode) != opcodeTable.end()) {
        string opcodeBinary = opcodeTable[opcode];

        // Check if operand is a label and resolve it.
        if (symbolTable.find(operand) != symbolTable.end()) {
            int address = symbolTable[operand];
            // Convert the address to binary and append it to the opcode.
            // Note: You may need to adjust the binary format based on your architecture.
            return opcodeBinary + to_string(address);
        } else {
            // Handle instructions without operands.
            return opcodeBinary + "0000";
        }
    } else {
        // Handle unrecognized opcodes.
        return "Invalid Opcode";
    }
}

int main() {
    string assemblyCode[] = {
        "ADD DATA",
        "SUB LOOP",
        "LD VALUE",
        // Add more assembly instructions here
    };

    for (const string &instruction : assemblyCode) {
        string objectCode = assembleInstruction(instruction);
        cout << instruction << " => " << objectCode << endl;
    }

    return 0;
}




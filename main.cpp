#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>

/*
Hello World Program: ++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.+++.
*/

std::string Solve(std::string input)
{
    const int cellsize = 1000;
    long cell[cellsize] = {0};
    int ptr = cellsize / 2;
    const char* program = input.c_str();
    long program_size = input.length();

    std::string output = "";
    
    for (long i = 0; i < program_size; i++)
    {
        switch (program[i])
        {
        case '>':
            ptr++;
            break;
        case '<':
            ptr--;
            break;
        case '+':
            cell[ptr]++;
            break;
        case '-':
            cell[ptr]--;
            break;
        case '.':
            output += (char)cell[ptr];
            break;
        case '[':
            if(!cell[ptr]) while(program[++i] != ']') {}
            break;
        case ']':
            if(cell[ptr]) while(program[--i] != '[') {}
            break;
        default:
            break;
        }
    }
    return output;
}

void PrintHelp()
{
    std::cout << "Brainfuck Interpreter:\nbrnfck <string>\nbrnfck -f <file>\nbrnfck -h" << std::endl;
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        PrintHelp();
        return 0;
    }
    if(!strcmp(argv[1], "-h"))
    {
        PrintHelp();
        return 0;
    }
    if(!strcmp(argv[1], "-f") && argc > 2)
    {
        std::ifstream file(argv[2]);
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::cout << Solve(buffer.str()) << std::endl;
        file.close();
    }
    else
    {
        std::cout << Solve(argv[1]) << std::endl;
    }
    return 0;
}
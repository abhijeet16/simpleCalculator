// Including a header file which includes every library
#include <bits/stdc++.h>
using namespace std;

// Data structure
struct command {
    string register1;
    string operand;
    string register2;
    
    command() {}
    command(const vector<string>& cmd)
        : register1(cmd[0])
        , operand(cmd[1])
        , register2(cmd[2])
    {
    }
};

int main(int argc, char* argv[])
{

    bool check_input_f = false;
    ifstream input_f; // input file stream
    istream* input_s; // handle input stream

    if (argc == 1) { // No file path, Take inputs from command line
        input_s = &cin;
    }
    else if (argc == 2) { // Command with exe and file path
        input_f.open(argv[1]);
        if (!input_f) {
            cerr << "Oopss!!! Input file not found" << endl;
            return 1;
        }
        input_s = &input_f;
        check_input_f = true;
    }
    else { // invalid command
        cerr << "Invalid command! More than two arguments found!" << endl;
        return 1;
    }
}
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


// Two condition to check from input
// 1. If input has any integer
bool check_int_input(const string& s)
{
    if (!isdigit(s[0]))
        return false;
    for (auto& ch : s.substr(1, s.size() - 1))
        if (!isdigit(ch))
            return false;
    return true;
}

// 2. If the register variable is alphanumeric or not
bool check_alnum(const string& s)
{ 
    for (auto& ch : s)
        if (!isalnum(ch))
            return false;
    return true;
}

// A function to split the command received into words
vector<string> split_vector(string s)
{
    vector<string> input_v;
    stringstream inp_ss(s);
    string inp_s;
    while (inp_ss >> inp_s) {
        input_v.push_back(inp_s);
    }
    return input_v;
}

// We check all the three commands possible.
bool check_command(const vector<string>& input_v)
{
    // If we have just one argument, it should be "quit" or "QUIT"
    if (input_v.size() == 1) {
        if (input_v[0] == "QUIT" || input_v[0] == "quit")
            return true;
        cerr << "Invalid command!" << endl;
        return false;
    }

    // If we have two arguments, it should print <register>
    if (input_v.size() == 2) {
        if (input_v[0] != "print") {
            cerr << "Invalid command!" << endl;
            return false;
        }
        if (!check_alnum(input_v[1])) {
            cerr << "Invalid register name! Only alphanumeric register name allowed" << endl;
            return false;
        }
        if (check_int_input(input_v[1])) {
            cerr << "Invalid register name! Only digits in register name is not allowed" << endl;
            return false;
        }
        return true;
    }

    // If we have three arguments, it should 
    if (input_v.size() == 3) {
        string reg1 = input_v[0];
        string op = input_v[1];
        string reg2 = input_v[2];

        // Check the operand spelling and case insensitiveness
        if (op != "add" && op != "subtract" && op != "multiply" && op != "ADD" && op != "SUBTRACT" && op != "MULTIPLY") {
            cerr << "Invalid command!" << endl;
            return false;
        }
        if (!check_alnum(reg1)) {
            cerr << "Invalid register name! Only alphanumeric register name allowed" << endl;
            return false;
        }
        if (check_int_input(reg1)) {
            cerr << "Invalid register name! Only digits in register name is not allowed" << endl;
            return false;
        }
        if (!check_alnum(reg2)) {
            if (!check_int_input(reg2)) {
                cerr << "Invalid register name!" << endl;
                return false;
            }
            else {
                cerr << "Invalid value entered." << endl;
                return false;
            }
        }
        return true;
    }
    cerr << "Invalid command!" << endl;
    return false;
}

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

    string input_l;
    vector<command> all_cmd; // Collect all command
    set<string> registers;

    // Handle each line of input
    while (getline(*input_s, input_l)) {
        vector<string> input_v = split_vector(input_l);

        if (!check_command(input_v))
            continue;

        if (input_v.size() == 1) {
            return 0;
        }
        if (input_v.size() == 2) {
            string reg = input_v[1];

            if (!registers.count(reg)) {
                cerr << "Register not found!" << endl;
            }
        }
        if (input_v.size() == 3) {
            string reg1 = input_v[0];
            string reg2 = input_v[2];
            registers.insert(reg1);
            registers.insert(reg2);

            all_cmd.push_back(command(input_v)); // push a valid command
        }
    }

    if (check_input_f)
        input_f.close(); // close the file opened

    return 0;

}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
// Create file

struct file {
public:
    string filename;
    string path;
};


bool isLetter(char x)
{
    return (x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z');
}


void CreateFile() {
    file file;
    string temp;
    cout << "Enter path for file ( 0 for default ): \n";
    cin >> temp;
    if (temp != "0") {
        file.path = temp;
        cout << "Enter filename:\n";
        cin >> file.filename;
        ofstream TFile(file.path + "/" + file.filename);
        TFile.close();
        cout << file.path + "/" + file.filename << "created";
    }
    else {
        cout << "Enter filename: ";
        cin >> file.filename;
        ofstream TFile(file.filename);
        TFile.close();
        cout << "File created.\n";
    }
}

void WriteFile() {
    string Temp;
    cout << "Enter full path to file: \n";
    getline(cin, Temp);
    ofstream TFile(Temp);
    cout << "Please enter string: ";
    getline(cin, Temp);
    TFile << Temp;
    TFile.close();
    cout << "\nFile written.\n";
}

void ReadFile() {
    string Temp;
    cout << "Enter full path to file: ";
    cin >> Temp;
    ifstream TFile(Temp);
    string line;
    Temp = "";
    while (getline(TFile, line)) {
        cout << line;
        cout << "\n";
        Temp += line;
    }
    TFile.close();

    int counter_str = 1;
    int counter_chars = 0;
    int counter_words = 1;


    for (const char c : Temp) {
        if (c == ' ') counter_words++;
        if (isLetter(c)) counter_chars++;
        if (c == '\n') counter_str++;
    }

    cout << "\n\n Stats:\n\n words in file: " << counter_words << "\n letters in file: " << counter_chars << "\nstrokes in file: " << counter_str << "\n";
}

void Console() {
    char command[30];
    while (command != "exit") {
        cin >> command;
        system(command);
    }
}


void Help() {
    cout << "cf - create file\nrf - read file\nwf - write file\ncmd - enter cmd\nexit - exit from application.\n";

}

void PowerHack() {
    vector <string> arr;
    string input = "";
    while (input != "0") {
        cout << "Enter command for execute with console\nWhen you ready, type 0.\nType --help to view commands.\n";
        getline(cin, input);
        if (input == "--help") {
            system("help");
            continue;
        }
        if (input == "0") break;
        else {
            arr.push_back(input);
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        const char* cstr = arr[i].c_str();
        system(cstr);
    }

}



int main()
{
    cout << "print --help to see tips\n";
    while (true) {
        string userCommand;
        getline(cin, userCommand);

        if (userCommand == "--help") {
            Help();
            continue;
        }

        if (userCommand == "cf") {
            CreateFile();
            continue;
        }

        if (userCommand == "rf") {
            ReadFile();
            continue;
        }

        if (userCommand == "wf") {
            WriteFile();
            continue;
        }

        if (userCommand == "cmd") {
            Console();
            continue;
        }

        if (userCommand == "exit") {
            break;
        }

        if (userCommand == "ph") {
            PowerHack();
        }

    }

}

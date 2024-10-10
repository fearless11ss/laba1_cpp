#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

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
    ofstream f1;
    f1.open("log.txt", ios::app);
    if (f1.is_open() == true) 
    {
        time_t timestamp;
        time(&timestamp);
        f1 << ctime(&timestamp) << "\t";
        f1 << "Программа запущена" << endl << endl;
    }
    else 
    {
        cout << "Не удалось открыть файл" << endl;
    }
    cout << "print --help to see tips\n";
    while (true) {
        string userCommand;
        getline(cin, userCommand);

        if (userCommand == "--help") {
            time_t timestamp;
            time(&timestamp);
            f1 << ctime(&timestamp) << "\t";
            f1 << "Вызвана команда --help" << endl << endl;
            Help();
            continue;
        }

        if (userCommand == "cf") {
            time_t timestamp;
            time(&timestamp);
            f1 << ctime(&timestamp) << "\t";
            f1 << "Создан новый файл" << endl << endl;
            CreateFile();
            continue;
        }

        if (userCommand == "rf") {
            time_t timestamp;
            time(&timestamp);
            f1 << ctime(&timestamp) << "\t";
            f1 << "Произошло чтение файла" << endl << endl;
            ReadFile();
            continue;
        }

        if (userCommand == "wf") {
            time_t timestamp;
            time(&timestamp);
            f1 << ctime(&timestamp) << "\t";
            f1 << "Произведена запись в файл" << endl << endl;
            WriteFile();
            continue;
        }

        if (userCommand == "cmd") {
            time_t timestamp;
            time(&timestamp);
            f1 << ctime(&timestamp) << "\t";
            f1 << "Вызвана консоль" << endl << endl;
            Console();
            continue;
        }

        if (userCommand == "exit") {
            time_t timestamp;
            time(&timestamp);
            f1 << ctime(&timestamp) << "\t";
            f1 << "Программа завершила свою работу" << endl << endl;
            break;
        }

        if (userCommand == "ph") {
            time_t timestamp;
            time(&timestamp);
            f1 << ctime(&timestamp) << "\t";
            f1 << "Вызван PowerShell" << endl << endl;
            PowerHack();
        }

    }
    f1.close();

}

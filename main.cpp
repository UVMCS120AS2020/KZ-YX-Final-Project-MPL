#include <fstream>
#include <iostream>
using namespace std;

string getUserChoice(string prompt);
bool writeToFile(string filename, string message);
void clearFile(string filename);

int main() {
    cout << "Welcome to Vermont COVID-19 database" << endl;
    string filename = "answers.txt";
    if (writeToFile(filename, getUserChoice("Which chart do you want to see? "
                                                             "Type 'a' for Cumulative Vermont COVID-19 Cases, "
                                                             "Type 'b' for New Vermont COVID-19 Cases: ")) &&
        writeToFile(filename, getUserChoice("Which period do you want to see? The range is 3.06 to 4.07. "
                                                             "Type the start date like 3.06: ")) &&
        writeToFile(filename, getUserChoice("And type the end date like 4.07: "))) {
        cout << "Your answers have been recorded! Let's compute some magic." << endl;
        system("python3 letterHistogram.py");
    } else {
        cout << "Oops, something went wrong!" << endl;
    }
    
    clearFile(filename);

    return 0;
}

string getUserChoice(string prompt) {
    cout << prompt;
    string answer;
    getline(cin, answer);
    return answer;
}

bool writeToFile(string filename, string message) {
    ofstream outFile(filename, ios::app);
    if (outFile) {
        outFile << message << endl;
        outFile.close();
        return true;
    }
    outFile.close();
    return false;
}

void clearFile(string filename) {
    ofstream outFile(filename);
    outFile.close();
}

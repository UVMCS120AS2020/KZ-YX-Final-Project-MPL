#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

string getUserChoiceOne(string promptOne);
string getUserChoiceTwo(string promptTwo);
string getUserChoiceThree(string promptThree);
bool checkForNumber(string answer);
bool writeToFile(string filename, string message);
void clearFile(string filename);

string secondAnswer = "";

int main() {
    cout << "Here are Vermont COVID-19 Cases" << endl;
    string filename = "answers.txt";
    if (writeToFile(filename, getUserChoiceOne("Which chart do you want to see? "
                                                                   "Type 'a' for Cumulative Vermont COVID-19 Cases, "
                                                                   "Type 'b' for New Vermont COVID-19 Cases: ")) &&
        writeToFile(filename, getUserChoiceTwo("Which period do you want to see? The range is 3.06 to 4.07. "
                                                                   "Type the start date like 3.06: ")) &&
        writeToFile(filename, getUserChoiceThree("And type the end date like 4.07: "))) {
        cout << "Your answers have been recorded. Here is the chart." << endl;
        system("python3 letterHistogram.py");
    } else {
        cout << "Oops, something went wrong!" << endl;
    }
    
    clearFile(filename);

    return 0;
}

string getUserChoiceOne(string promptOne) {
    cout << promptOne;
    string answerOne;
    getline(cin, answerOne);
    for (auto &c : answerOne) {
        c = tolower(c);
    }
    if (answerOne != "a" && answerOne != "b") {
        answerOne = "error";
    }
    return answerOne;
}

string getUserChoiceTwo(string promptTwo) {
    cout << promptTwo;
    string answerTwo;
    getline(cin, answerTwo);
    if (checkForNumber(answerTwo)) {
        double date = stod(answerTwo);
        if (date < 3.06 || (date > 3.31 && date < 4.01) || date > 4.07) {
            answerTwo = "error";
        } else {
            answerTwo = to_string(date);
            answerTwo = answerTwo.substr(0, answerTwo.length() - 4);
        }
    } else {
        answerTwo = "error";
    }
    secondAnswer = answerTwo;
    return answerTwo;
}

string getUserChoiceThree(string promptThree) {
    cout << promptThree;
    string answerThree;
    getline(cin, answerThree);
    if (checkForNumber(answerThree)) {
        double date = stod(answerThree);
        double answerTwo = stod(secondAnswer);
        if (date < 3.06 || (date > 3.31 && date < 4.01) || date > 4.07 || answerTwo > date) {
            answerThree = "error";
        } else {
            answerThree = to_string(date);
            answerThree = answerThree.substr(0, answerThree.length() - 4);
        }
    } else {
        answerThree = "error";
    }
    return answerThree;
}

bool checkForNumber(string answer) {
    int count = 0;
    for (auto &c : answer) {
        if (isdigit(c) || c == '.') {
            if (c == '.') {
                count += 1;
            }
        }
        if (isalpha(c)) {
            count += 1;
        }
    }
    return count == 1 && answer != "." && answer.length() == 4;
}

bool writeToFile(string filename, string message) {
    ofstream outFile(filename, ios::app);
    if (outFile && message != "error") {
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

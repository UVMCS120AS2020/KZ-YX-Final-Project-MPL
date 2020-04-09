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

// Global variable for second user choice to compare the dates
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
        system("python3 COVID19Chart.py");
    } else {
        cout << "Error occurred!" << endl;
    }
    
    clearFile(filename);

    return 0;
}

string getUserChoiceOne(string promptOne) {
    cout << promptOne;
    string answerOne;
    getline(cin, answerOne);
    // The first answer should be 'a' or 'b', case insensitive.
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
    // The second answer should be a double between 3.06 and 3.31 or 4.01 and 4.07
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
    // Store the answer in the global variable
    secondAnswer = answerTwo;
    return answerTwo;
}

string getUserChoiceThree(string promptThree) {
    cout << promptThree;
    string answerThree;
    getline(cin, answerThree);
    // The third answer should be a double between 3.06 and 3.31 or 4.01 and 4.07
    if (checkForNumber(answerThree)) {
        double date = stod(answerThree);
        // Get the second answer from global variable
        double answerTwo = stod(secondAnswer);
        // Besides the date range, the third answer should be equal to or greater than the second answer
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

// Function to check if the input is a two-decimal double
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

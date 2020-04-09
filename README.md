# KZ-YX-Final-Project-MPL
This project is to show the number of COVID-19 cases in Vermont between 3.06 and 4.07 as bar chart. <br>
Two charts are available, one is the every day number of total cases, another is the every day number of new cases.

*All data came from Vermont Department of Health: 
https://www.healthvermont.gov/response/coronavirus-covid-19/current-activity-vermont

## Team members
Ken Zhang & Yuhuan Xiang

## Direction
To run this program, please follow the steps below. 
* Open the terminal on your computer.
* Change the directory to the program path by using `cd`.
* Compile the cpp file `g++ -std=c++1y main.cpp`.
* Run the program `./a.out`.
* The program will ask three question.
* First, Which chart do you want to see? Type 'a' for Cumulative Vermont COVID-19 Cases, 
  or type 'b' for New Vermont COVID-19 Cases. Case insensitive.
* Then, Which period do you want to see? The range is 3.06 to 4.07. Type the start date like 3.06. 
  Any other type of answer would return error message.
* Next, type the end date like start date. It should be equal to or greater than the start date.
* The program will create a chart you chose. 
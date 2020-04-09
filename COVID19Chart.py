# import matplotlib to graph the data
import matplotlib.pyplot as plt

# open the txt file and make the user's choices as a list
choice = []
with open('answers.txt') as file:
    for line in file:
        line = line.replace('\n', '').split(",")
        choice.append(line[0])
choice1 = choice[0]
choice2 = choice[1]
choice3 = choice[2]
# input date
date = ["3.06","3.07","3.08","3.09","3.10","3.11","3.12","3.13","3.14","3.15","3.16","3.17","3.18","3.19","3.20","3.21","3.22","3.23","3.24","3.25","3.26","3.27","3.28","3.29","3.30","3.31","4.01","4.02","4.03","4.04","4.05","4.06","4.07"]

# xAxis -> date yAxis -> data
xAxis = []
for i in range(len(date)):
    xAxis.append(date[i].replace('.', '/'))
yAxis1 = [0,1,1,1,1,2,2,5,8,12,17,19,21,28,44,52,76,97,125,160,185,213,237,258,295,322,361,390,460,512,543,575,605]
yAxis2 = [0,1,0,0,0,1,0,3,3,4,5,2,2,7,16,8,24,21,28,35,25,28,24,21,37,27,39,29,70,52,31,32,30]

# Use matplotlib to graph the data
plt.figure(figsize=(10,5))
ax = plt.subplot(111)
plt.yticks(fontsize=10)
plt.xticks(fontsize=6)
plt.gcf().canvas.set_window_title('Vermont COVID-19 Cases')
plt.xlabel('Date')

# draw the bar graph according to user's choice
if (choice1 =='a'):
    plt.title('Cumulative Vermont COVID-19 Cases')
    plt.ylabel('Number of total people infected')
    ax.bar(xAxis[date.index(choice2):date.index(choice3)+1], yAxis1[date.index(choice2):date.index(choice3)+1])
    # Get range of y values to make sure y axis is labeled with integers
    yint = range(min(yAxis1[date.index(choice2):date.index(choice3)+1]), max(yAxis1[date.index(choice2):date.index(choice3)+1])+1)
    for x, y in zip(xAxis[date.index(choice2):date.index(choice3)+1], yAxis1[date.index(choice2):date.index(choice3)+1]):
        plt.text(x, y + 0.3, '%.0f' % y, ha='center', va='bottom', fontsize=10.5)
else:
    plt.title('New Vermont COVID-19 Cases')
    plt.ylabel('Number of new people infected')
    ax.bar(xAxis[date.index(choice2):date.index(choice3)+1], yAxis2[date.index(choice2):date.index(choice3)+1])
    yint = range(min(yAxis2[date.index(choice2):date.index(choice3)+1]), max(yAxis2[date.index(choice2):date.index(choice3)+1])+1)
    for x, y in zip(xAxis[date.index(choice2):date.index(choice3)+1], yAxis2[date.index(choice2):date.index(choice3)+1]):
        plt.text(x, y + 0.3, '%.0f' % y, ha='center', va='bottom', fontsize=10.5)

# Display the graph in a new window
plt.show()

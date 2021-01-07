
/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/12/19
** Description: Creates a linked list and presents the user with
** several options for interaction
*********************************************************************/
#include <string>
#include <iostream>
#include <fstream>
#include "menuShell.hpp"
#include "LinkedList.hpp"

void printFwd(LinkedList &list);
void loadFromFile(LinkedList &list, std::string fileName);

int main() {
	const int numOptions = 11;
	std::string chooseOptions[numOptions];
	chooseOptions[0] = "\nChoose from the following options";
	chooseOptions[1] = "1. Add a new node to the head";
	chooseOptions[2] = "2. Add a new node to the tail";
	chooseOptions[3] = "3. Delete from head";
	chooseOptions[4] = "4. Delete from tail";
	chooseOptions[5] = "5. Traverse the list reversely";
	chooseOptions[6] = "6. EC1** Print the value at head";
	chooseOptions[7] = "7. EC1** Print the value at tail";
	chooseOptions[8] = "8. EC2** Load List from default file";
	chooseOptions[9] = "9. EC2** Load List from custom .txt file";
	chooseOptions[10] = "10. Exit";

	LinkedList list;

	int choice = 0;
	while (choice != numOptions-1) {
		choice = choiceMenuMulti(chooseOptions, numOptions);
		switch (choice) {
			case 1:
				list.addToHead(chooseIntInRange("Enter an integer between 1 and 100000", 1, 100000));
				printFwd(list);
				break;
			case 2:
				list.addToTail(chooseIntInRange("Enter an integer between 1 and 100000", 1, 100000));
				printFwd(list);
				break;
			case 3:
				list.removeFromHead();
				printFwd(list);
				break;
			case 4:
				list.removeFromTail();
				printFwd(list);
				break;
			case 5:
				std::cout << "Your reverse linked list is: ";
				list.displayRevList();
				std::cout << "\n";
				break;
			case 6:
				std::cout << "The head of the list is: ";
				list.displayHead();
				std::cout << "\n";
				printFwd(list);
				break;
			case 7:
				std::cout << "The tail of the list is: ";
				list.displayTail();
				std::cout << "\n";
				break;
			case 8:
				loadFromFile(list, "numberFile.txt");
				printFwd(list);
				break;
			case 9:
				loadFromFile(list, enterTxtFileWithinRange("Please enter your text file name: ", 1, 31));
				printFwd(list);
				break;
			case 10: 
				std::cout << "Exiting program" << std::endl;
				break;
			default:
				std::cout << "Error in choosing options" << std::endl;
				break;
		}
	}
	return 0;
}


/*********************************************************************
** Description: prints the linked list
*********************************************************************/
void printFwd(LinkedList &list) {
	std::cout << "Your linked list is: ";
	list.displayFwdList();
	std::cout << "\n";
}

/*********************************************************************
** Description: adds to the current linked list, prints the values
** being added while doing so
*********************************************************************/
void loadFromFile(LinkedList &list, std::string fileName) {
	int number;
	std::ifstream numberFile(fileName);
	if (!numberFile) {
		std::cout << "Error opening the file of numbers.";
		exit(1);
	}

	std::cout << "\nThe contents of the file are: ";
	while (numberFile >> number) {
		std::cout << number << "   ";
		list.addToTail(number);
	}
	std::cout << "\n";
	numberFile.close();
}

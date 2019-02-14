//Lainey Schrag

#include "Executive.h"
#include "Gamer.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

//Name: Executive (std::string args)
//Pre-Condition: Takes in file name from the command line
//Post-Condition: Sets the command line arguments to a string
//Return: None 
Executive::Executive(std::string args)
{
	filename = args;
	std::string temp_rows = " ";
	int rank = 0;
	std::string name = "";
	int year = 0;
	double rating = 0.0;
	double av_rating = 0.0;
	int voters = 0; 

	//tries to open a file with the name that matches what was entered on the commandline
	std::string dataFile = filename; 
	std::ifstream inFile;
	inFile.open(dataFile);

	if(!inFile.good()) //checks to make sure file name exists 
	{
		std::cout << "\nSorry! No file matches the name you entered.";
		return; //ends method since no valid file name
	}

	inFile >> rows; //reads the number of rows entered at the top of the file
	myGamer = new Gamer[rows]; //creates array of Gamer objects

	//various variables used to parse through the text file
	 char comma = ',';
	 int name_size = 0;

	//for loop to read through different variables in txt file
	 for (int i = 0; i < rows; i++)
	   {
	 	inFile >> rank; //reads in the rank
	 	inFile >> comma; //looks for comma to seperate next value
	  
	 	std::getline(inFile, name, comma);//reads in next chunk of text before next comma
	 	name_size = name.size();
		std::string year_final;
		//pulls out the year that is within the name string
		year_final[3] = name[name_size-2];
	 	year_final[2] = name[name_size-3]; 
	 	year_final[1] = name[name_size-4]; 
	 	year_final[0] = name[name_size-5];  

	 	year = std::stoi(year_final); //converts the year string into an int

	 	name.erase(name.size() - 6); //erases the year from the name string

		inFile >> rating; //reads in the rating
		inFile >> comma; //looks for comma to seperate the next value
	 	inFile >> av_rating; //reads in the average rating
		inFile >> comma; //looks for comma to seperate the next value
	 	inFile >> voters; //reads in the number of voters

	 	//sets the variables to new variables within the Gamer object 
		myGamer[i].set_rank(rank);
		myGamer[i].set_name(name);
		myGamer[i].set_year(year);
	 	myGamer[i].set_rating(rating);
		myGamer[i].set_av_rating(av_rating);
		myGamer[i].set_voters(voters);
	 }

	inFile.close(); //closes file 
}

//Name: ~Executive
//Pre-Condition: 
//Post-Condition: Deallocates memory 
//Return: None 
Executive::~Executive()
{
	delete [] myGamer; //deletes array of gamers
}

//Name: run()
//Pre-Condition: 
//Post-Condition: Handles user interaction
//Return: None 
void Executive::run()
{
	char quit = 'n'; //quit char is used to make sure program doesn't after one time

	while (quit == 'n') //loop while continue as long as user wants
	{
		std::string choice = "0";
		//below prints out user menu
		std::cout<<"\n\nWelcome to your boardgame database!";
		std::cout<<"\nPlease select an option:\n";
		std::cout<<"\n1) Print all games from rank 1 to 100";
		std::cout<<"\n2) Print all games with a minimum amount of ratings";
		std::cout<<"\n3) Print all games from a specific year";
		std::cout<<"\n4) Print game with largest gap between geek rating and average rating";
		std::cout<<"\n5) Quit";

		std::cout<<"\n\nEnter your choice here:";
		std::cin>>choice;
		if (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5") //checks for valid choice
		{
			if (choice == "1")
			{
				for (int i = 0; i < rows; i++) //prints every game in order of text file
				{
					std::cout << "\n\n" << myGamer[i].get_rank() << ") ";
					std::cout << myGamer[i].get_name();
					std::cout << "\n\tGeek Rating: " << myGamer[i].get_rating();
					std::cout << "\n\tAverage Rating: " << myGamer[i].get_av_rating();
					std::cout << "\n\tNum Ratings: " << myGamer[i].get_voters();
					std::cout << "\n\tYear: " << myGamer[i].get_year();
				}

			}
			if (choice == "2") //prints every game that has a minimum number of rating 
			{
				int minimum = 0;
				std::cout<< "\nWhat is the minimum for number of ratings of games that you would like to see?";
				std::cout<< "\nMinimum: ";
				std::cin >> minimum; 
				if(std::cin.fail()) //makes sure user input is valid
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout<<"\n\nSorry! Your input was invalid.";
				}
				else
				{
					for (int i = 0; i < rows; i++) //loops through every gamer object 
					{
						if (myGamer[i].get_voters() >= minimum) //displays game if the minimum value is greater or equal to number of voters
						{
							std::cout << "\n\n" << myGamer[i].get_rank() << ") ";
							std::cout << myGamer[i].get_name();
							std::cout << "\n\tGeek Rating: " << myGamer[i].get_rating();
							std::cout << "\n\tAverage Rating: " << myGamer[i].get_av_rating();
							std::cout << "\n\tNum Ratings: " << myGamer[i].get_voters();
							std::cout << "\n\tYear: " << myGamer[i].get_year();
						}
					}
				}
			}
			if (choice == "3") //prints all games from a specific year
			{
				int chosen_year = 0;
				std::cout<< "\nWhat year's board games would you like to be see?";
				std::cout<< "\nYear: ";
				std::cin >> chosen_year; 
				if(std::cin.fail()) //checks for valid user input
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout<<"\n\nSorry! Your input was invalid.";
				}
				else
				{
					for (int i = 0; i < rows; i++) //loops through every gamer object
					{
						if (myGamer[i].get_year() == chosen_year) //displays game if year matches the year entered by user
						{
							std::cout << "\n\n" << myGamer[i].get_rank() << ") ";
							std::cout << myGamer[i].get_name();
							std::cout << "\n\tGeek Rating: " << myGamer[i].get_rating();
							std::cout << "\n\tAverage Rating: " << myGamer[i].get_av_rating();
							std::cout << "\n\tNum Ratings: " << myGamer[i].get_voters();
							std::cout << "\n\tYear: " << myGamer[i].get_year();
						}
					}

				}
			}
			if (choice == "4") //prints game with the largest gap between average rating and geek rating
			{
				double biggest_gap = 0.0;
				double test_gap = 0.0;
				int gap_number = 0;
				for (int i = 0; i < rows; i++) //loops through every gamer object
				{
					if (myGamer[i].get_rating() > myGamer[i].get_av_rating()) //checks to make sure difference is always positive
					{
						test_gap = myGamer[i].get_rating() - myGamer[i].get_av_rating(); //sets temporary double as difference between ratings
					}
					else //same test as above except average rating is the larger value
					{
						test_gap = myGamer[i].get_av_rating() - myGamer[i].get_rating();
					}
					if (test_gap >= biggest_gap) //compares temporary value to previous largest value
					{
						biggest_gap = test_gap; //sets the new largest value as temporary value
						gap_number = i; //stores the number object 
					}
				}

				//below displays the gamer object with the largest gap
				std::cout << "\n\n" << myGamer[gap_number].get_rank() << ") ";
				std::cout << myGamer[gap_number].get_name();
				std::cout << "\n\tGeek Rating: " << myGamer[gap_number].get_rating();
				std::cout << "\n\tAverage Rating: " << myGamer[gap_number].get_av_rating();
				std::cout << "\n\tNum Ratings: " << myGamer[gap_number].get_voters();
				std::cout << "\n\tYear: " << myGamer[gap_number].get_year();
				std::cout << "\n\tRatings Difference: " << biggest_gap;

			}
			if (choice == "5") //ends loop if user wants to leave
			{
				quit = 'y';
			}
		}
		else //displayed if user doesn't choose a valid option
		{
			std::cout<<"\n\nSorry! Not a valid choice.";
		}
	}
}
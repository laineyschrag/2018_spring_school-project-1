//Lainey Schrag

#include "Executive.h"
#include "Gamer.h"
#include <iostream>
#include <string.h>
#include <fstream>

int main(int argc, char* argv[])
{

	if (argc < 2 ) //checks to make sure user entered commandlind argumemt
	{
		std::cout<< "\nPlease enter a valid filename";
	}
	else
	{
		Executive myExec(argv[1]); //creates Executive object and sends commandline argument to Executive()
		myExec.run(); //handles all user interaction
	}

	return(0);
}
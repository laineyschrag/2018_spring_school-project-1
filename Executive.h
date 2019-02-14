//Lainey Schrag

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <iostream>
#include <fstream>
#include <string.h>
#include "Gamer.h"

class Executive
{
	private:
		std::string filename;
		Gamer * myGamer;
		int rows;

	public:
		Executive(std::string args);
		~Executive();
		void run();
};
#endif
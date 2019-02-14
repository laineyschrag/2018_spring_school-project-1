//Lainey Schrag

#include "Gamer.h"
#include "Executive.h"
#include <string.h>

//Name: Gamer()
//Pre-Condition: None
//Post-Condition: Assigns initial values to class variables 
//Return: None
Gamer::Gamer()
{
	m_rank = 0;
	m_name = " ";
	m_year = 0;
	m_rating = 0.0;
	m_av_rating = 0.0;
	m_voters = 0;	
}

//Name: set_rank(int rank)
//Pre-Condition: Takes in rank value passed in from file
//Post-Condition: Sets rank value to class variable
//Return: None
void Gamer::set_rank(int rank)
{
	m_rank = rank;
}

//Name: get_rank()
//Pre-Condition: none
//Post-Condition: returns rank value
//Return: m_rank
int Gamer::get_rank()
{
	return m_rank;
}

//Name: set_name(std::string name)
//Pre-Condition: Takes in name value passed in from file
//Post-Condition: Sets name value to class variable
//Return: None
void Gamer::set_name(std::string name)
{
	m_name = name;
}

//Name: get_name()
//Pre-Condition: none
//Post-Condition: returns name of game
//Return: m_name
std::string Gamer::get_name()
{
	return m_name;
}

//Name: set_year(int year)
//Pre-Condition: Takes in year value passed in from file
//Post-Condition: Sets year value to class variable
//Return: None
void Gamer::set_year(int year)
{
	m_year = year;
}

//Name: get_year()
//Pre-Condition: none
//Post-Condition: returns year value
//Return: m_year
int Gamer::get_year()
{
	return m_year;
}

//Name: set_rating(double rating)
//Pre-Condition: Takes in rating value passed in from file
//Post-Condition: Sets rating value to class variable
//Return: None
void Gamer::set_rating(double rating)
{
	m_rating = rating;
}

//Name: get_rating()
//Pre-Condition: none
//Post-Condition: returns rating value
//Return: m_rating
double Gamer::get_rating()
{
	return m_rating;
}

//Name: set_av_rating(double av_rating)
//Pre-Condition: Takes in av_rating value passed in from file
//Post-Condition: Sets av_rating value to class variable
//Return: None
void Gamer::set_av_rating(double av_rating)
{
	m_av_rating = av_rating;
}

//Name: get_av_rating()
//Pre-Condition: none
//Post-Condition: returns average rating value
//Return: m_av_rating
double Gamer::get_av_rating()
{
	return m_av_rating;
}

//Name: set_voters(int voters)
//Pre-Condition: Takes in voters value passed in from file
//Post-Condition: Sets vpters value to class variable
//Return: None
void Gamer::set_voters(int voters)
{
	m_voters = voters;
}

//Name: get_voters()
//Pre-Condition: none
//Post-Condition: returns number of voters
//Return: m_voters
int Gamer::get_voters()
{
	return m_voters;
}

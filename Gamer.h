//Lainey Schrag

#ifndef GAMER_H
#define GAMER_H
#include <iostream>
#include <fstream>
#include <string.h>

class Gamer
{
	private:
		int m_rank;
		std::string m_name;
		int m_year;
		double m_rating;
		double m_av_rating;
		int m_voters;

	public:
		Gamer();
		void set_rank(int rank);
		int get_rank();
		void set_name(std::string name);
		std::string get_name();
		void set_year(int year);
		int get_year();
		void set_rating(double rating);
		double get_rating();
		void set_av_rating(double av_rating);
		double get_av_rating();
		void set_voters(int voters);
		int get_voters();
};
#endif
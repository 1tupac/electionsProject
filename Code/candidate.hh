#pragma once

#include <string>

using namespace std;


class Candidate
{
	private:
		string _name; // name of candidate
		int _score;	// score of votes for the candidates	

	public:
		Candidate(string name);
		~Candidate();

		string get_name();
		int get_score() const;
		void set_score(int s);

};
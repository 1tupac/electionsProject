#pragma once

#include <string>
#include "buttonElection.hh"
#include "buttonMode.hh"
//class ButtonElection;

class Candidate
{
	private:
		std::string _name; // name of candidate
		mutable int _score;	// score of votes for the candidates	

		// file path for image of button
		std::string _image_button_filePath;


	public:

		ButtonElection _button_candidate;


		Candidate(std::string name);
		~Candidate();

		// getters
		std::string get_name() const;
		int get_score() const;
		ButtonElection get_button_candidate() const;
		std::string get_image_button_filePath() const;

		// setters
		void set_score(int s) const;
		// create for a button to vote for candidat
		void set_button_election( float x, float y) const;
		void set_image_button_filePath(std::string filePath);

		// check if user clicked on a button
		int check_event_click(SDL_Event* e) const;

};
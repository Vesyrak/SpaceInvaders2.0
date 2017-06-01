#include "FileWriter.h"
#include <algorithm>
#include <iostream>

namespace Game_Core {

	FileWriter::FileWriter() {
	}

	FileWriter::~FileWriter() {
	}

	//Gets users of score list. Should only be run after a ReadScore operation so the most recent is returned
	std::vector<std::string> FileWriter::GetUsers() {
		return users;
	}

	//Gets scores of score list. Should only be run after a ReadScore operation so the most recent is returned
	std::vector<int> FileWriter::GetScores() {
		return scores;
	}

	//Writes scores out to the file
	void FileWriter::WriteScore() {
		std::ofstream outfile;
		outfile.open(savefile);
		for (unsigned int i = 0; i < users.size(); i++) {
			outfile << users[i] << std::endl;
			outfile << scores[i] << std::endl;
		}
		outfile.close();
	}

	//Reads scores from file
	void FileWriter::ReadScore() {
		users.clear();
		scores.clear();
		std::string name;
		int score;
		std::ifstream infile;
		infile.open(savefile);
		int lines = std::count(std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>(), '\n');
		if (lines > 10)
			lines = 10;
		infile.clear();
		infile.seekg(0, std::ios::beg);
		for (int i = 0; i < lines / 2; i++) {
			infile >> name;
			users.push_back(name);
			infile >> score;
			scores.push_back(score);
		}
		infile.close();

	}

	//Updates scores with a new entry
	void FileWriter::UpdateScore(std::string name, int score) {
		ReadScore();
		std::vector<std::string>::iterator userIt = users.begin();
		std::vector<int>::iterator scoreIt = scores.begin();
		bool added = false;
		while (scoreIt != scores.end()) {
			if ((*scoreIt) < score) {
				users.insert(userIt, name);
				scores.insert(scoreIt, score);
				added = true;
				break;
			}
			userIt++;
			scoreIt++;
		}
		if (!added && scores.size() < 10) {
			users.push_back(name);
			scores.push_back(score);
		}
		WriteScore();
	}
}

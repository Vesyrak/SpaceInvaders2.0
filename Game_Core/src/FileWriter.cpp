#include "FileWriter.h"
#include <algorithm>
#include <iostream>
namespace Game_Core {
FileWriter::FileWriter() {

}
FileWriter::~FileWriter() {

}
std::vector<std::string> FileWriter::getUsers()
{
	return users;
}
std::vector<int> FileWriter::getScores()
{
	return scores;
}
void FileWriter::writeScore() {
	std::ofstream outfile;
	outfile.open(savefile);
	std::cout << "yo" << std::endl;
	for (unsigned int i = 0; i < users.size(); i++) {
		outfile << users[i] << std::endl;
		outfile << scores[i] << std::endl;
		std::cout << users[i] << std::endl;
		std::cout << scores[i] << std::endl;

	}
	outfile.close();
}
void FileWriter::readScore() {
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
	std::cout << "----" << std::endl;
	for (int i = 0; i < lines / 2; i++) {
		infile >> name;
		users.push_back(name);
		infile >> score;
		scores.push_back(score);
		std::cout << scores[i] << std::endl;
		std::cout << scores[i] << std::endl;
	}
	infile.close();

}
void FileWriter::updateScore(std::string name, int score) {
	readScore();
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
	writeScore();
}
}

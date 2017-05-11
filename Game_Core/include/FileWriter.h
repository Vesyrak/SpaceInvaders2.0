#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <fstream>
#include <iostream>
#include <vector>
namespace Game_Core {
class FileWriter {

	public:
		FileWriter();
		~FileWriter();
		void readScore();
		void updateScore(std::string name, int score);
	private:
		void writeScore();
		const std::string savefile = "score.dat";
		std::vector<std::string> users;
		std::vector<int> scores;
};
}
#endif

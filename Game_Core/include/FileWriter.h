#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <fstream>
#include <iostream>
#include <vector>

namespace Game_Core {

	// IO implementation for reading and writing the score file.
	class FileWriter {
		public:
			FileWriter();
			~FileWriter();
			void ReadScore();
			void UpdateScore(std::string name, int score);
			std::vector<std::string> GetUsers();
			std::vector<int> GetScores();
		private:
			void WriteScore();
			const std::string savefile = "score.dat";
			std::vector<std::string> users;
			std::vector<int> scores;
	};
}
#endif

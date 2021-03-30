#include <string>
#include <vector>
#include "Direction.hpp"


namespace ariel {
	class Board{
        private:
            uint rows, cols;
            std::vector<std::vector<char>> board;
            uint longestLine;

        public:
            Board() {}
            ~Board () {}
            void post(uint row, uint col, Direction direction,const std::string& message);
            std::string read(uint row, uint col, Direction direction, uint length);
            void show();
    };
};

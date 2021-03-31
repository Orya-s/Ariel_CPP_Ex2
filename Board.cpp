#include "Board.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

namespace ariel
{
    string const message;
    void Board::post(uint row, uint col, Direction direction, const string &message)
    {   
        // adding more vectors aka lines
        if (board.size() <= row + message.size())
        {
            int vecNum = 0;
            uint size = message.size() + 1;
            if(direction == Direction::Horizontal){
                vecNum = (int)(row - board.size() + 1);
            } else {
                vecNum = (int)(row - board.size() + message.size() + 1);
            }

            while (vecNum > 0){
                vector<char> v(size);
                fill(v.begin(), v.end(), '_');
                board.push_back(v);
                vecNum--;
            }
        }

        // if didn't need more lines but the line isn't long enough
        if (board.at(row).size() <= col + message.size())
        {
            for (uint i = board.at(row).size(); i <= col + message.size() +1; i++)
            {
                board.at(row).push_back('_');
            }
        }
        
        // if the message is vertical - make sure all lines of the message are long enough 
        if (direction == Direction::Vertical){
            for (uint i = row; i < row+message.size()+1; i++)
            {
                for (uint j = board.at(i).size(); j <= col + message.size() +1; j++)
                {
                    board.at(i).push_back('_');
                }   
            } 
        }

        // posting the message
        ulong index = 0;
        if (direction == Direction::Horizontal)
        {
            for (uint j = col; j < col+message.size(); j++)
            {
                board.at(row).at(j) = message.at(index++);
            }
        }
        else{
            for (uint i = row; i < row+message.size(); i++)
            {
                board.at(i).at(col) = message.at(index++);
            }
        }
    }


    std::string Board::read(uint row, uint col, Direction direction, uint length)
    {
        string ans;
   
        // if the reading location is beyond the board's current size
        if (board.size() <= row)
        {
            for (int i = 0; i < length; i++)
            {
                ans += "_";
            }
            return ans;
        }
        if (board.at(row).size() <= col)
        {
            for (int i = 0; i < length; i++)
            {
                ans += "_";
            }
            return ans;
        }
        
        // reading the line
        if (direction == Direction::Horizontal)
        {
            for (uint j = col; j < col+length && j < board.at(row).size(); j++)
            {
                ans += board.at(row).at(j);
            }
        }
        else{
            for (uint i = row; i < row+length && i < board.size(); i++)
            {
                ans += board.at(i).at(col);
            }
        }

        // if part of the reading is beyond the board's current size
        while (ans.size() < length)
        {
            ans += '_';
        }
        
        return ans;
    }


    void Board::show()
    {
        for(uint i = 0; i < board.size(); i++)
        {
            for(uint j = 0; j < board.at(i).size(); j++)
            {
                cout << board.at(i).at(j) << " ";
            }
            cout << endl;
        }
    }
}
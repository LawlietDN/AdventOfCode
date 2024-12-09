#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>    
#include "puzzleInput.h"

int main()
{
    std::vector<int> leftList;
    std::vector<int> rightList;

    for (size_t i = 0; i < puzzleInput.size(); i++)
    {
        if (i % 2 == 0)
        {
            leftList.push_back(puzzleInput[i]);
        } else
        {
            rightList.push_back(puzzleInput[i]);
        }
    }

    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    int totalDistance = 0;
    for (size_t i = 0; i < leftList.size(); i++)
    {
        totalDistance += std::abs(leftList[i] - rightList[i]);
    }

    std::cout << "Total distance: " << totalDistance << std::endl;

    return 0;
}

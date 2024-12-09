#include <iostream>
#include <vector>
#include "puzzleInput.h"
#include <unordered_map>

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
    std::unordered_map<int, int> rightCounts;

    for(int num : rightList)
    {
    rightCounts[num]++;
    }

    int similarityScore = 0;
    for(int num : leftList)
    {
        similarityScore += num * rightCounts[num];
    }

    std::cout << "Similarity Score: " << similarityScore << std::endl;

    return 0;
}

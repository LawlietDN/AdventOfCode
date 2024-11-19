#include <iostream>
#include <climits>
#include <vector>

const std::vector<char> availOperators = {'+'};
const int MAX_TRIES = 4;

void basicAddition(double x, double y, char operatorType);
char operatorChoice();
void getUserInput(double &x, double &y);
void results(double x, double y, double z, char operatorType);
void sayInvalid(int maxTries);
bool maxTriesChecker(int maxTries);

int main() 
{
    int maxTries = 0;
    double x = 0, y = 0;

    while (true) 
    {
        char operatorType = operatorChoice();
        for(auto i: availOperators)
        {
            if(operatorType == i)
            {
                 getUserInput(x, y);
                continue;
            }
        }
        

        switch (operatorType) 
        {
            case '+':
                basicAddition(x, y, operatorType);
                break;

            default:
                if (maxTriesChecker(maxTries))
                 {
                    std::cout << "\n\nToo many invalid inputs. Try again later.";
                    return 1;
                }
                maxTries++;
                sayInvalid(maxTries);
        }
    }
    return 0;
}


void results(double x, double y, double z, char operatorType) 
{
    std::cout << std::endl << x << " " << operatorType << " " << y << " = " << z << std::endl << std::endl;
}

void getUserInput(double &x, double &y) 
{
    while (true) 
    {
        std::cout << "Enter X value: ";
        std::cin >> x;
        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid input. Enter a number.\n";
            continue;
        }

        std::cout << "Enter Y value: ";
        std::cin >> y;
        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid input. Enter a number.\n";
            continue;
        }
        break;
    }
}

char operatorChoice()
{
    char userInput;
    std::cout << "Available operators: ";
    for(auto i: availOperators)
    {
        std::cout << i << " ";
    }
    std::cout << "\nChoose an arithmetic operator: ";
    std::cin >> userInput;
    return userInput;
}

void basicAddition(double x, double y, char operatorType) 
{
    results(x, y, x + y, operatorType);
}


void sayInvalid(int maxTries) 
{
    if (maxTries < MAX_TRIES) 
    {
        std::cout << "\nInvalid operator. Try again.\n";
    }
}

bool maxTriesChecker(int maxTries) 
{
    return maxTries >= MAX_TRIES;
}

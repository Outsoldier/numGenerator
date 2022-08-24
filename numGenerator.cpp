// numGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <time.h>
#include <limits>// to not close imeditely 

using namespace std;

int main()
{
    ofstream myFile("output.txt"); // creates a file


    int num = 0;
    int min = 0; // minimum number of thingy
    int max = 0; // maximum of random numbers
    int * nums = new int[9999999];
    int common;// most common number generated
    int least = 0; // least number generated
    int guess; // number that user guessed
    bool found = false; // bool to see if guess was found
    int count = 0; // count how many times it was found
    int L = 0;
    int* line = new int[L]; // store the lines where the guess was found
    char close; // to close app

    myFile << "How many times do you want to randomize? \n";
    std::cout << "How many times do you want to randomize? \n";
    myFile << num;
    std::cin >> num;

    myFile << "What do you want the minimum number to be? \n";
    std::cout << "What do you want the minimum number to be? \n";
    myFile << num;
    std::cin >> min;

    myFile << "Whats the max number you want to randomize? \n";
    std::cout << "Whats the max number you want to randomize? \n";
    myFile << max;
    std::cin >> max;
    
    common = max;

    myFile << "Try to guess a number that will be produced \n";
    std::cout << "Try to guess a number that will be produced \n";
    std::cin >> guess;

    for (int i = 1; i <= num; i++)
    {
        nums[i] = (min + rand() % (max - min));
        std::cout << "Number: " << nums[i] << " Line: " << i << "\n";

        if (nums[i] == guess)
        {
            found = true;
            count = count + 1;
            L++;
            line[L] = i;
        }

        if (nums[i] > common)
        {
            common = nums[i];
        }

        if (nums[i] < least)
        {
            least = nums[i];
        }

    }

    if (found == true)
    {
        std::cout << "Your number: " << guess << " was found " << count << " times on lines: \n";
    }
    else if (found == false)
    {
        std::cout << "\nYour number " << guess << " was not found";
    }

    for (int o = 1; o <= count; o++)
    {
        std::cout << line[o] << "\n";
    }

    do
    {
        std::cout << "Press any LETTER and then enter to continue... ";
        std::cin >> close;
    } while (close == false);
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
// 
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

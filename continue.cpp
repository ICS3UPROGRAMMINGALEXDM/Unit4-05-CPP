// Copyright (c) 2022 Alex De Meo All rights reserved
//
// Created By: Alex De Meo
// Date: 04s//22
// Description: Get an amount of numbers from user, then asks for a number
// until that max is met, then display the equation and sum
#include <stdlib.h>
#include <iostream>
#include <cstdlib>


using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::stof;




int main() {
    // Where the user input is recieved
    string maxNum;
    cout << "Enter the amount of numbers you would like to add together: ";
    cin >> maxNum;
    try {
        // converting to float so that we can later check if it is whole or not
        float maxFlt = stof(maxNum);
        if (maxFlt <= 0) {
            cout <<
            "Maximum amount must be a positive number. Requirements not met.";
        } else {
            // Checks if the floated number is the same as the
            // number would be as int. If it is the same, it means it is a
            // whole number. But if they are not
            // equal it means it is a decimal and
            // will throw the exception message
            if (maxFlt == static_cast<int>(maxFlt)) {
                // resetting everything
                int counter = 0, nSum = 0;
                string equation = "";
                // Where all the addition happens
                while (counter < maxFlt) {
                    string uNum = "";
                    cout << "Enter a number to be added: ";
                    cin >> uNum;
                    try {
                        float numFlt = stof(uNum);
                        // doing the same thing as described in lines 33-37
                        if (numFlt != static_cast<int>(numFlt) || numFlt <= 0) {
                            cout <<
                            "Please ensure that the" <<
                            " number is positive and whole"
                            << endl;
                            continue;
                        }
                        // update sum
                        nSum += numFlt;
                        // update counter
                        counter += 1;

                        // deciding how to concatenate string
                        if (counter < maxFlt) {
                            equation += uNum + " + ";
                        } else {
                            equation += uNum + " = ";
                        }
                    } catch (...) {
                        cout <<
                        "Please a whole and positive number is entered" <<
                        endl;
                    }
                }
                cout << equation << nSum;
            } else {
                cout << "Must be a whole number. Requirements not met.";
            }
        }
    } catch (...) {
        cout <<
        "Maximum amount must be a whole and" <<
        " positive NUMBER. Requirements not met.";
    }
}

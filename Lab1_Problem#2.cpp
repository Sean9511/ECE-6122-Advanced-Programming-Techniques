/*
Author: Shancong Mou
Class: ECE6122
Last Date Modified: 09/12/2020
Description:
This if for Hw1 Problem 2
 */

#include <iostream>
#include <fstream>
#include <string>
int main(int argc, const char * argv[]) {
    std::ofstream ofs;
    int input = std::stoi(argv[1]);
//    int input = 13;
    int sum = input; // intialize sumation
    do {
        if (input % 2 == 0){
            input = input / 2;
        }
        else{
            input = 3 * input + 1;
        }
        sum = sum + input;
    }
    while (input != 1);
    std::cout << sum;
    ofs.open ("output2.txt");
    ofs << sum;
    ofs.close();
    return 0;
}

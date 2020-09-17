/*
Author: Shancong Mou
Class: ECE6122
Last Date Modified: 09/12/22020
Description:
This si for La1 problem1
*/

#include <iostream>
#include <fstream>
#include <string>

bool IsPrime (unsigned long Inum)
{
    bool flag = 1;
    if (Inum==0 || Inum==1){
        flag = 0;
    }
    else{
        for(int i=2; i<=Inum/2; ++i){
            if (Inum % i ==0){
                flag =0;
            }
        }
    }
    return flag;

}


int main(int argc, const char * argv[]) {
    std::ofstream ofs;
    
    int l = stoi(argv[1]);
//    int l =10;
    int sum = 0;
    for (int i=0; i <= l; i++){
        if (IsPrime(i) == 1){
            sum =sum + i;
        }
    }
    std::cout << sum;
    ofs.open ("output1.txt");
    ofs << sum;
    ofs.close();
    return 0;
}



#include <iostream>
#include <random>
#include <stdio.h>
// Last Worked on: 19:35 2025/03/28
// What does it do: asks you for what diffuculty to play it
// Making it shorter via functions
int anscheck(int r, int g) {
    if (g < 1 || g> 100) {
        return 2;
    } else {
        if (r == g) {
            return 0;
        }
        else if (r < g) {
            return -1;
        }
        else if (r > g) {
            return 1;
        }
    }
}


int main() {
    int c=true;
    std::cout << "Hello Player i hope you have a great time playing this number guesing game\n";
    std::cout << "I m gone chose a number from 1-100 \nhave fun guessing it\n\n";
    while (c==true) {
        int dif;
        std::cout << "Chose your difficoulty:\n\n";
        std::cout << "1. Easy: 10 gueses\n";
        std::cout << "2. Medium:5 guesses\n";
        std::cout << "3. Hard: 3 geusses\n";
        std::cout << "waht difficulty will it be: ";
        std::cin >> dif;
        std::mt19937 mt{ std::random_device{}() };
        std::uniform_int_distribution<> rng{ 1,100 };
        int ran = rng(mt);
        if (dif <= 3 && dif >= 1) {
            int tf=0;
            int gues;
            switch (dif) {
            case 1:
                for (int i = 0; i < 10;) {
                    std::cout << "\nThis is your" << i + 1 << " guess";
                    std::cout << "\ntake a guess what number might be? ";
                    std::cin >> gues;
                    if (anscheck(ran, gues) == 0) {
                        std::cout << "\nYour guess was right the number was " << ran << std::endl;
                        i = 10;
                    }
                    else if (anscheck(ran, gues) == 1) {
                        std::cout << "\nYou guessed the wrong number, the number was bigger then your guess of " << gues << std::endl;
                        i++;
                    }
                    else if (anscheck(ran, gues) == -1) {
                        std::cout << "\nYou guesed the wrong number, the number was smaller then your guess of " << gues << std::endl;
                        i++;
                    }
                    else if (anscheck(ran, gues) == 2) {
                        std::cout << "\nPlease enter a number from 1-100 next time\n";
                    }
                }
                if (tf == 1) {
                }
                else {
                    std::cout << "The number was " << ran;
                }
                break;
            case 2:
                for (int i = 0; i < 5;) {
                    std::cout << "\nThis is your" << i + 1 << " guess";
                    std::cout << "\ntake a guess what number might be? ";
                    std::cin >> gues;
                    if (anscheck(ran, gues) == 0) {
                        std::cout << "\nYour guess was right the number was " << ran << std::endl;
                        i = 5;
                    }
                    else if (anscheck(ran, gues) == 1) {
                        std::cout << "\nYou guessed the wrong number, the number was bigger then your guess of " << gues << std::endl;
                        i++;
                    }
                    else if (anscheck(ran, gues) == -1) {
                        std::cout << "\nYou guessed the wrong number, the number was smaller then your guess of " << gues << std::endl;
                        i++;
                    }
                    else if (anscheck(ran, gues) == 2) {
                        std::cout << "\nPlease enter a number from 1-100 next time\n";
                    }
                }
                if (tf == 1) {
                }
                else {
                    std::cout << "The number was " << ran;
                }
                break;
            case 3:
                for (int i = 0; i < 3;) {
                    std::cout << "\nThis is your" << i + 1 << " guess";
                    std::cout << "\ntake a guess what number might be? ";
                    std::cin >> gues;
                    if (anscheck(ran, gues) == 0) {
                        std::cout << "\nYour guess was right the number was " << ran << std::endl;
                        i = 3;
                        tf = 1;
                    }
                    else if (anscheck(ran, gues) == 1) {
                        std::cout << "\nYou guessed the wrong number, the number was bigger then your guess of " << gues << std::endl;
                        i++;
                    }
                    else if (anscheck(ran, gues) == -1) {
                        std::cout << "\nYou guessed the wrong number, the number was smaller then your guess of " << gues << std::endl;
                        i++;
                    }
                    else if (anscheck(ran, gues) == 2) {
                        std::cout << "\nPlease enter a number from 1-100 next time\n";
                    }
                }
                if (tf == 1) {
                } else {
                    std::cout << "The number was " << ran;
                }
                break;
            }
        }
        else {
            std::cout << "Please enter a valid number\n";
        }
        int a;
        std::cout << "\nwould you like to continue Playing \n1. Yes \n2. No \nChose wisly:";
        std::cin >> a;
        if (a == 1){
            std::cout << "\n Have fun in your next round\n";
            c = true;
        } else if ( a == 2){
            std::cout << "\nGoodbey";
            c = false;
        }
        else{
            std::cout << "\nyou entered an invalid number so the game just ended!";
            c = false;
        }
    }
}
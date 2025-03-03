#include <iostream>
#include <vector>
extern char grid[11][23];
#pragma once

class Tail {
public:
    int tailQuant = 0;
    char tail = 'o';
    std::vector<int> tailX;
    std::vector<int> tailY;
    std::vector<int> prevtailX;
    std::vector<int> prevtailY;

    Tail() {
        // Baþlangýçta vektörler boþ olabilir, baþlangýç boyutu belirlemeye gerek yok
    }

    void addTail() {
        tailQuant++;
        tailX.push_back(0); // Yeni eleman eklerken baþlangýç deðeri 0 olarak ayarlayabilirsiniz
        tailY.push_back(0);
        prevtailX.push_back(0);
        prevtailY.push_back(0);
    }

    void moveTail(int x, int y) {
        /*
            With this function, our tail follows the head.
            1- first loop holds the previous coordinates.
            2- Second loop moves the tail to previous coordinate
            3- third loop cleanse the symbol on the previous coordinate
            4- fourth loop draws the symbol on the new coordinates
        */

        if (tailQuant > 0) {
            for (int i = 0; i < tailQuant; i++) {
                prevtailX[i] = tailX[i];
                prevtailY[i] = tailY[i];
            }

            for (int i = tailQuant-1; i > 0; i--) {
                tailX[i] = tailX[i - 1];
                tailY[i] = tailY[i - 1];
            }

            tailX[0] = x;
            tailY[0] = y;

            for (int i = 0; i < tailQuant; i++) {
                grid[prevtailY[i]][prevtailX[i]] = ' ';
            }

            for (int i = 0; i < tailQuant; i++) {
                grid[tailY[i]][tailX[i]] = tail;
            }
        }
    }

    bool checkTail(Player& player) {
        for (int i = 0; i < tailQuant; i++) {
            if (tailX[i] == player.playerX && tailY[i] == player.playerY) {
                return true;
            }
        }
        return false;
    }
};
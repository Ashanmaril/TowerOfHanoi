//
//  hanoi.cpp
//  Hanoi
//
//  Created by Hayden Lueck on 2015-10-15.
//  Copyright © 2015 Hayden Lueck. All rights reserved.
//

#include "hanoi.h"
#include <iostream>

Disk::Disk(int s)
{
    if(s >= 0 && s <= MAX_SIZE)
        size = s;
    else
        size = 0;
}

Peg::Peg()
{
    //nUser = 0;
    height = 0;
    Disk temp(0);
    
    
    for(int i = 0; i < MAX_SIZE; i++)
    {
        stack[i] = temp;
    }
}

Peg::Peg(int n)
{
    if(n > 0 && n <= MAX_SIZE)
    {
        nUser = n;
        height = n;
        Disk temp(0);
    
        for(int i = 0; i < MAX_SIZE; i++)
        {
            stack[i] = temp;
        }

    
        for(int i = 1; i <= n; i++)
        {
            Disk temp(i);
            stack[n - i] = temp;
        }
    }
    else
    {
        std::cout << "Error: invalid size" << std::endl;
        Peg();
    }
}

void Peg::printPeg() const
{
    //std::cout << "This peg has " << height << " disks on it" << std::endl;
    
    /* each loop prints out 1 disk in the stack */
    for(int i = height; i > 0; i--)
    {
        /* print out amount of x's on each disk based on its size */
        for(int j = 0; j < stack[i-1].getSize(); j++)
        {
            std::cout << 'x';
        }
        
        /* print out spaces to make each stack printout a block*/
        for(int j = 0; j < nUser - stack[i-1].getSize(); j++)
        {
            std::cout << ' ';
        }
        std::cout << "  end";
        
        std::cout << std::endl;
    }
}

void Peg::add(const Disk & d)
{
    height++;
    stack[height-1] = d;
}

void Peg::remove(Disk & d)
{
    d = stack[height - 1]; //set given disk to the top disk in the stack.
    height--; //decrement height
}

Hanoi::Hanoi()
{
    while(true)
    {
        std::cout << "Input n: ";
        std::cin >> size;
        if(std::cin && size >= 0 && size <= MAX_SIZE)
            break;
        
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    
    A = *new Peg(size);
    B = *new Peg;
    C = *new Peg;
    
    std::cout << "Peg A: " << std::endl;
    A.printPeg();
    std::cout << "Peg B: " << std::endl;
    B.printPeg();
    std::cout << "Peg C: " << std::endl;
    C.printPeg();
    
    hanoi(size, A, C, B);
    
    std::cout << "Peg A: " << std::endl;
    A.printPeg();
    std::cout << "Peg B: " << std::endl;
    B.printPeg();
    std::cout << "Peg C: " << std::endl;
    C.printPeg();
    
}

void Hanoi::hanoi(int n, Peg& p1, Peg& p3, Peg& p2)
{
    if(n > 0)
    {
        hanoi(n-1, p1, p2, p3);
        
        Disk temp;
        p1.remove(temp);
        p3.add(temp);
        
        hanoi(n-1, p2, p3, p1);
    }
}

void Hanoi::printHanoi() const
{
    printTowers(size, A, B, C);
}

void printTowers(const int& n, const Peg& p1, const Peg& p2, const Peg& p3)
{
    /* each loop prints out 1 disk in the stack */
    for(int i = nUser; i > 0; i--)
    {
        /* print out amount of x's on each disk based on its size */
        for(int j = 0; j < p1.stack[i-1].getSize(); j++)
        {
            std::cout << 'x';
        }
        
        /* print out spaces to make each stack printout a block*/
        for(int j = 0; j < nUser - p1.stack[i-1].getSize(); j++)
        {
            std::cout << ' ';
        }
        std::cout << "  end";
        
    }
}



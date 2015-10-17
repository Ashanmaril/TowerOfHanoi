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
        size = s; //set size to s if it's between 1 and the maximum allowed
    else
        size = 0; //otherwise, set the size to 0
}

Peg::Peg()
{
    height = 0; //0 disks on the peg
    
    for(int i = 0; i < MAX_SIZE; i++)
    {
        stack[i] = *new Disk; //set all pegs in stack to size 0 (empty stack)
    }
}

Peg::Peg(int n)
{
    if(n > 0 && n <= MAX_SIZE) //if valid number n was given
    {
        nUser = n; //set the global integer for storing n to given number
        height = n; //set height to n
    
        for(int i = 0; i < MAX_SIZE; i++)
        {
            stack[i] = *new Disk; //initialize all items in stack to disks with size 0
        }

		/* create stack from bottom up, starting at n and decreasing to 1 */
        for(int i = 1; i <= n; i++)
        {
            stack[n - i] = *new Disk(i); //set current item in stack to new disk with size i (current loop iteration)
        }
    }
    else
    {
        std::cout << "Error: invalid size" << std::endl; //if invalid size was given, print out error
        Peg(); //call default constructor
    }
}

/* printing function for testing only */
void Peg::printPeg() const
{
    std::cout << "This peg has " << height << " disks on it" << std::endl;
    
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
	if (height + 1 <= MAX_SIZE)
	{
		height++; //increment heigh
		stack[height - 1] = d; //set next item in stack to given Disk
	}
	else
		std::cout << "Error: no more room on stack" << std::endl;
}

void Peg::remove(Disk & d)
{
	if (height == 0)
		std::cout << "Error: no items on peg to remove" << std::endl;
	else
	{
		d = stack[height - 1]; //set given disk to the top disk in the stack.
		stack[height - 1] = *new Disk; //set "removed" disk to new disk with size 0
		height--; //decrement height
	}
}

Hanoi::Hanoi()
{
    while(true) //loop, asking for input until valid input is given
    {
        std::cout << "Input n (between 1 and " << MAX_SIZE << "): ";
        std::cin >> size;
        if(std::cin && size > 0 && size <= MAX_SIZE)
            break;
        
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    
	/* initialize pegs */
    A = *new Peg(size);
    B = *new Peg;
    C = *new Peg;
    
}

void Hanoi::begin()
{
    printHanoi(); //print out initial state
    hanoi(size, A, C, B); //begin solving
}

/* MAIN ALGORITHM */
void Hanoi::hanoi(int n, Peg& p1, Peg& p3, Peg& p2)
/*
	You're best off Googling how this thing works. There's a million
	explanations for it online, but basically it repeats 3 basic moves:
		1 - Move the top n-1 disks from peg 1 to peg 2, using peg 3
		2 - Move disk n (the bottom disk) to peg 3
		3 - Move the top n-1 disks from peg 2 to peg 3 using peg 1
*/
{
    if(n > 0) //base case: n is 0
    {
        hanoi(n-1, p1, p2, p3);
        
		/* make a move */
        Disk temp;
        p1.remove(temp);
        p3.add(temp);
        
        printHanoi();
        
        hanoi(n-1, p2, p3, p1);
    }
}

void Hanoi::printHanoi() const
{
    printTowers(size, A, B, C); //pass pegs into printTowers functions
}

void printTowers(const int& n, const Peg& p1, const Peg& p2, const Peg& p3)
/*
	Formatted to print out all 3 pegs, with proper formatting
	Will probably only work with monospace font. Joys of ASCII output.

	The variable, nUser is stored as a global variable that doesn't change once
	initialized, basically solely for this function.
	Once nUser is declared, you can imagine each stack printout to be a
	square matrix with dimensions: nUser x nUser
	
	[ ][ ][ ]
	[ ][ ][ ]
	[ ][ ][ ]

	Any items in the matrix that aren't stored as an 'x', meaing there's a disk
	taking up space, will be replaced with a space (' ') so the formatting doesn't
	break (horizontal printing in ASCII is annoying)
*/
{
	/* loop through for each row up to n */
    for(int i = nUser; i > 0; i--)
    {
        /* peg 1 */
        for(int j = 0; j < p1.stack[i - 1].getSize(); j++)
            std::cout << 'x'; //print out amount of x's equal to current disk's size
        for(int j = 0; j < nUser - p1.stack[i - 1].getSize(); j++)
            std::cout << ' '; //print out spaces for proper formatting
        std::cout << ' ';
        
        
        /* peg 2 */
        for(int j = 0; j < p2.stack[i - 1].getSize(); j++)
            std::cout << 'x';
        for(int j = 0; j < nUser - p2.stack[i - 1].getSize(); j++)
            std::cout << ' ';
        std::cout << ' ';
        
        /* peg 3 */
        for(int j = 0; j < p3.stack[i - 1].getSize(); j++)
            std::cout << 'x';
        for(int j = 0; j < nUser - p3.stack[i - 1].getSize(); j++)
            std::cout << ' ';
        
        std::cout << std::endl;
    }
    
    std::cout << std::endl;

}



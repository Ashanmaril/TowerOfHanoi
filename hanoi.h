//
//  hanoi.h
//  Hanoi
//
//  Created by Hayden Lueck on 2015-10-15.
//  Copyright © 2015 Hayden Lueck. All rights reserved.
//

#ifndef hanoi_h
#define hanoi_h

static const int MAX_SIZE = 15; //global constant for maximum size
static int nUser; //

class Disk {
private:
    int size; //stores the size of the disk
public:
    Disk(){size = 0;} //default constructor
    Disk(int s); //constructor with size given
    int getSize() const {return size;}
    
};

class Peg {
private:
    int height; //tracks the height of the stack at any given time
    Disk stack[MAX_SIZE]; //keeps track of disks, and given sizes
    //int nUser; //tracks original height
    
public:
    Peg(); //default constructor, makes empty peg
    Peg(int); //constructor with N given, creates stack from bottom up starting at n
    void remove(Disk&); //removes a disk, passes it into Disk argument
    void add(const Disk&); //adds a disk from given disk parameter
    void printPeg() const; //prints out a peg, used for testing
    
    friend void printTowers(const int&, const Peg&, const Peg&, const Peg&); //friend function for printing out 3 towers
};

class Hanoi {
private:
    Peg A, B, C; //3 towers for use in simulation
    int size; //size
public:
    Hanoi(); //constructor
    void begin(); //function called to begin solving
    void hanoi(int, Peg&, Peg&, Peg&); //recursive function, stores main algorithm
    void printHanoi() const; //prints out all 3 pegs
};

#endif /* hanoi_h */

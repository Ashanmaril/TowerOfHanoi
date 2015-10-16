//
//  hanoi.h
//  Hanoi
//
//  Created by Hayden Lueck on 2015-10-15.
//  Copyright © 2015 Hayden Lueck. All rights reserved.
//

#ifndef hanoi_h
#define hanoi_h

static const int MAX_SIZE = 10;
static int nUser;

class Disk {
private:
    int size;
public:
    Disk(){size = 0;}
    Disk(int s);
    int getSize() const {return size;}
    
};

class Peg {
private:
    int height; //tracks the height of the stack at any given time
    Disk stack[MAX_SIZE]; //keeps track of disks, and given sizes
    //int nUser; //tracks original height
    
public:
    Peg();
    Peg(int);
    void remove(Disk&);
    void add(const Disk&);
    void printPeg() const;
    
    friend void printTowers(const int&, const Peg&, const Peg&, const Peg&) ;
};

class Hanoi {
private:
    Peg A, B, C;
    int size;
public:
    Hanoi();
    void hanoi(int, Peg&, Peg&, Peg&);
    void printHanoi() const;
};

#endif /* hanoi_h */

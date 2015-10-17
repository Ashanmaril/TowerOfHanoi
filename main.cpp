//
//  main.cpp
//  Hanoi
//
//  Created by Hayden Lueck on 2015-10-15.
//  Copyright © 2015 Hayden Lueck. All rights reserved.
//

#include <iostream>
#include "hanoi.h"

int main() {
    
    Hanoi h;
    
    std::cout << "Hanoi:" << std::endl;
    
    h.printHanoi();
    
    return 0;
}

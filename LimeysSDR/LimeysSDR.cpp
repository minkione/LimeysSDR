//
//  LimeysSDR.cpp
//  LimeysSDR
//
//  Created by Paul Ciarlo on 8/3/18.
//  Copyright © 2018 Paul Ciarlo. All rights reserved.
//

#include <iostream>
#include "LimeysSDR.hpp"
#include "LimeysSDRPriv.hpp"

void LimeysSDR::HelloWorld(const char * s)
{
    LimeysSDRPriv *theObj = new LimeysSDRPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void LimeysSDRPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};


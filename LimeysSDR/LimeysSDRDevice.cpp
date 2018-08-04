//
//  LimeysSDRDevice.cpp
//  LimeysSDR
//
//  Created by Paul Ciarlo on 8/3/18.
//  Copyright © 2018 Paul Ciarlo. All rights reserved.
//

#include "LimeysSDRDevice.hpp"

namespace io {
namespace github {
namespace paulyc {
    
    LimeysSDRDevice::LimeysSDRDevice() :
        Loggable("io::github::paulyc::LimeysSDRDevice"),
        _dev(SoapySDR::Device::make())
    //,_caps(caps)
    {
        //_dev.sw(SoapySDR::Device::make());
    }
    
}
}
}

//
//  LimeysSDRDevice.hpp
//  LimeysSDR
//
//  Created by Paul Ciarlo on 8/3/18.
//  Copyright © 2018 Paul Ciarlo. All rights reserved.
//

#ifndef LimeysSDRDevice_hpp
#define LimeysSDRDevice_hpp

#include "Loggable.hpp"

#include <SoapySDR/Device.hpp>

namespace io {
namespace github {
namespace paulyc {
    
    class LimeSDRMiniDeviceCaps;
    
    class LimeysSDRDevice : public Loggable
    {
    public:
        LimeysSDRDevice();
        virtual ~LimeysSDRDevice() {}
    private:
        std::shared_ptr<LimeSDRMiniDeviceCaps> _caps;
        std::unique_ptr<SoapySDR::Device> _dev;
    };
    
}
}
}

#endif /* LimeysSDRDevice_hpp */

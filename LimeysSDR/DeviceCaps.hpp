//
//  DeviceCaps.hpp
//  LimeysSDR
//
//  Created by Paul Ciarlo on 8/3/18.
//  Copyright © 2018 Paul Ciarlo. All rights reserved.
//

#ifndef DeviceCaps_hpp
#define DeviceCaps_hpp

#include <SoapySDR/Device.hpp>

#include <string>
#include <vector>
#include <memory>

#include "Loggable.hpp"

namespace io {
namespace github {
namespace paulyc {
    
    template <typename Prop_T>
    class SelectableDeviceProp
    {
    public:
        virtual void Enumerate() = 0;
        virtual Prop_T GetValue() = 0;
        virtual void SetValue(Prop_T value) = 0;
        virtual std::vector<Prop_T> GetOptions() = 0;
    };
    
    class SelectableAntenna : public SelectableDeviceProp<std::string>
    {
    public:
        virtual void Enumerate() {}
        virtual std::string GetValue() { return ""; }
        virtual void SetValue(std::string value) {}
        virtual std::vector<std::string> GetOptions() { return std::vector<std::string>(); }
    };
    
    class SelectableGain : public SelectableDeviceProp<int>
    {
    public:
        virtual void Enumerate() {}
        virtual int GetValue() { return -1; }
        virtual void SetValue(int value) {}
        virtual std::vector<int> GetOptions() { return std::vector<int>(); }
    };
    
    class SoapySDRDeviceCaps;
    
    class SoapySDRDeviceList : public std::vector<std::shared_ptr<SoapySDRDeviceCaps>>
    {
    public:
        SoapySDRDeviceList(SoapySDR::KwargsList &l);
        virtual ~SoapySDRDeviceList() {}
        static std::shared_ptr<SoapySDRDeviceList> get();
    };
    
    class LimeysSDRDevice;

class SoapySDRDeviceCaps : public Loggable
{
public:
    SoapySDRDeviceCaps(const SoapySDR::Kwargs &args);
    virtual ~SoapySDRDeviceCaps() {}
    
    virtual void EnumerateCaps() = 0;
    virtual std::shared_ptr<LimeysSDRDevice> InstantiateDevice();
    
protected:
    
private:
    SoapySDR::Kwargs _args;
};
    
    class LimeSDRMiniDeviceCaps : public SoapySDRDeviceCaps
    {
    public:
        LimeSDRMiniDeviceCaps(const SoapySDR::Kwargs &args) : SoapySDRDeviceCaps(args) {}
        virtual ~LimeSDRMiniDeviceCaps() {}
        
        void EnumerateCaps();
    protected:
        SelectableAntenna antenna;
        SelectableGain lnaGain;
        SelectableGain tnaGain;
        SelectableGain pgaGain;
    };
    
}
}
}

#endif /* DeviceCaps_hpp */

//
//  DeviceCaps.cpp
//  LimeysSDR
//
//  Created by Paul Ciarlo on 8/3/18.
//  Copyright © 2018 Paul Ciarlo. All rights reserved.
//

#include <SoapySDR/Device.hpp>
#include "LimeysSDRDevice.hpp"
#include "DeviceCaps.hpp"

namespace io {
namespace github {
namespace paulyc {

SoapySDRDeviceCaps::SoapySDRDeviceCaps(const SoapySDR::Kwargs &args) :
    Loggable("io::github::paulyc::DeviceCaps"),
    _args(args)
{
    SetCurrentLogLevel(Debug);
    LogStream(Debug) << args << "\n";
}
    
    SoapySDRDeviceList::SoapySDRDeviceList(SoapySDR::KwargsList &l) {
        for (const SoapySDR::Kwargs &kv : l) {
            std::shared_ptr<LimeSDRMiniDeviceCaps> caps = std::make_shared<LimeSDRMiniDeviceCaps>(kv);
            caps->EnumerateCaps();
            push_back(caps);
        }
    }

    std::shared_ptr<LimeysSDRDevice> SoapySDRDeviceCaps::InstantiateDevice()
    {
        return std::make_shared<LimeysSDRDevice>();
    }
    
    void LimeSDRMiniDeviceCaps::EnumerateCaps()
    {
        antenna.Enumerate();
        
        /*
         Device *dev = Device::make(deviceList[0]);
         
         cout << "getHardwareInfo: " << dev->getHardwareInfo() << endl;
         cout << "getFrontendMapping: " << dev->getFrontendMapping(SOAPY_SDR_RX) << endl;
         cout << "getNumChannels: " << dev->getNumChannels(SOAPY_SDR_RX) << endl;
         cout << "getChannelInfo: " << dev->getChannelInfo(SOAPY_SDR_RX, 0) << endl;
         cout << "getStreamFormats: " << dev->getStreamFormats(SOAPY_SDR_RX, 0) << endl;
         double fullScale;
         string nativeFormat = dev->getNativeStreamFormat(SOAPY_SDR_RX, 0, fullScale);
         cout << "getNativeStreamFormat: " << nativeFormat << " fullScale: " << fullScale << endl;
         cout << "getStreamArgsInfo: " << dev->getStreamArgsInfo(SOAPY_SDR_RX, 0) << endl;
         
         cout << "listAntennas: " << dev->listAntennas(SOAPY_SDR_RX, 0) << endl;
         cout << "hasIQBalance: " << dev->hasIQBalance(SOAPY_SDR_RX, 0) << endl;
         cout << "hasFrequencyCorrection: " << dev->hasFrequencyCorrection(SOAPY_SDR_RX, 0) << endl;
         std::vector<std::string> gains = dev->listGains(SOAPY_SDR_RX, 0);
         cout << "hasGainMode: " << dev->hasGainMode(SOAPY_SDR_RX, 0) << endl;
         cout << "listGains: " << gains << endl;
         for (auto g : gains) {
         cout << "range of gain " << g << ": " << dev->getGainRange(SOAPY_SDR_RX, 0, g) << endl;
         }
         std::vector<std::string> freqs = dev->listFrequencies(SOAPY_SDR_RX, 0);
         cout << "listFrequencies: " << freqs << endl;
         for (auto f : freqs) {
         cout << "range of freq " << f << ": " << dev->getFrequencyRange(SOAPY_SDR_RX, 0, f) << endl;
         }
         cout << "getFrequencyArgsInfo: " << dev->getFrequencyArgsInfo(SOAPY_SDR_RX, 0) << endl;
         
         std::vector<double> rates = dev->listSampleRates(SOAPY_SDR_RX, 0);
         cout << "listSampleRates: " << rates << endl;
         cout << "getSampleRateRange: " << dev->getSampleRateRange(SOAPY_SDR_RX, 0) << endl;
         std::vector<double> bws = dev->listBandwidths(SOAPY_SDR_RX, 0);
         cout << "listBandwidths: " << bws << endl;
         cout << "getBandwidthRange: " << dev->getBandwidthRange(SOAPY_SDR_RX, 0) << endl;
         cout << "listClockSources: " << dev->listClockSources() << endl;
         cout << "listTimeSources: " << dev->listTimeSources() << endl;
         cout << "listSensors: " << dev->listSensors() << endl;
         cout << "listRegisterInterfaces: " << dev->listRegisterInterfaces() << endl;
         cout << "getSettingInfo: " << dev->getSettingInfo() << endl;
         
         
         Device::unmake(dev);
         */
    }

}
}
}

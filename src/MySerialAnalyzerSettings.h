#ifndef MYSERIAL_ANALYZER_SETTINGS
#define MYSERIAL_ANALYZER_SETTINGS

#include <AnalyzerSettings.h>
#include <AnalyzerTypes.h>
#include <map>
#include <memory>

namespace MySerialAnalyzerEnums
{
    enum Mode
    {
        Normal,
        MpModeMsbZeroMeansAddress,
        MpModeMsbOneMeansAddress
    };
}

typedef std::map<float, U32> BRTime ;

class MySerialAnalyzerSettings : public AnalyzerSettings
{
  public:
    MySerialAnalyzerSettings();
    virtual ~MySerialAnalyzerSettings();

    virtual bool SetSettingsFromInterfaces();
    void UpdateInterfacesFromSettings();
    virtual void LoadSettings( const char* settings );
    virtual const char* SaveSettings();


    Channel mInputChannel;
    U32 mBitRate;

    std::string mBitRateChangeStr; // string containing when to change bitrate, in the form time:bitrate, separated by spaces
    
    // this will contain when to change baudrate. Keys: timestamp, value: baudrate to set.
    BRTime mBRChange ; 
    
    U32 mBitsPerTransfer;
    AnalyzerEnums::ShiftOrder mShiftOrder;
    double mStopBits;
    AnalyzerEnums::Parity mParity;
    bool mInverted;
    bool mUseAutobaud;
    MySerialAnalyzerEnums::Mode mSerialMode;

  protected:
    void SyncBitRateChange();
    std::unique_ptr<AnalyzerSettingInterfaceChannel> mInputChannelInterface;
    std::unique_ptr<AnalyzerSettingInterfaceInteger> mBitRateInterface;
    std::unique_ptr<AnalyzerSettingInterfaceText> mBitRateChangeInterface;
    std::unique_ptr<AnalyzerSettingInterfaceNumberList> mBitsPerTransferInterface;
    std::unique_ptr<AnalyzerSettingInterfaceNumberList> mShiftOrderInterface;
    std::unique_ptr<AnalyzerSettingInterfaceNumberList> mStopBitsInterface;
    std::unique_ptr<AnalyzerSettingInterfaceNumberList> mParityInterface;
    std::unique_ptr<AnalyzerSettingInterfaceNumberList> mInvertedInterface;
    std::unique_ptr<AnalyzerSettingInterfaceBool> mUseAutobaudInterface;
    std::unique_ptr<AnalyzerSettingInterfaceNumberList> mSerialModeInterface;
};

#endif // MYSERIAL_ANALYZER_SETTINGS

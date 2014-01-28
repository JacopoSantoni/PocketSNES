#include "../../emu_interface.h"


extern "C" int mainEntry(int argc, char** argv);

using namespace std;

class PocketSnesEmulator : public CoreInterface
{
	private:

	public:
		PocketSnesEmulator()
		{
      registerInformations(CONSOLE_SUPER_NINTENDO, "pocketsnes", "PocketSNES", "1.0");
      registerExtension("smc");
      
      registerSetting(new BoolSetting("Auto Save SRAM", "auto-save-sram", false));
      registerSetting(new BoolSetting("Sound", "enable-sound", false));
      
      EnumSet<int32_t> sampleRates = {EnumValue<int32_t>("0",0),EnumValue<int32_t>("11025",11025),EnumValue<int32_t>("22050",22050),EnumValue<int32_t>("44100",44100),EnumValue<int32_t>("48000",48000)};
      registerSetting(new EnumSetting<int32_t>("Sample Rate", "sample-rate", sampleRates, sampleRates[3]));
      
      registerSetting(new BoolSetting("Stereo", "enable-sound-stereo", false));
      
      EnumSet<int32_t> frameSkip = {EnumValue<int32_t>("AUTO",-1),EnumValue<int32_t>("0",11025),EnumValue<int32_t>("1",1),EnumValue<int32_t>("2",2),EnumValue<int32_t>("3",3),EnumValue<int32_t>("4",4),EnumValue<int32_t>("5",5)};
      registerSetting(new EnumSetting<int32_t>("Frameskip", "frameskip", frameSkip, frameSkip[0]));
      
      registerSetting(new BoolSetting("Transparency", "transparency", false));
      registerSetting(new BoolSetting("Show FPS", "show-fps", false));
		}

		virtual void run(int argc, char **argv) { mainEntry(argc, argv); }
};

static PocketSnesEmulator emulator;

extern "C" CoreInterface* retrieve()
{
	return &emulator;
}

// /* ========================================
//  *  Capacitor2
//  *  Copyright (c) 2016 airwindows, Airwindows uses the MIT license
//  * ========================================
//  *  Capacitor2Fix - Capacitor2FixProcessor.cpp
//  *  Ported to VST3 by skarjala, open-sourced using GPLv3 license
//  * ======================================== */

#ifndef _CAPACITOR2_FIX_PROCESSOR_
#define _CAPACITOR2_FIX_PROCESSOR_

#include "public.sdk/source/vst/vstaudioeffect.h"

namespace Steinberg {
    namespace Vst {
        class Capacitor2FixProcessor : public Steinberg::Vst::AudioEffect
        {
          public:
            /** Called when creating an instance of the plugin */
            tresult PLUGIN_API initialize(FUnknown* context) override;

            /** Called when destroying an instance of the plugin */
            tresult PLUGIN_API terminate() override;

            /** Called when activating or deactivating an instance of the plugin */
            tresult PLUGIN_API setActive(TBool isActive) override;

            /** Called to check what data sizes (eg. 32-bit or 64-bit) can be handled*/
            tresult PLUGIN_API canProcessSampleSize(int32 symbolicSampleSize) override;

            /** Called to load a project or preset from stored data */
            tresult PLUGIN_API setState(IBStream* state) override;

            /** Called to save a project or preset from current state */
            tresult PLUGIN_API getState(IBStream* state) override;

            /** Called before any processing occurs */
            tresult PLUGIN_API setupProcessing(ProcessSetup& newSetup) override;

            /** Implements live audio processing for the plugin */
            tresult PLUGIN_API process(ProcessData& data) override;

            static FUnknown* createInstance(void*) { return static_cast<IAudioProcessor*>(new Capacitor2FixProcessor); }

          private:
            void handleProcessParamChanges(IParameterChanges* paramChanges, const int32 numSamples);

            ParamValue paramLowpass = 0;
            ParamValue paramHighpass = 0;
            ParamValue paramNonLin = 0;
            ParamValue paramDryWet = 0;
            bool pluginBypass = false;
        };
    }
}

#endif // _CAPACITOR2_FIX_PROCESSOR_

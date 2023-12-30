/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class NoiseEnhancerAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    NoiseEnhancerAudioProcessorEditor (NoiseEnhancerAudioProcessor&, juce::AudioProcessorValueTreeState&);
    ~NoiseEnhancerAudioProcessorEditor() override;

	// GUI setup
	static const int N_SLIDERS_COUNT = 9;
	static const int SCALE = 70;
	static const int LABEL_OFFSET = 25;
	static const int SLIDER_WIDTH = 200;
	static const int HUE = 25;

	static const int BOTTOM_MENU_HEIGHT = 50;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

	typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    NoiseEnhancerAudioProcessor& audioProcessor;

	juce::AudioProcessorValueTreeState& valueTreeState;

	juce::TextButton buttonS{ "S" };
	std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> buttonSAttachment;

	juce::Label m_labels[N_SLIDERS_COUNT] = {};
	juce::Slider m_sliders[N_SLIDERS_COUNT] = {};
	std::unique_ptr<SliderAttachment> m_sliderAttachment[N_SLIDERS_COUNT] = {};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoiseEnhancerAudioProcessorEditor)
};

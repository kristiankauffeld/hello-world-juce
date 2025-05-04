#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);

    auto& params = processor.getParameters();
    juce::AudioParameterFloat* gainParam = (juce::AudioParameterFloat*)params.getUnchecked (0);
    mGainControlSlider.setBounds (0, 0, 100, 100);
    mGainControlSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    mGainControlSlider.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    mGainControlSlider.setRange (gainParam->range.start, gainParam->range.end);
    mGainControlSlider.setValue (*gainParam);

    mGainControlSlider.onValueChange = [this, gainParam] () {
        *gainParam = mGainControlSlider.getValue();
    };

    mGainControlSlider.onDragStart = [gainParam] {
        gainParam->beginChangeGesture();
    };

    mGainControlSlider.onDragEnd = [gainParam] {
        gainParam->endChangeGesture();
    };

    addAndMakeVisible (&mGainControlSlider);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World from!", getLocalBounds(), juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
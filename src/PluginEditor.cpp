#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);

    // Retrieve the list of parameters from the processor.
    auto& params = processor.getParameters();

    // Access the gain parameter by index (assumed to be at index 0).
    juce::AudioParameterFloat* gainParam = (juce::AudioParameterFloat*)params.getUnchecked (0);

    // Configure the gain slider: position and size.
    mGainControlSlider.setBounds (0, 0, 100, 100);

    // Set slider style to rotary with vertical drag behavior.
    mGainControlSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);

    // Remove the text box below the slider.
    mGainControlSlider.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);

    // Set the slider’s range to match the gain parameter’s min and max.
    mGainControlSlider.setRange (gainParam->range.start, gainParam->range.end);

    // Set the slider’s initial value to match the gain parameter’s current value.
    mGainControlSlider.setValue (*gainParam);

    // Register the editor class as a listener to this slider.
    mGainControlSlider.addListener (this);

    // Make the slider visible on the editor.
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

// Listener callback: called whenever a connected slider’s value changes.
void AudioPluginAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    // Retrieve the list of parameters from the processor.
    auto& params = processor.getParameters();

    // Check if the gain control slider triggered this callback.
    if (slider == &mGainControlSlider)
    {
        // Access the gain parameter (assumed to be at index 0).
        juce::AudioParameterFloat* gainParam = (juce::AudioParameterFloat*)params.getUnchecked (0);

        // Update the gain parameter with the slider’s current value.
        *gainParam = mGainControlSlider.getValue();

        // Output a debug message to the console.
        DBG ("GAIN SLIDER HAS CHANGED");
    }
}
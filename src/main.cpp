#include <juce_core/juce_core.h>

int main()
{
    juce::String hello = "Hello, JUCE!";
    juce::Logger::writeToLog(hello);
    return 0;
}
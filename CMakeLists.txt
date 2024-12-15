cmake_minimum_required(VERSION 3.28)
project(hello_world_juce VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

find_package(juce CONFIG REQUIRED)

juce_add_plugin(${PROJECT_NAME}
        PLUGIN_MANUFACTURER_CODE Juce
        PLUGIN_CODE Dem0
        FORMATS AU VST3 Standalone # The formats to build. Other valid formats are: AAX Unity VST AU AUv3
        PRODUCT_NAME "Simple gain"
        COMPANY_NAME "Your Company"
        IS_SYNTH FALSE
        NEEDS_MIDI_INPUT FALSE
        NEEDS_MIDI_OUTPUT FALSE
        IS_MIDI_EFFECT FALSE
        EDITOR TRUE
        COPY_PLUGIN_AFTER_BUILD TRUE # Should the plugin be installed to a default location after building?
)

target_sources(${PROJECT_NAME}
        PRIVATE
        src/PluginProcessor.cpp
        src/PluginProcessor.h
        src/PluginEditor.cpp
        src/PluginEditor.h)

# Link with JUCE modules
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        juce::juce_audio_utils
        juce::juce_audio_processors
        juce::juce_core
        juce::juce_data_structures
        juce::juce_events
        juce::juce_graphics
        juce::juce_gui_basics
        juce::juce_gui_extra
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)

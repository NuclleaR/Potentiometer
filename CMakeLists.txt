cmake_minimum_required(VERSION 3.9)
project(potentiometr)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        /Users/skorenyuk/Library/Arduino15/packages/arduino/hardware/avr/1.6.21/cores/arduino
)

set(files Arduino.h)

add_subdirectory(src)
target_link_libraries(Potentiometer)
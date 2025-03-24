Setting up the build environment for EdgeTX
-------------------------------------------
For Ubuntu 20.04
----------------
    wget https://raw.githubusercontent.com/Gnathvm/edgetx-hazel/main/tools/setup_buildenv_ubuntu20.04.sh

Make Executable

    chmod a+x setup_buildenv_ubuntu20.04.sh

Execute Install Script 

    ./setup_buildenv_ubuntu20.04.sh    
    
For Ubuntu 22.04
----------------
    wget https://raw.githubusercontent.com/Gnathvm/edgetx-hazel/main/tools/setup_buildenv_ubuntu22.04.sh
    
Make Executable

    chmod a+x setup_buildenv_ubuntu22.04.sh
    
Execute Install Script
    
    ./setup_buildenv_ubuntu22.04.sh

Building EdgeTX firmware for the radio
--------------------------------------
We will next fetch the EdgeTX source files from the GitHub main development branch into local subfolder /edgetx/edgetx_main in current user home, prepare the environment and build output directory. Issue, in the same terminal window as above, the following commands, one at a time:


    git clone --recursive -b main https://github.com/Gnathvm/edgetx-hazel.git

Create Build Directory

    mkdir build-output && cd build-output

To build EdgeTX, we need to minimally specify the radio target, but can further select or de-select a number of build-time options. The following command will create a text-file list of all options for you to look at and saves it in current user home directory:

    cmake -LAH ../ > ~/edgetx_main-cmake-options.txt

You can use, e.g. gedit under Ubuntu to view the file.

As an example, we will build next for RadioMaster TX16S (PCB=X10, PCBREV=TX16S), mode 2 default stick (DEFAULT_MODE=2), global variables enabled (GVARS=YES), servo output unit as microseconds (PPM_UNIT=US), include Lua mixer script support (LUA_MIXER=YES) and selected the type as a Debug build with debug symbols included (CMAKE_BUILD_TYPE=Debug). The CMake command for this is (issue the following without line breaks and be sure to include at the end the two dots and a slash exactly as here listed):

    cmake -DPCB=X10 -DPCBREV=TX16S -DDEFAULT_MODE=2 -DGVARS=YES -DPPM_UNIT=US -DLUA_MIXER=YES -DCMAKE_BUILD_TYPE=Debug ../

If you do not want to include the debug symbols, use -DCMAKE_BUILD_TYPE=Release instead.

To build for other radios, you just need to select another build target by specifying appropriate values for PCB and PCBREV for your radio. If you are are wanting to build for multiple different targets, it is best to use a different build folder for each. Otherwise, delete the CMakeCache.txt file from the build directory before before running cmake to configure a different transmitter build, otherwise cached configuration values from your previous build target will cause weird compile results. As a tip, which values to use, have a look at a Python script according to your radio manufacturer in a file named build-<radio-manufacturer>.py under https://github.com/EdgeTX/edgetx/tree/main/tools

Starting with 2.8, an additional step is required. Issue:

    make configure

Alternatively, you can issue make arm-none-eabi-configure if you only want to build radio firmware or make native-configure if you only want to build targets meant to be run on computer (running make configure activates both architecture targets).

Only a few seconds later, you should be greeted with "-- Generating done" message.

The configure process generates the makefile that is required in the next step to build the firmware. For this, issue:

    make -j`nproc` firmware

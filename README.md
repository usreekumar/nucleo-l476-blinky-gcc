# nucleo-l476-blinky-gcc

## System Details
  OS : Ubuntu 20.04 LTS 

## Requirements
  Any text editor, make, gcc
  
## Location of files 
	- stm32l476xx.h, stm32l4xx.h, system_stm32l4xx.h => STM32CubeL4-master/Drivers/CMSIS/Device/ST/STM32L4xx/Include
	- system_stm32l4xx.c => STM32CubeL4-master/Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates
	- startup_stm32l476xx.s => STM32CubeL4-master/Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates/gcc

## Install cross compiler gcc-arm-none-eabi
	- Download the latest version (Linux x86_64 Tarball) from the website
		https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads

## Install st-link
	Ref : https://freeelectron.ro/installing-st-link-v2-to-flash-stm32-targets-on-linux/

	-Install dependecnies
		$ sudo apt-get install git make cmake libusb-1.0-0-dev gcc build-essential
	- Clone the repo in desired folder.
		$ git clone https://github.com/stlink-org/stlink
	- Build 
		$ cmake .
		$ make
	-Now the bin folder contains all the required binaries
	-udev rules
		$ sudo cp stlink/config/udev/rules.d/49-stlinkv* /etc/udev/rules.d/



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../device/2838x_RAM_lnk_cpu1.cmd \
../device/f2838x_headers_nonBIOS_cpu1.cmd 

ASM_SRCS += \
../device/f2838x_codestartbranch.asm \
../device/f2838x_usdelay.asm 

C_SRCS += \
../device/device.c \
../device/f2838x_defaultisr.c \
../device/f2838x_globalvariabledefs.c \
../device/f2838x_gpio.c \
../device/f2838x_piectrl.c \
../device/f2838x_pievect.c \
../device/f2838x_sysctrl.c 

C_DEPS += \
./device/device.d \
./device/f2838x_defaultisr.d \
./device/f2838x_globalvariabledefs.d \
./device/f2838x_gpio.d \
./device/f2838x_piectrl.d \
./device/f2838x_pievect.d \
./device/f2838x_sysctrl.d 

OBJS += \
./device/device.obj \
./device/f2838x_codestartbranch.obj \
./device/f2838x_defaultisr.obj \
./device/f2838x_globalvariabledefs.obj \
./device/f2838x_gpio.obj \
./device/f2838x_piectrl.obj \
./device/f2838x_pievect.obj \
./device/f2838x_sysctrl.obj \
./device/f2838x_usdelay.obj 

ASM_DEPS += \
./device/f2838x_codestartbranch.d \
./device/f2838x_usdelay.d 

OBJS__QUOTED += \
"device\device.obj" \
"device\f2838x_codestartbranch.obj" \
"device\f2838x_defaultisr.obj" \
"device\f2838x_globalvariabledefs.obj" \
"device\f2838x_gpio.obj" \
"device\f2838x_piectrl.obj" \
"device\f2838x_pievect.obj" \
"device\f2838x_sysctrl.obj" \
"device\f2838x_usdelay.obj" 

C_DEPS__QUOTED += \
"device\device.d" \
"device\f2838x_defaultisr.d" \
"device\f2838x_globalvariabledefs.d" \
"device\f2838x_gpio.d" \
"device\f2838x_piectrl.d" \
"device\f2838x_pievect.d" \
"device\f2838x_sysctrl.d" 

ASM_DEPS__QUOTED += \
"device\f2838x_codestartbranch.d" \
"device\f2838x_usdelay.d" 

C_SRCS__QUOTED += \
"../device/device.c" \
"../device/f2838x_defaultisr.c" \
"../device/f2838x_globalvariabledefs.c" \
"../device/f2838x_gpio.c" \
"../device/f2838x_piectrl.c" \
"../device/f2838x_pievect.c" \
"../device/f2838x_sysctrl.c" 

ASM_SRCS__QUOTED += \
"../device/f2838x_codestartbranch.asm" \
"../device/f2838x_usdelay.asm" 



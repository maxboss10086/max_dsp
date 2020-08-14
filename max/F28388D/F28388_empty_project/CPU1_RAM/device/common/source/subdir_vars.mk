################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../device/common/source/f2838x_codestartbranch.asm \
../device/common/source/f2838x_dbgier.asm \
../device/common/source/f2838x_dcsm_z1otp.asm \
../device/common/source/f2838x_dcsm_z2otp.asm \
../device/common/source/f2838x_usdelay.asm 

C_SRCS += \
../device/common/source/cm.c \
../device/common/source/device.c \
../device/common/source/f2838x_adc.c \
../device/common/source/f2838x_cputimers.c \
../device/common/source/f2838x_defaultisr.c \
../device/common/source/f2838x_dma.c \
../device/common/source/f2838x_ecap.c \
../device/common/source/f2838x_emif.c \
../device/common/source/f2838x_epwm.c \
../device/common/source/f2838x_eqep.c \
../device/common/source/f2838x_gpio.c \
../device/common/source/f2838x_mcbsp.c \
../device/common/source/f2838x_piectrl.c \
../device/common/source/f2838x_pievect.c \
../device/common/source/f2838x_sdfm_drivers.c \
../device/common/source/f2838x_struct.c \
../device/common/source/f2838x_swprioritizedpievect.c \
../device/common/source/f2838x_sysctrl.c \
../device/common/source/f2838x_tempsensorconv.c \
../device/common/source/startup_cm.c 

C_DEPS += \
./device/common/source/cm.d \
./device/common/source/device.d \
./device/common/source/f2838x_adc.d \
./device/common/source/f2838x_cputimers.d \
./device/common/source/f2838x_defaultisr.d \
./device/common/source/f2838x_dma.d \
./device/common/source/f2838x_ecap.d \
./device/common/source/f2838x_emif.d \
./device/common/source/f2838x_epwm.d \
./device/common/source/f2838x_eqep.d \
./device/common/source/f2838x_gpio.d \
./device/common/source/f2838x_mcbsp.d \
./device/common/source/f2838x_piectrl.d \
./device/common/source/f2838x_pievect.d \
./device/common/source/f2838x_sdfm_drivers.d \
./device/common/source/f2838x_struct.d \
./device/common/source/f2838x_swprioritizedpievect.d \
./device/common/source/f2838x_sysctrl.d \
./device/common/source/f2838x_tempsensorconv.d \
./device/common/source/startup_cm.d 

OBJS += \
./device/common/source/cm.obj \
./device/common/source/device.obj \
./device/common/source/f2838x_adc.obj \
./device/common/source/f2838x_codestartbranch.obj \
./device/common/source/f2838x_cputimers.obj \
./device/common/source/f2838x_dbgier.obj \
./device/common/source/f2838x_dcsm_z1otp.obj \
./device/common/source/f2838x_dcsm_z2otp.obj \
./device/common/source/f2838x_defaultisr.obj \
./device/common/source/f2838x_dma.obj \
./device/common/source/f2838x_ecap.obj \
./device/common/source/f2838x_emif.obj \
./device/common/source/f2838x_epwm.obj \
./device/common/source/f2838x_eqep.obj \
./device/common/source/f2838x_gpio.obj \
./device/common/source/f2838x_mcbsp.obj \
./device/common/source/f2838x_piectrl.obj \
./device/common/source/f2838x_pievect.obj \
./device/common/source/f2838x_sdfm_drivers.obj \
./device/common/source/f2838x_struct.obj \
./device/common/source/f2838x_swprioritizedpievect.obj \
./device/common/source/f2838x_sysctrl.obj \
./device/common/source/f2838x_tempsensorconv.obj \
./device/common/source/f2838x_usdelay.obj \
./device/common/source/startup_cm.obj 

ASM_DEPS += \
./device/common/source/f2838x_codestartbranch.d \
./device/common/source/f2838x_dbgier.d \
./device/common/source/f2838x_dcsm_z1otp.d \
./device/common/source/f2838x_dcsm_z2otp.d \
./device/common/source/f2838x_usdelay.d 

OBJS__QUOTED += \
"device\common\source\cm.obj" \
"device\common\source\device.obj" \
"device\common\source\f2838x_adc.obj" \
"device\common\source\f2838x_codestartbranch.obj" \
"device\common\source\f2838x_cputimers.obj" \
"device\common\source\f2838x_dbgier.obj" \
"device\common\source\f2838x_dcsm_z1otp.obj" \
"device\common\source\f2838x_dcsm_z2otp.obj" \
"device\common\source\f2838x_defaultisr.obj" \
"device\common\source\f2838x_dma.obj" \
"device\common\source\f2838x_ecap.obj" \
"device\common\source\f2838x_emif.obj" \
"device\common\source\f2838x_epwm.obj" \
"device\common\source\f2838x_eqep.obj" \
"device\common\source\f2838x_gpio.obj" \
"device\common\source\f2838x_mcbsp.obj" \
"device\common\source\f2838x_piectrl.obj" \
"device\common\source\f2838x_pievect.obj" \
"device\common\source\f2838x_sdfm_drivers.obj" \
"device\common\source\f2838x_struct.obj" \
"device\common\source\f2838x_swprioritizedpievect.obj" \
"device\common\source\f2838x_sysctrl.obj" \
"device\common\source\f2838x_tempsensorconv.obj" \
"device\common\source\f2838x_usdelay.obj" \
"device\common\source\startup_cm.obj" 

C_DEPS__QUOTED += \
"device\common\source\cm.d" \
"device\common\source\device.d" \
"device\common\source\f2838x_adc.d" \
"device\common\source\f2838x_cputimers.d" \
"device\common\source\f2838x_defaultisr.d" \
"device\common\source\f2838x_dma.d" \
"device\common\source\f2838x_ecap.d" \
"device\common\source\f2838x_emif.d" \
"device\common\source\f2838x_epwm.d" \
"device\common\source\f2838x_eqep.d" \
"device\common\source\f2838x_gpio.d" \
"device\common\source\f2838x_mcbsp.d" \
"device\common\source\f2838x_piectrl.d" \
"device\common\source\f2838x_pievect.d" \
"device\common\source\f2838x_sdfm_drivers.d" \
"device\common\source\f2838x_struct.d" \
"device\common\source\f2838x_swprioritizedpievect.d" \
"device\common\source\f2838x_sysctrl.d" \
"device\common\source\f2838x_tempsensorconv.d" \
"device\common\source\startup_cm.d" 

ASM_DEPS__QUOTED += \
"device\common\source\f2838x_codestartbranch.d" \
"device\common\source\f2838x_dbgier.d" \
"device\common\source\f2838x_dcsm_z1otp.d" \
"device\common\source\f2838x_dcsm_z2otp.d" \
"device\common\source\f2838x_usdelay.d" 

C_SRCS__QUOTED += \
"../device/common/source/cm.c" \
"../device/common/source/device.c" \
"../device/common/source/f2838x_adc.c" \
"../device/common/source/f2838x_cputimers.c" \
"../device/common/source/f2838x_defaultisr.c" \
"../device/common/source/f2838x_dma.c" \
"../device/common/source/f2838x_ecap.c" \
"../device/common/source/f2838x_emif.c" \
"../device/common/source/f2838x_epwm.c" \
"../device/common/source/f2838x_eqep.c" \
"../device/common/source/f2838x_gpio.c" \
"../device/common/source/f2838x_mcbsp.c" \
"../device/common/source/f2838x_piectrl.c" \
"../device/common/source/f2838x_pievect.c" \
"../device/common/source/f2838x_sdfm_drivers.c" \
"../device/common/source/f2838x_struct.c" \
"../device/common/source/f2838x_swprioritizedpievect.c" \
"../device/common/source/f2838x_sysctrl.c" \
"../device/common/source/f2838x_tempsensorconv.c" \
"../device/common/source/startup_cm.c" 

ASM_SRCS__QUOTED += \
"../device/common/source/f2838x_codestartbranch.asm" \
"../device/common/source/f2838x_dbgier.asm" \
"../device/common/source/f2838x_dcsm_z1otp.asm" \
"../device/common/source/f2838x_dcsm_z2otp.asm" \
"../device/common/source/f2838x_usdelay.asm" 



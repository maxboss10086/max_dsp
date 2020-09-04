################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/TI/ccs10.1/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./empty.obj" \
"./syscfg/clb_config.obj" \
"./syscfg/clb_sim.obj" \
"./Peripherals/clb/user_clb.obj" \
"./device/device.obj" \
"./device/f2838x_codestartbranch.obj" \
"../2838x_RAM_lnk_cpu1.cmd" \
"C:/TI/c2000_ware/C2000Ware_3_02_00_00/driverlib/f2838x/driverlib/ccs/Debug/driverlib.lib" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Peripherals/clb/subdir_vars.mk
-include device/subdir_vars.mk
-include subdir_rules.mk
-include Peripherals/clb/subdir_rules.mk
-include device/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
clb_pwm.out \

EXE_OUTPUTS__QUOTED += \
"clb_pwm.out" \

BIN_OUTPUTS += \
clb_pwm.hex \

BIN_OUTPUTS__QUOTED += \
"clb_pwm.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "clb_pwm.out"

# Tool invocations
clb_pwm.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"C:/TI/ccs10.1/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu64 --idiv_support=idiv0 --tmu_support=tmu0 -Ooff --define=DEBUG --define=CPU1 -g --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi -z -m"clb_pwm.map" --heap_size=0x200 --stack_size=0x100 --warn_sections -i"C:/TI/ccs10.1/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/lib" -i"C:/TI/ccs10.1/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/include" --reread_libs --define=RAM --diag_wrap=off --display_error_number --xml_link_info="clb_pwm_linkInfo.xml" --entry_point=code_start --rom_model -o "clb_pwm.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

clb_pwm.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: C2000 Hex Utility'
	"C:/TI/ccs10.1/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/bin/hex2000"  -o "clb_pwm.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(BIN_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "empty.obj" "syscfg\clb_config.obj" "syscfg\clb_sim.obj" "Peripherals\clb\user_clb.obj" "device\device.obj" "device\f2838x_codestartbranch.obj" 
	-$(RM) "empty.d" "syscfg\clb_config.d" "Peripherals\clb\user_clb.d" "device\device.d" 
	-$(RM) "syscfg\clb_sim.d" 
	-$(RM) "device\f2838x_codestartbranch.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-mkdir "C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Debug/simulation"
	-C:/TDM-GCC-64/bin/g++  -c -DCLB_SIM -IC:/TI/c2000_ware/C2000Ware_3_02_00_00/utilities/clb_tool/clb_syscfg/systemc-2.3.3/src -IC:/TI/c2000_ware/C2000Ware_3_02_00_00/utilities/clb_tool/clb_syscfg/systemc/include -IC:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm -IC:/TDM-GCC-64/bin/include -Og -g -gdwarf-3 -gstrict-dwarf -Wall -MMD -MP -MFC:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Debug/simulation/clb_sim.d -MTC:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Debug/simulation/clb_sim.o -IC:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Debug/syscfg   -fno-threadsafe-statics  -oC:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Debug/simulation/clb_sim.o C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Debug/syscfg/clb_sim.cpp
	-C:/TDM-GCC-64/bin/g++ -DCLB_SIM -Og -g -gdwarf-3 -gstrict-dwarf -Wall -Wl,-Map,C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Debug/simulation/simulation_output.map -LC:/TI/c2000_ware/C2000Ware_3_02_00_00/utilities/clb_tool/clb_syscfg/systemc-2.3.3/build/src -oC:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Debug/simulation/simulation_output.exe C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Debug/simulation/clb_sim.o C:/TI/c2000_ware/C2000Ware_3_02_00_00/utilities/clb_tool/clb_syscfg/systemc/src/CLB_FSM_SC_model.o C:/TI/c2000_ware/C2000Ware_3_02_00_00/utilities/clb_tool/clb_syscfg/systemc/src/CLB_HLC_SC_model.o C:/TI/c2000_ware/C2000Ware_3_02_00_00/utilities/clb_tool/clb_syscfg/systemc/src/CLB_LUT4_SC_model.o C:/TI/c2000_ware/C2000Ware_3_02_00_00/utilities/clb_tool/clb_syscfg/systemc/src/CLB_OutputLUT_SC_model.o C:/TI/c2000_ware/C2000Ware_3_02_00_00/utilities/clb_tool/clb_syscfg/systemc/src/CLB_counter_SC_model.o  -Wl,--start-group -lsystemc -Wl,--end-group
	-./simulation/simulation_output.exe
	-C:/TI/ccs10.1/ccs/tools/node/node.exe "C:/TI/c2000_ware/C2000Ware_3_02_00_00/utilities/clb_tool/clb_syscfg/dot_file_libraries/clbDotUtility.js"  "C:/TI/c2000_ware/C2000Ware_3_02_00_00/utilities/clb_tool/clb_syscfg" "C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Debug/syscfg" "C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Debug/syscfg/clb.dot"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets


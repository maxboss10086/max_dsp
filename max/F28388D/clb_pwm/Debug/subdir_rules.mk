################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/TI/ccs10.1/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu64 --idiv_support=idiv0 --tmu_support=tmu0 -Ooff --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Peripherals/clb" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/device" --include_path="C:/TI/c2000_ware/C2000Ware_3_02_00_00/driverlib/f2838x/driverlib" --include_path="C:/TI/c2000_ware/C2000Ware_3_02_00_00/device_support/f2838x/common/include" --include_path="C:/TI/c2000_ware/C2000Ware_3_02_00_00/utilities/clb_tool/clb_syscfg/systemc/include" --include_path="C:/TI/ccs10.1/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/include" --define=DEBUG --define=CPU1 -g --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Debug/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-326775791: ../empty.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/TI/ccs10.1/ccs/utils/sysconfig_1.5.0/sysconfig_cli.bat" -d "F2838x" -s "C:/TI/c2000_ware/C2000Ware_3_02_00_00/utilities/clb_tool/clb_syscfg/.metadata/product.json" -o "syscfg" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/clb_config.h: build-326775791 ../empty.syscfg
syscfg/clb_config.c: build-326775791
syscfg/clb.dot: build-326775791
syscfg/clb_sim.cpp: build-326775791
syscfg/: build-326775791

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/TI/ccs10.1/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu64 --idiv_support=idiv0 --tmu_support=tmu0 -Ooff --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Peripherals/clb" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/device" --include_path="C:/TI/c2000_ware/C2000Ware_3_02_00_00/driverlib/f2838x/driverlib" --include_path="C:/TI/c2000_ware/C2000Ware_3_02_00_00/device_support/f2838x/common/include" --include_path="C:/TI/c2000_ware/C2000Ware_3_02_00_00/utilities/clb_tool/clb_syscfg/systemc/include" --include_path="C:/TI/ccs10.1/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/include" --define=DEBUG --define=CPU1 -g --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Debug/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/%.obj: ./syscfg/%.cpp $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/TI/ccs10.1/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu64 --idiv_support=idiv0 --tmu_support=tmu0 -Ooff --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Peripherals/clb" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/device" --include_path="C:/TI/c2000_ware/C2000Ware_3_02_00_00/driverlib/f2838x/driverlib" --include_path="C:/TI/c2000_ware/C2000Ware_3_02_00_00/device_support/f2838x/common/include" --include_path="C:/TI/c2000_ware/C2000Ware_3_02_00_00/utilities/clb_tool/clb_syscfg/systemc/include" --include_path="C:/TI/ccs10.1/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/include" --define=DEBUG --define=CPU1 -g --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/clb_pwm/Debug/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/TI/ccs10.1/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu64 --idiv_support=idiv0 --tmu_support=tmu0 -Ooff --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/1_SCI_send/Peripherals/interrupt" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/1_SCI_send/Peripherals/led" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/1_SCI_send/Peripherals/dlog" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/1_SCI_send/Peripherals/dma" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/1_SCI_send/Peripherals/epwm" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/1_SCI_send/Peripherals/gpio" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/1_SCI_send/Peripherals/spi" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/1_SCI_send/Peripherals/sci" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/1_SCI_send" --include_path="C:/TI/work_space_ccs10.1/max_dsp/max/F28388D/1_SCI_send/device" --include_path="C:/TI/c2000_ware/C2000Ware_3_02_00_00/driverlib/f2838x/driverlib" --include_path="C:/TI/ccs10.1/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/include" --define=DEBUG --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
device/driverlib/%.obj: ../device/driverlib/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/TI/ccs10.1/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu64 --idiv_support=idiv0 --tmu_support=tmu0 -Ooff --include_path="C:/TI/work_space_ccs10.1/F28388_empty_project/device/driverlib/inc" --include_path="C:/TI/work_space_ccs10.1/F28388_empty_project" --include_path="C:/TI/work_space_ccs10.1/F28388_empty_project/device" --include_path="C:/TI/work_space_ccs10.1/F28388_empty_project/device/common/include" --include_path="C:/TI/work_space_ccs10.1/F28388_empty_project/device/headers/include" --include_path="C:/TI/work_space_ccs10.1/F28388_empty_project/device/driverlib" --include_path="C:/TI/ccs10.1/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/include" --advice:performance=all --define=DEBUG --define=CPU1 --define=_DUAL_HEADERS --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="device/driverlib/$(basename $(<F)).d_raw" --obj_directory="device/driverlib" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



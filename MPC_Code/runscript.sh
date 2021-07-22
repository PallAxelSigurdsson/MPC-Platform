#!/bin/bash

############################################

#########################
# CONFIGURATION SECTION #
#########################

#Choose the number of CPU tiles to have in the system to be uploaded. 
#Options: 2 - 8
N_CPU=8

#Choose test type.
#Options: CONGESTION or LATENCY 
TEST_TYPE=CONGESTION

#Choose the actual peripheral to be tested
# OPTIONS:
#	For LATENCY:
#		- FIFO_INITIALIZE
#		- FIFO_LEVEL
#		- FIFO_STATUS
#		- FIFO_TRANSACTIONS
#		- LED_GREEN
#		- LED_RED
#		- MEMORY
#		- MUTEX_FIRST_LOCK
#		- MUTEX_IS_MINE
#		- MUTEX_LOCKING
#		- MUTEX_OPEN
#		- MUTEX_OWNER
#		- PERF_COUNTER
#		- SWITCHES
#		- TIMERS_LOCAL
#		- TIMERS_SHARED
#	For CONGESTION:
#		- GREEN_LED_CONGESTION
#		- MULTIPLE_MUTEX_IS_MINE_CONGESTION
#		- MUTEX_FIRST_LOCK_CONGESTION
#		- MUTEX_OPEN_CONGESTION
#		- MUTEX_OWNER_CONGESTION
#		- MUTEX_TRYLOCK_READ_CONGESTION
#		- RED_LED_CONGESTION
#		- SHARED_MEM_READ_CONGESTION
#		- SHARED_MEM_WRITE_CONGESTION
#		- SHARED_TIMESTAMP_0_CONGESTION
#		- SHARED_TIMESTAMP_0_RESET_CONGESTION
#		- SHARED_TIMESTAMP_1_CONGESTION
#		- SHARED_TIMESTAMP_1_RESET_CONGESTION	
#		- SHARED_MUTEX_IS_MINE_CONGESTION
#		- SWITCHES_CONGESTION 
APP_NAME=GREEN_LED_CONGESTION

############################################

TOPOLOGY_PATH=Core

# Declare paths to the hardware files for the board
CORE_FILE=hardware/${TOPOLOGY_PATH}${N_CPU}.sopcinfo
SOF_FILE=hardware/${TOPOLOGY_PATH}${N_CPU}.sof
JDI_FILE=hardware/${TOPOLOGY_PATH}${N_CPU}.jdi
	
APP_PATH=app

CPU_NAME=cpu						#Appends cpu number to the end i.e. cpu_0, cpu_1, etc.
BSP_PATH=bsp						#BSP Path
SRC_PATH=src						#Appends cpu number to the end i.e. src_0, src_1, etc.
APP_BUILD_DIR=build					#Build directory for applications
LIB_BUILD_DIR=build					#Build directory for User Library
MPC_LIB_DIR_NAME=mpcLib					#User Library Name
MPC_LIB_PATH=${MPC_LIB_DIR_NAME}			#User Library Path
MPC_LIB_BUILD_PATH=${MPC_LIB_PATH}/${LIB_BUILD_DIR}	#User Library Build Path 

[[ ! -d ${APP_BUILD_DIR} ]] && mkdir  ${APP_BUILD_DIR}
[[ ! -d ${MPC_LIB_BUILD_PATH} ]] && mkdir  ${MPC_LIB_BUILD_PATH}

#Generate and compile BSP package for each cpu 
for ((i=0; i<${N_CPU}; i++))
do
	echo -e "\n******************************************"
	echo -e "Building the BSP Package for ${CPU_NAME}_$i"
	echo -e "******************************************\n"

	nios2-bsp hal ${TOPOLOGY_PATH}${N_CPU}/${BSP_PATH}/${CPU_NAME}_$i ${TOPOLOGY_PATH}${N_CPU}/$CORE_FILE \
		--cpu-name ${CPU_NAME}_$i \
		--set hal.make.bsp_cflags_debug -g \
		--set hal.make.bsp_cflags_optimization '-O0' \
		--set hal.max_file_descriptors 4 \
		--set hal.sys_clk_timer timer_${i}_0 \
		--default_sections_mapping onchip_memory_$i \
		--set hal.enable_lightweight_device_driver_api true \
		--set hal.enable_exit false \
		--set hal.enable_clean_exit false \
		--set hal.enable_small_c_library true \
		--set hal.enable_reduced_device_drivers true \
		--set hal.enable_c_plus_plus false \
		--set hal.enable_sopc_sysid_check true \
		--set hal.enable_sim_optimize false

	cd ${TOPOLOGY_PATH}${N_CPU}/${BSP_PATH}/${CPU_NAME}_$i
	make 3>&1 1>>log.txt 2>&1
	
	#Check if BSP compilation is successful or not
	if [ $? != 0 ]
	then
		echo "BSP compilation failed for CPU ${CPU_NAME}_$i"
		echo "Check log.txt for more info"
		exit 1
	fi

	cd -

	#Generate and Compile User library
	
	echo -e "\n******************************************"
	echo -e "Generating and Compiling the User Library"
	echo -e "******************************************\n"

	nios2-lib-generate-makefile \
		--bsp-dir ${TOPOLOGY_PATH}${N_CPU}/${BSP_PATH}/${CPU_NAME}_$i \
		--lib-dir ${TOPOLOGY_PATH}${N_CPU}/${MPC_LIB_BUILD_PATH}/${CPU_NAME}_$i \
		--src-rdir ${TOPOLOGY_PATH}${N_CPU}/${MPC_LIB_PATH}/src 	\
		--set ALT_INCLUDE_DIRS ../../inc \
		--public-inc-dir ${TOPOLOGY_PATH}${N_CPU}/${MPC_LIB_PATH}/inc

	cd ${TOPOLOGY_PATH}${N_CPU}/${MPC_LIB_BUILD_PATH}/${CPU_NAME}_$i
	make clean
        make 3>&1 1>>log.txt 2>&1

        #Check if User Library compilation is successful or not
        if [ $? != 0 ]
        then
                echo "User Library compilation failed for CPU ${CPU_NAME}_$i"
                echo "Check log.txt for more info"
                exit 1
        fi

        cd -

	#Generate and Compile Application
	
	echo -e "\n******************************************"
	echo -e "Generating and Compiling the Application"
	echo -e "******************************************\n"

	nios2-app-generate-makefile \
		--bsp-dir ${TOPOLOGY_PATH}${N_CPU}/${BSP_PATH}/${CPU_NAME}_$i\
		--app-dir ${TOPOLOGY_PATH}${N_CPU}/${APP_PATH}/${TEST_TYPE}/${APP_NAME}/${APP_BUILD_DIR}/${CPU_NAME}_$i \
		--elf-name ${APP_NAME}_$i.elf \
		--src-dir ${TOPOLOGY_PATH}${N_CPU}/${APP_PATH}/${TEST_TYPE}/${APP_NAME}/${SRC_PATH}_$i \
		--set APP_CFLAGS_OPTIMIZATION -O0 \
		--set CREATE_OBJDUMP 1 \
		--use-lib-dir ${TOPOLOGY_PATH}${N_CPU}/${MPC_LIB_BUILD_PATH}/${CPU_NAME}_$i

	cd ${TOPOLOGY_PATH}${N_CPU}/${APP_PATH}/${TEST_TYPE}/${APP_NAME}/${APP_BUILD_DIR}/${CPU_NAME}_$i
	make clean
	make 3>&1 1>>log.txt 2>&1
	
	#Check if Application compilation is successful or not
	if [ $? != 0 ]
	then
		echo "Application compilation failed for CPU ${CPU_NAME}_$i"
                echo "Check log.txt for more info"
                exit 1
	fi
	
	cd -
done
	
echo -e "\n**************************"
echo -e  "Download hardware to board"
echo -e  "**************************\n"

nios2-configure-sof ${TOPOLOGY_PATH}${N_CPU}/$SOF_FILE

echo -e "\n**************************"
echo -e   "Download software to board"
echo -e   "**************************\n"

#Separate Loops for nios2 terminal and downloading .elf file
#This will reduce the latency between CPU's initialization
for ((i=0; i<${N_CPU}; i++))
do
	#Open nios2 terminal
	xterm -e "nios2-terminal -i $i" &
done

for ((i=0; i<${N_CPU}; i++))
do
	#Download .elf file to it's respective processor memory 
	nios2-download -g ${TOPOLOGY_PATH}${N_CPU}/${APP_PATH}/${TEST_TYPE}/${APP_NAME}/${APP_BUILD_DIR}/${CPU_NAME}_$i/${APP_NAME}_$i.elf --cpu_name ${CPU_NAME}_$i --jdi ${TOPOLOGY_PATH}${N_CPU}/$JDI_FILE
done

echo ""
echo "Code compilation errors are logged in 'log.txt'"






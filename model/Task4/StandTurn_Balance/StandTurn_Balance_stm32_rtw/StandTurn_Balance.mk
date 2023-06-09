# Copyright 2022  Code Generator For STM32F
#
# File    : stacklite_dualdrive.tmf   
#
# Abstract:
#	Template makefile for building Linux OS of Simulink model using.
#
# 	This makefile attempts to conform to the guidelines specified in the
# 	IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make which is located in matlabroot/rtw/bin.
#
# 	Note that this template is automatically customized by the build 
#       procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#	build:
#	  OPT_OPTS       - Optimization options. Default is -O.
#	  CPP_OPTS       - C++ compiler options.
#	  OPTS           - User specific compile options.
#	  USER_SRCS      - Additional user sources, such as files needed by
#			   S-functions.
#	  USER_INCLUDES  - Additional include paths
#			   (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       To enable debugging:
#         set DEBUG_BUILD = 1 below, which will trigger OPTS=-g and
#          LDFLAGS += -g (may vary with compiler version, see compiler doc) 
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see grt.tlc

#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the build procedure (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

#MAKECMD         = D:\software\MATLAB2021b\bin/win64/gmake
MAKECMD         = make
HOST            = ANY
BUILD           = yes
SYS_TARGET_FILE = stacklite_dualdrive.tlc
#COMPILER_TOOL_CHAIN = unix

# Opt in to simplified format by specifying compatible Toolchain
#TOOLCHAIN_NAME = ["Clang v3.1 | gmake (64-bit Mac)", \
#             "GNU gcc/g++ v4.4.x | gmake (64-bit Linux)"]

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  S_FUNCTIONS         - List of S-functions.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  NUMST               - Number of sample times
#  TID01EQ             - yes (1) or no (0): Are sampling rates of continuous task
#                        (tid=0) and 1st discrete task equal.
#  NCSTATES            - Number of continuous states
#  COMPUTER            - Computer type. See the MATLAB computer command.
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  MAT_FILE            - yes (1) or no (0): Should mat file logging be done
#  GEN_MDLREF_SFCN     - (1/0): are we generating model reference wrapper s-function
#  TGT_FCN_LIB         - Target Funtion library to use
#  MODELREFS           - List of referenced models

MODEL                = StandTurn_Balance
MODULES              = StackLiteDualDrive_DataLinkInput.c StackLiteDualDrive_DataLinkOutput.c StackLiteDualDrive_Input.c StackLiteDualDrive_Output.c main.c rtGetInf.c rtGetNaN.c rt_nonfinite.c
MAKEFILE             = StandTurn_Balance.mk
MATLAB_ROOT          = D:\software\MATLAB2021b
ALT_MATLAB_ROOT      = D:\software\MATLAB2021b
MATLAB_BIN           = D:\software\MATLAB2021b\bin
MASTER_ANCHOR_DIR    = 
START_DIR            = D:\BaiduSyncdisk\000IFR\2022Balance\model\Task4\StandTurn_Balance
S_FUNCTIONS          = 
S_FUNCTIONS_LIB      = 
NUMST                = 1
TID01EQ              = 0
NCSTATES             = 0
COMPUTER             = PCWIN64
BUILDARGS            =  GENERATE_ERT_S_FUNCTION=0 INCLUDE_MDL_TERMINATE_FCN=1 INTEGER_CODE=0 GENERATE_ASAP2=0 EXT_MODE=0 EXTMODE_STATIC_ALLOC=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 EXTMODE_TRANSPORT=0 TMW_EXTMODE_TESTING=0 OPTS="-DTID01EQ=0"
MULTITASKING         = 0
MAT_FILE             = 0
MEXEXT               = mexw64
TGT_FCN_LIB          = ISO_C
MODELREFS            = 
SHARED_SRC           = 
SHARED_SRC_DIR       = 
SHARED_BIN_DIR       = 
SHARED_LIB           = 
TARGET_LANG_EXT      = c
OPTIMIZATION_FLAGS   = 
ADDITIONAL_LDFLAGS   = 
DEFINES_CUSTOM       = 
#SYSTEM_LIBS          = 
CODE_INTERFACE_PACKAGING = Nonreusable function

CLASSIC_INTERFACE    = 0
# Optional for GRT
ALLOCATIONFCN        = 0
ONESTEPFCN           = 1
TERMFCN              = 1
MULTI_INSTANCE_CODE  = 0

# To enable debugging:
# set DEBUG_BUILD = 1
DEBUG_BUILD          = 0

#--------------------------- Model and reference models -----------------------
MODELLIB                  = 
MODELREF_LINK_LIBS        = 
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref coder target
MODELREF_TARGET_TYPE       = NONE

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif
# MATLAB_ROOT := C:/MATLAB/2021b 这种耦合的语句应当删除

TARGET = $(MODEL)#这里保留，删除cubemx的定义， 注意后面不能带空格，否则会把空格也加入到变量中会报错 
REF_TARGET = $(MODELLIB)#$(MODEL)_rtwlib

#BUILD_DIR = build
#--------------------------- Tool Specifications -------------------------------

#删除原有耦合定义，使用cubemx生成的定义

#------------------------------ Include Path -----------------------------------

MATLAB_INCLUDES = \
	-I$(MATLAB_ROOT)/simulink/include \
	-I$(MATLAB_ROOT)/extern/include \
	-I$(MATLAB_ROOT)/rtw/c/src

# Additional file include paths
ADD_INCLUDES = \
	-I$(START_DIR) \
	-I$(START_DIR)\StandTurn_Balance_stm32_rtw \
	-I$(MATLAB_ROOT)\extern\include \
	-I$(MATLAB_ROOT)\simulink\include \
	-I$(MATLAB_ROOT)\rtw\c\src \
	-I$(MATLAB_ROOT)\rtw\c\src\ext_mode\common \
	-I$(MATLAB_ROOT)\rtw\c\ert \


SHARED_INCLUDES =
ifneq ($(SHARED_SRC_DIR),)
SHARED_INCLUDES = -I$(SHARED_SRC_DIR) 
endif
USER_INCLUDES = -I$(RELATIVE_PATH_TO_ANCHOR)/tlc_c #sfunction include、extern mode include
INCLUDES = -I. -I$(RELATIVE_PATH_TO_ANCHOR) $(MATLAB_INCLUDES) $(ADD_INCLUDES) $(USER_INCLUDES) \
	$(INSTRUMENT_INCLUDES)  $(MODELREF_INC_PATH) $(SHARED_INCLUDES)

#----------------------------- Real-Time Model ---------------------------------
RTM_CC_OPTS = -DUSE_RTMODEL
EXT_MODE=1
#-------------------------------- C Flags --------------------------------------

#删除原有定义，使用cubemx生成的标准定义

#-------------------------- Additional Libraries ------------------------------

#注释原有定义，使用cubemx生成的标准定义
#SYSTEM_LIBS += -lm 

#LIBS =
# 
#LIBS += $(S_FUNCTIONS_LIB) $(INSTRUMENT_LIBS)

#----------------------------- Source Files ------------------------------------
#删除OBJ定义，将simulink相关源文件统一到SIMULINK_SRCS变量中
USER_SRCS =$(MODEL).c
#$(MATLAB_ROOT)/rtw/c/src/rt_logging.c添加后报找不到头文件的错，暂时用不到他
SRCS = $(MODULES)#$(MODEL)_data.c main.c #2022.9删去$(MODULES) #2022.7删去$(S_FUNCTIONS)外部模式公共文件rtiostream_utils也存放在了这里#2022.6加入MODULES，tlc创建的文件名在此处 #2022.5不加入MODULES，sfunction壳函数不编译

#ifeq ($(MODELREF_TARGET_TYPE), NONE)
#    PRODUCT            = $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL)
#    BIN_SETTING        = $(LD) $(LDFLAGS) -o $(PRODUCT)
#    BUILD_PRODUCT_TYPE = "executable"
#else  
    # Model reference coder target
#    PRODUCT            = $(MODELLIB)
#    BUILD_PRODUCT_TYPE = "library"
#endif

#需判断非空，否则会创建/.o
ifneq ($(MODELREFS),)
#
#MODELREF_SRCS += $(START_DIR)/slprj/stm32f405//.c
#
#MODELREF_SRCS += $(START_DIR)/slprj/stm32f405//.c
#
MODELREFS := $(strip $(MODELREFS))
MODELREF_SRCS =$(START_DIR)/slprj/stacklite_dualdrive/$(MODELREFS)/$(MODELREFS).c
endif

ifneq ($(SHARED_SRC),)
SHARED_SRC := $(subst \,/, $(SHARED_SRC))
SHARED_SRC :=$(wildcard $(SHARED_SRC))
endif

SIMULINK_SRCS =$(USER_SRCS) $(SRCS) $(MODELREF_SRCS) $(SHARED_SRC)

#------------- Test Compile using gcc -Wall to look for warnings ---------------
#
# DO_GCC_TEST=1 runs gcc with compiler warning flags on all the source files
# used in this build. This includes the generated code, and any user source
# files needed for the build and placed in this directory.
#
# WARN_ON_GLNX=1 runs the linux compiler with warnings flags. On hand-written
# code we use the max amount of flags availabe while on the generated code, a
# few less.
#
# See rtw/c/tools/unixtools.mk for the definition of GCC_WARN_OPTS
#删除原有的不适用于windows的命令

#--------------------------------- Rules ---------------------------------------
#以下基于cubemx生成的makefile所修改
#began--------------------------------------------------------------
######################################
# target
######################################
#TARGET = makefile-stm32f405	#使用tmf定义的名称


######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og


#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

######################################
# source
######################################
# C sources
C_SOURCES =  \
../STM32CUBEMX/Core/Src/gpio.c \
../STM32CUBEMX/Core/Src/adc.c \
../STM32CUBEMX/Core/Src/dma.c \
../STM32CUBEMX/Core/Src/tim.c \
../STM32CUBEMX/Core/Src/usart.c \
../STM32CUBEMX/Core/Src/stm32f4xx_it.c \
../STM32CUBEMX/Core/Src/stm32f4xx_hal_msp.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_adc.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c \
../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c \
../STM32CUBEMX/Core/Src/system_stm32f4xx.c \
../STM32CUBEMX/Core/Src/uart_fifo.c \
../STM32CUBEMX/Core/Src/ifr-scope_device.c \
../STM32CUBEMX/Core/Src/ws2812.c \
$(SIMULINK_SRCS) 

# ASM sources
ASM_SOURCES =  \
../STM32CUBEMX/startup_stm32f405xx.s


#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
AR = $(GCC_PATH)/$(PREFIX)ar
else
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
AR = $(PREFIX)ar
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
 
#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m4

# fpu
FPU = -mfpu=fpv4-sp-d16

# float-abi
FLOAT-ABI = -mfloat-abi=hard

# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =  \
-DUSE_HAL_DRIVER \
-DSTM32F405xx \
-DARM_MATH_CM4 \
-D__TARGET_FPU_VFP

# AS includes
AS_INCLUDES = 

#以下添加相对路径
# C includes
C_INCLUDES =  \
-I../STM32CUBEMX/Core/Inc \
-I../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Inc \
-I../STM32CUBEMX/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy \
-I../STM32CUBEMX/Drivers/CMSIS/Device/ST/STM32F4xx/Include \
-I../STM32CUBEMX/Drivers/CMSIS/Include \
$(INCLUDES)


# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ARFLAGS = $(MCU) $(C_DEFS) $(INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = ../STM32CUBEMX/STM32F405RGTx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# default action: build all
ifeq ($(MODELREF_TARGET_TYPE),NONE)
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin dump download
else
REF_OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(MODULES:.c=.o)))
all: $(REF_TARGET)
endif

dump:
	arm-none-eabi-objdump -s -d $(BUILD_DIR)/$(TARGET).elf > $(BUILD_DIR)/$(TARGET).dis

#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

#下面需要把Makefile关键字删除 
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@
#	make -f $(MAKEFILE) download
	
$(BUILD_DIR):
	mkdir $@		

$(REF_TARGET): $(REF_OBJECTS)
	$(AR) -r $@ $(REF_OBJECTS)
	@echo success build $(REF_TARGET)

#$(CC) -c $(ARFLAGS) -o $(MODEL).o $<

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)
  
#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

#######################################
# Debug Download about
#######################################
# 芯片型号，用于JLink仿真调试、下载
CHIP := STM32F405RG

# 选择调试器 0为Jlink 1为DapLink
INTERFACE := 1

# 选择系统，0为Linux,1为Windows
SYS := 1
# 根据系统选择器调试器路径
ifeq ($(SYS), 1)
#GCC_PATH = ""
#JLINK_PATH = "/D/SEGGER/JLink_V612f"	#bash环境下使用此语句
JLINK_PATH = D:/SEGGER/JLink_V612f#powershell下使用此语句
OPENOCD_PATH = D:/openocd/OpenOCD-20211118-0.11.0/bin/openocd
endif

# JLink执行文件定义
ifdef JLINK_PATH
SUFFIX = .exe
JLINKEXE := $(JLINK_PATH)/JLink$(SUFFIX)
JLINKGDBSERVER :=  $(JLINK_PATH)/JLinkGDBServer$(SUFFIX)
else
JLINKEXE := "Jlink"
JLINKGDBSERVER := "JlinkGDBServer"
endif

.PHONY:download
ifeq ($(INTERFACE),0)
download:
	echo ### Created $(BUILD_DIR)/$(TARGET).hex success
	echo h > download.jlink
	echo r >> download.jlink
	echo Sleep 1 >> download.jlink
	echo loadfile $(BUILD_DIR)/$(TARGET).hex >> download.jlink
	echo r >> download.jlink
	echo qc >> download.jlink
	$(JLINKEXE) -device $(CHIP) -Speed 1000 -IF SWD -CommanderScript download.jlink
testdownload:
	echo h > testdownload.jlink
	echo r >> download.jlink
	echo Sleep 1 >> download.jlink
	echo loadfile testdownload.hex >> testdownload.jlink
	echo r >> testdownload.jlink
	echo qc >> testdownload.jlink
	$(JLINKEXE) -device $(CHIP) -Speed 1000 -IF SWD -CommanderScript testdownload.jlink
else
download:
	echo source [find interface/cmsis-dap.cfg] > stacklite-dualdrive.cfg
	echo transport select swd >> stacklite-dualdrive.cfg
	echo source [find target/stm32f4x.cfg] >> stacklite-dualdrive.cfg
	echo reset_config none >> stacklite-dualdrive.cfg
	$(OPENOCD_PATH) -f ./stacklite-dualdrive.cfg  -c init -c reset -c "sleep 1" -c halt -c "flash write_image erase $(BUILD_DIR)/$(TARGET).hex" -c reset -c shutdown
testdownload:
	echo source [find interface/cmsis-dap.cfg] > stacklite-dualdrive.cfg
	echo transport select swd >> stacklite-dualdrive.cfg
	echo source [find target/stm32f4x.cfg] >> stacklite-dualdrive.cfg
	echo reset_config none >> stacklite-dualdrive.cfg
	$(OPENOCD_PATH) -f ./stacklite-dualdrive.cfg  -c init -c reset -c "sleep 1" -c halt -c "flash write_image erase testdownload.hex" -c reset -c shutdown
endif
# *** EOF ***
#end--------------------------------------------------------------
#以下为原有对于.c .o的make描述，其中.c编译语句统一为了cubemx方式，路径未作修改
%.o : %.c
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

%.o : %.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) -c $(CPPFLAGS) "$<"

ifeq ($(CLASSIC_INTERFACE), 1)
ifeq ($(TARGET_LANG_EXT),cpp)
%.o : $(MATLAB_ROOT)/rtw/c/grt/%.c
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"
else
%.o : $(MATLAB_ROOT)/rtw/c/grt/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"
endif
else
ifeq ($(TARGET_LANG_EXT),cpp)
%.o : $(MATLAB_ROOT)/rtw/c/src/common/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/rtw/c/src/common/%.c
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"
else
%.o : $(MATLAB_ROOT)/rtw/c/src/common/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"
endif
endif

%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@
	
EXPAND_DIR_NAME=|>EXPAND_DIR_NAME<|
%.o : $(MATLAB_ROOT)\rtw\c\src/%.c
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

%.o : $(MATLAB_ROOT)\simulink\src/%.c
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@



%.o : $(MATLAB_ROOT)\rtw\c\src/%.cpp
	$(CPP) -c $(CPPFLAGS) "$<"
%.o : $(MATLAB_ROOT)\simulink\src/%.cpp
	$(CPP) -c $(CPPFLAGS) "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) -c $(CPPFLAGS) "$<"


#------------------------------- Libraries -------------------------------------





#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

$(SHARED_LIB) : $(SHARED_OBJS)
	@echo "### Creating $@ "
	$(AR) ruvs $@ $(SHARED_OBJS)
	@echo "### $@ Created  "

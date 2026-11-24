cmake_minimum_required(VERSION 3.10)
project(AutosarBcmSilFramework C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Werror -pedantic)
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/rte
    ${PROJECT_SOURCE_DIR}/bsw
    ${PROJECT_SOURCE_DIR}/swc
)

set(ECU_SOURCES
    swc/BcmWindowControl_SWC.c
    rte/Rte_BcmControl.c
    bsw/CanIf.c
    bsw/Dcm_Uds.c
    sil_framework/sil_ecu_runner.c
)

add_executable(bcm_sil_ecu ${ECU_SOURCES})

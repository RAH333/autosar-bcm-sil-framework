# autosar-bcm-sil-framework
AUTOSAR-compliant Body Control Module (BCM) Software Component (Power Window &amp; Exterior Lighting Control) in Embedded C with CAN/LIN &amp; UDS diagnostics, CMake build system, Python SIL test automation framework, and GitHub Actions CI/CD.




# AUTOSAR Body Control Module (BCM) & Automated SIL Test Framework

An **AUTOSAR-compliant Body Control Module (BCM)** power window control Software Component (`BcmWindowControl_SWC`) implemented in **MISRA-compliant Embedded C**, paired with a data-driven **Python Software-in-the-Loop (SIL) Test Framework**, **ISO 14229 UDS Diagnostics**, **CMake**, and **GitHub Actions CI/CD**.

## Key Features
* **AUTOSAR Layered Architecture:** Clean separation between Application SWC (`swc/`), Runtime Environment (`rte/`), and Basic Software modules (`CanIf`, `Dcm_Uds`).
* **Anti-Pinch Safety Logic:** Monitors window motor current thresholds in a 10ms cyclic runnable and reverses motor actuation upon obstruction detection.
* **UDS Diagnostics (ISO 14229):** Supports Service `0x22` (*ReadDataByIdentifier*) and Service `0x14` (*ClearDiagnosticInformation*).
* **Data-Driven Python SIL Framework:** Executes JSON-defined test vectors against the compiled C ECU binary with automated CI/CD verification.

## Quick Start (Build & Run SIL Tests)
```bash
cmake -B build -S .
cmake --build build
python3 sil_framework/run_sil_suite.py
```



```
autosar-bcm-sil-framework/
├── .github/
│   └── workflows/
│       └── bcm_sil_ci.yml
├── bsw/
│   ├── CanIf.c
│   ├── CanIf.h
│   ├── Dcm_Uds.c
│   └── Dcm_Uds.h
├── rte/
│   ├── Rte_BcmControl.c
│   ├── Rte_BcmControl.h
│   └── Rte_Type.h
├── swc/
│   ├── BcmWindowControl_SWC.c
│   └── BcmWindowControl_SWC.h
├── sil_framework/
│   ├── sil_ecu_runner.c
│   ├── test_cases.json
│   └── run_sil_suite.py
├── CMakeLists.txt
└── README.md
```

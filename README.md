# autosar-bcm-sil-framework
AUTOSAR-compliant Body Control Module (BCM) Software Component (Power Window &amp; Exterior Lighting Control) in Embedded C with CAN/LIN &amp; UDS diagnostics, CMake build system, Python SIL test automation framework, and GitHub Actions CI/CD.

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

import json
import os
import subprocess
import sys

EXECUTABLE = os.path.join("build", "bcm_sil_ecu")
if os.name == "nt":
    EXECUTABLE += ".exe"

TEST_CONFIG = os.path.join("sil_framework", "test_cases.json")

def execute_ecu_step(switch_cmd: int, motor_current: int) -> dict:
    proc = subprocess.run(
        [EXECUTABLE, str(switch_cmd), str(motor_current)],
        capture_output=True,
        text=True,
        check=True
    )
    for line in proc.stdout.splitlines():
        if line.startswith("SIL_TELEMETRY|"):
            fields = line.split("|")[1:]
            return {item.split(":")[0]: item.split(":")[1] for item in fields}
    raise RuntimeError("SIL_TELEMETRY output missing from ECU binary.")

def main():
    with open(TEST_CONFIG, "r", encoding="utf-8") as f:
        test_cases = json.load(f)

    print("===============================================================")
    print("  AUTOSAR BCM Window Control - Automated SIL Test Suite")
    print("===============================================================")

    passed = 0
    for tc in test_cases:
        telemetry = execute_ecu_step(tc["switch_cmd"], tc["motor_current_ma"])
        actual_state = int(telemetry["MOTOR_STATE"])
        actual_faults = int(telemetry["PINCH_FAULTS"])
        actual_uds_sid = telemetry["UDS_SID"]

        is_pass = (
            actual_state == tc["expected_motor_state"] and
            actual_faults == tc["expected_pinch_faults"] and
            actual_uds_sid == tc["expected_uds_sid"]
        )

        status = "PASS" if is_pass else "FAIL"
        print(f"[{status}] {tc['id']}: {tc['description']} -> State={actual_state}, Faults={actual_faults}, UDS={actual_uds_sid}")
        if is_pass:
            passed += 1

    print("---------------------------------------------------------------")
    print(f"Total Passed: {passed}/{len(test_cases)} ({(passed/len(test_cases))*100:.0f}% Pass Rate)")
    print("===============================================================")
    sys.exit(0 if passed == len(test_cases) else 1)

if __name__ == "__main__":
    main()
  

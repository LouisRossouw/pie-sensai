# === Config ===

# Board / port
# FQBN = esp32:esp32:esp32c3
FQBN=esp32-bluepad32:esp32:lolin_c3_mini
PORT = COM6
BAUD = 115200

# Arduino CLI
ARDUINO_CLI = arduino-cli

# === Sketch paths ===
SENSAI_SKETCH = sensai-beacon/sensai-beacon.ino
MONITOR_SKETCH = sensai-monitor/sensai-monitor.ino
TEST_SKETCH = test/test.ino

# === Commands ===
.PHONY: all sensai-beacon build-sensai-beacon build-sensai-monitor upload-sensai upload-monitor serial clean info 

all: sensai sensai-monitor

sensai-beacon: build-sensai-beacon upload-sensai monitor
sensai-monitor: build-sensai-monitor upload-monitor monitor

# --- Build targets ---
build-sensai-beacon:
	$(ARDUINO_CLI) compile --fqbn $(FQBN) --libraries lib $(SENSAI_SKETCH)

build-sensai-monitor:
	$(ARDUINO_CLI) compile --fqbn $(FQBN) --libraries lib $(MONITOR_SKETCH)

# --- Upload targets ---
upload-sensai:
	$(ARDUINO_CLI) upload -p $(PORT) --fqbn $(FQBN) $(SENSAI_SKETCH)

upload-monitor:
	$(ARDUINO_CLI) upload -p $(PORT) --fqbn $(FQBN) $(MONITOR_SKETCH)

# --- Monitor serial ---
monitor:
	$(ARDUINO_CLI) monitor -p $(PORT) --fqbn $(FQBN) --config baudrate=$(BAUD)
# --- Cleanup ---
clean:
	rm -rf build .arduino*

# --- Board info ---
info:
	$(ARDUINO_CLI) board list


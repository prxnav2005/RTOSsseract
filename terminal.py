import serial
import threading
import sys
import os
import time
import readline

PORT = "/dev/ttyUSB1"   
BAUD = 115200
LOG_FILE = "rto_shell.log"

def log_output(data):
    with open(LOG_FILE, "a") as f:
        f.write(data)

def read_serial(ser):
    while True:
        try:
            data = ser.read().decode(errors='ignore')
            if data:
                print(data, end='', flush=True)
                log_output(data)
        except:
            break

def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

def main():
    ser = None
    while ser is None:
        try:
            ser = serial.Serial(PORT, BAUD, timeout=0.1)
            print(f"[CONNECTED] {PORT} at {BAUD} baud")
        except serial.SerialException:
            print(f"Waiting for {PORT}...")
            time.sleep(1)

    # Clear log on new session
    open(LOG_FILE, 'w').close()

    # Start background UART listener
    reader = threading.Thread(target=read_serial, args=(ser,), daemon=True)
    reader.start()

    try:
        while True:
            # readline gives you nice arrow-key support
            line = input(">>> ") + "\r"
            ser.write(line.encode())
            log_output(f">>> {line}")
    except KeyboardInterrupt:
        print("\n[EXIT]")
    finally:
        ser.close()

if __name__ == "__main__":
    clear_screen()
    print(" Welcome to RTOSsseract Shell ")
    print("Type commands or Ctrl+C to exit.\n")
    main()

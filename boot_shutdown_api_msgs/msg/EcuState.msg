uint16 UNKNOWN = 0
uint16 STARTUP = 1
uint16 RUNNING = 2
uint16 SHUTDOWN_PREPARING = 3
uint16 SHUTDOWN_READY = 4
uint16 STARTUP_TIMEOUT = 1001
uint16 SHUTDOWN_TIMEOUT = 1002

uint16 state
string name
string message
builtin_interfaces/Time power_off_time  # Invalid value except for SHUTDOWN_READY

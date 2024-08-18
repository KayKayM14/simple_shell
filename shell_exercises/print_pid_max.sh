#!/bin/bash

# Read the max PID value from /proc/sys/kernel/pid_max
max_pid=$(cat /proc/sys/kernel/pid_max)

# print the max PID value
echo "The max value a process ID can be is: $max_pid"

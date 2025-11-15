#!/bin/bash


ARCHITECTURE=$(uname -a)
PCPU=$(grep -c "physical id" /proc/cpuinfo)
VCPU=$(grep -c "^processor" /proc/cpuinfo)
MEM_USAGE=$(free -m | awk '/Mem:/ {printf "%d/%dMB (%.2f%%)", $3, $2, $3/$2*100}')
DISK_USAGE=$(df -BM | awk '/^\/dev\// {u+=$3; t+=$2} END {printf "%d/%dGb (%.2f%%)", u, t/1024, u/t*100}')
LVM_USAGE=$(lsblk | grep -q "lvm" && echo "yes" || echo "no")
CPU_LOAD=$(iostat | awk '/avg-cpu/ {getline; printf("%.1f%%", 100-$6)}')
LAST_BOOT=$(who -b | awk '{print $3" "$4}')
TCP=$(ss -t state established | tail -n +2 | wc -l)
USER_LOG=$(who | awk '{print $1}' | sort -u | wc -l)
IP=$(hostname -I)
MAC=$(ip link show | awk '/link\/ether/ {print $2}')
SUDO=$(journalctl -q _COMM=sudo | grep -c "COMMAND")


wall "
#Architecture : $ARCHITECTURE 
#CPU physical : $PCPU 
#vCPU : $VCPU
#Memory Usage : $MEM_USAGE
#Disk Usage : $DISK_USAGE
#CPU load : $CPU_LOAD
#Last boot : $LAST_BOOT
#LVM use : $LVM_USAGE
#Connections TCP : $TCP ESTABLISHED
#User log : $USER_LOG
#Network : IP $IP ($MAC)
#Sudo : $SUDO cmd
"

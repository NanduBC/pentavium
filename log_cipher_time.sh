#!/bin/bash
# Create log files for benchmarking purposes
var=$(date +"%Y-%m-%dT%H:%M:%S")
echo $var
while [ -n "$1" ]; do
	case "$1" in 
	-h) echo "Usage: ./log_cipher_time.sh -h";
		echo "       ./log_cipher_time.sh [-p] [-c]";;
	-c) gcc time_comparison.c -o time_comparison;
		FILENAME="benchmark/$var-c.txt";
		touch $FILENAME;
		./time_comparison > $FILENAME;;
	-p) FILENAME="benchmark/$var-py.txt";
		touch $FILENAME;
		python time_comparison_script.py > $FILENAME;;
	*) echo "Invalid option"
		echo "Usage: ./log_cipher_time.sh -h" ;
		echo "       ./log_cipher_time.sh [-p] [-c]"
	esac
	shift
done
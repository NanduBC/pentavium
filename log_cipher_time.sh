#!/bin/bash
# Create log files for benchmarking purposes
var=$(date +"%Y-%m-%dT%H:%M:%S")
iterations=100000000
while [ "$1" != "" ]; do
	case "$1" in 
	-h) echo "Usage: ./log_cipher_time.sh -h";
		echo "       ./log_cipher_time.sh -i <iterations> [-c] [-p]";;
	-i|--iter) iterations=$2
		shift
		;;
	-c) gcc time_comparison.c -o time_comparison;
		FILENAME="benchmark/$var-c.txt";
		touch $FILENAME;
		./time_comparison $iterations > $FILENAME;;
	-p) FILENAME="benchmark/$var-py.txt";
		touch $FILENAME;
		python time_comparison_script.py $iterations > $FILENAME;;
	*) echo "Invalid option"
		echo "Usage: ./log_cipher_time.sh -h" ;
		echo "       ./log_cipher_time.sh -i <iterations> [-c] [-p]";;
	esac
	shift
done
#!/bin/bash

counter=0
while IFS='' read -r line || [[ -n "$line" ]]; do
	if [ $counter = 9 ]; then
		echo "$line"
	fi
	counter=$(( $counter + 1))
done < "$1"

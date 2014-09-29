#!/bin/bash
arg=$1
#-std=c++0x #-std=c++11
flag="-std=c++0x"
if [ "x$arg" != "x" ];then
	if [ "x$arg" != "xclean" ];then
		echo "Usage '$0 clean' or '$0'"
	else
		for f in $(ls *.cpp); do
			object=`echo $f | sed 's/\.cpp//g'`
			if [ -f $object ];then
				echo "rm $object"
				rm $object
			fi
		done
	fi
else
	for f in $(ls *.cpp); do
		object=`echo $f | sed 's/\.cpp//g'`
		fdate=`stat -c %Y $f`
		objdate=`stat -c %Y $object 2>/dev/null`
		if [ "x$fdate" != "x$objdate" ];then
			#echo "g++ $f -o $object"
			#g++ $f -o $object
			echo "g++ $flag $f -o $object"
			g++ $flag $f -o $object

			if [ -f $object ];then
				touch -r $f $object
			fi
		fi
	done
fi


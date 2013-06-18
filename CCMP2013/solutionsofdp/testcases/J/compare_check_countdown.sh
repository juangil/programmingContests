#!/bin/bash 
# usage: sh compare_check testcase_input program_output testcase_output

function WrongAnswer()
{
cat >result.xml <<EOF
<?xml version="1.0"?>
<!DOCTYPE result [
<!ELEMENT result (#PCDATA)>
<!ATTLIST result outcome CDATA #REQUIRED>
]>
<result outcome="Wrong Answer">Wrong Answer</result>
EOF
}

function Accepted()
{
cat >result.xml <<EOF
<?xml version="1.0"?>
<!DOCTYPE result [
<!ELEMENT result (#PCDATA)>
<!ATTLIST result outcome CDATA #REQUIRED>
]>
<result outcome="Accepted">Accepted</result>
EOF
}


# MAIN

TEST_INPUT="$1"
PROGRAM_OUTPUT="$2"
TEST_OUTPUT="$3"

CLASSPATH="$CLASSPATH:/opt/domjudge/judgehost/lib/judge"
export CLASSPATH

WrongAnswer

#if [ ! -x checker_countdown ] ; then
#	gcc -O2 -Wall checker_countdown.c -o checker_countdown
#fi
#
#./checker_countdown ${PROGRAM_OUTPUT}  ${TEST_OUTPUT}

if [ ! -f CountDownChecker.class ] ; then
	javac CountDownChecker.java
fi

#echo " 1 " ${TEST_INPUT}
#echo " 2 " ${PROGRAM_OUTPUT}
#echo " 3 " ${TEST_OUTPUT}

java CountDownChecker ${PROGRAM_OUTPUT}  ${TEST_OUTPUT}

exit 0

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

java BasicSolution <${TEST_INPUT} --check-solutions ${PROGRAM_OUTPUT} 

exit 0

#!/bin/bash

# p3: display the current logged in user and log name
# p4: display current shell, home dir, OS, current path, current working dir
# p5: display OS version, release number, and kernel version

# Q1:
echo User: $(whoami)
echo
echo

# Q2:
echo SHELL: $SHELL
echo home dir: $HOME
echo OS: $(lsb_release -is)
echo current path: $(pwd)
echo
echo

# Q3:
echo OS Version: $(lsb_release -rs)
echo Release number: $(uname -r)
echo Kernel version: $(uname -v)

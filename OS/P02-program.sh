#!/bin/bash

# display the current logged in user and log name
# display current shell, home dir, OS, current path, current working dir
# display OS version, release number, and kernel version

# Q1:
echo User: $(whoami)
echo

# Q2:
echo SHELL: $SHELL
echo home dir: $HOME
echo OS: $(lsb_release -is)
echo current path: $(pwd)
echo

# Q3:
echo OS Version: $()
echo Release number: $(lsb_release -rs)
echo kernel version: $(uname -r)

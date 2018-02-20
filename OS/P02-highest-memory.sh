#!/bin/bash
#display process with highest memory usage

ps -aux | sort -rk 4 | head -2

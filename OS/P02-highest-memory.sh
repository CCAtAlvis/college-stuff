#!/bin/bash
#display process with highest memory usage

ps -aux | sort -rk4 | head -2

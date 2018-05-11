#!/bin/bash
# write a shell script to diaplay top 10 process in descending order

ps -e | sort -rk4 | head -10

# sort: to sort the data
# -r: to sort in reverse order
# -k: to sort according to a particular column, followed by the column index (starts from 1)
# head: to limit the entries, followed by no. of entries

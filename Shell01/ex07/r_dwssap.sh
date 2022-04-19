#!/bin/bash
cat /etc/passwd | sed '/^#/d' | awk 'NR%2==0' | awk -F: '{print $1}' | rev | sort -r | awk "FNR>=$FT_LINE1&&FNR<=$FT_LINE2" | sed 's/$/, /' | tr -d '\n' | sed 's/..$/./' | tr -d '\n'

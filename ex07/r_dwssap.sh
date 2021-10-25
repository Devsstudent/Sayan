#!/bin/bash
export FT_LINE1 && export FT_LINE2 | cat /etc/passwd | sed 's/[:].*//g' | sed 's/^#//g' | awk 'NR>=2 && NR%2==0 {print $0}' | rev | sort -r | awk -v comma=, 'NR<=ENVIRON["FT_LINE2"] && NR>=ENVIRON[FT_LINE1]  {print $1 comma}' | tr '\n' ' ' | sed 's/, $/./'

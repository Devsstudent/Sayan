#!/bin/bash
find ./ -regextype posix-basic -regex '^./.*.sh$' | sed -E 's/.sh$//g' | sed -E 's/^.\///g'

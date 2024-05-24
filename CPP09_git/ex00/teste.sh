#!/bin/bash

whiteSpace = '             '

mkdir aDirectory
touch permissionDeniedFile emptyFile whiteSpacesFile
chmod 000 permissionDeniedFile
cat "$whiteSpace" > whiteSpaceFile


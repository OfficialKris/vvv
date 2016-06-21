#!/bin/bash

# this script creates the distribution package for VVV

PROGRAM_NAME="VVV"

# change here the version number
VERSION="1.2.9"

# changest the file name based on the package being 32 or 64 bit
NBITS=`getconf LONG_BIT`

if [ $NBITS == 64 ]; then
  mkdir ${PROGRAM_NAME}-${VERSION}-x86_64
  rm ${PROGRAM_NAME}-${VERSION}-x86_64/*
  cp -r ../installed_output/* ${PROGRAM_NAME}-${VERSION}-x86_64/
else
  mkdir ${PROGRAM_NAME}-${VERSION}-i386
  rm ${PROGRAM_NAME}-${VERSION}-i386/*
  cp -r ../installed_output/* ${PROGRAM_NAME}-${VERSION}-i386/
fi

if [ $NBITS == 64 ]; then
  rm ${PROGRAM_NAME}-${VERSION}-x86_64.tar.gz
  tar cvzf ${PROGRAM_NAME}-${VERSION}-x86_64.tar.gz ${PROGRAM_NAME}-${VERSION}-x86_64/
  rm -r ${PROGRAM_NAME}-${VERSION}-x86_64
else
  rm ${PROGRAM_NAME}-${VERSION}-i386.tar.gz
  tar cvzf ${PROGRAM_NAME}-${VERSION}-i386.tar.gz ${PROGRAM_NAME}-${VERSION}-i386/
  rm -r ${PROGRAM_NAME}-${VERSION}-i386
fi



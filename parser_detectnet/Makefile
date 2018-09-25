################################### tell Emacs this is a -*- makefile-gmake -*-
#
# Copyright (c) 2018 NVIDIA CORPORATION.  All Rights Reserved.
#
# NVIDIA CORPORATION and its licensors retain all intellectual property
# and proprietary rights in and to this software, related documentation
# and any modifications thereto.  Any use, reproduction, disclosure or
# distribution of this software and related documentation without an express
# license agreement from NVIDIA CORPORATION is strictly prohibited.
#
# Makefile for compiling on host
#
#
#
###############################################################################

CC:= g++
TARGET_NAME:= libnvparsebbox.so
INSTALL_DIR:=.

SRCS:= nvparsebbox.cpp
OBJS:= nvparsebbox.o

CFLAGS += -std=c++11 -fPIC
LDFLAGS:= -shared

LIBS:= -lnvinfer -lnvcaffe_parser

all:
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(TARGET_NAME) $(OBJS) $(LIBS) $(LDFLAGS)
	rm *.o

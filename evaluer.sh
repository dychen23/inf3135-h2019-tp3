#!/bin/bash

grep -c -e 'default :' -e 'default:' Makefile
gtimeout 5s make
gtimeout 20s make data


#!/bin/bash

kill -9  `ps aux | grep "tp3" | awk '{print $2}'`
 


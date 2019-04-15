#!/bin/bash

kill -9  `ps aux | grep root | grep "evaluer" | awk '{print $2}'`
 


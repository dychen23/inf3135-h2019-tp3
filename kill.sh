#!/bin/bash

kill -9  `ps aux | grep "evaluer" | awk '{print $2}'`
 


#!/bin/bash
cat $1 | grep -iw redpill | sed "s/redpill/bluepill/I"

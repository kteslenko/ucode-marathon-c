#!/bin/bash
while getopts "c:e:" opt; do
    case $opt in
        c)
            shift $((OPTIND-1))
            tar -cf $OPTARG $*
            ;;
        e)
            tar -xf $OPTARG
            ;;
    esac
done

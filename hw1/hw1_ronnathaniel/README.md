
# Homework 1 
#### Linux assembly inlining and setting up Linux Cross Referencer LXR 

## Table of Contents
 - [Structure](#structure)
 - [1. Install LXR](#install-lxr)
 - [2. Substring Extraction](#substring-extraction)
 - [Copyright](#copyright)
 
## Structure

Attached are several files which are named as follows:

    .
    ├── Dockerfile.lxr                  - Dockerfile for containerized LXR
    ├── README.md   
    ├── img                             - all img
    │    └── subextract_invocation.png
    ├── install_lxr.sh                  - Bash Script to install LXR
    └── subextract.c                    - Substring Extraction

## Install LXR

Choose to install LXR by simply invoking 
    
    #! sh
    $ ./install_lxr.sh [<VERSION>]
    
This will cause LXR to install at version `2.0.0` by default.

The author chose this version as best for his setup, but a client may have other versions in mind. 

Change Installation Version by passing in a version string as an arg. For version `1.0.0` as an example:

    #! sh
    $ ./install_lxr.sh 1.0.0
    
and manually enter *only* what cannot be defaulted.
 
-- Important Notice:

The author at the time of writing had no access to a linux machine, much less a personal computer. 
As the author was forced to work on his employer's Macbook, he could not dual boot or access an ubuntu or fedora machine.
For this reason- the author chose to containerize the application and make it work despite the circumstances.

The author appreciates your recognition of his perseverance.

## Substring Extraction

Invoke the program in the same way as the author:

    #! sh
     $ gcc subextract.c -o subextract && ./subextract

And see the expected output:

    loWorl
    loWorl
    Strings Are Equal.

To confirm both methods work as expected.

## Copyright

All Rights Reserved.
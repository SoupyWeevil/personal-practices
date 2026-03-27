#!/bin/bash

#Created by Brandon Vandergriff
#Date of Creation: November 2024
#Comments modified by April Crockett
#Date of Modification: February 2025

# Check if Homebrew is installed.
# Homebrew is a package manager for macOS that we need to install GCC.
which -s brew 
if [[ $? != 0 ]] ; then
    # If Homebrew is not found, install it.
    echo "Homebrew not found on this Mac, installing Homebrew"
    curl -fsSL "https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh" | bash
else
    # If Homebrew is already installed, proceed with installing GCC.
    echo "Homebrew found, installing GCC" 
fi

# Pause execution to allow Homebrew installation to complete.
read -p "Once Homebrew finishes installing, press enter. " 

# Remove existing macOS Command Line Tools to resolve potential <wchar.h> not found error.
sudo rm -rf /Library/Developer/CommandLineTools

# Prompt user to install macOS Command Line Tools (Xcode CLI tools).
echo "The next command will open a box on your Dock. Click on it, and select Yes. This will take a few minutes."
xcode-select --install

# Pause execution until the user confirms that the installation is complete.
read -p "Press enter when that command finishes. "

# Install GCC via Homebrew, since macOS does not ship with an OpenMP-ready GCC by default.
echo "Finally, we will install GCC."
brew install gcc

# Pause execution until the user confirms that GCC installation is complete.
read -p "Press enter when GCC finishes installing. "

# Ensure /usr/local/bin is included in the system PATH to access installed binaries.
PATH=/usr/local/bin:$PATH

# Attempt to compile the program and check for the correct GCC version.
echo "I will now try to compile the file for you."

# Check if g++-14 is installed.
which -s g++-14
if [[ $? != 0 ]] ; then
    # If g++-14 is not found, instruct the user to check for available versions.
    echo "g++-14 not found. Please find the correct g++ version below, and your compilation will use the version you find."
    echo "Run the following command with the correct version you find: g++-XX parallel.cpp -std=c++20 -fopenmp -D_GLIBCXX_PARALLEL -o parallel_v"
    ls /usr/local/bin | grep "g++"
else 
	# If g++-14 is found, provide the correct compilation command.
	echo "G++-14 found! When you compile, use the following command:"
    echo "g++-14 program2.cpp -std=c++20 -fopenmp -D_GLIBCXX_PARALLEL -o program2"
fi

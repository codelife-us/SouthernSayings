# Southern Sayings

A collection of Southern sayings with their meanings - a C++ command line application.

## Description

Southern Sayings is a command-line program that displays a curated collection of traditional Southern expressions, their meanings, and cultural context. Perfect for those interested in Southern culture and colorful language!

## Building

To compile the program, use the provided build task:


For Mac
```bash
clang++ -std=c++20 -stdlib=libc++ -fcolor-diagnostics -fansi-escape-codes -g southernsayings.cpp -o southernsayings
```
For Linux
```bash
g++ -std=c++20 southernsayings.cpp -o southernsayings
```

## Usage

```
./southernsayings [OPTIONS]
```

### Options

- `-1, --one` - Display a single random saying
- `-s, --separate` - Separate lines format: saying on one line, meaning on the next, then a blank line (useful for readable output)
- `-c, --color` - Colored output: pink for saying, orange for meaning
- `-h, --help` - Display this help message
- *(none)* - Display all sayings in shuffled order

### Examples

```bash
# Display all sayings shuffled
./southernsayings

# Display one random saying
./southernsayings -1

# Display all sayings with colors and separate lines
./southernsayings --color --separate

# Display one random saying in color
./southernsayings --one --color

# Get help
./southernsayings -h
```

## Features

- 200+ Southern sayings with detailed meanings
- Random selection or display all options
- Colored output support (pink for sayings, orange for meanings)
- Separate line formatting for better readability
- Automatic shuffling of sayings
- Helpful command-line interface with built-in help

## License

This project is licensed under the MIT License - see the file header or LICENSE for details.

## Author

Created by Code Life

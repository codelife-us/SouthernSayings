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

- `-h, --help` - Display this help message
- *(none)* - Display one random saying
- `-a, --all` - Display all sayings shuffled
- `-1, --oneline` - Display saying and meaning on one line with colon separator
- `-c, --color` - Colored output: pink for saying, orange for meaning
- `-nm, --nomeaning` - Display only the saying without the meaning
- `     --polite` - Display only polite sayings
- `-p, --pick [number]` - Display a specific saying by number
- `-sn, --shownumber` - Display the unique saying number in brackets
- `-j, --json` - Output the full collection in JSON format
- `--csv` - Output the full collection in CSV format

### Examples

```bash
# Display one random saying
./southernsayings
# Display all sayings shuffled
./southernsayings -a
# Display one random sayings in colors
./southernsayings --color
# Display all sayings shuffled with colors on one line
./southernsayings -a --color -t
# Display one random saying without the meaning and show the number
./southernsayings -nm -sn
# Get help
./southernsayings -h
```

## Features

- 392 Southern sayings with detailed meanings
- Random selection or display all sayings
- Colored output support (pink for sayings, orange for meanings)
- Separate line formatting option for more compact format
- Automatic shuffling of sayings
- Helpful command-line interface with built-in help

## License

This project is licensed under the MIT License - see the file header or LICENSE for details.

## Author

Created by Code Life

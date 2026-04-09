# Southern Sayings

A collection of Southern sayings with their meanings - a C++ command line application.

## Description

Southern Sayings is a command-line program that displays a curated collection of traditional Southern expressions, their meanings, and cultural context. Perfect for those interested in Southern culture and colorful language!

## Building

To compile the program, use the provided build task:

For Mac

```bash
clang++ southernsayings.cpp -o southernsayings
```

For Linux

```bash
g++ southernsayings.cpp -o southernsayings
```

## Usage

```
./southernsayings [OPTIONS]
```

### Options

- `-h, --help` - Display this help message
- _(none)_ - Display one random saying
- `-a, --all` - Display all sayings shuffled
- `-1, --oneline` - Display saying and meaning on one line with colon separator
- `-nc, --nocolor` - Disable colored output (color by default and pink for saying, orange for meaning)
- `-nm, --nomeaning` - Display only the saying without the meaning
- `     --polite` - Display only polite sayings
- `     --showcategory` - Display the category before the saying
- `     --category [name]` - Filter by category (advice, appearance, emotions, expressions, family, food, intelligence, laziness, relationships, money)
- `-p, --pick [number]` - Display a specific saying by number
- `-sn, --shownumber` - Display the unique saying number in brackets
- `-j, --json` - Output the full collection in JSON format
- `--csv` - Output the full collection in CSV format
- `--appinfo` - Display the app version links

### Examples

```bash
# Display one random saying
./southernsayings
# Display all sayings shuffled
./southernsayings -a
# Display one random saying without colors
./southernsayings --nocolor
# Display all sayings shuffled without colors on one line
./southernsayings -a -nc -1
# Display one random saying without the meaning and show the number
./southernsayings -nm -sn
# Display only polite sayings and show categories
./southernsayings -a --polite --showcategory
# Get help
./southernsayings -h
```

## Features

- 450 Southern sayings with meanings
- Random selection or display all sayings
- Colored output by default (pink for sayings, orange for meanings), disable with `--nocolor`
- Separate line formatting option for more compact format
- Automatic shuffling of sayings
- Output to JSON or CSV
- Polite filter can be used to show only for polite company
- Filter on category and optional display of category
- Helpful command-line interface with built-in help

## License

This project is licensed under the MIT License - see the file header or LICENSE for details.

## Author

Created by Code Life

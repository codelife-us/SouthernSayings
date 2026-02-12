// MIT License
//
// Copyright (c) 2026 Code Life
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// Southern Sayings - command line version using modern C++
// A collection of Southern sayings with their meanings.
//     version 1.4 - 2/3/2026
//     version 1.5 - 2/7/2026 - new option --polite to exclude sayings that aren't suitable for polite company
//     version 1.6 - 2/10 - 2/11/2026 - new option and sayings added
//     version 1.7 - 2/12/2026 - moved data into a separate header file and added more sayings
//

#include <array>
#include <string>
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <numeric>
#include "southernsayingsdata.h" // contains the array of sayings

using namespace std;

void outputSaying(const Saying& saying, int sayingIndex, bool separateLines = false, bool colored = false, bool noMeaning = false, bool showNumber = false) {
    string sayingColor = "\033[35m";  // pink
    string meaningColor = "\033[33m"; // orange
    string resetColor = "\033[0m";    // no color
    string label = showNumber ? "[" + to_string(sayingIndex + 1) + "] " : "";
    if (!colored) {
        sayingColor = meaningColor = resetColor = "";
    }
    if (noMeaning) {
        cout << label << sayingColor << saying.text << resetColor << "\n";
        if (separateLines) cout << "\n";
    } else {
        if (separateLines) {
            cout << label << sayingColor << saying.text << resetColor << "\n"
                 << meaningColor << saying.meaning << resetColor << "\n\n";
        } else {
            cout << label << sayingColor << saying.text << resetColor << ": "
                 << meaningColor << saying.meaning << resetColor << "\n";
        }
    }
}

void displayHelp() {
    cout << "Southern Sayings - A collection of Southern sayings with their meanings\n\n";
    cout << "Usage: ./southernsayings [OPTIONS]\n\n";
    cout << "Options:\n";
    cout << "  (none)               Display a single random saying (default)\n";
    cout << "  -a, --all            Display all sayings in shuffled order\n";
    cout << "  -1, --oneline        Display saying and meaning on one line with colon separator\n";
    cout << "  -c, --color          Colored output: pink for saying, orange for meaning\n";
    cout << "  -nm, --nomeaning     Display only the saying without the meaning\n";
    cout << "  -sn, --shownumber    Display the unique saying number in brackets\n";
    cout << "  -p, --pick [number]  Display a specific saying by number\n";
    cout << "      --polite         Display only sayings suitable for polite company\n";
    cout << "  -j, --json           Output all sayings in JSON format\n";
    cout << "  --csv                Output all sayings in CSV format\n";
    cout << "      --appinfo        Display links to the app version\n";
    cout << "  -h, --help           Display this help message\n";
}

// Helper to escape characters for JSON output
string escapeJSON(const string& s) {
    string res;
    for (char c : s) {
        if (c == '"') res += "\\\"";
        else if (c == '\\') res += "\\\\";
        else if (c == '\b') res += "\\b";
        else if (c == '\f') res += "\\f";
        else if (c == '\n') res += "\\n";
        else if (c == '\r') res += "\\r";
        else if (c == '\t') res += "\\t";
        else res += c;
    }
    return res;
}

// Helper to escape characters for CSV output
string escapeCSV(const string& s) {
    string res = "\"";
    for (char c : s) {
        if (c == '"') res += "\"\"";
        else res += c;
    }
    res += "\"";
    return res;
}

int main(int argc, char* argv[]) {
    bool together = false, showAll = false, colored = false, noMeaning = false, showNumber = false, pickSpecific = false;
    bool politeOnly = false;
    bool impoliteOnly = false; // unadvertised option
    bool jsonOutput = false, csvOutput = false;
    bool appInfo = false; // show links to app version
    int pickedNumber = -1;

    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-1" || arg == "--oneline") together = true;
        else if (arg == "-a" || arg == "--all") showAll = true;
        else if (arg == "-c" || arg == "--color") colored = true;
        else if (arg == "-nm" || arg == "--nomeaning") noMeaning = true;
        else if (arg == "-sn" || arg == "--shownumber") showNumber = true;
        else if (arg == "--polite") politeOnly = true;
        else if (arg == "--impolite") impoliteOnly = true;
        else if (arg == "--appinfo") appInfo = true;
        else if (arg == "-j" || arg == "--json") jsonOutput = true;
        else if (arg == "--csv") csvOutput = true;
        else if (arg == "-p" || arg == "--pick") {
            if (i + 1 < argc) {
                try {
                    pickedNumber = stoi(argv[++i]);
                    pickSpecific = true;
                } catch (...) {
                    cerr << "Error: --pick requires a valid number.\n";
                    return 1;
                }
            } else {
                cerr << "Error: --pick requires a number.\n";
                return 1;
            }
        } else if (arg == "-h" || arg == "--help") {
            displayHelp();
            return 0;
        }
    }
    if (appInfo) {
        cout << "Southern Sayings App - Available on:" << endl;
        cout << "iOS:" << "https://apps.apple.com/app/southern-sayings/id6757964917" << endl;
        //cout << "Android: https://play.google.com/store/apps/details?id=pro.codelife.southernsayings\n";
        return 0;
    }
    if (impoliteOnly && politeOnly) {
        cerr << "It is impossible to be polite and impolite at the same time.\n";
        return 1;
    }
    // Create filtered list of indices based on politeOnly flag
    vector<int> availableIndices;
    for (size_t i = 0; i < southernSayings.size(); ++i) {
        if (impoliteOnly) {
            if (!southernSayings[i].okForPoliteCompany) {
                availableIndices.push_back(i);
            }
            continue;
        }
        else if (!politeOnly || southernSayings[i].okForPoliteCompany) {
            availableIndices.push_back(i);
        }
    }

    // Handle JSON output
    if (jsonOutput) {
        cout << "[\n";
        for (size_t i = 0; i < availableIndices.size(); ++i) {
            int idx = availableIndices[i];
            cout << "  {\n";
            cout << "    \"polite\": " << (southernSayings[idx].okForPoliteCompany ? "true" : "false" ) << ",\n";
            cout << "    \"text\": \"" << escapeJSON(southernSayings[idx].text) << "\",\n";
            cout << "    \"meaning\": \"" << escapeJSON(southernSayings[idx].meaning) << "\"\n";
            cout << "  }" << (i < availableIndices.size() - 1 ? "," : "") << "\n";
        }
        cout << "]\n";
        return 0;
    }

    // Handle CSV output
    if (csvOutput) {
        cout << "Polite,Text,Meaning\n";
        for (int idx : availableIndices) {
            cout << (southernSayings[idx].okForPoliteCompany ? "Yes" : "No") << "," << escapeCSV(southernSayings[idx].text) << "," << escapeCSV(southernSayings[idx].meaning) << "\n";
        }
        return 0;
    }

    bool separateLines = !together;
    // We work with indices to preserve the original association regardless of output order
    vector<int> originalIndices = availableIndices;

    if (showAll) {
        cout << "Southern Sayings - A collection of Southern sayings with their meanings\n\n";
        random_device rd;
        mt19937 gen(rd());
        shuffle(originalIndices.begin(), originalIndices.end(), gen);

        for (int idx : originalIndices) {
            outputSaying(southernSayings[idx], idx, separateLines, colored, noMeaning, showNumber);
        }
        cout << "\nTotal sayings: " << availableIndices.size() << "\n";
    } else if (pickSpecific) {
        if (pickedNumber >= 1 && pickedNumber <= static_cast<int>(southernSayings.size())) {
            int idx = pickedNumber - 1;
            // Check if this saying is available (not filtered out by politeOnly)
            if (find(availableIndices.begin(), availableIndices.end(), idx) != availableIndices.end()) {
                outputSaying(southernSayings[idx], idx, separateLines, colored, noMeaning, showNumber);
            } else {
                cerr << "Error: Saying #" << pickedNumber << " is not available with --polite filter\n";
                return 1;
            }
        } else {
            cerr << "Error: Picked number " << pickedNumber << " out of range (1-" << southernSayings.size() << ")\n";
            return 1;
        }
    } else {
        if (availableIndices.empty()) {
            cerr << "Error: No sayings available with current filters\n";
            return 1;
        }
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, availableIndices.size() - 1);
        int randomIdx = availableIndices[dis(gen)];
        outputSaying(southernSayings[randomIdx], randomIdx, separateLines, colored, noMeaning, showNumber);
    }
    return 0;
}

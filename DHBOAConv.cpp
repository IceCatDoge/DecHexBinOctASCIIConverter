// 12.02.2020
// *Learning project*
// EASCII translation results depend on system encoding

#include <iostream>
#include <bitset>
#include <string>
#include <sstream>

void converter();
void printHex(long long a);
void printBin(long long a);
void stringToBinary();
void binaryToString();
void hexToDec();
void hexToBin();
void printOct(long long a);
void octToDec();

int main()
{
    char answer;
    char quitter = 'n';
    std::cout << "NumberAndTextConverter v1.1\n*********By IceCat*********\n" << std::endl;
    while (quitter != 'y' && quitter != 'Y') {
        answer = 'y';
        std::cout << "1 - Convert decimal whole numbers to hex, binary and octal\n2 - Convert characters to binary\n3 - Convert binary to EASCII(8-bit conversion)\n4 - Convert hex numbers to decimal\n5 - Convert hex numbers to binary\n6 - Convert octal numbers to decimal\nAnything else quits\n";
        char option;
        std::cin >> option;
        switch (option) {
        case '1':

            while (answer == 'y' || answer == 'Y')
            {
                converter();
                std::cout << "\nTry again? y/n\n";
                std::cin >> answer;
            }
            continue;
        case '2':
            while (answer == 'y' || answer == 'Y')
            {
                stringToBinary();
                std::cout << "\nTry again? y/n\n";
                std::cin >> answer;
            }
            continue;
        case '3':
            while (answer == 'y' || answer == 'Y')
            {
                binaryToString();
                std::cout << "\nTry again? y/n\n";
                std::cin >> answer;
            }
            continue;
        case '4':
            while (answer == 'y' || answer == 'Y')
            {
                hexToDec();
                std::cout << "\nTry again? y/n\n";
                std::cin >> answer;
            }
            continue;
        case '5':
            while (answer == 'y' || answer == 'Y')
            {
                hexToBin();
                std::cout << "\nTry again? y/n\n";
                std::cin >> answer;
            }
            continue;
        case '6':
            while (answer == 'y' || answer == 'Y')
            {
                octToDec();
                std::cout << "\nTry again? y/n\n";
                std::cin >> answer;
            }
            continue;
        default:
            std::cout << "Quitting...\n";
            quitter = 'y';
        }
    }
    return 0;
}
void converter() {
    long long value{};
    std::cout << "This will convert integers to hex, binary and octal (up to 4 bytes, max: 4 294 967 295)\n";
    while ((std::cout << "Give a number: ") && !(std::cin >> std::dec >> value)) { // care: std::hex and the like are sticky
        std::cout << "Wrong input!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skips the non-numeric characters at the end of the loop
    }
    std::cout << std::endl;
    printHex(value);
    printBin(value);
    printOct(value);
}

void printHex(long long a) {
    std::stringstream buffstream;
    std::string althexprintmode = "Alternative print mode: 0x";
    buffstream << std::hex << a << std::endl << std::endl;
    char finalbuffer;
    std::string finalbufferstr;
    for (int i = 0; buffstream.good(); i++) {
        buffstream >> finalbuffer;
        finalbufferstr += finalbuffer;
    }
    finalbufferstr.resize(finalbufferstr.length() - 1);
    try {
        finalbufferstr.insert(finalbufferstr.length() - 4, " ");
    }
    catch (...) { althexprintmode = ""; }
    try {
        finalbufferstr.insert(finalbufferstr.length() - 9, " ");
    }
    catch (...) {}
    std::cout << "HEX:\n";
    if (althexprintmode._Equal("Alternative print mode: 0x")) {
        std::cout << finalbufferstr << "\n" << althexprintmode;
    }
    printf("%llx\n", a);
    std::cout << std::endl;
}
void printBin(long long a) {
    if (a < 256) {
        std::string str = std::bitset<8>(a).to_string();
        std::cout << "BINARY:\n(8-bit) " << str.substr(0, 4) << " " << str.substr(4, 4) << std::endl;
        std::cout << "Alternative print mode: " << std::bitset<8>(a).to_string() << "\n\n";
    }
    else if (a < 65535) {
        std::string str = std::bitset<16>(a).to_string();
        std::cout << "BINARY:\n(16-bit) " << str.substr(0, 4) << " " << str.substr(4, 4) << " " << str.substr(8, 4) << " " << str.substr(12, 4) << std::endl;
        std::cout << "Alternative print mode: " << std::bitset<16>(a).to_string() << "\n\n";
    }
    else if (a < 16777216) {
        std::string str = std::bitset<24>(a).to_string();
        std::cout << "BINARY:\n(24-bit) " << str.substr(0, 4) << " " << str.substr(4, 4) << " " << str.substr(8, 4) << " " << str.substr(12, 4) << " " << str.substr(16, 4) << " " << str.substr(20, 4) << std::endl;
        std::cout << "Alternative print mode: " << std::bitset<24>(a).to_string() << "\n\n";
    }
    else {
        std::string str = std::bitset<32>(a).to_string();
        std::cout << "BINARY:\n(32-bit) " << str.substr(0, 4) << " " << str.substr(4, 4) << " " << str.substr(8, 4) << " " << str.substr(12, 4) << " " << str.substr(16, 4) << " " << str.substr(20, 4) << " " << str.substr(24, 4) << " " << str.substr(28, 4) << std::endl;
        std::cout << "Alternative print mode: " << std::bitset<32>(a).to_string() << "\n\n";
    }
}
void stringToBinary() {
    std::cout << "Write any character string: ";
    std::string bString;
    std::cin.ignore(); //otherwise getline reads the last \n
    std::getline(std::cin, bString);
    for (unsigned int i = 0; i < bString.size(); ++i)
    {
        std::cout << std::bitset<8>(bString[i]) << std::endl;
    }
}

//Results are machine dependent
void binaryToString() {
    std::cout << "Write a binary string: (e.g. input '01000001' will be character 'A') ";
    std::string binaryString;
    std::cin.ignore(); //otherwise getline reads the last \n
    std::getline(std::cin, binaryString);
    std::stringstream sstream(binaryString);
    std::string output;
    while (sstream.good())
    {
        std::bitset<8> bits_8;
        sstream >> bits_8;
        char letter = char(bits_8.to_ulong());
        output += letter;
    }
    std::cout << output << std::endl;

}
void hexToDec() {
    signed long long hnum;
    std::cout << "This will convert hex to dec (up to 7fff ffff ffff ffff)\n";
    std::cout << "Write a hex number: ";
    std::cin >> std::hex >> hnum;
    if (std::cin.fail())
    {
        std::cout << "Error! Bad input.";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else std::cout << "\nDEC: " << hnum << std::endl;

}
void hexToBin() {
    long long hbnum;
    std::cout << "This will convert hex to bin (up to 4 bytes)\n";
    std::cout << "Write a hex number: ";
    std::cin >> std::hex >> hbnum;
    if (hbnum <= 0xff) {
        std::cout << "\nBIN: " << std::bitset<8>(hbnum).to_string() << std::endl;
    }
    else if (hbnum <= 0xffff) {
        std::cout << "\nBIN: " << std::bitset<16>(hbnum).to_string() << std::endl;
    }
    else if (hbnum <= 0xffffff) {
        std::cout << "\nBIN: " << std::bitset<24>(hbnum).to_string() << std::endl;
    }
    else if (hbnum <= 0xffffffff) {
        std::cout << "\nBIN: " << std::bitset<32>(hbnum).to_string() << std::endl;
    }
    else if (hbnum > 0xffffffff) {
        std::cout << "\nError! (max=ffffffff)" << std::endl;
    }
    if (std::cin.fail())
    {
        std::cout << "Error! Bad input.";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

}
void printOct(long long a) {
    std::cout << "OCTAL: \n";
    printf("%llo\n", a); // this is used to prevent std::oct from sticking to std::cout
}
void octToDec() {
    long long octnum;
    std::cout << "This will convert octals to decimals (up to 77777777777777777777)\n";
    std::cout << "Write an octal number: ";
    std::cin >> std::oct >> octnum;
    std::cout << "DEC: " << octnum << std::endl;
    if (std::cin.fail())
    {
        std::cout << "Error! Bad input.";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

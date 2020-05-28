#include <unistd.h>

#include <cstring>
#include <iostream>

typedef long long llong; // alias for long long

// a simple recursive function
llong factorial(int n) {
    if (n == 1) {
        return n;
    }

    return factorial(n - 1) * n;
}

// that's a simple enum to cover all possible logging levels
enum class LogLevel {
    Debug = 0,
    Info,
    Warning,
    Error
};

/*
 * One of the possible command line parameters is log level.
 * Let's check if we have a correct one.
 */
void checkLogLevel(LogLevel logLevel) {
    switch (logLevel) {
        case LogLevel::Debug:
            std::cout << "Debug log level"<< std::endl;
            break;
        case LogLevel::Info:
            std::cout << "Info log level"<< std::endl;
            break;
        case LogLevel::Warning:
            std::cout << "Warning log level"<< std::endl;
            break;
        case LogLevel::Error:
            std::cout << "Error log level"<< std::endl;
            break;
        default:
            std::cout << "Unknown log level: " << static_cast<int>(logLevel) << std::endl;
    }
}

// a function to parse our program's command line arguments
void parseArguments(int argc, char** argv) {
    const char optstring[]{"hc:v:"};
    int option{0};

    while((option = getopt(argc, argv, optstring)) != -1) {
        switch (option) {
            case 'h':
                    std::cout << "\nUsage: " << argv[0]
                              << " [-c <path_to_config_file>]"
                              << " [-v <loglevel>]"
                              << std::endl;
                    exit(0);
            case 'c':
                    std::cout<< "Config path is " << optarg << std::endl;
                    break;
            case 'v': {
                    const int level{std::atoi(optarg)};
                    checkLogLevel(static_cast<LogLevel>(level));
                    break;
            }
            default:
                std::cout << "Unknown option:" << option << std::endl;
        }
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    parseArguments(argc, argv);

    char str1[]{"Hello "};
    strncpy(str1, "hello", 3);
    const char* str2 = "World";
    std::strcat(str1, str2);

    std::cout << "str1 + str2 = " << str1 << std::endl;

    std::strncpy(str1 + 2, "new", 2);
    std::cout << "str1 modified = " << str1 << std::endl;

    const int ret{std::strncmp("CCa", "CCc", 2)};
    char str3[255]{};
    if (ret < 0) {
        strcpy(str3, "string 1 is less than string 2");
    } else if (ret == 0) {
        strcpy(str3, "strings are equal");
    } else {
        strcpy(str3, "string 1 is bigger than string 2");
    }
    std::cout << "strcmp: " << str3<< std::endl;

    char strings[]{"a,b,c, d, e"};
    const char* delim{","};

    const char* token = std::strtok(strings, delim);
    while (token != nullptr) {
        std::cout << token << std::endl;
        token = strtok(nullptr, delim);
    }
    std::cout<< "strings: " << strings << std::endl;

    std::cout<< "factorial: " << factorial(5) << std::endl;

    return 0;
}

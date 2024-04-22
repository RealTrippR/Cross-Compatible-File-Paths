#include <iostream>
#include <fstream>

#ifdef __unix__                    /* __unix__ is usually defined by compilers targeting Unix systems */

#define OS_Windows 0


#elif defined(_WIN32) || defined(WIN32)     /* _Win32 is usually defined by compilers targeting 32 or   64 bit Windows systems */

#define OS_Windows 1

#endif

void replace(std::string& str, char toReplace, char replaceWith) {
	for (unsigned int i = 0; i < str.length(); ++i) {
		if (str[i] == toReplace) {
			str[i] = replaceWith;
		}
	}
}
void pathToWindows(std::string path) {
	replace(path,'/', '\\');
}

void pathToUnix(std::string path) {
	replace(path, '\\', '/');
}

// returns the converted path.
std::string convertPath(std::string path, std::string data) {
	if (OS_Windows) {
		pathToWindows(path);
	}
	else {
		pathToUnix(path);
	}
	return path;
}

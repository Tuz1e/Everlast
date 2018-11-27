#ifndef FILELOADER_H
#define FILELOADER_H

class FileLoader
{
public:
	FileLoader();
	~FileLoader();

	std::vector<int, int> *GetMap(const std::string &aPath);
	std::vector<std::string> GetFiles(const std::string &aPath);
};

#endif
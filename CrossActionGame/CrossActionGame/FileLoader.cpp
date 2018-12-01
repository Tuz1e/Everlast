#include "pch.h"
#include "FileLoader.h"
#include <fstream>
#include <filesystem>

FileLoader::FileLoader()
{
}

FileLoader::~FileLoader()
{
}

//std::vector<int, int>* FileLoader::GetMap(const std::string & aPath)
//{
//	std::vector<int, int> tempFiles;
//	//TODO: Map Logic, making you able to load in maps from txt files.
//}

//std::vector<std::string> FileLoader::GetFiles(const std::string &aPath)
//{
//	std::vector<std::string> tempFiles;
//	for (auto & files : std::experimental::filesystem::v1::directory_iterator(aPath))
//	{
//		int tempFind = (int)files.path().string().find(".xml");
//		if (tempFind != std::string::npos)
//		{
//			tempFiles.push_back(files.path().string());
//		}
//	}
//
//	return tempFiles;
//}
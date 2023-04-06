/*
 * EncodeVideo.cpp
 *
 *  Created on: 2021/11/13
 *      Author: luker
 */


#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <cstddef>
#include <cstring>

int main(int argc, char **argv)
{
	//DETERMINE INPUT
	if(argc < 2) {
		std::cout << "No file passed." <<std::endl;
		system("PAUSE");
		return 1;
	}

	//SEPARATE STRING INTO PARTS
	std::string pathname = argv[1];
	std::string currentExt = "";
	int extMarker = pathname.find_last_of(".");
	if(extMarker != -1){
		currentExt = pathname.substr(extMarker);
	}
	if(currentExt != ".mp4" && currentExt != ".mkv" && currentExt != ".webm") {
	//if(currentExt != ".gif") {
		std::cout << "Not a correct file type passed." <<std::endl;
		system("PAUSE");
		return 2;
	}
	std::string newName = pathname.substr(0, extMarker);
	newName = newName + ".mp4";

	//THIS COMMAND IS FOR RE-ENCODING VIDEOS
	//std::string consoleCmd = "ffmpeg -i \"" + pathname + "\" -c:v libx265 -preset slow -crf 23 -c:a aac \"" + newName + "\"";
	//THIS IS FOR GIF TO VIDEO
	//std::string consoleCmd = "ffmpeg -i \"" + pathname + "\" -movflags faststart -pix_fmt yuv420p -vf \"scale=trunc(iw/2)*2:trunc(ih/2)*2\" \"" + newName + "\"";
	//THIS IS FOR RE_ENCODING 1080p LIVE ACTION VIDEOS
	int pathMark = newName.find_last_of("\\");
	std::string newDir = newName.substr(0, pathMark + 1) + "-RE-ENCODED";
	std::string cmdOne = "mkdir \"" + newDir + "\"";
	const char* cmdOne1 = const_cast<char*>(cmdOne.c_str());
	system(cmdOne1);
	newName = newDir + newName.substr(pathMark);
	std::string consoleCmd = "ffmpeg -i \"" + pathname + "\" -c:v libx265 -preset slow -crf 22 -c:a aac \"" + newName + "\"";
	const char* cmdcon = const_cast<char*>(consoleCmd.c_str());
	system(cmdcon);


	return 0;
}




